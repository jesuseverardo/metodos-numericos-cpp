#include <cmath>
#include <iomanip>
#include <iostream>

double funcion(double x) {
    return std::exp(-x) - x;
}

int main() {
    double inferior, superior, tolerancia;
    int maxIteraciones;

    std::cout << "Metodo de regla falsa para f(x) = exp(-x) - x\n";
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
    std::cout << "Iteracion\tx\t\tError aproximado\n";

    double anterior = inferior;
    double aproximacion = inferior;
    for (int iteracion = 1; iteracion <= maxIteraciones; ++iteracion) {
        const double denominador = fInferior - fSuperior;
        if (std::abs(denominador) < 1e-15) {
            std::cerr << "No es posible continuar: denominador casi nulo.\n";
            return 1;
        }

        aproximacion = superior - fSuperior * (inferior - superior) / denominador;
        const double fAproximacion = funcion(aproximacion);
        const double error = iteracion == 1 ? std::abs(superior - inferior)
                                            : std::abs(aproximacion - anterior);
        std::cout << iteracion << '\t' << aproximacion << '\t' << error << '\n';

        if (std::abs(fAproximacion) <= tolerancia || error <= tolerancia) {
            std::cout << "Raiz aproximada: " << aproximacion << '\n';
            return 0;
        }

        if (fInferior * fAproximacion < 0.0) {
            superior = aproximacion;
            fSuperior = fAproximacion;
        } else {
            inferior = aproximacion;
            fInferior = fAproximacion;
        }
        anterior = aproximacion;
    }

    std::cout << "Aproximacion tras alcanzar el limite: " << aproximacion << '\n';
    return 0;
}
