#include "board.hpp"
#pragma once

std::array<int,4> getCoord()
{
    std::array<int,4> cord;
    printw("\nYour turn\n");

    echo();
    //char piece=getch()-48;

    printw("From: ");
    refresh();
    cord[0]=getch()-48; // Curses numbers: 48 (0) - 58 (10)
    cord[1]=getch()-48;

    printw("\nTo: ");
    refresh();
    cord[2]=getch()-48;
    cord[3]=getch()-48;
    printw("\n");
    refresh();

    return cord;
}

//I love std::array. How could you tell?

bool verify(std::array<int,4> __cord, std::array<std::array<piece,7>,7> __board)
{
    switch(__board[__cord[0]][__cord[1]].id)
    {
        case 1:
            if(__cord[2]==__cord[0]+1)
            {
                return true;
            }
            break;
        case 7:
        return true;
        break;
    }
    return false;
}

std::array<std::array<piece,7>,7> movePiece(std::array<std::array<piece,7>,7> _board)
{
    std::array<int,4> _cord = getCoord();
    bool possible = false;
    possible = verify(_cord, _board);

    while (possible == false)
    {
    printw("Invalid movement!\n");
    _cord = getCoord();
    possible = verify(_cord, _board);
    }
    _board[_cord[2]][_cord[3]].id=_board[_cord[0]][_cord[1]].id;
    _board[_cord[0]][_cord[1]].id=0;
    
    possible=false;
    return _board;
}