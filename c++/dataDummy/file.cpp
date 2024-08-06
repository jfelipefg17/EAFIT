#include "file.h"
#include <iostream>

// Constructor
File::File() {
    // Inicializar el generador de números aleatorios con el tiempo actual
    std::srand(static_cast<unsigned int>(std::time(0)));
}

// Método para leer los textos desde un archivo
void File::leerDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream file(nombreArchivo);
    if (file.is_open()) {
        std::string texto;
        while (std::getline(file, texto)) {
            items.push_back(texto);
        }
        file.close();
    } else {
        std::cerr << "We can't open the file: " << nombreArchivo << std::endl;
    }
}

// Método para imprimir los items
void File::imprimirItems() const {
    int i=1;
    for (const auto& item : items) {
        std::cout << "[" << i << "]: " << item << std::endl;
        i=i+1;
    }
    std::cout << std::endl;
}

// Método para retornar un item aleatorio
std::string File::obtenerItemAleatorio() const {
    if (items.empty()) {
        return "No names on the list";
    }
    int indiceAleatorio = std::rand() % items.size();
    return items[indiceAleatorio];
}