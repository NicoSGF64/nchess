#include "board.hpp"
#include <cstdlib>
#include <curses.h>
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
/*
bool verifyMovement(movement __cord, std::array<std::array<piece*,8>,8> __board)
{

    //Examples "Be4", "e3", "Qxe4", Nxa7++;

    switch(__cord.at(0))
    {
        case "B":
        
            for(auto y=0; y>=7; y)
            {
                for(auto x=0; x>=7; x)
                {
                    
                }
            }
        
        case PAWNMOVE:
    }

    return false;
}
*/
void movePiece(std::array<std::array<piece*,8>,8> &_board)
{
    movement cord ;
    getCord(cord);
    bool possible = false;

    /*
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
    */
}
std::array<int, 4> parseCoord(std::string _squaref, std::string _squaret) {
    const std::string letters = "abcdefgh";
    std::array<int, 4> _cord;
    auto i = 0; // Look at me! I know C++11!
    while (letters.at(i) != _squaref.at(0)) {
    i++;
    }

    _cord[0] = static_cast<int>(_squaref.at(1)) - 49; // Safety? Overrated
    _cord[1] = i;

    i = 0;

    while (letters.at(i) != _squaret.at(0)) {
    i++;
    }

    _cord[2] = static_cast<int>(_squaret.at(1)) - 49;
    _cord[3] = i;

    return _cord;
}
