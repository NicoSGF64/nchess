#ifndef PIECE_HPP
#define PIECE_HPP
#include <string>

#define white false
#define black true

//Ugly workaround because switch cases must know the values at compile time
#define EMPTY_ID 0
#define PAWN_ID 1
#define KNIGHT_ID 2
#define BISHOP_ID 3
#define ROOK_ID 4
#define QUEEN_ID 5
#define KING_ID 6
#define DEBUG_ID 7

struct piece
{  
    const int id;
    std::string_view name; //Unused for now. Might remove later
    bool colour; //0 - white; 1 - black. No, I'm not bri'ish
    const char* const icon;
};

//I could probably create a whitepiece and blackpiece substructs as well as subsubstructs for each piece,
//but I don't think it's worth it to have a struct for each piece and each colour for just a single thing

extern piece empty;
extern piece debug;

extern piece whitepawn;
extern piece whiteknight;
extern piece whitebishop;
extern piece whiterook;
extern piece whitequeen;

extern piece blackknight;
extern piece blackbishop;
extern piece blackrook;
extern piece blackqueen;


extern piece* emptyptr;

extern piece* whitepawnptr;
extern piece* whitedebugptr;
extern piece* whiteknightptr;
extern piece* whiterookptr;
extern piece* whitebishopptr;
extern piece* whitequeenptr;

extern piece* blackpawnptr;
extern piece* blackdebugptr;
extern piece* blackknightptr;
extern piece* blackrookptr;
extern piece* blackbishopptr;
extern piece* blackqueenptr;
#endif
