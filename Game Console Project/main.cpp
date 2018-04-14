#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "console.h"
#define consoleWight 900
#define consoleHight 550

using namespace std;
int _x = 5, _y = 2; /// begin map
int score;
int num;
bool sound;
int mode; /// 1 : easy 2 : normal 3 : hard
int v; /// van toc
int h = 25, w = 31; /// height weight map
bool die;
int _min_h;
int kc, dc, dieuhuong;
string name;
struct nv
{
    int td_x, td_y;
    int str; ///ascii
};

nv item[1000], me;

void hungs20()
{

    gotoXY(5, 15);cout << " _    _                            ___    ___  \n";
    gotoXY(5, 16);cout << "| |  | |                          |__ \\  / _ \\ \n";
    gotoXY(5, 17);cout << "| |__| | _   _  _ __    __ _  ___    ) || | | | \n";
    gotoXY(5, 18);cout << "|  __  || | | || '_ \\  / _` |/ __|  / / | | | | \n";
    gotoXY(5, 19);cout << "| |  | || |_| || | | || (_| |\\__ \\ / /_ | |_| | \n";
    gotoXY(5, 20);cout << "|_|  |_| \\__,_||_| |_| \\__, ||___/|____| \\___/ \n" ;
    gotoXY(5, 21);cout << "                        __/ |                  \n";
    gotoXY(5, 22);cout << "                       |___/                   \n";
}

void rand_item(int id)
{
    int random = ((rand() % 100)) % 3;
    random++;
    item[id].td_x = _x + kc * random;
    if(id > 1) item[id].td_y = _min_h - (rand() % 2 + 2);
    else item[id].td_y = _y;
    item[id].str = 233;
}
void _sound()
{
   mciSendString("open \"sound.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3 repeat", NULL, 0, NULL);
}

void build_begin()
{
    //if(sound) _sound();
    score = 0, num = 0;
    kc = (w - 2) / 4;
    kc++;
    dc = 0;
    dieuhuong = 0;
    if(mode == 1 || mode == 0) v = 500;
    if(mode == 2) v = 300;
    if(mode == 3) v = 100;
    me.str = 234;
    _min_h = _y;

    me.td_y = _y + h - 1;
    int random = ((rand() % 100)) % 3;
    random++;
    me.td_x = _x + kc * random;
    clrscr();

}
void build_map()
{
    TextColor(10);
    int __x = _x, __y = _y;
    gotoXY(__x, __y - 1);
	for(int i = 1; i <= w; i++)
    {
        if(i == 1) cout << char(201);
        else if (i == w) cout << char(187);
        else cout << char(205);
    }
    for(int i = 1; i <= h; i++)
    {
        gotoXY(__x, __y);
        cout << char(186);
        gotoXY(__x + w - 1, __y);
        cout << char(186);
        __y++;
    }
    gotoXY(__x, __y);
    for(int i = 1; i <= w; i++)
    {
        if(i == 1) cout << char(200);
        else if (i == w) cout << char(188);
        else cout << char(205);
    }

    gotoXY(me.td_x - dc, me.td_y);
    cout << " ";
    gotoXY(me.td_x, me.td_y);
    TextColor(13);
    cout << char(me.str);
    TextColor(10);
}

void menu()
{
    int __x = _x;
    gotoXY(__x + 45, 2);
    cout << "MENU";
    gotoXY(__x + 40, 5);
    cout << "Hello : " << name;
    gotoXY(__x + 40, 7);
    cout << "Level : " ; if(mode == 2) cout << "Nomal";else if(mode == 3) cout << "Hard";else cout << "Easy";
    gotoXY(__x + 40, 9);
    cout << "Sound : "; (sound) ? cout << "On" : cout << "Off";
    gotoXY(__x + 40, 11);
    cout << "Score : " << score;
}
void dieukhien()
{
	dieuhuong = 0;
    if(_kbhit())
    {
        char key = _getch();
        if((key == 'a' || key == 'A'  || key == 75) && me.td_x - kc >= _x + 1) me.td_x -= kc, dc = -kc, dieuhuong = -1;
        else if ((key == 'd' || key == 'D' || key == 77 ) && me.td_x + kc <= _x + w - 2) me.td_x += kc, dc = kc, dieuhuong = 1;
        if(sound)
		{
			mciSendString("open \"move.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
			mciSendString("play mp3 from 0", NULL, 0, NULL);
		}
    }
}

void build_item()
{
    int sl = 0;
    _min_h = _y + h;
    for(int col = 1; col <= num; col++)
    {
        dieukhien();
        if(item[col].td_y - 1 >= _y){
			gotoXY(item[col].td_x, item[col].td_y - 1);
			cout << " " ;
        }
        gotoXY(item[col].td_x, item[col].td_y);
        if(item[col].td_y >= _y && item[col].td_y < _y + h) {
               cout << char(item[col].str);
        }
        item[col].td_y++;
        if(item[col].td_x == me.td_x && item[col].td_y == me.td_y) {
			die = 1;
			gotoXY(me.td_x - dc, me.td_y);
			cout << " ";
			if(dieuhuong < 0) gotoXY(item[col].td_x + 1, item[col].td_y);
			else if(dieuhuong > 0) gotoXY(item[col].td_x - 1, item[col].td_y);
			else if(dieuhuong == 0) gotoXY(me.td_x, me.td_y);
			TextColor(13);
			cout << char(me.str);
			TextColor(10);
		}
        if(item[col].td_y > _y + h)
        {
            rand_item(col);
            score++;
        }
        else
        {
            item[++sl] = item[col];
            _min_h = min(_min_h, item[col].td_y);
             dieukhien();
        }
    }
    num = sl;
}
void Begin()
{
    while(!name.size())
    {
        clrscr();
        gotoXY(50, 5);
        cout << "Wellcome to my game !";
        gotoXY(5, 10);
        cout << "Write your name to start : ";
        getline(cin , name);
        cout << "\n";
        gotoXY(5, 13);
        cout << "Choose level : ( 1:Easy , 2:Normal , 3:Hard ) ";
        cin >> mode;
        gotoXY(5, 16);
        cout << "Sound : ( 0:Off , 1:On ) ";
        cin >> sound;
    }
    for(int i = 1; i <= 100; i++) {
        gotoXY(40, 5);
        for(int j = 1; j <= i % 10 + 1; j++) cout << " = ";
        gotoXY(50, 8);
        cout << "LOADING..." << i << "%";
        gotoXY(70, 25);
        cout << "Code by Hungs20.";
        hungs20();
        Sleep(100);
        clrscr();
    }
}
void load_item()
{
    bg:
    while(!die)
    {
        dieukhien();
        build_map();
        dieukhien();
        build_item();
        if(die) break;
        dieukhien();
        menu();
        dieukhien();
        if(num == 0 || _min_h - _y >= (rand() % 2) + 2) rand_item(++num);
        Sleep(v/5);
    }
	if(sound)
	{
		mciSendString("close mp3", NULL, 0, NULL);
		mciSendString("open \"gameover.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		mciSendString("play mp3 from 0 wait", NULL, 0, NULL);
		mciSendString("close mp3", NULL, 0, NULL);
	}
    gotoXY(_x + 10, _y + h + 5);
    cout << "GAME OVER";
    gotoXY(_x + 10, _y + h + 7);
    cout << "Your Score : " << score;
    gotoXY(_x + 10, _y + h + 9);
    cout << "Play again ? (y/n) ";
    char ctn;
    cin >> ctn;
    if(ctn == 'y' || ctn == 'Y') {die = 0; build_begin(); goto bg;}
    else
    {
        gotoXY(_x + 10, _y + h + 11);
        cout << "Thank you.\n";
    }

}

void config()
{
    TextColor(12);
    ResizeConsole(consoleWight, consoleHight);
    HideCursor();
    SetConsoleTitle("Game Project");
    ShowCur(false);
}
int main()
{
    srand(time(NULL));
    config();
    Begin();
    build_begin();
    load_item();
    return 0;
}
