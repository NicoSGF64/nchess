#include <locale.h>
#include "bscurses.hpp"
#include "board.hpp"
#include "move.hpp"

int main()
{
	setlocale(LC_ALL, ""); //Unicode support
	initCurses();
	defPieces();
	
	std::array<std::array<piece*,8>,8> board = initBoard();
	drawBoard(board);
	for(int t=0; t<=8; t++)
	{
		movePiece(board);
		drawBoard(board);
	}
	
	endCurses(false);

	return 0;
}