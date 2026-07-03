#include <cmath>
#include <iomanip>
#include <iostream>

double funcion(double x) {
    return x * x * x + 2.0 * x * x + 7.0 * x - 20.0;
}

double derivada(double x) {
    return 3.0 * x * x + 4.0 * x + 7.0;
}

int main() {
    double x, tolerancia;
    int maxIteraciones;

    std::cout << "Metodo de Newton-Raphson para x^3 + 2x^2 + 7x - 20\n";
    std::cout << "Valor inicial, tolerancia y maximo de iteraciones: ";
    if (!(std::cin >> x >> tolerancia >> maxIteraciones) ||
        tolerancia <= 0.0 || maxIteraciones <= 0) {
        std::cerr << "Datos de entrada no validos.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Iteracion\tx\t\t|f(x)|\n";

    for (int iteracion = 1; iteracion <= maxIteraciones; ++iteracion) {
        const double pendiente = derivada(x);
        if (std::abs(pendiente) < 1e-15) {
            std::cerr << "La derivada es demasiado cercana a cero.\n";
            return 1;
        }

        const double siguiente = x - funcion(x) / pendiente;
        std::cout << iteracion << '\t' << siguiente << '\t'
                  << std::abs(funcion(siguiente)) << '\n';

        if (std::abs(siguiente - x) <= tolerancia ||
            std::abs(funcion(siguiente)) <= tolerancia) {
            std::cout << "Raiz aproximada: " << siguiente << '\n';
            return 0;
        }
        x = siguiente;
    }

    std::cout << "Aproximacion tras alcanzar el limite: " << x << '\n';
    return 0;
}
