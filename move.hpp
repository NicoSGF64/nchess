#include <string>
#pragma once

std::array<int,2> parseCoord(std::string _square)
{
    std::string letters="abcdefgh";
    std::array<int,2> _cord;
    auto i=0; // Look at me! I know C++11!
    while(letters.at(i)!=_square.at(0))
    {
        i++;
    }
    _cord[0]=i;
    _cord[1]=static_cast<int>(_square.at(1));

    return _cord;
}

std::array<int,4> getCoord()
{
    std::array<int,4> cord;
    std::string squaref,squaret;
    
    std::array<int,2> copyCoord; //We get a buffer until I find a more elegant solution
    echo();
    printw("\nYour turn\n");

    printw("From: ");
    refresh();
    getstr(squaref.data());

    printw("\nTo: ");
    refresh();
    squaret = getstr(squaret.data());
    printw(squaret.data());
    refresh();
    getch();
    /*
    printw("\nYour turn\n");
    echo();

    printw("From: ");
    refresh();

    //Cord 0 goes with cord 2, and cord 1 goes with cord 3
    getstr(squaref.data());
    //cord[0]=getch()-49; // Curses numbers: 48 (0) - 58 (10)
    //cord[1]=getch()-49;
    copyCord = parseCoord(squaref);
    cord[0,1] = copyCord[0,1];
    
    printw("\nTo: ");
    refresh();
    getstr(squaret.data());
    copyCord = parseCoord(squaret);
    cord[2,3] = copyCord[0,1];
    //cord[2]=getch()-49;
    //cord[3]=getch()-49;
    printw("\n");
    refresh();
    */
    throw std::runtime_error("Someone fucked up");
    //return cord;
}

//I love std::array. How could you tell?

bool verify(std::array<int,4> __cord, std::array<std::array<piece*,8>,8> __board)
{
    if((!(__board[__cord[0]][__cord[1]]->colour==__board[__cord[2]][__cord[3]]->colour) || __board[__cord[2]][__cord[3]]->id==0)==true)
    {
        switch(__board[__cord[0]][__cord[1]]->id)
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
                if(MOVEKNIGHT)
                {
                    return true;
                }
                break;
            case 3:
                if(MOVEBISHOP)
                {
                    return true;
                }
                break;

            //case 4:
                

            case 7:
            return true;
            break;
        }
    }
    return false;
}

std::array<std::array<piece*,8>,8> movePiece(std::array<std::array<piece*,8>,8> _board)
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
    _board[_cord[0]][_cord[1]]=emptyptr;
    
    possible=false;
    return _board;
}