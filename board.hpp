#pragma once //Does magic to stop redefinition errors. Header include guards don't work for some reason. Probably because I'd implemented them poorly.
#include <array>
#include "bscurses.hpp"
#include "piece.hpp"
#include <iostream>

// Since we are working with ncurses, first one is y and second one is x. I hate
// it, but I'd rather not have two coordinate systems at the same time

extern void initBoard(std::array<std::array<piece *, 8>, 8> &_board);
extern void drawBoard(std::array<std::array<piece *, 8>, 8> _board);
#endif
