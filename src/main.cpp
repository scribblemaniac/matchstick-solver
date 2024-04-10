#include "Character.hpp"
#include "Equation.hpp"
#include "ConsoleOutput.hpp"

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <equation>" << endl;
        return 1;
    }

    ConsoleOutput output;

    Equation eq(argv[1]);
    output << eq << endl;

    //cout << "Evaluate results: " << (eq.evaluate() ? "true" : "false") << endl;
}
