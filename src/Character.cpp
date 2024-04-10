#include "Character.hpp"

#include "NumericCharacter.hpp"
#include "OperatorCharacter.hpp"
#include "EqualityCharacter.hpp"

#include <ctype.h>

Character* Character::fromChar(char c)
{
    if (isdigit(c)) {
        return new NumericCharacter(c - '0');
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/') {
        return new OperatorCharacter(c);
    }
    else if (c == '=') {
        return new EqualityCharacter();
    }
    return nullptr;
}

/**
 * Returns a string representation of the character in a layout like this:
 * |‾‾‾|
 * |\|/|
 * |---|
 * |/|\|
 * |___|
 */
std::array<std::string, LINE_HEIGHT> Character::toString() const {
    std::array<std::string, LINE_HEIGHT> result;
    for (int i = 0; i < LINE_HEIGHT; ++i) {
        result[i].assign(5, ' ');
    }

    if (layout[8]) {
        result[1][1] = result[2][2] = result[3][3] = '\\';
    }
    if (layout[10]) {
        result[1][3] = result[2][2] = result[3][1] = '/';
    }
    if (layout[9]) {
        result[1][2] = result[2][2] = result[3][2] = '|';
    }
    if (layout[7]) {
        result[3][1] = result[3][2] = result[3][3] = '-';
    }

    if (layout[0]) {
        result[0][1] = result[0][2] = result[0][3] = '-';
    }
    if (layout[1]) {
        result[0][0] = result[1][0] = result[2][0] = '|';
    }
    if (layout[2]) {
        result[0][4] = result[1][4] = result[2][4] = '|';
    }
    if (layout[3]) {
        result[2][1] = result[2][2] = result[2][3] = '-';
    }
    if (layout[4]) {
        result[2][0] = result[3][0] = result[4][0] = '|';
    }
    if (layout[5]) {
        result[2][4] = result[3][4] = result[4][4] = '|';
    }
    if (layout[6]) {
        result[4][1] = result[4][2] = result[4][3] = '_';
    }

    return result;
}
