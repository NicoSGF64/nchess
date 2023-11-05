#include <locale.h>
#include "board.hpp"
#include "move.hpp"

int main()
{
	setlocale(LC_ALL, ""); //Unicode support
	initCurses();

	std::array<std::array<piece*,8>,8> board;
	initBoard(board);
	drawBoard(board);
	//Fixed at 8 moves at the moment
	for(int t=0; t<=8; t++)
	{
		movePiece(board);
		drawBoard(board);
	}
	
	endCurses(false);

	return 0;
}