#include <functional>

#include "Operator.hpp"

enum class ExpTreeNodeType {
    CONSTANT,
    OPERATOR
};

class ExpTreeNode {
    public:
        ExpTreeNode *left, *right;

        virtual const int getValue() = 0;
        virtual const ExpTreeNodeType getType() = 0;
};

class ConstantNode : public ExpTreeNode {
    public:
        explicit ConstantNode(const int value);

        const int getValue() override;
        const ExpTreeNodeType getType() override { return ExpTreeNodeType::CONSTANT; }

    private:
        int value;
};

class OperatorNode : public ExpTreeNode {
    public:
        explicit OperatorNode(Operator c);

        const int getValue() override;
        const ExpTreeNodeType getType() override { return ExpTreeNodeType::OPERATOR; }

    private:
        std::function<int(int, int)> op;
};
