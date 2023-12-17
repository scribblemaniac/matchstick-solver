#ifndef EQUATION_HPP
#define EQUATION_HPP

#include "Character.hpp"

#include <string>
#include <vector>
#include <memory>

class ExpTreeNode;

class Equation {
    public:
        explicit Equation(const std::string equation);
        //explicit Equation(std::vector<Character> characters) : characters(characters) {}

        bool evaluate();
        //Equation withTransform(Transform t);

        std::vector<std::unique_ptr<Character>> characters;

    private:
        bool parseEquation();

        std::vector<ExpTreeNode*> expRoots;
};

#endif // EQUATION_HPP
