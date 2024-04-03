#include "arbol.h"

ArbolBinario::ArbolBinario() : root(nullptr) {}

void ArbolBinario::insert(Arbol*& node, std::string value) {
    if (node == nullptr) {
        node = new Arbol(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else {
        insert(node->right, value);
    }
}

void ArbolBinario::inOrden(Arbol* node) {
    if (node != nullptr) {
        inOrden(node->left);
        std::cout << node->data << " ";
        inOrden(node->right);
    }
}

void ArbolBinario::printTree(Arbol* node, std::string prefix, bool isLeft) {
    if (node != nullptr) {
        std::cout << (isLeft ? "/" : "\\");
        std::cout << node->data << std::endl;

        printTree(node->left, prefix + (isLeft ? "│   " : "    "), true);
        printTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

void ArbolBinario::insert(std::string value) {
    insert(root, value);
}

void ArbolBinario::displayInOrder() {
    inOrden(root);
    std::cout << std::endl;
}

void ArbolBinario::buscarPalabra(std::string palabra) {
    Arbol* current = root;
    while (current != nullptr) {
        if (current->data == palabra) {
            std::cout << palabra << " fue encontrada" << std::endl;
            return;
        } else if (palabra < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    std::cout << "Palabra no encontrada" << std::endl;
}

void ArbolBinario::printTree() {
    printTree(root);
}
