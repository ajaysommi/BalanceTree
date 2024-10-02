#include <queue>
#include "AVL.h"
//used https://www.geeksforgeeks.org/insertion-in-binary-search-tree/ for assistance in inserting nodes
//used https://www.geeksforgeeks.org/deletion-in-binary-search-tree/ for assistance in deleting nodes

Node* AVLTree::rotateLeft(Node *node) {
    Node* gc = node->right->left;
    Node* np = node->right;
    np->left = node;
    node->right = gc;
    updateHeight(node);
    updateHeight(np);
    return np; //update heights once don
}

Node* AVLTree::rotateRight(Node *node) {
    Node* gc = node->left->right;
    Node* np = node->left;
    np->right = node;
    node->left = gc;
    updateHeight(node);
    updateHeight(np);
    return np; //update heights once don
}

Node* AVLTree::rotateLeftRight(Node *node) {
    node->left = rotateLeft(node->left);
    node = rotateRight(node);
    return node;
}

Node* AVLTree::rotateRightLeft(Node *node) {
    node->right = rotateRight(node->right);
    node = rotateLeft(node);
    return node;
}

void AVLTree::insert(std::string name, const std::string& ufid) {
    this->root = insertHelper(this->root, name, ufid);
    if (!insertCond) { //prints unsuccessful if new node was not inserted and adjusts bool to reflect that
        std::cout << "unsuccessful" << std::endl;
    }
    else {
        insertCond = false;
    }
}

Node* AVLTree::insertHelper(Node *node, const std::string& name, const std::string& ufid) {
    //if BST empty
    if (node == nullptr) {
        std::cout << "successful" << std::endl;
        Node* newNode = new Node(name, ufid);
        insertCond = true;
        return newNode;
        //return new Node(name, ufid);
    }

    //binary search insertion using recursion
    else if (std::stoi(ufid) < std::stoi(node->ufid)) {
        node->left = insertHelper(node->left, name, ufid);
    }
    else {
        node->right = insertHelper(node->right, name, ufid);
    }

    //call update height function
    updateHeight(node);

    //call rotations
    if ((node->left == nullptr ? 0 : node->left->height) - (node->right == nullptr ? 0 : node->right->height) == -2) {
        //right heavy
        if ((node->left == nullptr ? 0 : node->left->height) - (node->right == nullptr ? 0 : node->right->height) == 1) {
            node = rotateRightLeft(node);
        }
        else {
            node = rotateLeft(node);
        }
    }
    else if ((node->left == nullptr ? 0 : node->left->height) - (node->right == nullptr ? 0 : node->right->height) == 2) {
        if ((node->left == nullptr ? 0 : node->left->height) - (node->right == nullptr ? 0 : node->right->height) == -1) {
            node = rotateLeftRight(node);
        }
        else {
            node = rotateRight(node);
        }
    }
    return node;
}

void AVLTree::removeID(const std::string& ufid) {
    this->root = removeIDHelper(this->root, ufid);
    if (!removeIDCond) {
        std::cout << "unsuccessful" << std::endl;
    }
    else {
        std::cout << "successful" << std::endl;
        removeIDCond = false;
    }
}
void AVLTree::updateHeight(Node *node) {
    node->height = 1 + std::max(node->left == nullptr ? 0 : node->left->height,
                                node->right == nullptr ? 0 : node->right->height);
}

Node* AVLTree::removeIDHelper(Node* node, const std::string& ufid) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->ufid == ufid) { //dont need to convert to int
        return removeHelper(node);
    }
    if (ufid < node->ufid && node->left != nullptr) {
        node->left = removeIDHelper(node->left, ufid);
        return node;
    }
    if (ufid > node->ufid && node->right != nullptr) {
        node->right = removeIDHelper(node->right, ufid);
        return node;
    }
    return node;
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

int AVLTree::getHeight(Node *node) {
    return node->height;
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
        //if node left and right null print w/ newline
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
        depth_level = 0;
    }
    else {
        std::cout << 0 << std::endl;
    }
}

void AVLTree::printLevelCountHelper(Node *node) {
    //using queue and BFS
    std::queue<Node*> total_q;
    if (node != nullptr) {
        total_q.push(node);
    }
    else {
        std::cout << 0 << std::endl;
    }
    while (not total_q.empty()) {
        depth_level++;
        for (int i = 0; i < total_q.size(); i++) {
            Node* iter_node = total_q.front();
            total_q.pop();
            if (iter_node->left != nullptr) {
                total_q.push(iter_node->left);
            }
            if (iter_node->right != nullptr) {
                total_q.push(iter_node->right);
            }
        }
    }
    std::cout << depth_level << std::endl;
}

Node* AVLTree::removeHelper(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    //rules based on 0, 1, 2 children. after performing operations, check bF and perform appropriate rotations.
    if (node->left == nullptr && node->right == nullptr) { //assumes node has no children
        removeIDCond = true;
        delete node;
        return nullptr;
    }
    //single child
    else if (node->left != nullptr && node->right == nullptr) {
        removeIDCond = true;
        Node* leftC = node->left;
        delete node;
        updateHeight(leftC);
        return leftC;
    }
    else if (node->left == nullptr && node->right != nullptr) {
        removeIDCond = true;
        Node* rightC = node->right;
        delete node;
        updateHeight(rightC);
        return rightC;
    }
    //two children
    else if (node->left != nullptr && node->right != nullptr) {
        Node* tempNode = node->right;
        while (tempNode->left != nullptr) {
            tempNode = tempNode->left;
        }
        //node = tempNode;
        node->name = tempNode->name;
        node->ufid = tempNode->ufid;
        node->right = removeHelper(node->right);
        removeIDCond = true;
        updateHeight(node);
        return node;
    }
    return nullptr;
}

void AVLTree::removeInorder(int N) {
    this->root = removeInorderHelper(this->root, N);
    if (!removeIDCond) {
        std::cout << "unsuccessful" << std::endl;
    }
    else {
        std::cout << "successful" << std::endl;
        removeIDCond = false;
        remove_counter = -1;
    }
    //usual bst delete but also update height after deleting

    //once node removed, update heights, perform rotations
}

Node* AVLTree::removeInorderHelper(Node *node, int N) {
    if (node == nullptr) {
        return nullptr;
    }
    node->left = removeInorderHelper(node->left, N);
    remove_counter++;
    if (remove_counter == N) {
        return removeHelper(node);
    }
    node->right = removeInorderHelper(node->right, N);
    return node;
}

//used https://www.programiz.com/cpp-programming/library-function/cctype/isalpha
//for help with checking
bool AVLTree::isAlphaVal(std::string name) {
    for (char c : name) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}