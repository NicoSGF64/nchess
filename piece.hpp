#include <string>
#include "bscurses.hpp"
#pragma once
//I love unreadable code. Refractor later!
#define MOVEPAWNFOWARD (((__cord[2]==__cord[0]+1) && (__cord[1]==__cord[3]) && (__board[__cord[2]][__cord[3]]->id==0)))
#define MOVEPAWNCAPTURE ((__cord[2]==__cord[0]+1) && (((__cord[1]==__cord[3]+1) || (__cord[1]==__cord[3]-1))) && (__board[__cord[2]][__cord[3]]->id==0))
#define MOVEBISHOP ((__cord[2]-__cord[0])==(__cord[3]-__cord[1]) || (__cord[2]-__cord[0])==-(__cord[3]-__cord[1]))

class piece
{  
    public:
    int id;
    std::string name;
    bool colour; //0 - white; 1 - black. No, I'm not bri'ish
    const char* icon;
    bool verify(std::array<int,4> __cord, std::array<std::array<piece,8>,8> __board);
};

//These are global variables until I manage to find a better way, since I don't want to have ______piece_______
piece empty;
piece pawn;
piece debug;
piece knight;
piece bishop;

piece* emptyptr = &empty;
piece* pawnptr = &pawn;
piece* debugptr = &debug;
piece* knightptr = &knight;
piece* bishopptr = &bishop;

void defPieces()
{
    
    empty.id=0;
    empty.name="empty space";
    empty.icon=".";
    
    pawn.id=1;
    pawn.name="pawn";
    pawn.icon="\u265F";

    knight.id=2;
    knight.name="knight";
    knight.icon="♞";

    bishop.id=3;
    bishop.name="bishop";
    bishop.icon="♝";
    
    debug.id=7;
    debug.name="debug piece";
    debug.icon="D";
}