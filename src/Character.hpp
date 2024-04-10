#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ConsoleOutput.hpp"

#include <array>
#include <bitset>

#define MATCHSTICK_LAYOUT_SIZE 11

enum class CharacterType {
    NUMERIC,
    OPERATOR,
    EQUALITY
};

class Character {
public:
    explicit Character(const std::bitset<MATCHSTICK_LAYOUT_SIZE> layout) : layout(layout) {}
    virtual ~Character() {}

    virtual const CharacterType getType() = 0;
    virtual const char toChar() = 0;

    std::array<std::string, LINE_HEIGHT> toString() const;

    static Character* fromChar(const char c);
protected:
    std::bitset<MATCHSTICK_LAYOUT_SIZE> layout;
};

#endif // CHARACTER_HPP
