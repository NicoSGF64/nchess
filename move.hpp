#pragma once

std::array<int,4> getCoord()
{
    std::array<int,4> cord;
    printw("\nYour turn\n");

    echo();
    //char piece=getch()-48;

    printw("From: ");
    refresh();
    cord[0]=getch()-48; // Curses numbers: 48 (0) - 58 (10)
    cord[1]=getch()-48;

    printw("\nTo: ");
    refresh();
    cord[2]=getch()-48;
    cord[3]=getch()-48;
    printw("\n");
    refresh();

    return cord;
}

//I love std::array. How could you tell?

bool verify(std::array<int,4> __cord, std::array<std::array<piece,8>,8> __board)
{
    if(((__board[__cord[0]][__cord[1]].colour==__board[__cord[2]][__cord[3]].colour) && __board[__cord[2]][__cord[3]].id==0)==true)
    {
        switch(__board[__cord[0]][__cord[1]].id)
        {
            case 1:
            
                if(MOVEPAWNFOWARD)
                {
                    return true;
                }
                    else
                    { 
                        if (MOVEPAWNCAPTURE)
                        {
                            return true;
                        }
                    }
                break;

            case 2:
                return true;
                break;
            case 3:
                if(MOVEBISHOP)
                {
                    return true;
                }
                break;

            case 7:

            return true;
            break;
        }
    }
    return false;
}

std::array<std::array<piece,8>,8> movePiece(std::array<std::array<piece,8>,8> _board)
{
    std::array<int,4> _cord = getCoord();
    bool possible = false;
    possible = verify(_cord, _board);

    while (possible == false)
    {
    drawBoard(_board);
    printw("Invalid movement!\n");
    _cord = getCoord();
    possible = verify(_cord, _board);
    }
    _board[_cord[2]][_cord[3]]=_board[_cord[0]][_cord[1]];
    _board[_cord[0]][_cord[1]]=empty;
    
    possible=false;
    return _board;
}