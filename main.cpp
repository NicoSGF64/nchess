#include <locale.h>
#include "bscurses.hpp"
#include "board.hpp" // ld won't work unless this is a .hpp for some reason
#include "move.hpp"

int main()
{
	setlocale(LC_ALL, "");
	initCurses();
	defPieces();
	std::array<std::array<piece*,8>,8> board = initBoard();
	drawBoard(board);
	for(int t=0; t<=8; t++)
	{
		board = movePiece(board);
		drawBoard(board);
	}
	
	endCurses(false);

	return 0;
}