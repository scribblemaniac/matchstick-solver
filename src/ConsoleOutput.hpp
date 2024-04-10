#ifndef CONSOLEOUTPUT_HPP
#define CONSOLEOUTPUT_HPP

#include <array>
#include <iostream>
#include <sstream>

class Character;
class Equation;

#define LINE_HEIGHT 5

class ConsoleOutput {
    public:
        explicit ConsoleOutput(std::ostream &stream = std::cout) : stream(stream) {}
        ~ConsoleOutput() { flush(); }

        ConsoleOutput& operator<<(const Character& character);
        ConsoleOutput& operator<<(const Equation& character);
        ConsoleOutput& operator<<(std::ostream& (*manipulator)(std::ostream&));

    private:
        std::ostream &stream;

        void flush();

        std::array<std::ostringstream, LINE_HEIGHT> lines;
};

#endif // CONSOLEOUTPUT_HPP
