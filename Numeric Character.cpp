//
//

#include "Numeric Character.hpp"

NumericCharacter::NumericCharacter(string s, int value, bool representation[7]) {
  stringValue = s;
  numericValue = value;

  for (int i = 0; i < 7; ++i) {
    matchstickRepresentation[i] = representation[i];
  }
}

NumericCharacterTransform NumericCharacter::movesRequired(NumericCharacter& character) {
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
}


NumericCharacter NumericCharacter::initFromCharacter(char c) {
  switch (c) {
    case '0':
      return NumericCharacter::zero();

    case '1':
      return NumericCharacter::one();

    case '2':
      return NumericCharacter::two();

    case '3':
      return NumericCharacter::three();

    case '4':
      return NumericCharacter::four();

    case '5':
      return NumericCharacter::five();

    case '6':
      return NumericCharacter::six();

    case '7':
      return NumericCharacter::seven();

    case '8':
      return NumericCharacter::eight();

    case '9':
      return NumericCharacter::nine();

    default:
    cout << "Error, could not create a valid numeric character for " << c << endl;
    break;
  }

  bool representation[7];
  representation[0] = false;
  representation[1] = false;
  representation[2] = false;
  representation[3] = false;
  representation[4] = false;
  representation[5] = false;
  representation[6] = false;

  return NumericCharacter("", -1, representation);
}

NumericCharacter NumericCharacter::zero() {
  bool representation[7];
  representation[0] = true;
  representation[1] = true;
  representation[2] = true;
  representation[3] = true;
  representation[4] = true;
  representation[5] = true;
  representation[6] = false;

  NumericCharacter zero = NumericCharacter("0", 0, representation);

  NumericCharacterModification eight;
  eight.moveType = addition;
  eight.character = '8';
  zero.validOneStepMoves.push_back(eight);

  NumericCharacterModification six;
  six.moveType = inCharacterMove;
  six.character = '6';
  zero.validOneStepMoves.push_back(six);

  return zero;
}

NumericCharacter NumericCharacter::one() {
  bool representation[7];
  representation[0] = false;
  representation[1] = false;
  representation[2] = false;
  representation[3] = true;
  representation[4] = true;
  representation[5] = false;
  representation[6] = false;

  NumericCharacter one = NumericCharacter("1", 1, representation);

  NumericCharacterModification seven;
  seven.moveType = addition;
  seven.character = '7';
  one.validOneStepMoves.push_back(seven);

  return one;
}

NumericCharacter NumericCharacter::two() {
  bool representation[7];
  representation[0] = true;
  representation[1] = false;
  representation[2] = true;
  representation[3] = true;
  representation[4] = false;
  representation[5] = true;
  representation[6] = true;

  NumericCharacter two = NumericCharacter("2", 2, representation);

  NumericCharacterModification three;
  three.moveType = inCharacterMove;
  three.character = '3';
  two.validOneStepMoves.push_back(three);

  return two;
}

NumericCharacter NumericCharacter::three() {
  bool representation[7];
  representation[0] = false;
  representation[1] = false;
  representation[2] = true;
  representation[3] = true;
  representation[4] = true;
  representation[5] = true;
  representation[6] = true;

  NumericCharacter three = NumericCharacter("3", 3, representation);

  NumericCharacterModification two;
  two.moveType = inCharacterMove;
  two.character = '2';
  three.validOneStepMoves.push_back(two);

  NumericCharacterModification five;
  five.moveType = inCharacterMove;
  five.character = '5';
  three.validOneStepMoves.push_back(five);

  NumericCharacterModification nine;
  nine.moveType = inCharacterMove;
  nine.character = '9';
  three.validOneStepMoves.push_back(nine);

  return three;
}

NumericCharacter NumericCharacter::four() {
  bool representation[7];
  representation[0] = false;
  representation[1] = true;
  representation[2] = false;
  representation[3] = true;
  representation[4] = true;
  representation[5] = false;
  representation[6] = true;

  NumericCharacter four = NumericCharacter("4", 4, representation);

  NumericCharacterModification nine;
  nine.moveType = addition;
  nine.character = '9';
  four.validOneStepMoves.push_back(nine);

  return four;
}

NumericCharacter NumericCharacter::five() {
  bool representation[7];
  representation[0] = false;
  representation[1] = true;
  representation[2] = true;
  representation[3] = false;
  representation[4] = true;
  representation[5] = true;
  representation[6] = true;

  NumericCharacter five = NumericCharacter("5", 5, representation);

  NumericCharacterModification three;
  three.moveType = inCharacterMove;
  three.character = '3';
  five.validOneStepMoves.push_back(three);

  NumericCharacterModification six;
  six.moveType = addition;
  six.character = '6';
  five.validOneStepMoves.push_back(six);

  NumericCharacterModification nine;
  nine.moveType = inCharacterMove;
  nine.character = '9';
  five.validOneStepMoves.push_back(nine);

  return five;
}

NumericCharacter NumericCharacter::six() {
  bool representation[7];
  representation[0] = true;
  representation[1] = true;
  representation[2] = true;
  representation[3] = false;
  representation[4] = true;
  representation[5] = true;
  representation[6] = true;

  NumericCharacter six = NumericCharacter("6", 6, representation);

  NumericCharacterModification five;
  five.moveType = removal;
  five.character = '5';
  six.validOneStepMoves.push_back(five);

  NumericCharacterModification eight;
  eight.moveType = inCharacterMove;
  eight.character = '8';
  six.validOneStepMoves.push_back(eight);

  NumericCharacterModification zero;
  zero.moveType = inCharacterMove;
  zero.character = '0';
  six.validOneStepMoves.push_back(zero);

  return six;
}

NumericCharacter NumericCharacter::seven() {
  bool representation[7];
  representation[0] = false;
  representation[1] = false;
  representation[2] = true;
  representation[3] = true;
  representation[4] = true;
  representation[5] = false;
  representation[6] = false;

  NumericCharacter seven = NumericCharacter("7", 7, representation);

  NumericCharacterModification one;
  one.moveType = removal;
  one.character = '1';
  seven.validOneStepMoves.push_back(one);

  return seven;
}

NumericCharacter NumericCharacter::eight() {
  bool representation[7];
  representation[0] = true;
  representation[1] = true;
  representation[2] = true;
  representation[3] = true;
  representation[4] = true;
  representation[5] = true;
  representation[6] = true;

  NumericCharacter eight = NumericCharacter("8", 8, representation);

  NumericCharacterModification six;
  six.moveType = removal;
  six.character = '6';
  eight.validOneStepMoves.push_back(six);

  NumericCharacterModification zero;
  zero.moveType = removal;
  zero.character = '0';
  eight.validOneStepMoves.push_back(zero);

  return eight;
}

NumericCharacter NumericCharacter::nine() {
  bool representation[7];
  representation[0] = false;
  representation[1] = true;
  representation[2] = true;
  representation[3] = true;
  representation[4] = true;
  representation[5] = false;
  representation[6] = true;

  NumericCharacter nine = NumericCharacter("9", 9, representation);

  NumericCharacterModification four;
  four.moveType = removal;
  four.character = '4';
  nine.validOneStepMoves.push_back(four);

  NumericCharacterModification three;
  three.moveType = inCharacterMove;
  three.character = '3';
  nine.validOneStepMoves.push_back(three);

  NumericCharacterModification five;
  five.moveType = inCharacterMove;
  five.character = '5';
  nine.validOneStepMoves.push_back(five);

  return nine;
}
