#ifndef BSCURSES_HPP
#define BSCURSES_HPP
#include <ncurses.h>
//A private collection of ncurses shorcuts
extern void initCurses();

extern void endCurses(bool doGetch);
#endif
