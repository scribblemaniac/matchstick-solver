#include "Equation.hpp"

#include "ExpNodes.hpp"
#include "NumericCharacter.hpp"
#include "OperatorCharacter.hpp"

#include <ctype.h>

Equation::Equation(const std::string equation)
{
    for (const char& c : equation) {
        characters.push_back(std::unique_ptr<Character>(Character::fromChar(c)));
    }
}

bool Equation::evaluate()
{
    if (!parseEquation()) {
        return false; // Invalid equation
    }

    if (expRoots.size() < 2) {
        std::cout << "Not enough expressions: " << expRoots.size() << std::endl;
        return false; // Not enough expressions
    }

    int result = expRoots.at(0)->getValue();
    for (const auto& root : expRoots) {
        if (root->getValue() != result) {
            return false; // Not equal to previous expressions
        }
    }
    return true;
}

bool Equation::parseEquation() {
    ExpTreeNode *currentNode = nullptr;
    bool isReadingNum = false;
    int currentNum = 0;
    NumericCharacter *nc;
    OperatorCharacter *oc;
    for (const auto& c : characters) {
        if ((nc = dynamic_cast<NumericCharacter*>(c.get())) != nullptr) {
            isReadingNum = true;
            currentNum = currentNum * 10 + nc->getValue();
            continue;
        }
        else if (isReadingNum) {
            ConstantNode *newNode = new ConstantNode(currentNum);
            if (currentNode == nullptr) {
                currentNode = newNode;
            }
            else if (currentNode->getType() == ExpTreeNodeType::OPERATOR && currentNode->right == nullptr) {
                currentNode->right = newNode;
            }
            else {
                return false;
            }
            isReadingNum = false;
            currentNum = 0;
        }

        if (c->getType() == CharacterType::EQUALITY) {
            if (currentNode == nullptr) {
                // Empty expression, invalid
                return false;
            }
            expRoots.push_back(currentNode);
            currentNode = nullptr;
        }
        else if ((oc = dynamic_cast<OperatorCharacter*>(c.get())) != nullptr) {
            if (currentNode == nullptr) {
                // Empty lhs, invalid
                return false;
            }
            OperatorNode *newNode = new OperatorNode(oc->getOperator());
            newNode->left = currentNode;
            currentNode = newNode;
        }
        else {
            // Unknown character
            return false;
        }
    }

    if (isReadingNum) {
        ConstantNode *newNode = new ConstantNode(currentNum);
        if (currentNode == nullptr) {
            currentNode = newNode;
        }
        else if (currentNode->getType() == ExpTreeNodeType::OPERATOR && currentNode->right == nullptr) {
            currentNode->right = newNode;
        }
        else {
            return false;
        }
    }

    if (currentNode == nullptr || (currentNode->getType() == ExpTreeNodeType::OPERATOR && currentNode->right == nullptr)) {
        // Empty expression, invalid
        return false;
    }
    expRoots.push_back(currentNode);

    return true;
}
