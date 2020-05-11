#include "TreeNode.h"

/* These are all getters and setters except for the last function */
void TreeNode::setItem(char anItem)
{
    item = anItem;
}

void TreeNode::setItem(std::string anItem)
{
    item = anItem;
}

std::string TreeNode::getItem() const
{
    return item;
}

TreeNode* TreeNode::getLeftChildPtr() const
{
    // Return the address of leftChild
    return leftChild;
}

TreeNode* TreeNode::getRightChildPtr() const
{
    // Return the address of rightChild
    return rightChild;
}

TreeNode* TreeNode::getParentPtr()
{
    return parent;
}

void TreeNode::setLeftChildPtr(TreeNode* leftPtr)
{
    // Change the address of the leftChild currently point to
    leftChild = leftPtr;
}

void TreeNode::setRightChildPtr(TreeNode* rightPtr)
{
    // Change the address of the rightChild currently point to
    rightChild = rightPtr;
}

void TreeNode::setParentPtr(TreeNode* parentPtr)
{
    parent = parentPtr;
}

/* Checks if the given string/char is an operator */
bool TreeNode::isOperator(std::string ch)
{
    if (ch[0] == '+' || ch[0] == '-' || ch[0] == '/' || ch[0] == '*') {
        return true;
    }

    return false;
}


