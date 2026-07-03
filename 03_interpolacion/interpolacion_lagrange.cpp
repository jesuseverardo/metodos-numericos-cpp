#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Interpolacion polinomial de Lagrange\nNumero de puntos: ";
    if (!(std::cin >> n) || n < 2 || n > 1000) {
        std::cerr << "Cantidad de puntos no valida.\n";
        return 1;
    }

    std::vector<double> x(n), y(n);
    std::cout << "Capture cada par x y:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    double consulta;
    std::cout << "Valor de x que se interpolara: ";
    if (!(std::cin >> consulta)) {
        std::cerr << "Entrada no valida.\n";
        return 1;
    }

    double resultado = 0.0;
    for (int i = 0; i < n; ++i) {
        double base = 1.0;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            const double denominador = x[i] - x[j];
            if (std::abs(denominador) < 1e-15) {
                std::cerr << "Los valores de x deben ser distintos.\n";
                return 1;
            }
            base *= (consulta - x[j]) / denominador;
        }
        resultado += y[i] * base;
    }

    std::cout << std::setprecision(12)
              << "P(" << consulta << ") = " << resultado << '\n';
    return 0;
}
