#pragma once
#include <iostream>

struct Node {
    std::string name = "";
    std::string ufid = "";
    Node* left;
    Node* right;
    int height = 0;

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
    bool comma_val = false;
    int bf = 0; //initializes balance factor to 0
    int depth_level = 0;
    Node* insertHelper(Node* node, const std::string& name, const std::string& ufid);
    bool searchIDHelper(Node* node, const std::string& ufid);
    bool searchNameHelper(Node* node, const std::string& name);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);
    void printPreorderHelper(Node* node);
    void printInorderHelper(Node* node);
    void printPostorderHelper(Node* node);
    void printLevelCountHelper(Node* node);
    void updateHeight(Node* node);
    int getHeight(Node* node);

public:
    void insert(std::string name, const std::string& ufid);
    void removeID(const std::string& ufid);
    void searchID(const std::string& ufid); //good
    void searchName(const std::string& name); //good
    void printInorder(); //good
    void printPreorder(); //good
    void printPostorder(); //good
    void printLevelCount(); //good
    void removeInorder(int N);



    ~AVLTree() {

    }
};
