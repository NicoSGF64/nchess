#ifndef MOVE_HPP
#define MOVE_HPP
#include "board.hpp"

struct movement
{
    std::string notation="Qxe4"; //Initialize it so that getstr() doesn't write into air.
    std::array <int,2> from; //Just as a reminder, [0] is the y axis, and [1] is the x axis.
    std::array <int,2> to;  //Just as a reminder, [0] is the y axis, and [1] is the x axis.
    bool isCapture;
    int type;   // See piece.hpp for more details
    bool turn=white;
};

extern void movePiece(movement &_cord, BOARD &_board);
extern void getCord(movement &_cord, BOARD &__board);
#endif
