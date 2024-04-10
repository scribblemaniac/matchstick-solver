#ifndef OPERATOR_CHARACTER_HPP
#define OPERATOR_CHARACTER_HPP

#include "Character.hpp"
#include "Operator.hpp"

#include <bitset>
#include <vector>
#include <unordered_map>

class OperatorCharacter : public Character {
    public:
        explicit OperatorCharacter(const char c) : OperatorCharacter(charToOperator(c)) {}
        explicit OperatorCharacter(const Operator op, const int variant = 0) : Character(LayoutMapping.at(op)[variant]), op(op) {}

        virtual const CharacterType getType() { return CharacterType::OPERATOR; }
        virtual const char toChar() override;

        virtual Operator getOperator() { return this->op; }

    private:
        Operator op;

        static const std::unordered_map<Operator,std::vector<std::bitset<MATCHSTICK_LAYOUT_SIZE>>> LayoutMapping;
};

#endif // OPERATOR_CHARACTER_HPP
