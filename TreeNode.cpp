#include "TreeNode.h"

TreeNode::TreeNode()
{
	// Initialize the pointers
	//leftChild = nullptr;
	//rightCHild = nullptr;
}

/*
// class constructor, Im not sure if we need this 
TreeNode::TreeNode(char newItem)
{
	item = newItem;
	leftChild = nullptr;
	rightChild = nullptr;
}
*/


void TreeNode::setItem(char anItem)
{
	item = anItem;
}

char TreeNode::getItem() const
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

TreeNode TreeNode::getLeftValue()
{
	// Return the value of leftChild
	return (*leftChild);
}

TreeNode TreeNode::getRightValue()
{
	// Return the value of rightChild
	return (*rightChild);
}

