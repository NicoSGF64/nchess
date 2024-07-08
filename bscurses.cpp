#include "bscurses.hpp"

void initCurses()
{
    initscr();              //Start curses mode
    cbreak();               //Line buffering disabled
    keypad(stdscr, TRUE);   //We get F1, F2 etc..
    noecho();               //Don't echo() while we do getch

    refresh();              //Print it on to the real screen 
}

void endCurses(bool doGetch)
{
    if(doGetch==true)
    {
        getch();
    }

	endwin();               //End curses mode
}