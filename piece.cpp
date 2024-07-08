#include "piece.hpp"

piece empty {EMPTY_ID, "empty space", NULL,  "."};
piece debug {DEBUG_ID, "debug piece", NULL, "D"};

piece whitepawn {PAWN_ID, "pawn", white, "♟︎"};
piece whiteknight {KNIGHT_ID, "knight", white, "♞"};
piece whitebishop {BISHOP_ID, "bishop", white, "♝"};
piece whiterook {ROOK_ID, "rook", white, "♜"};
piece whitequeen {QUEEN_ID, "piece", white, "♛"};

piece blackpawn {PAWN_ID, "pawn", black, "♙"};
piece blackknight {KNIGHT_ID, "knight", black, "♘"};
piece blackbishop {BISHOP_ID, "bishop", black, "♗"};
piece blackrook {ROOK_ID, "rook", black, "♖"};
piece blackqueen {QUEEN_ID, "piece", black, "♕"};

piece* emptyptr = &empty;
piece* debugptr = &debug;

piece* whitepawnptr = &whitepawn;
piece* whiteknightptr = &whiteknight;
piece* whiterookptr = &whiterook;
piece* whitebishopptr = &whitebishop;
piece* whitequeenptr = &whitequeen;

piece* blackpawnptr = &blackpawn;
piece* blackknightptr = &blackknight;
piece* blackrookptr = &blackrook;
piece* blackbishopptr = &blackbishop;
piece* blackqueenptr = &blackqueen;