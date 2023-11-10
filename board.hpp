#ifndef BOARD_HPP
#define BOARD_HPP
#include <array>
#include "bscurses.hpp"
#include "piece.hpp"

// Since we are working with ncurses, first one is y and second one is x. I hate
// it, but I'd rather not have two coordinate systems at the same time

extern void initBoard(std::array<std::array<piece*, 8>, 8> &_board);
extern void drawBoard(std::array<std::array<piece*, 8>, 8> _board);
#endif
