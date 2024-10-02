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
            std::string skip;
            getline(instream, skip, '"');

            //gathers name (ex: insert "/Ajay/" 1234567)
            std::string name; //CHECK IS ALPHA()OSIDJFOISDJFOISJDFOSJDFOISJDF
            //try catch for std::invalid_argument
            getline(instream, name, '"');

            //skips over second space (ex: insert "Ajay"/ /1234567)
            std::string skip2;
            getline(instream, skip2, ' ');

            //gathers ufid (ex: insert "Ajay" /1234567/)
            std::string number;
            getline(instream, number);

            //executes insertion after gathering name and number
            tree.insert(name, number);
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















            //skips over first space (ex: search/ /1234567)
//            std::string skip;
//            getline(instream, skip, ' ');
//
//            //skips over first space (ex: search/ /"Ajay")
//            std::string skip;
//            getline(instream, skip, '"');
//
//            //gathers value(name or ufid) (ex: search /1234567/ or search /)
//            std::string value;
//            getline(instream, value);

            //check if alpha(). if valid proceed to name
        }

        else if (operation == "printInorder") {
            //writes to console in comma-separated format
            tree.printInorder();
            std::cout << "" << std::endl;
        }

        else if (operation == "printPreorder") {
            //writes to console in comma-separated format
            tree.printPreorder();
            std::cout << "" << std::endl;
        }

        else if (operation == "printPostorder") {
            //writes to console in comma-separated format
            tree.printPostorder();
            std::cout << "" << std::endl;
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
            tree.removeInorder(std::stoi(skip)); //EXCEPTION HANDLE!!!!!!!!!!!!!!!
        }

//        std::string skip;
//        getline(instream, skip, '"');
//        std::string name; //check if name is alpha()
//        getline(instream, name, '"');
//        std::string skip2;
//        getline(instream, skip2, ' ');
//        std::string number;
//        getline(instream, number);

//        tree.insert("A", "0000001");
//        tree.insert("B", "0000002");
//        tree.insert("C", "0000003");
//        tree.insert("D", "0000004");
//        tree.insert("E", "0000005");
//        tree.insert("F", "0000006");
//        tree.insert("G", "0000007");
//        tree.insert("H", "0000008");
//        tree.insert("I", "0000009");
//        tree.searchName("Ajay");
//        tree.searchID("0000003");
//        tree.printLevelCount();
////        tree.printInorder();
//        //tree.removeID("3249043");
//        //tree.removeID("0000003"); //ERROR: remove function removes everything above. ex rm Jackie removes Ajay as well
//        tree.removeInorder(4);
//        //tree.removeInorder(2);
//        //tree.removeInorder(3);
//        tree.printInorder();
//        std::cout << "" << std::endl;
//        tree.printPreorder();
//        std::cout << "" << std::endl;
//        tree.printPostorder();
//        std::cout << "" << std::endl;
    }
    std::cout << " " << std::endl;
	return 0;
}

