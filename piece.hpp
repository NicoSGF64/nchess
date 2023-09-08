#include <string>
#pragma once

struct piece
{
    int id;
    std::string name;
    bool colour; //0 - white; 1 - black. No, I'm not bri'ish
    char icon;
};

//These are global variables until I manage to get a better version, since I don't want to have ______piece_______
piece empty;
piece pawn;
piece debug;
void defPieces()
{
    
    empty.id=0;
    empty.name="empty space";
    empty.icon='.';
    
    pawn.id=1;
    pawn.name="pawn";
    pawn.icon='♟︎';
    
    debug.id=7;
    debug.name="debug piece";
    debug.icon='D';
}