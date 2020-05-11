#include "BuildTree.h"
#include <iterator>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

//constructor
BuildTree::BuildTree(std::string aFileName)
{
    std::ifstream in(aFileName); // Creates the specified input file (determined by the passed 'aFileName')

    /* Uses std::string::assign, which iterates through our file 'in' and stores it in our variable 'exp' */
    exp.assign((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

    // Creates new node
    TreeNode *newNode = new TreeNode;

    // Sets root equal to the new, empty node
    root = newNode;

    // Our current node is also at the root at the beginning
    currentNode = root;

}//constructor

std::vector<char> BuildTree::tokenize() {

    /* temporary vector, this is the vector we return after tokenizing */
    std::vector<char> v;

    std::cout << "The expression is: ";

    /* Stores each individual token in the vector, accounting for spaces which shouldn't be included */
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] != ' ') {
            v.push_back(exp[i]);
            std::cout << exp[i];
        }//if
    }//for

    std::cout << std::endl;

    return v; // Returns our vector of chars
}//tokenize

TreeNode* BuildTree::build(std::vector<char> v) {

    // Iterates through our vector of chars
    for (int i = 0; i < v.size(); i++) {

        // Switch statement which builds the tree depending on the type of character
        switch (v[i]) {

            //if opening bracket, we create a left child of our currentNode
            //left Parenthesis
        case '(': {

            // Create new node
            TreeNode* newNode = new TreeNode;

            // Creating a new left child of the current node
            currentNode->setLeftChildPtr(newNode);

            // Set the new node (which is a child) to have a parent of the current node, which is at this stage one level higher than the new node
            newNode->setParentPtr(currentNode);

            // Bring the current node down a level to the new node's level
            currentNode = newNode;

            break;
        }

            //rightParenthesis
            case ')': {

                // Bring the current node up a level by accessing it's parent
                currentNode = currentNode->getParentPtr();

                break;
            }

            //if an operator
            case '+':
            case '-':
            case '/':
            case '*': {
                
                // Set the value of the current node to whatever operator it is currently
                currentNode->setItem(v[i]); 

                // Create a new node
                TreeNode* newNode = new TreeNode;

                // Have the current node make a new right child node
                currentNode->setRightChildPtr(newNode);

                // Set the new node (which is a child) to have a parent of the current node, which is at this stage one level higher than the new node 
                newNode->setParentPtr(currentNode);
                
                // Bring current node down to level of the new node
                currentNode = newNode;

                break;
            }

            // If character is a number
            default: {

                // Set the current node to the value of the number
                currentNode->setItem(v[i]);

                // Bring the current node up a level by accessing it's parent
                currentNode = currentNode->getParentPtr();

                break;
            }
       
        }//switch
    }//for size of the vector

    return root; // Return the root of the tree
}

int BuildTree::evaluate(TreeNode* root)
{

    // If the current node is an operator, call evaluate again until we find two children that are numbers
    if (root->isOperator(root->getLeftChildPtr()->getItem())) {
        evaluate(root->getLeftChildPtr());
    }

    // If the current node is an operator, call evaluate again until we find two children that are numbers
    if (root->isOperator(root->getRightChildPtr()->getItem())) {
        evaluate(root->getRightChildPtr());
    }

    else {

        // Stores value of left child
        int leftValue = std::stoi(root->getLeftChildPtr()->getItem());

        // Stores value of right child
        int rightValue = std::stoi(root->getRightChildPtr()->getItem());

        // Switch statement using whatever operator is stored in current node
        switch (root->getItem()[0]) {
            /* Each case here does its operation specified in the current node and if we are still not at the top
              of the tree, then call evaluate again, otherwise just return the number in the root node,
              which would signify we are done*/
        case '+':

            root->setItem(std::to_string(add(leftValue, rightValue)));

            if (root->getParentPtr() != nullptr) {
                evaluate(root->getParentPtr());
                break;
            }
            else {
                return (std::stoi(root->getItem()));
                break;
            }

        case '-':

            root->setItem(std::to_string(sub(leftValue, rightValue)));

            if (root->getParentPtr() != nullptr) {
                evaluate(root->getParentPtr());
                break;
            }
            else {
                return (std::stoi(root->getItem()));
                break;
            }

        case '*':
            root->setItem(std::to_string(mul(leftValue, rightValue)));

            if (root->getParentPtr() != nullptr) {
                evaluate(root->getParentPtr());
                break;
            }

            else {
                return (std::stoi(root->getItem()));
                break;
            }
            

        case '/':
            root->setItem(std::to_string(div(leftValue, rightValue)));

            if (root->getParentPtr() != nullptr) {
                evaluate(root->getParentPtr());
                break;
            }
            else {
                return (std::stoi(root->getItem()));
                break;
            } // else
            
        } // case

    } // else

    return (std::stoi(root->getItem())); // Return the final value in the root node

} // function

