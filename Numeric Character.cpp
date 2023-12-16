//
//

#include "Numeric Character.hpp"

MatchstickTransform NumericCharacter::movesRequired(NumericCharacter& character) {
    MatchstickTransform movesRequired;
    movesRequired.additions = 0;
    movesRequired.removals = 0;

    for (int i = 0; i < 7; ++i) {
        movesRequired.changes[i] = matchstickRepresentation[i] != character.matchstickRepresentation[i];
        if (matchstickRepresentation[i] && !character.matchstickRepresentation[i])
            movesRequired.additions++;
        else if (matchstickRepresentation[i] && !character.matchstickRepresentation[i])
            movesRequired.removals++;
    }

    return movesRequired;
}
