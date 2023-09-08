#pragma once //Does magic to stop redifinition errors. Apparently this makes it so that files don't get included twice.
             //I don't know why they would be included twice but here we are
#include <array>
#include "piece.hpp"

// Since we are working with ncurses, first one is y and second one is x. I hate it, but I'd rather not have two coordinate systems at the same time

std::array<std::array<piece,7>,7> initBoard()
{
    std::array<std::array<piece,7>,7> _board;

    for(int i=0; i<=6; i++)
    {
        for(int j=0; j<=6; j++)
        {
            _board[i][j].id=0;
        }
    }
    _board[0][0].id=7;
    _board[0][1].id=1;

    return _board;
}

void drawBoard(std::array<std::array<piece,7>,7> _board)
{
    clear(); //clear the board so that we don't use up space

    for(int i=6; i>=0; i--)
    {
        for(int j=0; j<=6; j++)
        {
            switch(_board[i][j].id)
            {
                case 0:
                    printw(".");
                    break;
                case 1:
                    printw("\u265F");
                    break;
                case 7:
                    printw("D");
                    break;
                default:
                    printw("E");
                    break;
            }
        }
        printw("\n");
    }
    refresh();
}