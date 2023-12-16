//
//

#ifndef Numeric_Character_hpp
#define Numeric_Character_hpp

#include <stdio.h>
#include <string>
#include <list>
#include <iostream>

using namespace std;

struct NumericCharacterTransform
{
  int additions;
  int removals;

  bool changes[7];
};

// types of moves that can be made to the matchsticks (should be shared with operators)
enum MoveType
{
  inCharacterMove,
  addition,
  removal
};

struct NumericCharacterModification
{
  // the type of move made to change into the character
  MoveType moveType;
  char character;
};

class NumericCharacter
{
  public:
  NumericCharacter(string s, int value, bool representation[7]);

  // String Representation
  string stringValue;

  // Numeric Representation
  int numericValue;

  // Matchstick Represtentation
  //   _    2
  //  |_|  163
  //  |_|  054
  bool matchstickRepresentation[7];

  // list of valid one step moves
  list<NumericCharacterModification> validOneStepMoves;

  // Given a numericCharacter give the number of additions and removals required to transform this into the given character
  NumericCharacterTransform movesRequired(NumericCharacter& character);

  // convienence init for the below 10
  static NumericCharacter initFromCharacter(char c);

  // Static constructors for the 10 numeric characters
  static NumericCharacter zero();
  static NumericCharacter one();
  static NumericCharacter two();
  static NumericCharacter three();
  static NumericCharacter four();
  static NumericCharacter five();
  static NumericCharacter six();
  static NumericCharacter seven();
  static NumericCharacter eight();
  static NumericCharacter nine();
};

#endif /* Numeric_Character_hpp */
