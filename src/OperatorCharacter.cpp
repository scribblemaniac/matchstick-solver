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

const std::unordered_map<Operator,std::vector<std::bitset<MATCHSTICK_LAYOUT_SIZE>>> OperatorCharacter::LayoutMapping = {
    { ADDITION, { std::bitset<MATCHSTICK_LAYOUT_SIZE>("01000001000") } },
    { SUBTRACTION, { std::bitset<MATCHSTICK_LAYOUT_SIZE>("00000001000") } },
    { MULTIPLICATION, {
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("11100001000"),
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("10100001000")
    } },
    { DIVISION, { std::bitset<MATCHSTICK_LAYOUT_SIZE>("10000000000") } }
};
