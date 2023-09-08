#include "bscurses.hpp"
#include "board.hpp"
#include "move.hpp"
#include "piece.hpp"

int main()
{
	setlocale(LC_ALL, "");
	initCurses();
	//defPieces();
	std::array<std::array<piece,7>,7> board = initBoard();
	drawBoard(board);
	for(int t=0; t<=3; t++)
	{
		board = movePiece(board);
		drawBoard(board);
	}
	
	endCurses(false);

	return 0;
}