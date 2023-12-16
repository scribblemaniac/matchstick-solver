//
//  main.cpp
//  Matchstick Solver
//
//  Created by Erik Spooner on 2023-12-16.
//

#include <iostream>
#include "Numeric Character.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    // Create seven
    NumericCharacter seven;
    seven.numericValue = 7;
    seven.stringValue = "7";
    seven.matchstickRepresentation[0] = false;
    seven.matchstickRepresentation[1] = false;
    seven.matchstickRepresentation[2] = true;
    seven.matchstickRepresentation[3] = true;
    seven.matchstickRepresentation[4] = true;
    seven.matchstickRepresentation[5] = false;
    seven.matchstickRepresentation[6] = false;

    NumericCharacter one;
    one.numericValue = 1;
    one.stringValue = "1";
    one.matchstickRepresentation[0] = false;
    one.matchstickRepresentation[1] = false;
    one.matchstickRepresentation[2] = false;
    one.matchstickRepresentation[3] = true;
    one.matchstickRepresentation[4] = true;
    one.matchstickRepresentation[5] = false;
    one.matchstickRepresentation[6] = false;

    MatchstickTransform movesRequired = seven.movesRequired(one);

    cout << "The number of matches that need to be added is " << movesRequired.additions << ". The number of matches that need to be removed is " << movesRequired.removals << endl;
}
