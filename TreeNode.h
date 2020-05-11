#pragma once
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>

class TreeNode {
private:
    std::string item; // The item stored in the node
    TreeNode* leftChild; // The left child of the node
    TreeNode* rightChild; // The right child of the node
    TreeNode* parent; // The parent of the node so that we don't lose nodes the further down we go

public:

    // Set the value of class member : item
    void setItem(char anItem);
    void setItem(std::string anItem);

    // Get the value of item, does no have implementation yet
    std::string getItem() const;

    // Return the address of leftChild point to
    TreeNode* getLeftChildPtr() const;

    // Return the address of rightChild point to
    TreeNode* getRightChildPtr() const;

    TreeNode* getParentPtr();

    // leftChild -> leftPtr, leftChild now point to the address of leftPtr pointing to
    void setLeftChildPtr(TreeNode* leftPtr);

    // rightChild -> rightPtr, rightChild now point to the address of rightPtr pointing to
    void setRightChildPtr(TreeNode* rightPtr);

    void setParentPtr(TreeNode* parentPtr);

    // Helper function
    bool isOperator(std::string ch);

};
