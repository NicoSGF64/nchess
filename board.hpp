#pragma once //Does magic to stop redefinition errors. Header include guards don't work for some reason. Probably because I'd implemented them poorly.
#include <array>
#include "bscurses.hpp"
#include "piece.hpp"
#include <iostream>

// Since we are working with ncurses, first one is y and second one is x. I hate it, but I'd rather not have two coordinate systems at the same time

std::array<std::array<piece,8>,8> initBoard()
{

    std::array<std::array<piece,8>,8> _board;

    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            _board[i][j]=empty;
        }
    }

    for(int i=0; i<=7; i++)
    {
        _board[1][i]=pawn;
        _board[1][i].colour=true;
    }
    _board[0][1]=debug;
    _board[0][0]=bishop;

    return _board;
}

void drawBoard(std::array<std::array<piece,8>,8> _board)
{
    
    clear(); //clear the board so that we don't use up space
    for(int i=7; i>=0; i--)
    {
        for(int j=0; j<=7; j++)
        {
            //const char simplenton1[]=_board[i][j].icon;
            printw(_board[i][j].icon);
            refresh();
        }
        printw("\n");
    }
    refresh();
    
}