#include <cmath>
#include <iomanip>
#include <iostream>

double funcion(double x) {
    return std::exp(-x) - x;
}

int main() {
    double inferior, superior, tolerancia;
    int maxIteraciones;

    std::cout << "Metodo de biseccion para f(x) = exp(-x) - x\n";
    std::cout << "Limite inferior, limite superior, tolerancia y maximo de iteraciones: ";
    if (!(std::cin >> inferior >> superior >> tolerancia >> maxIteraciones) ||
        inferior >= superior || tolerancia <= 0.0 || maxIteraciones <= 0) {
        std::cerr << "Datos de entrada no validos.\n";
        return 1;
    }

    double fInferior = funcion(inferior);
    double fSuperior = funcion(superior);
    if (fInferior * fSuperior > 0.0) {
        std::cerr << "El intervalo no encierra una raiz.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Iteracion\tx\t\tError estimado\n";

    double medio = inferior;
    for (int iteracion = 1; iteracion <= maxIteraciones; ++iteracion) {
        medio = (inferior + superior) / 2.0;
        const double fMedio = funcion(medio);
        const double error = (superior - inferior) / 2.0;
        std::cout << iteracion << '\t' << medio << '\t' << error << '\n';

        if (std::abs(fMedio) <= tolerancia || error <= tolerancia) {
            std::cout << "Raiz aproximada: " << medio << '\n';
            return 0;
        }

        if (fInferior * fMedio < 0.0) {
            superior = medio;
            fSuperior = fMedio;
        } else {
            inferior = medio;
            fInferior = fMedio;
        }
    }

    std::cout << "Aproximacion tras alcanzar el limite: " << medio << '\n';
    return 0;
}
