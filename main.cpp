#include "bscurses.hpp"
#include "board.hpp"

int main()
{
	initCurses();
	std::array<std::array<int,7>,7> board = initBoard();
	drawBoard(board);

	return 0;
}