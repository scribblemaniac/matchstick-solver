#include "ExpNodes.hpp"

ConstantNode::ConstantNode(int value) {
    this->value = value;
}

const int ConstantNode::getValue() {
    return this->value;
}

OperatorNode::OperatorNode(Operator c) {
    switch (c) {
        case ADDITION:
            this->op = [](int a, int b) { return a + b; };
            break;
        case SUBTRACTION:
            this->op = [](int a, int b) { return a - b; };
            break;
        case MULTIPLICATION:
            this->op = [](int a, int b) { return a * b; };
            break;
        case DIVISION:
            this->op = [](int a, int b) { return a / b; };
            break;
    }
}

const int OperatorNode::getValue() {
    return this->op(this->left->getValue(), this->right->getValue());
}
