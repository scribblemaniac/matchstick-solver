#include "Character.hpp"

#include "NumericCharacter.hpp"
#include "OperatorCharacter.hpp"
#include "EqualityCharacter.hpp"

#include <ctype.h>

Character* Character::fromChar(char c)
{
    if (isdigit(c)) {
        return new NumericCharacter(NumericCharacter::initFromCharacter(c));
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/') {
        return new OperatorCharacter(c);
    }
    else if (c == '=') {
        return new EqualityCharacter();
    }
    return nullptr;
}
