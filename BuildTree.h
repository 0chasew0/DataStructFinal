#define DATASTRUCTFINAL_BUILDTREE_H

#pragma once
#include <string>
#include <vector>
#include "TreeNode.h"

class BuildTree
{

public:

    //default constructor
    BuildTree();

    //constructor that gets a name file and reads in expression
    BuildTree(std::string aFileName = " ");

    //tokenize() returns a vector containing char of the expression
    std::vector<char> tokenize();


    //build the parse tree
    void build(std::vector<char> v);



private:


    std::string exp;
    TreeNode* root;
    TreeNode* parentNode;

    TreeNode* currentNode;
    int groupCount;

};

#endif //DATASTRUCTFINAL_BUILDTREE_H
