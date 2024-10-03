#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include "AVL.h"


/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
    //creates instance (tree) of AVLTree class
    AVLTree tree;

    //gets initial value (number of following commands)
    std::string numCommands;
    getline(std::cin, numCommands);

    //converts to int to iterate through inside loop
    int instructionCount = std::stoi(numCommands);
    //std::cout << "" << std::endl;

    for(int i = 0; i < instructionCount; i++) {
        //gets entire line (ex: insert "Ajay" 1234567)
        std::string total_command;
        getline(std::cin, total_command);

        //sets up parsing for that line
        std::istringstream instream(total_command);

        //stores task word into operation (ex: insert/remove/search/etc.)
        std::string operation;
        getline(instream, operation, ' ');

        if (operation == "insert") {
            //skips over first space (ex: insert/ /"Ajay" 1234567)
            try {
                std::string skip;
                getline(instream, skip, '"');

                //gathers name (ex: insert "/Ajay/" 1234567)
                std::string name;
                //try catch for std::invalid_argument
                getline(instream, name, '"');

                //skips over second space (ex: insert "Ajay"/ /1234567)
                std::string skip2;
                getline(instream, skip2, ' ');

                //gathers ufid (ex: insert "Ajay" /1234567/)
                std::string number;
                getline(instream, number);

                //executes insertion after gathering name and number
                if (tree.isAlphaVal(name) && name.length() > 0) {
                    tree.insert(name, number);
                }
                else {
                    std::cout << "unsuccessful" << std::endl;
                }
            }
            catch (std::invalid_argument& e){
                std::cout << "unsuccessful" << std::endl;
            }
        }

        else if (operation == "remove") {
            //skips over first space (ex: remove/ /1234567)
            std::string skip;
            getline(instream, skip, ' ');

            //gathers ufid (ex: remove /1234567/)
            std::string number;
            getline(instream, number);

            //calls remove method with given ufid
            tree.removeID(skip);
        }

        else if (operation == "search") {
            //used https://www.geeksforgeeks.org/stdfind_first_of-in-cpp/ as a guide
            //used https://cplusplus.com/reference/string/string/back/ and
            // https://cplusplus.com/reference/string/string/front/ for checking quotations

            //grabs whatever is after the search command (ex: search/ 1234/)
            std::string value;
            getline(instream, value);

            if (value.front() == '"' && value.back() == '"') {
                std::string name = value.substr(1,value.length()-2);
                if (tree.isAlphaVal(name)) {
                    tree.searchName(name);
                }
                //assume name (search name)
            }
            else {
                tree.searchID(value);
                //assume ufid being searched (search ID)
            }
        }

        else if (operation == "printInorder") {
            //writes to console in comma-separated format
            tree.printInorder();
            //std::cout << "" << std::endl;
        }

        else if (operation == "printPreorder") {
            //writes to console in comma-separated format
            tree.printPreorder();
            //std::cout << "" << std::endl;
        }

        else if (operation == "printPostorder") {
            //writes to console in comma-separated format
            tree.printPostorder();
            //std::cout << "" << std::endl;
        }

        else if (operation == "printLevelCount") {
            //writes to console in integer format
            tree.printLevelCount();
        }

        else if (operation == "removeInorder") {
            //skips over first space (ex: removeInorder/ /2)
            std::string skip;
            getline(instream, skip, ' ');

            //gathers ufid (ex: removeInorder /2/)
            std::string number;
            getline(instream, number);

            //calls remove method with given ufid
            try {
                tree.removeInorder(std::stoi(skip));
            }
            catch (std::exception& e) {
                std::cout << "unsuccessful" << std::endl;
            }
        }
    }
    //std::cout << " " << std::endl;
	return 0;
}

