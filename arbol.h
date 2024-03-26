#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <string>

struct TreeNode {
    std::string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    void insert(TreeNode*& node, std::string value);
    void traverseInOrder(TreeNode* node);
    void printTree(TreeNode* node, std::string prefix = "", bool isLeft = false);

public:
    BinaryTree();
    void insert(std::string value);
    void displayInOrder();
    void buscarPalabra(std::string palabra);
    void printTree();
};

#endif /* ARBOL_H */
