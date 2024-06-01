#include <iostream>
#include "arbol.h"
#include "curl_helper.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include "arbolAvl.h"
#include <windows.h>
using namespace std;
ofstream &es = *new ofstream;
ArbolBinario tree;
ArbolAvl treeAvl;
std::ifstream archivo("D:\\Maynor\\Repositorios\\Proyecto\\Traductor.txt");

void mostrarMenu() {
    int opcion;
    do {
        std::cout << "El archivo de palabras ya se cargo al árbol" << std::endl;
        std::cout << "Menu" << std::endl;
        std::cout << "1. Anadir palabra al rbol" << std::endl;
        std::cout << "2. Mostrar el arbol con sus traducciones" << std::endl;
        std::cout << "3. Buscar palabra" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;



        switch (opcion) {
            case 1: {
                std::string palabra;  // Declaración dentro de un bloque
                std::cout << "Ingrese la palabra: ";
                std::cin >> palabra;
                tree.insert(palabra);
                break;
            }
            case 2:
                std::cout << "Recorrido en orden de las palabras:" << std::endl;
                tree.displayInOrder();
                break;
            case 3: {
                std::string palabra;
                std::cout << "Ingrese la palabra a buscar  y esuchar traducciones: ";
                std::cin >> palabra;
                treeAvl.insertar(palabra);
                treeAvl.insertarEnArchivo(palabra, "D:\\Maynor\\Repositorios\\Proyecto\\historial.txt");
                tree.buscarPalabra(palabra);
                break;
            }
            case 4:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "No ingresó una opción válida, vuelva a ingresar una opción válida" << std::endl;
                break;
        }
    } while (opcion != 3);
}
int main() {




    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return 1; // Terminar el programa con un código de error
    }

    std::string palabra;
    while (archivo >> palabra) {
        tree.insert(palabra);
    }

    archivo.close();




    // Insertar la palabra en el �rbol binario
    // Las palabras a traducir
//    tree.insert("perro");
//    tree.insert("gato");
//    tree.insert("elefante");
//    tree.insert("casa");
//    tree.insert("zapato");
//    tree.insert("ruta");
//    tree.insert("cocodrilo");
//    tree.insert("aguila");
//    tree.insert("barco");

//    // Mostrar el árbol en orden alfabético
//    std::cout << "Recorrido in orden de las palabras:" << std::endl;
//    tree.displayInOrder();


// Menu
    int opcion;
    do {
        mostrarMenu();
        cout << "Desea realizar otra acción? (1. Si, 2. No): ";
        cin >> opcion;
    } while (opcion == 1);

    // Mostrar el árbol en orden alfabético
//    std::cout << "Recorrido in orden de las palabras:" << std::endl;
//    tree.displayInOrder();


//    std::string q = "";
//    std::string source = "es";
//    std::string target = "en";
//
//    std::string translation = CurlHelper::translate(q, source, target);
////call again
//    std::string q2 = "carro";
//    std::string source2 = "es";
//    std::string target2 = "en";
//    std::string translation2 = CurlHelper::translate(q2, source2, target2);

    return 0;
}

