#include <cstddef>
#include <string>
#include "bscurses.hpp"
#pragma once

#define white false
#define black true

//Ugly workaround because switch cases must know the values at compile time
#define EMPTY_ID 0
#define PAWN_ID 1
#define KNIGHT_ID 2
#define BISHOP_ID 3
#define DEBUG_ID 7

struct piece
{  
    int id;
    std::string name;
    bool colour; //0 - white; 1 - black. No, I'm not bri'ish
    char* const icon;
};

extern piece empty;
extern piece pawn;
extern piece knight;
extern piece bishop;
extern piece debug;

extern piece* emptyptr;
extern piece* pawnptr;
extern piece* debugptr;
extern piece* knightptr;
extern piece* bishopptr;