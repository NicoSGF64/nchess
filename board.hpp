#pragma once //Does magic to stop redefinition errors. Header include guards don't work for some reason. Probably because I'd implemented them poorly.
#include <array>
#include "piece.hpp"
#include <iostream>

// Since we are working with ncurses, first one is y and second one is x. I hate it, but I'd rather not have two coordinate systems at the same time

std::array<std::array<piece,7>,7> initBoard()
{

    std::array<std::array<piece,7>,7> _board;

    for(int i=0; i<=6; i++)
    {
        for(int j=0; j<=6; j++)
        {
            _board[i][j]=empty;
        }
    }
    _board[0][0]=pawn;
    _board[0][1]=debug;

    return _board;
}

void drawBoard(std::array<std::array<piece,7>,7> _board)
{
    clear(); //clear the board so that we don't use up space

    for(int i=6; i>=0; i--)
    {
        for(int j=0; j<=6; j++)
        {
            printw("%s", &_board[i][j].icon);
        }
        printw("\n");
    }
    refresh();
}