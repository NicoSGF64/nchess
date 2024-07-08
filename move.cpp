#include "bscurses.hpp"
#include "move.hpp"
#include "verify.hpp"
#include "piece.hpp"

void parseCord(movement &_cord, std::array<std::array<piece*,8>,8> &__board)
{
    try 
    {
        constexpr std::string_view letters = "abcdefgh";
        constexpr std::string_view pieces = "NBRQK";

        for (auto i=0; i<=pieces.size(); i++) //Check which piece is being moved
        {
            if (i>=pieces.size()) 
            {
                _cord.type = PAWN_ID;
                break; //Just in case
            }
            else if(_cord.notation.at(0)==pieces.at(i))
            {
                _cord.type = i+2;
                break;
            }

        }

        bool isNotPawn;

        if(_cord.type!=1) //Check if it's a pawn
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
                _cord.to.at(1)=i;
                break;
            }

        }

        _cord.to.at(0) = static_cast<int>(_cord.notation.at(1+isNotPawn+_cord.isCapture))-49;
    } 
    catch (...) 
    {
        drawBoard(__board);
        printw("Invalid notation!\n");
        getCord(_cord, __board);
        verifyMovement(_cord, __board);
    }
}

void getCord(movement &_cord, BOARD &__board)
{
    echo();
    if (_cord.turn == white) 
    {
        printw("\nWhite's turn!\n");
    }
    else 
    {
        printw("\nBlack's turn!\n");
    }
    

    printw("Your move: ");
    refresh();
    getnstr(_cord.notation.data(), 4);

    parseCord(_cord, __board);
}


void movePiece(movement &_cord, BOARD &_board)
{
    
    getCord(_cord, _board);
    
    verifyMovement(_cord, _board);

    //Move the piece
    _board.at(_cord.to.at(0)).at(_cord.to.at(1)) = _board.at(_cord.from.at(0)).at(_cord.from.at(1));
    //Place an empty space at the origin
    _board.at(_cord.from.at(0)).at(_cord.from.at(1)) = emptyptr;
    //Change turns
    if (_cord.turn == white)
    {
        _cord.turn = black;
    }
    else 
    {
        _cord.turn = white;
    }
}