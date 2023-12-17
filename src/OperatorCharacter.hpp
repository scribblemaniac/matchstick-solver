#ifndef OPERATOR_CHARACTER_HPP
#define OPERATOR_CHARACTER_HPP

#include "Character.hpp"
#include "Operator.hpp"

class OperatorCharacter : public Character {
    public:
        explicit OperatorCharacter(const char c) : OperatorCharacter(charToOperator(c)) {}
        explicit OperatorCharacter(Operator op) : op(op) {}

        virtual const CharacterType getType() { return CharacterType::OPERATOR; }
        virtual const char toChar() override;

        virtual Operator getOperator() { return this->op; }

    private:
        Operator op;
};

#endif // OPERATOR_CHARACTER_HPP
