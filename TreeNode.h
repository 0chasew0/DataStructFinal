#pragma once

class TreeNode {
private:
	char item;
	TreeNode* leftChild;
	TreeNode* rightChild;

public:
	TreeNode();
	//TreeNode(char newItem);
	
	// Set the value of class memeber : item
	void setItem(char anItem);
	
	// Get the value of item, does no have implementation yet
	char getItem() const;

	//bool isLeaf() const;
	
	// Return the address of leftChild point to
	TreeNode* getLeftChildPtr() const;

	// Return the address of rightChild point to
	TreeNode* getRightChildPtr() const;
	
	// leftChild -> leftPtr, leftChild now point to the address of leftPtr pointing to
	void setLeftChildPtr(TreeNode* leftPtr);

	// rightChild -> rightPtr, rightChild now point to the address of rightPtr pointing to
	void setRightChildPtr(TreeNode* rightPtr);
	
	// Return the value in the address of leftChild point to
	TreeNode getLeftValue();
	// Return the value in the address of rightChild point to
	TreeNode getRightValue();

};
