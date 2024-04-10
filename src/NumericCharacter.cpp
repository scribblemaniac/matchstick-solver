#include "NumericCharacter.hpp"

const std::unordered_map<short,std::vector<std::bitset<MATCHSTICK_LAYOUT_SIZE>>> NumericCharacter::LayoutMapping = {
    { 0, { std::bitset<MATCHSTICK_LAYOUT_SIZE>("00001110111") } },
    { 1, {
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("00000100100"),
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("00000010010")
    } },
    { 2, { std::bitset<MATCHSTICK_LAYOUT_SIZE>("00001011101") } },
    { 3, { std::bitset<MATCHSTICK_LAYOUT_SIZE>("00001101101") } },
    { 4, { std::bitset<MATCHSTICK_LAYOUT_SIZE>("00000101110") } },
    { 5, { std::bitset<MATCHSTICK_LAYOUT_SIZE>("00001101011") } },
    { 6, {
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("00001111011"),
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("00001111010")
    } },
    { 7, {
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("00000100101"),
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("00000100111")
    } },
    { 8, { std::bitset<MATCHSTICK_LAYOUT_SIZE>("00001111111") } },
    { 9, {
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("00001101111"),
        std::bitset<MATCHSTICK_LAYOUT_SIZE>("00000101111")
    } }
};

/*NumericCharacterTransform NumericCharacter::movesRequired(NumericCharacter& character) {
    NumericCharacterTransform movesRequired;
    movesRequired.additions = 0;
    movesRequired.removals = 0;

    for (int i = 0; i < 7; ++i) {
        movesRequired.changes[i] = matchstickRepresentation[i] != character.matchstickRepresentation[i];
        // if the thing that we want to transform into has a matchstick that we do not have
        if (!matchstickRepresentation[i] && character.matchstickRepresentation[i])
            movesRequired.additions++;
        // if the thing that we want to transform does not have a matchstick that we have
        else if (matchstickRepresentation[i] && !character.matchstickRepresentation[i])
            movesRequired.removals++;
    }

    return movesRequired;
}*/
