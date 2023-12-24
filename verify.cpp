#include "verify.hpp"

bool verifyPawn(movement &___cord, BOARD &___board)
{
    if(___cord.isCapture==true)
    {
        //Capture logic. Unimplemented for now
        throw -1;
    }
    else if (___board.at(___cord.to.at(0)-2).at(___cord.to.at(1)) == pawnptr && ___cord.to.at(0)-2 == 1) 
    {
        ___cord.from.at(0)=___cord.to.at(0)-2;
        ___cord.from.at(1)=___cord.to.at(1);
        return true;

    }
    else if (___board.at(___cord.to.at(0)-1).at(___cord.to.at(1)) == pawnptr) 
    {
        ___cord.from.at(0)=___cord.to.at(0)-1;
        ___cord.from.at(1)=___cord.to.at(1);
        return true;
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
            if(___board.at(___cord.to.at(0)+y).at(___cord.to.at(1)+x) == knightptr)
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

                
                
                    if(___board.at(y).at(x) == bishopptr) // && __board.at(i).at(j)->colour==="the same colour than the current player"
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
    for (int ref=0; ref<=1; ref++)
    {
        for(int x=___cord.to.at(1); x<=7; x+=(ref == 0 ? 1 : -1))
        {
            if (x<0) 
            {
                break;
            }
            if(___board.at(___cord.to.at(0)).at(x) == rookptr) // && __board.at(i).at(j)->colour==="the same colour than the current player"
            {
                ___cord.from.at(0)=___cord.to.at(0);
                ___cord.from.at(1)=x;
                return true;
            }
            else if (___board.at(___cord.to.at(0)).at(x) != emptyptr) 
            {
                break;
            }
        }

        for(int y=___cord.to.at(0); y<=7; y+=(ref == 0 ? 1 : -1))
        {
            if (y<0) 
            {
                break;
            }
            if(___board.at(y).at(___cord.to.at(1)) == rookptr) // && __board.at(i).at(j)->colour==="the same colour than the current player"
            {
                ___cord.from.at(0)=y;
                ___cord.from.at(1)=___cord.to.at(1);
                return true;
            }
            else if (___board.at(y).at(___cord.to.at(1)) != emptyptr) 
            {
                break;
            }
        }
                
    }

    
    
    return false;
}

bool verifyQueen(movement &___cord, BOARD &___board)
{
    //It's a big copy-paste. Deal with it

    //Rook part
    for (int ref=0; ref<=1; ref++)
    {
        for(int x=___cord.to.at(1); x<=7; x+=(ref == 0 ? 1 : -1))
        {
            if (x<0) 
            {
                break;
            }
            if(___board.at(___cord.to.at(0)).at(x) == queenptr) // && __board.at(i).at(j)->colour==="the same colour than the current player"
            {
                ___cord.from.at(0)=___cord.to.at(0);
                ___cord.from.at(1)=x;
                return true;
            }
            else if (___board.at(___cord.to.at(0)).at(x) != emptyptr) 
            {
                break;
            }
        }

        for(int y=___cord.to.at(0); y<=7; y+=(ref == 0 ? 1 : -1))
        {
            if (y<0) 
            {
                break;
            }
            if(___board.at(y).at(___cord.to.at(1)) == queenptr) // && __board.at(i).at(j)->colour==="the same colour than the current player"
            {
                ___cord.from.at(0)=y;
                ___cord.from.at(1)=___cord.to.at(1);
                return true;
            }
            else if (___board.at(y).at(___cord.to.at(1)) != emptyptr) 
            {
                break;
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

                
                
                    if(___board.at(y).at(x) == queenptr) // && __board.at(i).at(j)->colour==="the same colour than the current player"
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
        if(__board.at(__cord.from.at(0)).at(__cord.from.at(1))->colour == __board.at(__cord.to.at(0)).at(__cord.to.at(1))->colour && __board.at(__cord.to.at(0)).at(__cord.to.at(1)) != emptyptr)
        {
            valid = false;
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