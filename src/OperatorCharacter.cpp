#include "OperatorCharacter.hpp"

const char OperatorCharacter::toChar() {
    switch (this->op) {
        case ADDITION:
            return '+';
        case SUBTRACTION:
            return '-';
        case MULTIPLICATION:
            return '*';
        case DIVISION:
            return '/';
        default:
            throw "Invalid operator";
    }
}
