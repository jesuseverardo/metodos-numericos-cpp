#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double x;
    int cifrasSignificativas;

    std::cout << "Aproximacion de exp(x) mediante la serie de Maclaurin\n";
    std::cout << "Valor de x y numero de cifras significativas (1 a 12): ";
    if (!(std::cin >> x >> cifrasSignificativas) ||
        cifrasSignificativas < 1 || cifrasSignificativas > 12) {
        std::cerr << "Datos de entrada no validos.\n";
        return 1;
    }

    const double valorReal = std::exp(x);
    const double criterioPorcentual =
        0.5 * std::pow(10.0, 2 - cifrasSignificativas);

    double aproximacion = 1.0;
    double termino = 1.0;
    double anterior = aproximacion;

    std::cout << std::scientific << std::setprecision(10);
    std::cout << "Terminos\tAproximacion\tError relativo aprox. (%)\n";
    std::cout << 1 << '\t' << aproximacion << "\t---\n";

    for (int n = 1; n <= 200; ++n) {
        termino *= x / n;
        aproximacion += termino;

        const double denominador = std::max(std::abs(aproximacion), 1e-300);
        const double error = std::abs((aproximacion - anterior) / denominador) * 100.0;
        std::cout << n + 1 << '\t' << aproximacion << '\t' << error << '\n';

        if (error <= criterioPorcentual) {
            const double errorVerdadero =
                std::abs((valorReal - aproximacion) / valorReal) * 100.0;
            std::cout << "exp(" << x << ") ~= " << aproximacion << '\n';
            std::cout << "Error relativo verdadero (%) = " << errorVerdadero << '\n';
            return 0;
        }
        anterior = aproximacion;
    }

    std::cerr << "No se alcanzo el criterio en 200 terminos.\n";
    return 2;
}
