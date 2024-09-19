#include <iostream>
#include <sstream>
#include <string>
#include "AVL.h"


/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
    AVLTree tree;
    std::string numCommands;
    getline(std::cin, numCommands);
    int instructionCount = std::stoi(numCommands);
    Node* one; //not sure why this exists
    for(int i = instructionCount; i > 0; i--) {
        std::string total_command;
        getline(std::cin, total_command);
        std::istringstream instream(total_command);
        std::string operation;
        getline(instream, operation, ' ');
        std::string skip;
        getline(instream, skip, '"');
        std::string name;
        getline(instream, name, '"');
        std::string skip2;
        getline(instream, skip2, ' ');
        std::string number;
        getline(instream, number);
        //tree.insert("Jackie", "00000000");
    }
	return 0;
}

