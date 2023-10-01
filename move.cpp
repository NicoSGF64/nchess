#include "move.hpp"

void drawBoard(std::array<std::array<piece *, 8>, 8> _board);

void parseCord(movement &_cord)
{
    const std::string letters = "abcdefgh";
    const std::string pieces = "NBRQK";

    for (auto i=0; i<=pieces.size(); i++) //Check which piece is being moved
    {
        if (i>=pieces.size()) 
        {
            _cord.type = pawn.id;
            break; //Just in case
        }
        else if(_cord.notation.at(0)==pieces.at(i))
        {
            _cord.type = i+2;
            break;
        }

    }

    bool isNotPawn;

    if(_cord.type!=1) //Check if it's a capture
    {
        isNotPawn = true;
    } 
    else {
        isNotPawn = false;
    }

    if(_cord.notation.at(1)=='x') //Check if it's a capture
    {
        _cord.isCapture = true;
    } 
    else {
        _cord.isCapture = false;
    }
    
    

    for (auto i=0; i<=letters.size(); i++)
    {
        if(_cord.notation.at(_cord.isCapture+isNotPawn)==letters.at(i))
        {
            _cord.to[1]=i;
            break;
        }

    }

    _cord.to[0] = static_cast<int>(_cord.notation.at(1+isNotPawn+_cord.isCapture))-49;
}

void getCord(movement &_cord)
{
    echo();
    printw("\nYour turn\n");

    printw("Your move: ");
    refresh();
    getnstr(_cord.notation.data(), 4);
    
    parseCord(_cord);
}

void reverseSearch(movement &___cord, std::array<std::array<piece*,8>,8> ___board)
{
    switch(___cord.type)
    {
        case PAWN_ID:
            if(___cord.isCapture==true)
            {
                //Capture logic
                throw -1;
            }
            else if (___board[___cord.to[0]-2][___cord.to[1]] == pawnptr && ___cord.to[0]-2 == 1 && ___cord.to[1]) 
            {
                ___cord.from[0]=___cord.to[0]-2;
                ___cord.from[1]=___cord.to[1];

            }
            else if (___board[___cord.to[0]-1][___cord.to[1]] == pawnptr) 
            {
                ___cord.from[0]=___cord.to[0]-1;
                ___cord.from[1]=___cord.to[1];
            }
            break;
            
        case KNIGHT_ID:
        
        for(auto i=0; i<=8; i++)
        {
            short a,b;
            switch (i) 
            {
                case 0:
                    a=1;
                    b=2;
                    break;
                case 1:
                    a=-1;
                    b=-2;
                break;
                case 2:
                    b=2;
                    a=1;
                    break;
                case 3:
                    a=-2;
                    b=-1;
                    break;
                case 4:
                    a=1;
                    b=-2;
                    break;
                case 5:
                    a=-1;
                    b=2;
                    break;
                case 6:
                    a=2;
                    b=-1;
                    break;
                case 7:
                    a=-2;
                    b=1;
                    break;
                default:
                    throw -1;
                    break;
            }

            if(___cord.to[0]+a >= 0  && ___cord.to[0]+a <= 7 && ___cord.to[1]+b >= 0  && ___cord.to[1]+b <= 7 && ___board[___cord.to[0]+a][___cord.to[1]+b] == knightptr)
            {
                ___cord.from[0]=___cord.to[0]+a;
                ___cord.from[1]=___cord.to[1]+b;
                break;
            }
        }
        break;
        
        default:
            throw -1;
            break;
    }
}

bool verifyMovement(movement &__cord, std::array<std::array<piece*,8>,8> __board)
{
    try
    {
        reverseSearch(__cord, __board);
    }
    catch (int error)
    {
        return false;
    }

    if(__board[__cord.from[0]][__cord.from[1]]->colour == __board[__cord.to[0]][__cord.to[1]]->colour && __board[__cord.to[0]][__cord.to[1]] != emptyptr)
    {
        return false;
    }

    return true;
}


void movePiece(std::array<std::array<piece*,8>,8> &_board)
{
    movement cord;
    getCord(cord);
    bool possible = false;
    possible = verifyMovement(cord, _board);

    while (possible == false)
    {
        drawBoard(_board);
        printw("Invalid movement!\n");
        getCord(cord);
        possible = verifyMovement(cord, _board);
    }
    _board[cord.to[0]][cord.to[1]]=_board[cord.from[0]][cord.from[1]];
    _board[cord.from[0]][cord.from[1]]=emptyptr;
    
    possible=false;
}