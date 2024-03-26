#include <iostream>
#include "arbol.h"

int main() {
    BinaryTree tree;

    // Insertar palabras en el árbol
    tree.insert("perro");
    tree.insert("gato");
    tree.insert("elefante");
    tree.insert("avion");
    tree.insert("ruta");
    tree.insert("cocodrilo");
    tree.insert("aguila");
    tree.insert("barco");

    // Mostrar el árbol en orden alfabético
    std::cout << "Palabras en orden alfabetico:" << std::endl;
    tree.displayInOrder();

    tree.buscarPalabra("perro");
    tree.buscarPalabra("gata");
    tree.printTree();

    return 0;
}
