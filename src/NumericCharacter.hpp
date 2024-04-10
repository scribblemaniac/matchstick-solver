#ifndef NUMERIC_CHARACTER_HPP
#define NUMERIC_CHARACTER_HPP

#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#include "Character.hpp"

struct NumericCharacterTransform {
    int additions;
    int removals;

    bool changes[7];
};

// types of moves that can be made to the matchsticks (should be shared with operators)
enum MoveType {
    inCharacterMove,
    addition,
    removal
};

struct NumericCharacterModification {
    // the type of move made to change into the character
    MoveType moveType;
    char character;
};

class NumericCharacter : public Character {
    public:
        NumericCharacter(const short value, const int variant = 0) : Character(LayoutMapping.at(value)[variant]), value(value) {};

        // Given a numericCharacter give the number of additions and removals required to transform this into the given character
        //NumericCharacterTransform movesRequired(NumericCharacter& character);

        const CharacterType getType() override { return CharacterType::NUMERIC; }
        const char toChar() override { return std::to_string(value).back(); }

        const short getValue() { return value; }

        static NumericCharacter initFromCharacter(char c);
    private:
        short value;

        static const std::unordered_map<short,std::vector<std::bitset<MATCHSTICK_LAYOUT_SIZE>>> LayoutMapping;
};

#endif /* NUMERIC_CHARACTER_HPP */
