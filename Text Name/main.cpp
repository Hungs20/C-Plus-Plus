#include "console.h"
#include <iostream>
#include <random>
#include <time.h>
#include <thread>
#include <windows.h>
using namespace std;
const char* Hoa1[]
{
"     . . .    ",
"   .       .   ",
"  .         .   ",
"  .    O    .   ",
"   .       .    ",
"     . . .     ", NULL
};
const char* Hoa2[]
{
	"   . . .",
	" .       .",
	".    o    .",
	" .       .  ",
	"   . . .   ", NULL
};
const char* Hoa3[]
{
	"  .. ",
	".    .",
	".  o .    ",
	"  ..   ", NULL
};
const char* Hoa4[]
{
	"  .",
	". o .",
	"  .  ",NULL
};
const char* Rose[]
{
"               {@}             ",
"          *{@} {@} {@}*        ",
"        *;* {@} * {@} * ;*     ",
"        ' @} * {@} * {@}'      ",
"           * ; {@} * ;         ",
"            \\\\  |  //        ",
"             \\\\ Y //         ",
"              \\\\|//          ",
"          >=|'14.2'|=<        ", NULL
};

const char* I[]
{
    "    oo  ",
    "   oooo ",
    "    oo  ",
    "        ",
    "   IIII ",
    "   IIII ",
    "   IIII ",
    "   IIII ",
    "   IIII ",
    "   IIII ",
    "   IIII ",
    "   IIII ",
    "   IIII ", NULL
};
const char* You[]
{
    "  YYY     YYY       OOOOOOO        UUU        UUU     ",
    "  YYY     YYY    OO         OO     UUU        UUU     ",
    "  YYY     YYY   OO           OO    UUU        UUU     ",
    "  YYYYYYYYYYY  OO             OO   UUU        UUU     ",
    "  YYYYYYYYYYY  OO             OO   UUU        UUU     ",
    "          YYY  OO             OO   UUU        UUU     ",
    "          YYY   OO           OO    UUU        UUU     ",
    "  YYYYYYYYYYY     OO       OO      UUUUUUUUUUUUUU     ",
    "  YYYYYYYYYYY        OOOOOO        UUUUUUUUUUUUUU     ", NULL
};
const char* Iloveyou[]
{
    "	 oo                                                                                                         ",
    "	oooo                                                                                                        ",
    "	 oo                                                                                                         ",
    "                                                                                                              ",
    "	IIII     LLLL           00 00    VVV         VVV  EEEEEEEEE      YYY    YYY      00 00      UUU     UUU     ",
    "	IIII     LLLL         00     00   VVV       VVV   EEE            YYY    YYY    00     00    UUU     UUU     ",
    "	IIII     LLLL        00       00   VVV     VVV    EEEEEEEEE      YYYYYYYYYY   00       00   UUU     UUU     ",
    "	IIII     LLLL        00       00    VVV   VVV     EEE                   YYY   00       00   UUU     UUU     ",
    "	IIII     LLLLLLLLLLL  00     00      VVV VVV      EEE            YYY    YYY    00     00    UUUUUUUUUUU     ",
    "	IIII     LLLLLLLLLLL    00 00         VVVVV       EEEEEEEEE      YYYYYYYYYY      00 00      UUUUUUUUUUU     ", NULL
};
const char* hung[] =
{
    "                       __                                  ",
    " __     __   __     __ )_) ____     __	  ___________       ",
    "|  |   |  | |  |   |  |   |    \\   |  | |   ________|     ",
    "|  |___|  | |  |   |  |   |  \\  \\  |  | |  |  ______     ",
    "|   ___   | |  |   |  |   |  |\\  \\ |  | |  | |____  |    ",
    "|  |   |  | |  |___|  |   |  | \\  \\|  | |  |_____|  |    ",
    "|__|   |__| |_________|   |__|  \\_____| |___________|     ", NULL
};
const char* Love[] =
{
    "       00000000000           000000000000          ",
    "      00000000     00000   000000     0000000      ",
    "    0000000             000              00000     ",
    "   0000000               0                 0000    ",
    "  000000                                    0000   ",
    " 00000                  I                   0000   ",
    " 00000                                      00000  ",
    " 00000                 LOVE                000000  ",
    "  000000                                 0000000   ",
    "   0000000             YOU              0000000    ",
    "    000000                            000000       ",
    "       000000                        000000        ",
    "         000000                    000000          ",
    "            00000                 00000            ",
    "               0000              0000              ",
    "                 0000          0000                ",
    "                   0000      0000                  ",
    "                     000   000                     ",
    "                       00 00                       ",NULL

};
const char* num9[] =
{
    "                     ",
    "      999999999      ",
    "    99:::::::::99    ",
    "  99:::::::::::::99  ",
    " 9::::::99999::::::9 ",
    " 9:::::9     9:::::9 ",
    " 9:::::9     9:::::9 ",
    "  9:::::99999::::::9 ",
    "   99::::::::::::::9 ",
    "     99999::::::::9  ",
    "          9::::::9   ",
    "         9::::::9    ",
    "        9::::::9     ",
    "       9:::::9       ",
    "      9:::::9        ",
    "     9999999         ", NULL
};
const char* num8[] =
{
    "                     ",
    "      888888888      ",
    "    88:::::::::88    ",
    "  88:::::::::::::88  ",
    " 8::::::88888::::::8 ",
    " 8:::::8     8:::::8 ",
    " 8:::::8     8:::::8 ",
    "  8:::::88888:::::8  ",
    "   8:::::::::::::8   ",
    "  8:::::88888:::::8  ",
    " 8:::::8     8:::::8 ",
    " 8:::::8     8:::::8 ",
    " 8::::::88888::::::8 ",
    "  88:::::::::::::88  ",
    "    88:::::::::88    ",
    "      888888888      ", NULL
};
const char* num7[] =
{
    "                     ",
    " 77777777777777777777",
    " 7::::::::::::::::::7",
    " 7::::::::::::::::::7",
    " 777777777777:::::::7",
    "            7::::::7 ",
    "           7::::::7  ",
    "          7::::::7   ",
    "         7::::::7    ",
    "        7::::::7     ",
    "       7::::::7      ",
    "      7::::::7       ",
    "     7::::::7        ",
    "    7::::::7         ",
    "   7::::::7          ",
    "  77777777           ",NULL
};
const char* num6[] =
{
    "                     ",
    "         66666666    ",
    "        6::::::6     ",
    "       6::::::6      ",
    "      6::::::6       ",
    "     6::::::6        ",
    "    6::::::6         ",
    "   6::::::::66666    ",
    "  6::::::::::::::6   ",
    " 6::::::66666:::::6  ",
    " 6:::::6     6:::::6 ",
    " 6:::::6     6:::::6 ",
    " 6::::::66666::::::6 ",
    "  66:::::::::::::66  ",
    "    66:::::::::66    ",
    "      666666666      ",NULL
};
const char* num5[] =
{
    "                     ",
    " 555555555555555555  ",
    " 5::::::::::::::::5  ",
    " 5:::::555555555555  ",
    " 5:::::5             ",
    " 5:::::5             ",
    " 5:::::5555555555    ",
    " 5:::::::::::::::5   ",
    " 555555555555:::::5  ",
    "             5:::::5 ",
    "             5:::::5 ",
    " 5555555     5:::::5 ",
    " 5::::::55555::::::5 ",
    "  55:::::::::::::55  ",
    "    55:::::::::55    ",
    "      555555555      ",NULL
};
const char* num4[] =
{
    "                     ",
    "        444444444    ",
    "       4::::::::4    ",
    "      4:::::::::4    ",
    "     4::::44::::4    ",
    "    4::::4 4::::4    ",
    "   4::::4  4::::4    ",
    "  4::::4   4::::4    ",
    " 4::::444444::::444  ",
    " 4::::::::::::::::4  ",
    " 4444444444:::::444  ",
    "           4::::4    ",
    "           4::::4    ",
    "         44::::::44  ",
    "         4::::::::4  ",
    "         4444444444  ",NULL
};
const char* num3[] =
{
    "                     ",
    " 3333333333333333    ",
    " 3:::::::::::::::33  ",
    " 3::::::33333::::::3 ",
    " 3333333     3:::::3 ",
    "             3:::::3 ",
    "             3:::::3 ",
    "     33333333:::::3  ",
    "     3:::::::::::3   ",
    "     33333333:::::3  ",
    "             3:::::3 ",
    "             3:::::3 ",
    " 3333333     3:::::3 ",
    " 3::::::33333::::::3 ",
    " 3:::::::::::::::33  ",
    "  333333333333333    ",NULL
};
const char* num2[] =
{
    "                     ",
    " 222222222222222     ",
    " 2:::::::::::::::22  ",
    " 2::::::222222:::::2 ",
    " 2222222     2:::::2 ",
    "             2:::::2 ",
    "             2:::::2 ",
    "          2222::::2  ",
    "     22222::::::22   ",
    "   22::::::::222     ",
    "  2:::::22222        ",
    " 2:::::2             ",
    " 2:::::2       222222",
    " 2::::::2222222:::::2",
    " 2::::::::::::::::::2",
    " 22222222222222222222",NULL
};
const char* num1[] =
{
    "                     ",
    "       1111111       ",
    "      1::::::1       ",
    "     1:::::::1       ",
    "     111:::::1       ",
    "        1::::1       ",
    "        1::::1       ",
    "        1::::1       ",
    "        1::::l       ",
    "        1::::l       ",
    "        1::::l       ",
    "        1::::l       ",
    "     111::::::111    ",
    "     1::::::::::1    ",
    "     1::::::::::1    ",
    "     111111111111    ",NULL
};
const char* num0[] =
{
    "                     ",
    "      000000000      ",
    "    00:::::::::00    ",
    "  00:::::::::::::00  ",
    " 0:::::::000:::::::0 ",
    " 0::::::0   0::::::0 ",
    " 0:::::0     0:::::0 ",
    " 0:::::0     0:::::0 ",
    " 0:::::0 000 0:::::0 ",
    " 0:::::0     0:::::0 ",
    " 0:::::0     0:::::0 ",
    " 0::::::0   0::::::0 ",
    " 0:::::::000:::::::0 ",
    "  00:::::::::::::00  ",
    "    00:::::::::00    ",
    "      000000000      ",NULL
};
void info()
{
        int i, x, y;
        x = 33;
        y = 25;
        i = 0;
        int color;
        while (hung[i] != '\0')
        {
            gotoXY(x, y+i);
            color = rand() % 14 + 1;
            TextColor(color);
            cout << hung[i] << endl;
            ++i;
        }
        Sleep(500);
}
void Show(const char* text[], int x, int y, int timesleep)
{

    int i = 0;
    int color;
    while (text[i] != '\0')
    {
        gotoXY(x, y + i);
        color = rand() % 14 + 1;
        TextColor(color);
        cout << text[i] << endl;
        ++i;
    }
    Sleep(timesleep);
	clrscr();
}

void ShowText(const char* text[], int x, int y, int timesleep)
{
    int i = 0;
    int color;
    while (text[i] != '\0')
    {
        gotoXY(x, y+i);
        color = rand() % 14 + 1;
        TextColor(color);
        cout << text[i] << "\n";
        ++i;
    }
    Sleep(timesleep);
}

void shownum()
{
    int Time = 9;
    while(Time >= 0)
    {
        if(Time == 9) ShowText(num9, 50, 7, 500);
        if(Time == 8) ShowText(num8, 50, 7, 500);
        if(Time == 7) ShowText(num7, 50, 7, 500);
        if(Time == 6) ShowText(num6, 50, 7, 500);
        if(Time == 5) ShowText(num5, 50, 7, 500);
        if(Time == 4) ShowText(num4, 50, 7, 500);
        if(Time == 3) ShowText(num3, 50, 7, 500);
        if(Time == 2) ShowText(num2, 50, 7, 500);
        if(Time == 1) ShowText(num1, 50, 7, 500);
        if(Time == 0) ShowText(num0, 50, 7, 500);
        Time--;
        info();
    }
    if(Time == -1) clrscr();
}
void Flower()
{
        int x = 0, y = 0;
        x = rand() % 10 + 90;
        y = rand() % 10 + 20;
        for(int i = 1; i <= 4; i++)
		{
			if(i == 1) ShowText(Hoa4, x, y, 10);
			if(i == 2) ShowText(Hoa3, x, y - i, 10);
			if(i == 3) ShowText(Hoa2, x, y - i, 10);
			if(i == 4) ShowText(Hoa1, x, y - i, 10);
		}
}
void Head()
{
    while(1)
    {
        ShowText(Iloveyou, 1, 1, 100);
        ShowText(Rose, 1, 20, 100);
    }
}
void Bot()
{
	int ib = 1;
    while(ib > 0)
    {
        if(ib % 3 == 1) Show(I, 40, 15, 500);
        if(ib % 3 == 2) Show(Love, 39, 15, 500);
        if(ib % 3 == 0) Show(You, 37, 15, 500);
        ib++;
    }
}
void sound(){
	mciSendString("open \"mylove.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3 repeat", NULL, 0, NULL);
}
void play()
{
	for(int i = 1; ; ++i)
	{
		ShowText(Iloveyou, 1, 1, 100);
        ShowText(Rose, 1, 20, 100);
        Flower();
        Flower();
        Flower();
        Flower();
        Flower();
        if(i % 3 == 1) Show(I, 40, 15, 100);
        if(i % 3 == 2) Show(Love, 39, 15, 100);
        if(i % 3 == 0) Show(You, 37, 15, 100);
	}
}
void playthread()
{
    thread fi (Head);
    thread se (Flower);
    thread thir (Bot);
    if(fi.joinable()) fi.join();
	if(se.joinable()) se.join();
    if(thir.joinable()) thir.join();
}
int main()
{
    srand(time(NULL));
    HideCursor();
    ResizeConsole(1000, 600);
    SetConsoleTitle("Love");
    shownum();
    std::thread soundd(sound);
    soundd.detach();
    play();
    return 0;
}
