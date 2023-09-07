// ld won't work unless this is a .hpp for some reason

#include <array>

 std::array<std::array<int,7>,7> initBoard()
{
    std::array<std::array<int,7>,7> board;

    for(int i=0; i<=6; i++)
    {
        for(int j=0; j<=6; j++)
        {
            board[i][j]=0;
        }
    }
    board[0][0]=1;

    return board;
}

void drawBoard(std::array<std::array<int,7>,7> _board)
{
    for(int i=6; i>=0; i--)
    {
        for(int j=0; j<=6; j++)
        {
            switch(_board[i][j])
            {
                case 0:
                    printw(".");
                    break;
                case 1:
                    printw("D");
                    break;
                default:
                    printw("E");
                    break;
            }
        }
        printw("\n");
    }
    refresh();
}