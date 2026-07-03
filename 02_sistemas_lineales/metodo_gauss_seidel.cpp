#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int n, maxIteraciones;
    double tolerancia;

    std::cout << "Metodo de Gauss-Seidel\nNumero de incognitas: ";
    if (!(std::cin >> n) || n <= 0 || n > 100) {
        std::cerr << "Dimension no valida.\n";
        return 1;
    }

    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<double> b(n);
    std::cout << "Capture cada fila de A seguida del elemento correspondiente de b:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
        std::cin >> b[i];
        if (!std::cin || std::abs(a[i][i]) < 1e-15) {
            std::cerr << "Entrada no valida o elemento diagonal nulo.\n";
            return 1;
        }
    }

    std::cout << "Tolerancia y maximo de iteraciones: ";
    if (!(std::cin >> tolerancia >> maxIteraciones) ||
        tolerancia <= 0.0 || maxIteraciones <= 0) {
        std::cerr << "Criterio de paro no valido.\n";
        return 1;
    }

    std::vector<double> x(n, 0.0);
    std::cout << std::fixed << std::setprecision(10);

    for (int iteracion = 1; iteracion <= maxIteraciones; ++iteracion) {
        const std::vector<double> anterior = x;
        double errorMaximo = 0.0;

        for (int i = 0; i < n; ++i) {
            double suma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    suma += a[i][j] * x[j];
                }
            }
            x[i] = (b[i] - suma) / a[i][i];
            errorMaximo = std::max(errorMaximo, std::abs(x[i] - anterior[i]));
        }

        std::cout << "Iteracion " << iteracion << ":";
        for (double valor : x) {
            std::cout << ' ' << valor;
        }
        std::cout << "  error=" << errorMaximo << '\n';

        if (errorMaximo <= tolerancia) {
            return 0;
        }
    }

    std::cerr << "No se alcanzo la tolerancia solicitada.\n";
    return 2;
}
