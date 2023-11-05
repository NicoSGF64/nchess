#include "verify.hpp"
#include <exception>
#include <stdexcept>

bool verifyMovement(movement &__cord, std::array<std::array<piece*,8>,8> __board)
{
    

    switch(__cord.type)
    {
        case PAWN_ID:
            if(__cord.isCapture==true)
            {
                //Capture logic. Unimplemented
                return false;
            }
            else if (__board.at(__cord.to.at(0)-2).at(__cord.to.at(1)) == pawnptr && __cord.to.at(0)-2 == 1 && __cord.to.at(1)) 
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
                auto refSwapper = [](int& _ref, bool isY)
                {
                    switch(_ref)
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
                            throw std::runtime_error("Lambda refSwapper couldn't find a value");
                        
                    }
                };
                
                try 
                {
                    for(int i=0; i<=8; i++)
                    {
                        int y,x;//=0; // For some reason they don't go out of scope
                        y=__cord.to.at(0)+i*refSwapper(ref, true);
                        x=__cord.to.at(1)+i*refSwapper(ref, false);

                        
                        
                            if(__board.at(y).at(x) == bishopptr) // && __board.at(i).at(j)->colour=="the same colour than the current player"
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

            //I could use a fancy reference counter with a lambda function and whatnot but copy-pasting is more readable and easier to debug
            /*
            for(int i=__cord.to.at(0); i<=__board.size(); i++)
            {
                for(int j=__cord.to.at(1); j<=__board.size(); j++)
                {
                    //Probably better to not do anything if it's empty than to check if the board isn't emptyptr AND 
                    if(__board.at(i).at(j) == bishopptr) // && __board.at(i).at(j)->colour=="the same colour than the current player"
                    {
                        return true;
                    }
                    else if (__board.at(i).at(j) != emptyptr) 
                    {
                        return false;
                    }
                }
            }
            
            for(int i=__cord.to.at(0); i<=__board.size(); i--)
            {
                for(int j=__cord.to.at(1); j<=__board.size(); j--)
                {
                    if(__board.at(i).at(j) == bishopptr)
                    {
                        return true;
                    }
                    else if (__board.at(i).at(j) != emptyptr) 
                    {
                        return false;
                    }
                }
            }

            for(int i=__cord.to.at(0); i<=__board.size(); i++)
            {
                for(int j=__cord.to.at(1); j<=__board.size(); j--)
                {
                    if(__board.at(i).at(j) == bishopptr)
                    {
                        return true;
                    }
                    else if (__board.at(i).at(j) != emptyptr) 
                    {
                        return false;
                    }
                }
            }

            for(int i=__cord.to.at(0); i<=__board.size(); i--)
            {
                for(int j=__cord.to.at(1); j<=__board.size(); j--)
                {
                    if(__board.at(i).at(j) == bishopptr)
                    {
                        return true;
                    }
                    else if (__board.at(i).at(j) != emptyptr) 
                    {
                        return false;
                    }
                }
            }
            */
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