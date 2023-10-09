#include "move.hpp"

void drawBoard(std::array<std::array<piece *, 8>, 8> _board);

void parseCord(movement &_cord) {
  const std::string letters = "abcdefgh";
  const std::string pieces = "NBRQK";

  for (auto i = 0; i <= pieces.size(); i++) // Check which piece is being moved
  {
    if (i >= pieces.size()) {
      _cord.type = pawn.id;
      break; // Just in case
    } else if (_cord.notation.at(0) == pieces.at(i)) {
      _cord.type = i + 2;
      break;
    }
  }

  bool isNotPawn;

  if (_cord.type != 1) // Check if it's a capture
  {
    isNotPawn = true;
  } else {
    isNotPawn = false;
  }

  if (_cord.notation.at(1) == 'x') // Check if it's a capture
  {
    _cord.isCapture = true;
  } else {
    _cord.isCapture = false;
  }

  for (auto i = 0; i <= letters.size(); i++) {
    if (_cord.notation.at(_cord.isCapture + isNotPawn) == letters.at(i)) {
      _cord.to.at(1) = i;
      break;
    }
  }

  _cord.to.at(0) =
      static_cast<int>(_cord.notation.at(1 + isNotPawn + _cord.isCapture)) - 49;
}

void getCord(movement &_cord) {
  echo();
  printw("\nYour turn\n");

  printw("Your move: ");
  refresh();
  getnstr(_cord.notation.data(), 4);

  parseCord(_cord);
}
/*
void reverseSearch(movement &__cord, std::array<std::array<piece*,8>,8> __board)
{

}
*/

bool verifyMovement(movement &__cord,
                    std::array<std::array<piece *, 8>, 8> __board) {

  switch (__cord.type) {
  case PAWN_ID:
    if (__cord.isCapture == true) {
      // Capture logic
      return false;
    } else if (__board.at(__cord.to.at(0) - 2).at(__cord.to.at(1)) == pawnptr &&
               __cord.to.at(0) - 2 == 1 && __cord.to.at(1)) {
      __cord.from.at(0) = __cord.to.at(0) - 2;
      __cord.from.at(1) = __cord.to.at(1);

    } else if (__board.at(__cord.to.at(0) - 1).at(__cord.to.at(1)) == pawnptr) {
      __cord.from.at(0) = __cord.to.at(0) - 1;
      __cord.from.at(1) = __cord.to.at(1);
    }
    break;

  case KNIGHT_ID:

    for (auto i = 0; i <= 8; i++) {
      short a, b;
      switch (i) {
      case 0:
        a = 1;
        b = 2;
        break;
      case 1:
        a = -1;
        b = -2;
        break;
      case 2:
        b = 2;
        a = 1;
        break;
      case 3:
        a = -2;
        b = -1;
        break;
      case 4:
        a = 1;
        b = -2;
        break;
      case 5:
        a = -1;
        b = 2;
        break;
      case 6:
        a = 2;
        b = -1;
        break;
      case 7:
        a = -2;
        b = 1;
        break;
      default:
        return false;
        break;
      }
      try {
        if (__board.at(__cord.to.at(0) + a).at(__cord.to.at(1) + b) ==
            knightptr) {
          __cord.from.at(0) = __cord.to.at(0) + a;
          __cord.from.at(1) = __cord.to.at(1) + b;
          break;
        }
      } catch (std::exception) {
      }
    }
    break;

  case BISHOP_ID:

    break;

  default:
    return false;
    break;
  }

  if (__board.at(__cord.from.at(0)).at(__cord.from.at(1))->colour ==
          __board.at(__cord.to.at(0)).at(__cord.to.at(1))->colour &&
      __board.at(__cord.to.at(0)).at(__cord.to.at(1)) != emptyptr) {
    return false;
  }

  return true;
}

void movePiece(std::array<std::array<piece *, 8>, 8> &_board) {
  movement cord;
  getCord(cord);
  bool possible = false;

  try {
    possible = verifyMovement(cord, _board);
  } catch (std::exception &ex) {
    possible = false;
  }

  while (possible == false) {
    drawBoard(_board);
    printw("Invalid movement!\n");
    getCord(cord);
    possible = verifyMovement(cord, _board);
  }
  _board.at(cord.to.at(0)).at(cord.to.at(1)) =
      _board.at(cord.from.at(0)).at(cord.from.at(1));
  _board.at(cord.from.at(0)).at(cord.from.at(1)) = emptyptr;

  possible = false;
}