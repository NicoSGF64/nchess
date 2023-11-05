#ifndef MOVE_HPP
#define MOVE_HPP
#include <array>
#include "bscurses.hpp"
#include "piece.hpp"

struct movement
{
    std::string notation="Qxe4"; //Initialize it so that getstr() doesn't write into air.
    std::array <int,2> from; //Just as a reminder, [0] is the y axis, and [1] is the x axis.
    std::array <int,2> to;  //Just as a reminder, [0] is the y axis, and [1] is the x axis.
    bool isCapture;
    int type;   // See piece.hpp for more details

};

extern void movePiece(std::array<std::array<piece*,8>,8> &_board);
#endif