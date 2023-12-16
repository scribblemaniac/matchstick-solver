//
//

#ifndef Numeric_Character_hpp
#define Numeric_Character_hpp

#include <stdio.h>
#include <string>
#include <array>

using namespace std;

struct MatchstickTransform
{
  int additions;
  int removals;

  bool changes[7];
};

class NumericCharacter
{
  public:
  // String Representation
  string stringValue;

  // Numeric Representation
  int numericValue;

  // Matchstick Represtentation
  //   _    2
  //  |_|  163
  //  |_|  054
  bool matchstickRepresentation[7];

  // Given a numericCharacter give the number of additions and removals required to transform this into the given character
  MatchstickTransform movesRequired(NumericCharacter& character);
};

#endif /* Numeric_Character_hpp */
