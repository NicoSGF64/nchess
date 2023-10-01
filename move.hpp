#include "board.hpp"
#include <cstdlib>
#include <curses.h>
#include <memory>
#include <stdexcept>
#include <string>
#pragma once



struct movement
{
    std::string notation="Qxe4"; //Initialize it so that getstr() doesn't write into air.
    std::array <int,2> from; //Just as a reminder, [0] is the y axis, and [1] is the x axis.
    std::array <int,2> to;  //Just as a reminder, [0] is the y axis, and [1] is the x axis.
    bool isCapture;
    int type;   // See piece.hpp for more details

};

movement parseCord(movement &_cord)
{
    const std::string letters = "abcdefgh";
    const std::string pieces = "NBRQK";

    for (auto i=0; i<=pieces.size(); i++) //Check which piece is being moved
    {
        if(_cord.notation.at(0)==pieces.at(i))
        {
            _cord.type = i+2;
            break;
        }
        else if (i>=pieces.size()) 
        {
            _cord.type = pawn.id;
            break; //Just in case
        }

    }
    
    if(_cord.notation.at(1)=='x') //Check if it's a capture
    {
        _cord.isCapture = true;
    } 
    else {
        _cord.isCapture = false;
    }

    for (auto i=0; i<=letters.size(); i++)
    {
        if(_cord.notation.at(1+_cord.isCapture)==letters.at(i))
        {
            _cord.to[1]=i;
            break;
        }

    }

    _cord.to[0] = static_cast<int>(_cord.notation.at(2+_cord.isCapture))-49;

    return _cord;
}

void getCord(movement &_cord)
{
    echo();
    printw("\nYour turn\n");

    printw("Your move: ");
    refresh();
    getnstr(_cord.notation.data(), 4);
    
    parseCord(_cord);
}

void reverseSearch(movement &___cord, std::array<std::array<piece*,8>,8> ___board)
{
    
    switch(___cord.type)
    {
        case pawn.id:
            if(___cord.isCapture==true)
            {
                //Capture logic
            }
            else if (___board[___cord.to[0]-2][___cord.to[1]] == pawnptr && ___cord.to[0]-2 == 1) 
            {
                ___cord.from[0]=___cord.to[0]-2;
                ___cord.from[1]=___cord.to[1];

            }
            else if (___board[___cord.to[0]-1][___cord.to[1]]) 
            {
                ___cord.from[0]=___cord.to[0]-1;
                ___cord.from[1]=___cord.to[1];
            }

            break;
        default:
            throw -1;
            break;
    }
}

bool verifyMovement(movement __cord, std::array<std::array<piece*,8>,8> __board)
{
    try {
    reverseSearch(__cord, __board);
    } catch (int x) {
        return false;
    }

    return false;
}


std::array<std::array<piece*,8>,8> movePiece(std::array<std::array<piece*,8>,8> &_board)
{
    movement cord;
    getCord(cord);
    bool possible = false;
    possible = verifyMovement(cord, _board);

    while (possible == false)
    {
        drawBoard(_board);
        printw("Invalid movement!\n");
        getCord(cord);
        possible = verifyMovement(cord, _board);
    }
    _board[cord.from[0]][cord.from[1]]=_board[cord.to[0]][cord.to[1]];
    _board[cord.from[0]][cord.from[1]]=emptyptr;
    
    possible=false;
    return _board;
}
