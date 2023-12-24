#ifndef BOARD_HPP
#define BOARD_HPP
#include <array>
#include "piece.hpp"
#include "bscurses.hpp"

#define BOARD_SIZE 8
#define BOARD std::array<std::array<piece*, BOARD_SIZE>, BOARD_SIZE>

// Since we are working with ncurses, first one is y and second one is x. I hate
// it, but I'd rather not have two coordinate systems at the same time

extern void initBoard(BOARD &_board);
extern void drawBoard(BOARD &_board);
#endif
