// ld won't work unless this is a .hpp for some reason
#include <array>
#include <locale.h>
#include "piece.hpp"

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