#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <stdexcept>

enum Operator {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

static Operator charToOperator(const char c) {
    switch (c) {
        case '+':
            return ADDITION;
        case '-':
            return SUBTRACTION;
        case '*':
            return MULTIPLICATION;
        case '/':
            return DIVISION;
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

#endif // OPERATOR_HPP
