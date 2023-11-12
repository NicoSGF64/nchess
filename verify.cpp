#include "verify.hpp"
#include <exception>
#include <stdexcept>

bool verifyMovement(movement &__cord, std::array<std::array<piece*,8>,8> __board)
{
    //auto foo = __board.at(__cord.to.at(0)-2).at(__cord.to.at(1));

    switch(__cord.type)
    {
        
        case PAWN_ID:
            if(__cord.isCapture==true)
            {
                //Capture logic. Unimplemented
                return false;
            }
            else if (__board.at(__cord.to.at(0)-2).at(__cord.to.at(1)) == pawnptr && __cord.to.at(0)-2 == 1) 
            {
                __cord.from.at(0)=__cord.to.at(0)-2;
                __cord.from.at(1)=__cord.to.at(1);

            }
            else if (__board.at(__cord.to.at(0)-1).at(__cord.to.at(1)) == pawnptr) 
            {
                __cord.from.at(0)=__cord.to.at(0)-1;
                __cord.from.at(1)=__cord.to.at(1);
            }
            break;
            
        case KNIGHT_ID:
        // I don't have a better idea
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
                    return false;
                    break;
            }
            try 
            {
                if(__cord.to.at(0)+a >= 0  && __cord.to.at(0)+a <= 7 && __cord.to.at(1)+b >= 0  && __cord.to.at(1)+b <= 7 && __board.at(__cord.to.at(0)+a).at(__cord.to.at(1)+b) == knightptr)
                {
                __cord.from.at(0)=__cord.to.at(0)+a;
                __cord.from.at(1)=__cord.to.at(1)+b;
                break;
                }
            } 
            catch (std::exception) 
            {
              //Do nothing because we already "handle" it
            }
            
        }
        break;

        case BISHOP_ID:
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
                        int y=__cord.to.at(0)+i*refSwapper(true);
                        int x=__cord.to.at(1)+i*refSwapper(false);

                        
                        
                            if(__board.at(y).at(x) == bishopptr) // && __board.at(i).at(j)->colour==="the same colour than the current player"
                            {
                                __cord.from.at(0)=y;
                                __cord.from.at(1)=x;
                                return true;
                            }
                            else if (__board.at(y).at(x) != emptyptr) 
                            {
                                break;
                            }
                    } 
                }
                //This probably bad design
                catch (std::exception& ex) 
                {
                    //Do nothing because errors are already "handled" by just quitting
                } 
                        
            }

        break;

        case ROOK_ID:
            for (int ref=0; ref<=1; ref++)
            {
                for(int x=__cord.to.at(1); x<=7; x+=(ref == 0 ? 1 : -1))
                {
                    if (x<0) 
                    {
                        break;
                    }
                    if(__board.at(__cord.to.at(0)).at(x) == rookptr) // && __board.at(i).at(j)->colour==="the same colour than the current player"
                    {
                        __cord.from.at(0)=__cord.to.at(0);
                        __cord.from.at(1)=x;
                        return true;
                    }
                    else if (__board.at(__cord.to.at(0)).at(x) != emptyptr) 
                    {
                        break;
                    }
                }

                for(int y=__cord.to.at(0); y<=7; y+=(ref == 0 ? 1 : -1))
                {
                    if (y<0) 
                    {
                        break;
                    }
                    if(__board.at(y).at(__cord.to.at(1)) == rookptr) // && __board.at(i).at(j)->colour==="the same colour than the current player"
                    {
                        __cord.from.at(0)=y;
                        __cord.from.at(1)=__cord.to.at(1);
                        return true;
                    }
                    else if (__board.at(y).at(__cord.to.at(1)) != emptyptr) 
                    {
                        break;
                    }
                }
                        
            }
            break;


        default:
            throw std::runtime_error("Invalid movement");
        break;
    }

    //Check whether the the destination is empty, the same colour or if it has a different colour (and if it is a capture)
    if(__board.at(__cord.from.at(0)).at(__cord.from.at(1))->colour == __board.at(__cord.to.at(0)).at(__cord.to.at(1))->colour && __board.at(__cord.to.at(0)).at(__cord.to.at(1)) != emptyptr)
    {
        return false;
    }

    return true;
}