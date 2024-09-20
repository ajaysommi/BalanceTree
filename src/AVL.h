#pragma once
#include <iostream>

struct Node {
    std::string name;
    std::string ufid;
    Node* left;
    Node* right;

    Node(std::string name, std::string ufid) {
        this->name = name;
        this->ufid = ufid;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AVLTree {
private:
    Node* root = nullptr;
    int bf = 0; //initializes balance factor to 0
    Node* insertHelper(Node* node, std::string name, std::string ufid);
    Node* searchIDHelper(Node* node, std::string ufid);
    Node* searchNameHelper(Node* node, std::string name);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);
    int getHeight(Node* node);

public:
    void insert(std::string name, std::string ufid);
    void removeID(std::string ufid);
    void searchID(std::string ufid);
    void searchName(std::string name);
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printLevelCount();
    void removeInorder(int N);



    ~AVLTree() {

    }
};
