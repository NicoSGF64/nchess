#include "bscurses.hpp"
#include "board.hpp"
#include "move.hpp"

int main()
{
	initCurses();
	std::array<std::array<int,7>,7> board = initBoard();
	drawBoard(board);
	for(int t=0; t<=6; t++)
	{
		board = movePiece(board);
		drawBoard(board);
	}
	

	return 0;
}