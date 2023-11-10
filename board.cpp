#include "board.hpp"
#include "piece.hpp"

// Since we are working with ncurses, first one is y and second one is x. I hate
// it, but I'd rather not have two coordinate systems at the same time

void initBoard(std::array<std::array<piece*, 8>, 8> &_board) {

  
  for (int i = 0; i <= 7; i++) {
    for (int j = 0; j <= 7; j++) {
      _board[i][j] = emptyptr;
    }
  }

  for (int i = 0; i <= 7; i++) {
    _board[1][i] = pawnptr;
    _board[1][i]->colour = white;
  }
  _board[3][3] = debugptr;
  _board[3][3]->colour = black;
  _board[0][2] = bishopptr;
  _board[0][5] = bishopptr;
  _board[0][1] = knightptr;
  _board[0][6] = knightptr;
}

void drawBoard(std::array<std::array<piece *, 8>, 8> _board)
{
  clear(); // clear the board so that we don't use up space
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j <= 7; j++) {
      printw("%s ", _board[i][j]->icon);
      refresh();
    }
    printw("\n");
  }
  refresh();
}