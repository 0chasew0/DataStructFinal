#include "BuildTree.h"
#include "TreeNode.h"

#include <iostream>

int main() {

	// Object which reads our expression from the text file and creates an empty root node
	BuildTree b("expression.txt");

	std::cout << "Expression result is: " << b.evaluate(b.build(b.tokenize()));

	return 0;

}