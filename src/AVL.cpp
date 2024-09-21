#include "AVL.h"
//used https://www.geeksforgeeks.org/insertion-in-binary-search-tree/ for assistance in inserting nodes

Node* AVLTree::rotateLeft(Node *node) {

}

Node* AVLTree::rotateRight(Node *node) {

}

Node* AVLTree::rotateLeftRight(Node *node) {

}

Node* AVLTree::rotateRightLeft(Node *node) {

}

int AVLTree::getHeight(Node *node) {

}

void AVLTree::insert(std::string name, const std::string& ufid) {
    this->root = insertHelper(this->root, name, ufid);
}

Node* AVLTree::insertHelper(Node *node, const std::string& name, const std::string& ufid) {
    //if BST empty
    if (node == nullptr) {
        return new Node(name, ufid);
    }
    else if (std::stoi(ufid) < std::stoi(node->ufid)) {
        node->left = insertHelper(node->left, name, ufid);
    }
    else {
        node->right = insertHelper(node->right, name, ufid);
    }
    return node;
}

void AVLTree::removeID(const std::string& ufid) {
    std::cout << "unsuccessful" << std::endl;
}

void AVLTree::searchID(const std::string& ufid) {
    searchIDHelper(this->root, ufid);
}

Node* AVLTree::searchIDHelper(Node *node, const std::string& ufid) {
    Node* iterator = node;

    if (iterator == nullptr) {
        std::cout << "unsuccessful" << std::endl;
    }
    else {
        if (iterator->ufid == ufid) {
            std::cout << iterator->name << std::endl;
        }
        if (iterator->left != nullptr) {
            searchIDHelper(iterator->left, ufid);
        }
        if (iterator->right != nullptr) {
            searchIDHelper(iterator->right, ufid);
        }
    }
}

void AVLTree::updateHeight(Node *node) {
    //check balance factor left and right and call rotations
}

void AVLTree::searchName(const std::string& name) {
    searchNameHelper(this->root, name);
}

Node* AVLTree::searchNameHelper(Node *node, const std::string& name) {
    Node* iterator = node;

    if (iterator == nullptr) {
        std::cout << "unsuccessful" << std::endl;
    }
    else {
        if (iterator->name == name) {
            std::cout << iterator->ufid << std::endl;
        }
        if (iterator->left != nullptr) {
            searchNameHelper(iterator->left, name);
        }
        if (iterator->right != nullptr) {
            searchNameHelper(iterator->right, name);
        }
    }
}

void AVLTree::printPreorder() {
    if (this->root == nullptr) {
        std::cout << "" << std::endl;
    }
    else {
        printPreorderHelper(this->root);
        this->comma_val = false;
    }
}

void AVLTree::printPreorderHelper(Node *node) {
    if (node == nullptr) {
        return;
    }

    if (this->comma_val) {
        std::cout << ", " << node->name;
    } else {
        std::cout << node->name;
        this->comma_val = true; //declares first word has been printed
    }

    printPreorderHelper(node->left);
    printPreorderHelper(node->right);
}

void AVLTree::printInorder() {
    if (this->root == nullptr) {
        std::cout << "" << std::endl;
    }
    else {
        printPreorderHelper(this->root);
        this->comma_val = false; //condition indicates if beginning of print statement
    }
}

void AVLTree::printInorderHelper(Node *node) {
    if (node == nullptr) {
        return;
    }

    printInorderHelper(node->left);
    if (this->comma_val) {
        std::cout << ", " << node->name;
    } else {
        std::cout << node->name;
        this->comma_val = true; //declares first word has been printed
    }

    printInorderHelper(node->right);
}

void AVLTree::printPostorder() {
    if (this->root == nullptr) {
        std::cout << "" << std::endl;
    }
    else {
        printPostorderHelper(this->root);
        this->comma_val = false;
    }
}

void AVLTree::printPostorderHelper(Node *node) {
    if (node == nullptr) {
        return;
    }

    printPostorderHelper(node->left);
    printPostorderHelper(node->right);

    if (this->comma_val) {
        std::cout << ", " << node->name;
    } else {
        std::cout << node->name;
        this->comma_val = true; //declares first word has been printed
    }
}

void AVLTree::printLevelCount() {
    //use queue and BFS
    int level = 0; //tracks number of levels in tree
    if (this->root == nullptr) {
        std::cout << 0 << std::endl;
    }
}

void AVLTree::removeInorder(int N) {

}