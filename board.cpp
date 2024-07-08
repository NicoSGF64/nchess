#include "bscurses.hpp"
#include "board.hpp"

// Since we are working with ncurses, first one is y and second one is x. I hate
// it, but I'd rather not have two coordinate systems at the same time

void initBoard(std::array<std::array<piece*,8>,8> &_board) {

  
  for (int i = 0; i <= 7; i++) {
    for (int j = 0; j <= 7; j++) {
      _board[i][j] = emptyptr;
    }
  }

  for (int i = 0; i <= 7; i++) {
    _board[1][i] = whitepawnptr;
  }
  _board[0][2] = whitebishopptr;
  _board[0][5] = whitebishopptr;
  _board[0][1] = whiteknightptr;
  _board[0][6] = whiteknightptr;
  _board[0][0] = whiterookptr;
  _board[0][7] = whiterookptr;
  _board[0][3] = whitequeenptr;

    for (int i = 0; i <= 7; i++) {
    _board[6][i] = blackpawnptr;
  }
  _board[7][2] = blackbishopptr;
  _board[7][5] = blackbishopptr;
  _board[7][1] = blackknightptr;
  _board[7][6] = blackknightptr;
  _board[7][0] = blackrookptr;
  _board[7][7] = blackrookptr;
  _board[7][3] = blackqueenptr;
}

void drawBoard(std::array<std::array<piece*,8>,8> &_board)
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