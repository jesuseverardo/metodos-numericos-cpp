#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Inversion de matrices mediante Gauss-Jordan\nOrden de la matriz: ";
    if (!(std::cin >> n) || n <= 0 || n > 100) {
        std::cerr << "Dimension no valida.\n";
        return 1;
    }

    std::vector<std::vector<double>> aumentada(
        n, std::vector<double>(2 * n, 0.0));

    std::cout << "Capture los elementos de la matriz por filas:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> aumentada[i][j];
        }
        aumentada[i][n + i] = 1.0;
    }
    if (!std::cin) {
        std::cerr << "Entrada no valida.\n";
        return 1;
    }

    for (int columna = 0; columna < n; ++columna) {
        int pivote = columna;
        for (int fila = columna + 1; fila < n; ++fila) {
            if (std::abs(aumentada[fila][columna]) >
                std::abs(aumentada[pivote][columna])) {
                pivote = fila;
            }
        }

        if (std::abs(aumentada[pivote][columna]) < 1e-12) {
            std::cerr << "La matriz es singular o casi singular.\n";
            return 1;
        }
        std::swap(aumentada[columna], aumentada[pivote]);

        const double divisor = aumentada[columna][columna];
        for (double& valor : aumentada[columna]) {
            valor /= divisor;
        }

        for (int fila = 0; fila < n; ++fila) {
            if (fila == columna) {
                continue;
            }
            const double factor = aumentada[fila][columna];
            for (int j = 0; j < 2 * n; ++j) {
                aumentada[fila][j] -= factor * aumentada[columna][j];
            }
        }
    }

    std::cout << "Matriz inversa:\n" << std::fixed << std::setprecision(8);
    for (int i = 0; i < n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            std::cout << std::setw(14) << aumentada[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}
