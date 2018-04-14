#include "console.h"
#include <iostream>
#include <random>
#include <time.h>
#include <thread>
#include <windows.h>
using namespace std;
void a()
{
    for(int i = 1; i <= 110 ; i++)
    {
		gotoXY(1,5);
        cout <<i << " ";
       // clrscr();
        Sleep(1000);
    }
    cout << "\n";
}
void b()
{
    for(int i = 1; i <= 100; i++)
    {

		gotoXY(1, 20);
        cout << i << " ";
        //clrscr();
        Sleep(1050);
    }
}
int mmain()
{

    thread x (a);
    thread y (b);
   // x.detach();
    if (x.joinable())
    {
        x.join();
    }
   // y.detach();

    return 0;
}
