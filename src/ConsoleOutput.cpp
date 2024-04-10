#include "ConsoleOutput.hpp"

#include "Character.hpp"
#include "Equation.hpp"

ConsoleOutput& ConsoleOutput::operator<<(const Character& character) {
    std::array<std::string, LINE_HEIGHT> charArray = character.toString();
    const bool isFirstChar = lines[0].str().empty();
    for (int i = 0; i < LINE_HEIGHT; ++i) {
        if (!isFirstChar) {
            lines[i] << "  ";
        }

        lines[i] << charArray[i];
    }
    return *this;
}

ConsoleOutput& ConsoleOutput::operator<<(const Equation& equation) {
    for (const auto& character : equation.characters) {
        *this << *character;
    }
    return *this;
}

ConsoleOutput& ConsoleOutput::operator<<(std::ostream& (*manipulator)(std::ostream&)) {
    if (manipulator == static_cast<std::ostream& (*)(std::ostream&)>(std::endl)) {
        flush();
    }
    return *this;
}

void ConsoleOutput::flush() {
    if (lines[0].str().empty()) {
        return;
    }
    for (int i = 0; i < LINE_HEIGHT; ++i) {
        stream << lines[i].str() << std::endl;
        lines[i].str(std::string());
    }
}
