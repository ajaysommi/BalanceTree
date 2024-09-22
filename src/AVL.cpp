#include <queue>
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
        std::cout << "successful" << std::endl;
        Node* newNode = new Node(name, ufid);
        updateHeight(newNode);
        return newNode;
        //return new Node(name, ufid);
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
    if (this->root == nullptr) {
        std::cout << "unsuccessful" << std::endl;
    }
    else {
        bool ID_check = searchIDHelper(this->root, ufid);
        if (!ID_check) {
            std::cout << "unsuccessful" << std::endl;
        }
    }
}

bool AVLTree::searchIDHelper(Node *node, const std::string& ufid) {
    Node* iterator = node;
    if (iterator == nullptr) {
        return false;
    }
    if (std::stoi(iterator->ufid) == std::stoi(ufid)) {
        std::cout << iterator->name << std::endl;
        return true;
    }
    if (std::stoi(ufid) < std::stoi(iterator->ufid) && iterator->left != nullptr) {
        return searchIDHelper(iterator->left, ufid);
    }
    if (std::stoi(ufid) > std::stoi(iterator->ufid) && iterator->right != nullptr) {
        return searchIDHelper(iterator->right, ufid);
    }
    return false;
}

void AVLTree::updateHeight(Node *node) {
    //check balance factor left and right and call rotations
}

void AVLTree::searchName(const std::string& name) {
    if (this->root == nullptr) {
        std::cout << "unsuccessful" << std::endl;
    }
    else {
        bool name_check = searchNameHelper(this->root, name);
        if (!name_check) {
            std::cout << "unsuccessful" << std::endl;
        }
    }
}

bool AVLTree::searchNameHelper(Node *node, const std::string& name) {
    Node* iterator = node;
    if (iterator == nullptr) {
        return false;
    }
    if (iterator->name == name) {
        std::cout << iterator->ufid << std::endl;
        return true;
    }
    if (name < iterator->name && iterator->left != nullptr) {
        return searchNameHelper(iterator->left, name);
    }
    if (name > iterator->name && iterator->right != nullptr) {
        return searchNameHelper(iterator->right, name);
    }
    return false;
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
        printInorderHelper(this->root);
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
    if (this->root != nullptr) {
        printLevelCountHelper(this->root);
    }
    else {
        std::cout << 0 << std::endl;
    }
}

void AVLTree::printLevelCountHelper(Node *node) {
    //using queue and BFS
    std::queue<Node*> total_q;
    int depth_level = 0; //tracks number of levels in tree
    if (node != nullptr) {
        total_q.push(node);
    }
    else {
        std::cout << 0 << std::endl;
    }
    while (not total_q.empty()) {
        total_q.pop();
        for (int i = 0; i < total_q.size(); i++) {
            if (node->left != nullptr) {
                total_q.push(node->left);
            }
            if (node->right != nullptr) {
                total_q.push(node->right);
            }
            depth_level++;
        }
    }
    std::cout << depth_level << std::endl;
}

void AVLTree::removeInorder(int N) {

}