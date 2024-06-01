#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include <string>
#include <fstream>

class ArbolAvl {
private:
    struct Nodo {
        std::string palabra;
        Nodo* izquierda;
        Nodo* derecha;
        int altura;

        Nodo(const std::string& palabra)
                : palabra(palabra), izquierda(nullptr), derecha(nullptr), altura(1) {}
    };

    Nodo* raiz;

    // Funciones auxiliares
    int altura(Nodo* n);
    int max(int a, int b);
    Nodo* insertar(Nodo* nodo, const std::string& palabra);
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);
    int obtenerBalance(Nodo* n);
    void guardarEnArchivo(Nodo* nodo, std::ofstream& archivo);

public:
    ArbolAvl();
    void insertar(const std::string& palabra);
    void insertarEnArchivo(const std::string& palabra, const std::string& nombreArchivo);
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    void guardarEnArchivo(const std::string& nombreArchivo);
    void displayInOrder();
    void displayInOrder(Nodo* nodo);
};

#endif // ARBOLAVL_H
