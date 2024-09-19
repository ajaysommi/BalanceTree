#include "AVL.h"
//used https://www.geeksforgeeks.org/insertion-in-binary-search-tree/ for assistance in inserting nodes

void AVLTree::insert(std::string name, std::string ufid) {
    this->root = insertHelper(this->root, name, ufid);
}

Node* AVLTree::insertHelper(Node *node, std::string name, std::string ufid) {
    //if BST empty
    if (node == nullptr) {
        return new Node(name, ufid);
    }

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
    std::cout << "unsuccessful" << std::endl;
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