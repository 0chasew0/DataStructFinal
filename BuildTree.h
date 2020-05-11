#pragma once
#include <string>
#include <vector>
#include "TreeNode.h"

class BuildTree
{

public:

    //constructor that gets a name file and reads in expression
    BuildTree(std::string aFileName = " ");

    //tokenize() returns a vector containing char of the expression
    std::vector<char> tokenize();


    //builds the parse tree
    TreeNode* build(std::vector<char> v);

    //evaluates the parse tree
    int evaluate(TreeNode* tree);

    /* helper functions for evaluate */
    int add(int x, int y) {
        return x + y;
    }

    int sub(int x, int y) {
        return x - y;
    }

    int mul(int x, int y) {
        return x * y;
    }

    int div(int x, int y) {
        return x / y;
    }

private:

    // Our expression string 
    std::string exp; 

    // The root node
    TreeNode* root;

    // The current node
    TreeNode* currentNode;

};
