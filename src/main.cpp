#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include "AVL.cpp"


/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
    AVLTree tree;
    std::string numCommands;
    getline(std::cin, numCommands);
    int instructionCount = std::stoi(numCommands);
    //Node* one; //not sure why this exists
    for(int i = instructionCount; i > 0; i--) {
        std::string total_command;
        getline(std::cin, total_command);
        std::istringstream instream(total_command);
        std::string operation;
        getline(instream, operation, ' ');
        std::string skip;
        getline(instream, skip, '"');
        std::string name; //check if name is alpha()
        getline(instream, name, '"');
        std::string skip2;
        getline(instream, skip2, ' ');
        std::string number;
        getline(instream, number);
        tree.insert("A", "0000001");
        tree.insert("B", "0000002");
        tree.insert("C", "0000003");
        tree.insert("D", "0000004");
        tree.insert("E", "0000005");
        tree.insert("F", "0000006");
        tree.searchName("Ajay");
        tree.searchID("0000003");
        tree.printLevelCount();
//        tree.printInorder();
        //tree.removeID("3249043");
        //tree.removeID("0000003"); //ERROR: remove function removes everything above. ex rm Jackie removes Ajay as well
        tree.removeInorder(1);
        //tree.removeInorder(2);
        //tree.removeInorder(3);
        tree.printInorder();
        std::cout << "" << std::endl;
        tree.printPreorder();
        std::cout << "" << std::endl;
        tree.printPostorder();
        std::cout << "" << std::endl;
    }
	return 0;
}

