#include <iostream>
#include <omp.h>
#include <vector>
#include <ctime>

int main() {
    const int size = 1000; // Tamaño de los arreglos
    std::vector<int> A(size), B(size), C(size);

    // Inicializar los arreglos con valores aleatorios
    std::srand(std::time(0));
    for (int i = 0; i < size; ++i) {
        A[i] = std::rand() % 100; // Valores entre 0 y 99
        B[i] = std::rand() % 100; // Valores entre 0 y 99
    }

    // Imprimir los arreglos iniciales
    std::cout << "Arreglo A: ";
    for (int i = 0; i < size; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Arreglo B: ";
    for (int i = 0; i < size; ++i) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    // Sumar los arreglos en paralelo usando OpenMP
#pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        C[i] = A[i] + B[i];
        int thread_id = omp_get_thread_num();
        std::cout << "Suma realizada por el hilo " << thread_id << " en el índice " << i << std::endl;
    }

    // Imprimir el resultado
    std::cout << "Arreglo C (resultado de la suma): ";
    for (int i = 0; i < size; ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
