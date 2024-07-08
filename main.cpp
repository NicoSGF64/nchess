#include <locale.h>
#include "bscurses.hpp"
#include "board.hpp"
#include "move.hpp"

int main()
{
	setlocale(LC_ALL, ""); //Unicode support
	initCurses();

	BOARD board;
	movement cord;
	initBoard(board);
	drawBoard(board);
	//Fixed at 8 moves at the moment
	for(int t=0; t<=8; t++)
	{
		movePiece(cord, board);
		drawBoard(board);
	}
	
	endCurses(false);

	return 0;
}
