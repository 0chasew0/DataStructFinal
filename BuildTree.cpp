
#include "BuildTree.h"
#include <iterator>
#include <fstream>
#include <iostream>
#include <vector>


BuildTree::BuildTree() {
    exp=" ";
    root= nullptr;

    currentNode=root;

    parentNode= nullptr;

    groupCount=0;
}//default constructor


//constructor
BuildTree::BuildTree(std::string aFileName)
{
    std::ifstream in(aFileName); // Creates the specified input file (determined by the passed 'aFileName')

    /* Uses std::string::assign, which iterates through our file 'in' and stores it in our variable 'exp' */
    exp.assign((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

    TreeNode *newNode = new TreeNode;
    root = newNode;

    currentNode = root;

    parentNode= nullptr;


    groupCount = 0;
}//constructor


std::vector<char> BuildTree::tokenize() {

    /* temporary vector, this is the vector we return after tokenizing */
    std::vector<char> v;

    /* Stores each individual token in the vector, accounting for spaces which shouldn't be included */
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] != ' ') {
            v.push_back(exp[i]);
        }//if
    }//for

    return v; // Returns our vector of chars
}//tokenize

void BuildTree::build(std::vector<char> v) {

    for (int i = 0; i < v.size(); i++) {

        //if (root != nullptr) {

        switch (v[i]) {

            //if opening bracket, we create a left child of our currentNode
            case '(': {

                TreeNode *newNode = new TreeNode;

                currentNode->setLeftChildPtr(newNode);//creating a new left child

                //parent node is now pointing to current
                parentNode = currentNode;

                //current is pointing to the left child
                currentNode = newNode;

                break;

            }//left Parenthesis
            case ')': {

                currentNode = parentNode;

                break;
            }//rightParenthesis


            //if an operator
            case '+':
            case '-':
            case '/':
            case '*': {
                currentNode->setItem(v[i]);//setting the root of the current node to the operator

                TreeNode *newNode = new TreeNode;

                currentNode->setRightChildPtr(newNode);

                parentNode = currentNode;

                currentNode=newNode;

                break;

            }//operator


            default :
                {
                currentNode->setItem(v[i]);
                currentNode=parentNode;

                break;
            }//if token is a number
        }//switch
    }//for size of the vector
}//build

