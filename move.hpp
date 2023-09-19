#include <string>
#pragma once

//Just as a reminder, [0] and [2] are the y axis, and [1] and [3] are the x axis

std::array<int,4> parseCoord(std::string _squaref, std::string _squaret)
{
    std::string letters="abcdefgh";
    std::array<int,4> _cord;
    auto i=0; // Look at me! I know C++11!
    while(letters.at(i)!=_squaref.at(0))
    {
        i++;
    }
    
    _cord[0]=static_cast<int>(_squaref.at(1))-49; //Safety? Overrated
    _cord[1]=i;

    i=0;

    while(letters.at(i)!=_squaret.at(0))
    {
        i++;
    }

    _cord[2]=static_cast<int>(_squaret.at(1))-49;
    _cord[3]=i;

    return _cord;
}

std::array<int,4> getCoord()
{
    std::array<int,4> cord;
    std::string squaref,squaret;
    std::array<char,3> buffer; // We have to do this bad buffer workaround since string.data() doesn't actually externally set the 
    
    std::array<int,2> copyCoord; //We get a buffer until I find a more elegant solution
    echo();
    printw("\nYour turn\n");

    printw("From: \0");
    refresh();
    getnstr(buffer.data(), 2);
    squaref = buffer.data();

    printw("To: ");
    refresh();
    getnstr(buffer.data(), 2);
    squaret = buffer.data();
    cord = parseCoord(squaref, squaret);
    return cord;
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