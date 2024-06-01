#include <iostream>
#include <vector>
#include "curl_helper.h" // Incluir la clase CurlHelper

class ArbolBinario {
public:
    ArbolBinario();
    void insert(std::string value);
    void displayInOrder();
    void buscarPalabra(std::string palabra);
    void eliminarPalabra(std::string palabra);
private:
    struct Arbol {
        std::string data;
        Arbol* left;
        Arbol* right;
        Arbol(const std::string& value) : data(value), left(nullptr), right(nullptr) {}
    };
    Arbol* root;
    void insert(Arbol*& node, std::string value);
    void inOrden(Arbol* node);

    void buscarPalabra(Arbol *node, std::string palabra);

    void eliminarPalabra(Arbol *node, std::string palabra);

};

