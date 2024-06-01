#include "ArbolAvl.h"

// Constructor
ArbolAvl::ArbolAvl() : raiz(nullptr) {}

// Obtener altura del nodo
int ArbolAvl::altura(Nodo* n) {
    return n ? n->altura : 0;
}

// Obtener el máximo entre dos números
int ArbolAvl::max(int a, int b) {
    return (a > b) ? a : b;
}

// Rotación simple a la derecha
ArbolAvl::Nodo* ArbolAvl::rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierda;
    Nodo* T2 = x->derecha;
    x->derecha = y;
    y->izquierda = T2;
    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
    return x;
}

// Rotación simple a la izquierda
ArbolAvl::Nodo* ArbolAvl::rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecha;
    Nodo* T2 = y->izquierda;
    y->izquierda = x;
    x->derecha = T2;
    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
    return y;
}

// Obtener balance del nodo
int ArbolAvl::obtenerBalance(Nodo* n) {
    return n ? altura(n->izquierda) - altura(n->derecha) : 0;
}

// Insertar una palabra en el árbol AVL
ArbolAvl::Nodo* ArbolAvl::insertar(Nodo* nodo, const std::string& palabra) {
    if (!nodo) return new Nodo(palabra);

    if (palabra < nodo->palabra)
        nodo->izquierda = insertar(nodo->izquierda, palabra);
    else if (palabra > nodo->palabra)
        nodo->derecha = insertar(nodo->derecha, palabra);
    else
        return nodo;

    nodo->altura = 1 + max(altura(nodo->izquierda), altura(nodo->derecha));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && palabra < nodo->izquierda->palabra)
        return rotarDerecha(nodo);

    if (balance < -1 && palabra > nodo->derecha->palabra)
        return rotarIzquierda(nodo);

    if (balance > 1 && palabra > nodo->izquierda->palabra) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && palabra < nodo->derecha->palabra) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

// Método público para insertar una palabra
void ArbolAvl::insertar(const std::string& palabra) {
    raiz = insertar(raiz, palabra);
}

// Insertar una palabra en el archivo
void ArbolAvl::insertarEnArchivo(const std::string& palabra, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (archivo.is_open()) {
        archivo << palabra << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
    }
}

// Cargar palabras desde un archivo
void ArbolAvl::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string palabra;
        while (std::getline(archivo, palabra)) {
            insertar(palabra);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
    }
}

// Guardar el árbol en un archivo
void ArbolAvl::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        guardarEnArchivo(raiz, archivo);
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
    }
}

// Guardar en archivo (recursivo)
void ArbolAvl::guardarEnArchivo(Nodo* nodo, std::ofstream& archivo) {
    if (nodo) {
        guardarEnArchivo(nodo->izquierda, archivo);
        archivo << nodo->palabra << std::endl;
        guardarEnArchivo(nodo->derecha, archivo);
    }
}

// Mostrar en orden (recursivo)
void ArbolAvl::displayInOrder(Nodo* nodo) {
    if (nodo) {
        displayInOrder(nodo->izquierda);
        std::cout << nodo->palabra << std::endl;
        displayInOrder(nodo->derecha);
    }
}

// Método público para mostrar en orden
void ArbolAvl::displayInOrder() {
    displayInOrder(raiz);
}
