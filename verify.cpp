#include <stdexcept>
#include "verify.hpp"
#include "bscurses.hpp"
#include "move.hpp"
#include "piece.hpp"

bool verifyPawn(movement &___cord, BOARD &___board)
{
    //Could I use a fancy lambda for clean, elegant code? Sure
    //But this is I'd wager more readable and around as performant
    if (___cord.turn == white) 
    {
        if(___cord.isCapture==true)
        {
            //Capture logic. Unimplemented for now
            throw -1;
        }
        else if (___board.at(___cord.to.at(0)-2).at(___cord.to.at(1)) == whitepawnptr && ___cord.to.at(0)-2 == 1) 
        {
            ___cord.from.at(0)=___cord.to.at(0)-2;
            ___cord.from.at(1)=___cord.to.at(1);
            return true;

        }
        else if (___board.at(___cord.to.at(0)-1).at(___cord.to.at(1)) == whitepawnptr) 
        {
            ___cord.from.at(0)=___cord.to.at(0)-1;
            ___cord.from.at(1)=___cord.to.at(1);
            return true;
        }
    }
    else 
    {
        if(___cord.isCapture==true)
        {
            //Capture logic. Unimplemented for now
            throw -1;
        }
        else if (___board.at(___cord.to.at(0)+2).at(___cord.to.at(1)) == blackpawnptr && ___cord.to.at(0)+2 == 6) 
        {
            ___cord.from.at(0)=___cord.to.at(0)+2;
            ___cord.from.at(1)=___cord.to.at(1);
            return true;

        }
        else if (___board.at(___cord.to.at(0)+1).at(___cord.to.at(1)) == blackpawnptr) 
        {
            ___cord.from.at(0)=___cord.to.at(0)+1;
            ___cord.from.at(1)=___cord.to.at(1);
            return true;
        }
    }
    
    return false;            
}

bool verifyKnight(movement &___cord, BOARD &___board)
{
    // I don't have a better idea
    for(auto ref=0; ref<=8; ref++)
    {
        short y,x;
        //Switch case for switching the y and x values based on ref
        switch (ref) 
        {
            case 0:
                y=1;
                x=2;
                break;
            case 1:
                y=-1;
                x=-2;
            break;
            case 2:
                y=2;
                x=1;
                break;
            case 3:
                y=-2;
                x=-1;
                break;
            case 4:
                y=1;
                x=-2;
                break;
            case 5:
                y=-1;
                x=2;
                break;
            case 6:
                y=2;
                x=-1;
                break;
            case 7:
                y=-2;
                x=1;
                break;
            default:
                throw -1;
                break;
        }
        try 
        {
            if((___board.at(___cord.to.at(0)+y).at(___cord.to.at(1)+x) == whiteknightptr && ___cord.turn==white) || 
            (___board.at(___cord.to.at(0)+y).at(___cord.to.at(1)+x) == blackknightptr && ___cord.turn==black))
            {
            ___cord.from.at(0)=___cord.to.at(0)+y;
            ___cord.from.at(1)=___cord.to.at(1)+x;
            return true;
            }
        } 
        catch (...) 
        {
        //Do nothing because we already "handle" it by increasing ref
        }
        
    }
    return false;
}

bool verifyBishop(movement &___cord, BOARD &___board)
{
    for (int ref=0; ref<=3; ref++)
    {
        //Lambda funtion for switching states (going foward or backwards) based on the iteration and if it is the first or second for loop
        auto refSwapper = [ref](bool isY)
        {
            switch(ref)
            {
                case 0:
                    return 1;
                break;

                case 1:
                    return -1;
                break;

                case 2:
                    return isY == true ? 1 : -1;
                break;

                case 3:
                    return isY == true ? -1 : 1;
                break;
                
                default:
                    throw std::runtime_error("Lambda refSwapper couldn't find a value. Go complain in the Git repo.");
                
            }
        };
        
        try 
        {
            for(int i=0; i<=8; i++)
            {
                int y=___cord.to.at(0)+i*refSwapper(true);
                int x=___cord.to.at(1)+i*refSwapper(false);

                    if((___board.at(y).at(x) == whitebishopptr && ___cord.turn == white) ||
                    (___board.at(y).at(x) == blackbishopptr && ___cord.turn == black))
                    {
                        ___cord.from.at(0)=y;
                        ___cord.from.at(1)=x;
                        return true;
                    }
                    else if (___board.at(y).at(x) != emptyptr) 
                    {
                        break;
                    }
            } 
        }
        //This probably bad design
        catch (...) 
        {
            //Do nothing because errors are already "handled" by just quitting
        } 
                
    }

    return false;
}

bool verifyRook(movement &___cord, BOARD &___board)
{
    //Reference counter for swapping checking up or down
    //Might want to unroll into four for loops instead of using ref
    for (int ref=0; ref<=1; ref++)
    {
        for(int x=___cord.to.at(1); x<=7; x+=(ref == 0 ? 1 : -1))
        {
            if (x<0) 
            {
                break;
            }
            //x+___cord.to.at(1) could be interesting instead of just x to adjust the reverse-search to start where the player wants to move
            //instead of starting aimlessly and hoping that we find where it is located, maybe helping with the checks in the elseif
            if((___board.at(___cord.to.at(0)).at(x) == whiterookptr && ___cord.turn==white) ||
            (___board.at(___cord.to.at(0)).at(x) == blackrookptr && ___cord.turn==black))
            {
                ___cord.from.at(0)=___cord.to.at(0);
                ___cord.from.at(1)=x;
                return true;
            }
            else if (___board.at(___cord.to.at(0)).at(x) != emptyptr) 
            {
                if (___board.at(___cord.to.at(0)).at(x)->colour == ___cord.turn) 
                {
                    break;
                }
                //Check if it's a capture and, if so, if it's a different colour, then reverse it since we want to check the opposite
                else if (!(___cord.isCapture == true && ___board.at(___cord.to.at(0)).at(x)->colour != ___cord.turn))
                {
                    break;
                }
            }
        }

        for(int y=___cord.to.at(0); y<=7; y+=(ref == 0 ? 1 : -1))
        {
            if (y<0) 
            {
                break;
            }
            //Same comment as the x for loop
            if((___board.at(y).at(___cord.to.at(1)) == whiterookptr && ___cord.turn==white) ||
            (___board.at(y).at(___cord.to.at(1)) == blackrookptr && ___cord.turn==black))
            {
                ___cord.from.at(0)=y;
                ___cord.from.at(1)=___cord.to.at(1);
                return true;
            }
            else if (___board.at(y).at(___cord.to.at(1)) != emptyptr) 
            {
                if (___board.at(y).at(___cord.to.at(1))->colour == ___cord.turn) 
                {
                    break;
                }
                //Check if it's a capture and, if so, if it's a different colour, then reverse it since we want to check the opposite
                else if (!(___cord.isCapture == true && ___board.at(y).at(___cord.to.at(1))->colour != ___cord.turn))
                {
                    break;
                }
            }
        }
                
    }

    return false;
}

bool verifyQueen(movement &___cord, BOARD &___board)
{
    //It's a big copy-paste

    //Rook part
    for (int ref=0; ref<=1; ref++)
    {
        for(int x=___cord.to.at(1); x<=7; x+=(ref == 0 ? 1 : -1))
        {
            if (x<0) 
            {
                break;
            }
            //x+___cord.to.at(1) could be interesting instead of just x to adjust the reverse-search to start where the player wants to move
            //instead of starting aimlessly and hoping that we find where it is located, maybe helping with the checks in the elseif
            if((___board.at(___cord.to.at(0)).at(x) == whitequeenptr && ___cord.turn==white) ||
            (___board.at(___cord.to.at(0)).at(x) == blackqueenptr && ___cord.turn==black))
            {
                ___cord.from.at(0)=___cord.to.at(0);
                ___cord.from.at(1)=x;
                return true;
            }
            else if (___board.at(___cord.to.at(0)).at(x) != emptyptr) 
            {
                if (___board.at(___cord.to.at(0)).at(x)->colour == ___cord.turn) 
                {
                    break;
                }
                //Check if it's a capture and, if so, if it's a different colour, then reverse it since we want to check the opposite
                else if (!(___cord.isCapture == true && ___board.at(___cord.to.at(0)).at(x)->colour != ___cord.turn))
                {
                    break;
                }
            }
        }

        for(int y=___cord.to.at(0); y<=7; y+=(ref == 0 ? 1 : -1))
        {
            if (y<0) 
            {
                break;
            }
            //Same comment as the x for loop
            if((___board.at(y).at(___cord.to.at(1)) == whitequeenptr && ___cord.turn==white) ||
            (___board.at(y).at(___cord.to.at(1)) == blackqueenptr && ___cord.turn==black))
            {
                ___cord.from.at(0)=y;
                ___cord.from.at(1)=___cord.to.at(1);
                return true;
            }
            else if (___board.at(y).at(___cord.to.at(1)) != emptyptr) 
            {
                if (___board.at(y).at(___cord.to.at(1))->colour == ___cord.turn) 
                {
                    break;
                }
                //Check if it's a capture and, if so, if it's a different colour, then reverse it since we want to check the opposite
                else if (!(___cord.isCapture == true && ___board.at(y).at(___cord.to.at(1))->colour != ___cord.turn))
                {
                    break;
                }
            }
        }
                
    }

    //Bishop part

    for (int ref=0; ref<=3; ref++)
    {
        //See verifyBishop for more info
        auto refSwapper = [ref](bool isY)
        {
            switch(ref)
            {
                case 0:
                    return 1;
                break;

                case 1:
                    return -1;
                break;

                case 2:
                    return isY == true ? 1 : -1;
                break;

                case 3:
                    return isY == true ? -1 : 1;
                break;
                
                default:
                    throw std::runtime_error("Lambda refSwapper couldn't find a value. Go complain in the Git repo.");
                
            }
        };
        
        try 
        {
            for(int i=0; i<=8; i++)
            {
                int y=___cord.to.at(0)+i*refSwapper(true);
                int x=___cord.to.at(1)+i*refSwapper(false);

                
                
                    if((___board.at(y).at(x) == whitequeenptr && ___cord.turn == white) ||
                     (___board.at(y).at(x) == blackqueenptr && ___cord.turn == black))
                    {
                        ___cord.from.at(0)=y;
                        ___cord.from.at(1)=x;
                        return true;
                    }
                    else if (___board.at(y).at(x) != emptyptr) 
                    {
                        break;
                    }
            } 
        }
        //This probably bad design
        catch (...) 
        {
            //Do nothing because errors are already "handled" by just quitting
        } 
                
    }

    return false;
}

void verifyMovement(movement &__cord, BOARD &__board)
{
    try 
    {
        bool valid=false;

        switch(__cord.type)
        {
            
            
            case PAWN_ID:
                valid = verifyPawn(__cord, __board);
            break;
                
                
            case KNIGHT_ID:
                valid = verifyKnight(__cord, __board);
            break;

            case BISHOP_ID:
                valid = verifyBishop(__cord, __board);
            break;

            case ROOK_ID:
                valid = verifyRook(__cord, __board);
            break;

            case QUEEN_ID:
                
                valid = verifyQueen(__cord, __board);
            break;

            default:
                throw std::runtime_error("Invalid movement");
            break;
        }

        //Check whether the the destination is empty, the same colour or if it has a different colour (and if it is a capture)
        if (__board.at(__cord.to.at(0)).at(__cord.to.at(1)) != emptyptr) 
        {
            if(__board.at(__cord.from.at(0)).at(__cord.from.at(1))->colour == __board.at(__cord.to.at(0)).at(__cord.to.at(1))->colour) 
            {
                valid = false;
            }
            else if (__cord.isCapture == false) 
            {
                valid = false;
            }
        }

        if (valid == false)
        {
            drawBoard(__board);
            printw("Invalid movement!\n");
            getCord(__cord, __board);
            verifyMovement(__cord, __board);
        }

        return;
    } 
    catch (...) 
    {
        drawBoard(__board);
        printw("Invalid movement!\n");
        getCord(__cord, __board);
        verifyMovement(__cord, __board);
    }
}