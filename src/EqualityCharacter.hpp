#ifndef EQUALITY_CHARACTER_HPP
#define EQUALITY_CHARACTER_HPP

#include "Character.hpp"
#include "Operator.hpp"

class EqualityCharacter : public Character {
    public:
        explicit EqualityCharacter() : Character(std::bitset<MATCHSTICK_LAYOUT_SIZE>("00010001000")) {}

        virtual const CharacterType getType() { return CharacterType::EQUALITY; }
        virtual const char toChar() override { return '='; }
};

#endif // EQUALITY_CHARACTER_HPP
