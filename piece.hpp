#include <cstddef>
#include <string>
#include "bscurses.hpp"
#pragma once
//I love macros. Refractor later! Maybe.
#define white false
#define black true;
//Again, cord 0 goes with cord 2, and cord 1 goes with cord 3.
// 0 and 2 are height and 1 and 3 are with.
#define MOVEPAWNFOWARD (((__cord[2]==__cord[0]+1) && (__cord[1]==__cord[3]) && (__board[__cord[2]][__cord[3]]->id==0)))
#define MOVEPAWNCAPTURE ((__cord[2]==__cord[0]+1) && (((__cord[1]==__cord[3]+1) || (__cord[1]==__cord[3]-1))) && (__board[__cord[2]][__cord[3]]->id==0))
#define MOVEBISHOP ((__cord[2]-__cord[0])==(__cord[3]-__cord[1]) || (__cord[2]-__cord[0])==-(__cord[3]-__cord[1]))
//I can't separate this so enjoy this ugly mess
//Maybe a nested macro would help? Anyway try debugging that
#define MOVEKNIGHT (((__cord[0]==__cord[2]+2) && (__cord[1]==__cord[3]+1)) || ((__cord[0]==__cord[2]+1) && (__cord[1]==__cord[3]+2)) || ((__cord[0]==__cord[2]+2) && (__cord[1]==__cord[3]-1)) || ((__cord[0]==__cord[2]+1) && (__cord[1]==__cord[3]-2)) || /**/ ((__cord[0]==__cord[2]-2) && (__cord[1]==__cord[3]+1)) || ((__cord[0]==__cord[2]-1) && (__cord[1]==__cord[3]+2)) || ((__cord[0]==__cord[2]-2) && (__cord[1]==__cord[3]-1)) || ((__cord[0]==__cord[2]-1) && (__cord[1]==__cord[3]-2)))


struct piece
{  
    int id;
    std::string name;
    bool colour; //0 - white; 1 - black. No, I'm not bri'ish
    const char* icon;
    bool verify(std::array<int,4> __cord, std::array<std::array<piece,8>,8> __board);
};

//These are global variables until I manage to find a better way, since I don't want to have to deal with ______piece_______
piece empty {0, "empty space",NULL,  "."};
piece pawn {1, "pawn", NULL, "\u265F"};
piece knight {2, "knight", NULL, "♞"};
piece bishop {3, "bishop", NULL, "♝"};
piece debug {7, "debug piece", NULL, "D"};

piece* emptyptr = &empty;
piece* pawnptr = &pawn;
piece* debugptr = &debug;
piece* knightptr = &knight;
piece* bishopptr = &bishop;