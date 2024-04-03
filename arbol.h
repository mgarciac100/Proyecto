#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <string>

struct Arbol {
    std::string data;
    Arbol* left;
    Arbol* right;

    Arbol(std::string valor) : data(valor), left(nullptr), right(nullptr) {}
};

class ArbolBinario {
private:
    Arbol* root;

    void insert(Arbol*& nodo, std::string valor);
    void inOrden(Arbol* nodo);
    void printTree(Arbol* nodo, std::string prefix = "", bool isLeft = false);

public:
    ArbolBinario();
    void insert(std::string valor);
    void displayInOrder();
    void buscarPalabra(std::string palabra);
    void printTree();
};

#endif /* ARBOL_H */
