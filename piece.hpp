#ifndef PIECE_HPP
#define PIECE_HPP
#include <string>
#include "bscurses.hpp"

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
    const int id;
    std::string_view name;
    bool colour; //0 - white; 1 - black. No, I'm not bri'ish
    const char* const icon;
};

//These should be constexpr, but I can't get it working

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
#endif
