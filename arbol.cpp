#include "arbol.h"

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(TreeNode*& node, std::string value) {
    if (node == nullptr) {
        node = new TreeNode(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else {
        insert(node->right, value);
    }
}

void BinaryTree::traverseInOrder(TreeNode* node) {
    if (node != nullptr) {
        traverseInOrder(node->left);
        std::cout << node->data << " ";
        traverseInOrder(node->right);
    }
}

void BinaryTree::printTree(TreeNode* node, std::string prefix, bool isLeft) {
    if (node != nullptr) {
        std::cout << (isLeft ? "/" : "\\");
        std::cout << node->data << std::endl;

        printTree(node->left, prefix + (isLeft ? "│   " : "    "), true);
        printTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

void BinaryTree::insert(std::string value) {
    insert(root, value);
}

void BinaryTree::displayInOrder() {
    traverseInOrder(root);
    std::cout << std::endl;
}

void BinaryTree::buscarPalabra(std::string palabra) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (current->data == palabra) {
            std::cout << "Palabra encontrada" << std::endl;
            return;
        } else if (palabra < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    std::cout << "Palabra no encontrada" << std::endl;
}

void BinaryTree::printTree() {
    printTree(root);
}
