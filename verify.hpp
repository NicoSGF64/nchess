#ifndef VERIFY_HPP
#define VERIFY_HPP
#include <stdexcept>
#include "move.hpp"
#include "board.hpp"

extern void verifyMovement(movement &__cord, std::array<std::array<piece*,8>,8> &__board);
#endif