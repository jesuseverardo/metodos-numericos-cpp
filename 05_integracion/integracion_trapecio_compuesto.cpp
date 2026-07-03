#include <cmath>
#include <iomanip>
#include <iostream>

double velocidadCohete(double t) {
    return -9.81 * t + 5650.0 * std::log(21500.0 / (21500.0 - 165.0 * t));
}

int main() {
    double inferior, superior;
    int subintervalos;

    std::cout << "Integracion mediante la regla del trapecio compuesto\n";
    std::cout << "Limite inferior, limite superior y numero de subintervalos: ";
    if (!(std::cin >> inferior >> superior >> subintervalos) ||
        inferior >= superior || subintervalos <= 0 ||
        inferior < 0.0 || superior >= 21500.0 / 165.0) {
        std::cerr << "Datos no validos para el dominio de la funcion.\n";
        return 1;
    }

    const double h = (superior - inferior) / subintervalos;
    double suma = 0.5 * (velocidadCohete(inferior) + velocidadCohete(superior));
    for (int i = 1; i < subintervalos; ++i) {
        suma += velocidadCohete(inferior + i * h);
    }

    const double integral = h * suma;
    std::cout << std::fixed << std::setprecision(10)
              << "Ancho h = " << h << '\n'
              << "Integral aproximada = " << integral << '\n';
    return 0;
}
