#include <iostream>
#include "arbol.h"
#include "curl_helper.h"
#include <fstream>
#include <string>
#include <cstdlib>

#include <windows.h>
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

void ArbolBinario::buscarPalabra(Arbol* node, std::string palabra) {
    if (node != nullptr) {
        if (node->data == palabra) {
            std::cout << "La palabra " << palabra << " fue encontrada en el árbol" << std::endl;
            //show translations
            std::cout << "- Traducciones de " << palabra << ":" << std::endl;
            for (const auto& target : {"en", "de", "pt", "fr"}) {
                std::string translation = CurlHelper::translate(palabra, "es", target);
                std::cout << "  - " << target << ": " << translation << std::endl;
                // reproducir audio
                std::string command = "espeak \"" + translation + "\"";
                const char* charCommand = command.c_str();
                system(charCommand);

            }
        } else if (palabra < node->data) {
            buscarPalabra(node->left, palabra);
        } else {
            buscarPalabra(node->right, palabra);
        }
    } else {
        std::cout << "La palabra " << palabra << " no fue encontrada en el árbol" << std::endl;
    }
}

void ArbolBinario::eliminarPalabra(Arbol* node, std::string palabra) {
    if (node != nullptr) {
        if (node->data == palabra) {
            // Eliminar la palabra
            delete node;
        } else if (palabra < node->data) {
            eliminarPalabra(node->left, palabra);
        } else {
            eliminarPalabra(node->right, palabra);
        }
    }
}

void ArbolBinario::inOrden(Arbol* node) {
    if (node != nullptr) {
        if (node->data == "aguila") {
            std::cout << node->data << std::endl;
            std::cout << "- Traducciones del aguila:" << std::endl;

            // Definir los idiomas a traducir
            std::vector<std::string> idiomas = {"en", "de", "pt", "fr"};

            // Realizar la traducción para cada idioma
            for (const auto& target : idiomas) {
                std::string translation = CurlHelper::translate("aguila", "es", target);
                std::cout << "  - " << target << ": " << translation << std::endl;
            }
        } else {
            inOrden(node->left);
            std::cout << node->data << std::endl; // Imprimir la palabra en español

            // Realizar la traducción para cada idioma para las palabras restantes
            std::cout << "- Traducciones de " << node->data << ":" << std::endl;
            for (const auto& target : {"en", "de", "pt", "fr"}) {
                std::string translation = CurlHelper::translate(node->data, "es", target);
                std::cout << "  - " << target << ": " << translation << std::endl;
            }

            inOrden(node->right);
        }
    }
}

void ArbolBinario::insert(std::string value) {
    insert(root, value);
}

void ArbolBinario::displayInOrder() {
    inOrden(root);
}

void ArbolBinario::buscarPalabra(std::string palabra) {
    buscarPalabra(root, palabra);
}

void ArbolBinario::eliminarPalabra(std::string palabra) {
    eliminarPalabra(root, palabra);
}


