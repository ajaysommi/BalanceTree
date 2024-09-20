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

void AVLTree::insert(std::string name, std::string ufid) {
    this->root = insertHelper(this->root, name, ufid);
}

Node* AVLTree::insertHelper(Node *node, std::string name, std::string ufid) {
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

void AVLTree::removeID(std::string ufid) {
    std::cout << "unsuccessful" << std::endl;
}


void AVLTree::searchID(std::string ufid) {
    searchIDHelper(this->root, ufid);
}

Node* AVLTree::searchIDHelper(Node *node, std::string ufid) {
    Node* iterator = node;

    if (iterator == nullptr) {
        std::cout << "unsuccessful" << std::endl;
    }

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

void AVLTree::searchName(std::string name) {
    searchNameHelper(this->root, name);
}

Node* AVLTree::searchNameHelper(Node *node, std::string name) {
    Node* iterator = node;

    if (iterator == nullptr) {
        std::cout << "unsuccessful" << std::endl;
    }
    if (iterator->name == name) {
        std::cout << iterator->ufid << std::endl;
    }
    if (iterator->left != nullptr) {
        searchIDHelper(iterator->left, name);
    }
    if (iterator->right != nullptr) {
        searchIDHelper(iterator->right, name);
    }

}

void AVLTree::printInorder() {

}

void AVLTree::printPreorder() {

}

void AVLTree::printPostorder() {

}

void AVLTree::printLevelCount() {
    int level = 0; //tracks number of levels in tree
    if (this->root == nullptr) {
        std::cout << 0 << std::endl;
    }

}

void AVLTree::removeInorder(int N) {

}