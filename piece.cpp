#include "piece.hpp"

piece empty {EMPTY_ID, "empty space", NULL,  "."};
piece pawn {PAWN_ID, "pawn", NULL, "\u265F"};
piece knight {KNIGHT_ID, "knight", NULL, "♞"};
piece bishop {BISHOP_ID, "bishop", NULL, "♝"};
piece debug {DEBUG_ID, "debug piece", NULL, "D"};

piece* emptyptr = &empty;
piece* pawnptr = &pawn;
piece* debugptr = &debug;
piece* knightptr = &knight;
piece* bishopptr = &bishop;