#include "TreeNode.h"
#include "BuildTree.h"

int main() {
    // WWARNING Each time you run it, the expression.txt will only have the expression2
    std::string expression1 = "(5*(6+7))", expression2 = "(8/(7-6))";

    // Object which reads our expression from the text file and creates an empty root node
    BuildTree b("expression.txt");

    std::cout <<  b.evaluate(b.build(b.tokenize()));
    std::cout << " is the result" << "\n";



    std::cout <<"\n\n";
    std::ofstream output;
    output.open("expression.txt");
    output << expression1;
    output.close();

    BuildTree c("expression.txt");
    std::cout <<  c.evaluate(c.build(c.tokenize()));
    std::cout << " is the result" << "\n";



    std::cout <<"\n\n";
    output.open("expression.txt");
    output << expression2;
    output.close();

    BuildTree d("expression.txt");
    std::cout <<  d.evaluate(d.build(d.tokenize()));
    std::cout << " is the result" << "\n";

    return 0;
}
