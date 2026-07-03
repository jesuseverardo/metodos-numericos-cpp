# Métodos Numéricos en C++

Este repositorio contiene una selección de programas desarrollados en C++ para practicar métodos básicos de análisis numérico.

Los ejercicios están organizados por tema y fueron depurados para que el código sea más claro, portable y fácil de compilar. Cada programa implementa un método numérico específico y puede ejecutarse de forma independiente.

## Contenido del repositorio

```text
metodos-numericos-cpp/
│
├── README.md
├── CMakeLists.txt
│
├── 01_raices/
├── 02_sistemas_lineales/
├── 03_interpolacion/
├── 04_series/
└── 05_integracion/
```

## Programas incluidos

| Tema | Archivo | Método implementado |
|---|---|---|
| Raíces | `01_raices/metodo_biseccion.cpp` | Método de bisección para resolver `exp(-x) - x` |
| Raíces | `01_raices/metodo_regla_falsa.cpp` | Método de regla falsa para resolver `exp(-x) - x` |
| Raíces | `01_raices/metodo_newton_raphson.cpp` | Método de Newton-Raphson aplicado a un polinomio cúbico |
| Sistemas lineales | `02_sistemas_lineales/metodo_gauss_seidel.cpp` | Solución iterativa de un sistema lineal `Ax = b` |
| Sistemas lineales | `02_sistemas_lineales/matriz_inversa_gauss_jordan.cpp` | Cálculo de la matriz inversa mediante Gauss-Jordan con pivoteo parcial |
| Interpolación | `03_interpolacion/interpolacion_lagrange.cpp` | Interpolación mediante el polinomio de Lagrange |
| Series | `04_series/serie_maclaurin_exponencial.cpp` | Aproximación de `exp(x)` usando la serie de Maclaurin |
| Integración | `05_integracion/integracion_rectangulos.cpp` | Integración numérica con la regla compuesta del punto medio |
| Integración | `05_integracion/integracion_trapecio_compuesto.cpp` | Integración numérica con la regla compuesta del trapecio |

## Temas abordados

- Métodos cerrados para encontrar raíces
- Métodos abiertos para encontrar raíces
- Solución de sistemas de ecuaciones lineales
- Inversión de matrices
- Interpolación polinómica
- Series de aproximación
- Integración numérica
- Compilación individual de programas en C++
- Organización de proyectos con CMake

## Requisitos

Para compilar y ejecutar los programas se necesita:

- Un compilador compatible con C++17
- CMake 3.16 o posterior

Compiladores recomendados:

- GCC
- Clang
- Microsoft Visual C++

## Compilación con CMake

Desde la carpeta principal del repositorio, ejecuta:

```bash
cmake -S . -B build
cmake --build build
```

Los archivos compilados se generarán dentro de la carpeta `build`.

## Compilación individual

Cada archivo también puede compilarse por separado.

Ejemplo con GCC o Clang:

```bash
g++ -std=c++17 01_raices/metodo_biseccion.cpp -o metodo_biseccion
```

Para ejecutar el programa:

```bash
./metodo_biseccion
```

En Windows, el ejecutable puede ejecutarse así:

```bash
metodo_biseccion.exe
```

## Criterio de selección

Se conservaron los programas que representan métodos numéricos distintos y que podían dejarse completos, claros y funcionales.

Durante la revisión se corrigieron problemas comunes encontrados en las versiones originales, como:

- Criterios de paro que terminaban en la primera iteración.
- Arreglos indexados fuera de rango.
- Variables sin inicializar.
- Dependencias antiguas o poco portables, como `conio.h`.
- Repetición de programas con el mismo método.
- Archivos incompletos o con funciones principales vacías.

## Archivos no incluidos en la selección principal

No se incluyeron en esta versión principal los siguientes casos:

- Versiones repetidas de bisección, regla falsa, Lagrange y Newton-Raphson.
- `Romberg.cpp`, porque su contenido correspondía a otra copia de Newton-Raphson y no implementaba el método de Romberg.
- `Deriva.cpp`, porque las funciones principales de derivación estaban incompletas.
- `Menus.cpp`, porque la mayoría de sus opciones no tenían implementación.
- Versiones originales de Gauss-Jordan, porque presentaban problemas en la captura de la matriz o usaban dimensiones sin inicializar.
- Interpolación inversa, porque intercambiaba incorrectamente las variables del problema.
- Fórmula general, porque corresponde a álgebra elemental y no agrega un método numérico al conjunto.

## Objetivo

El objetivo de este repositorio es documentar prácticas académicas de análisis numérico en C++, mostrando implementaciones básicas y organizadas de métodos utilizados para resolver problemas matemáticos mediante aproximaciones computacionales.

## Nota académica

Este material se publica con fines educativos. Los programas pueden servir como apoyo para estudiar la lógica de cada método, practicar programación en C++ y comparar resultados numéricos.

## Autor

Jesús Everardo Díaz Alvarado

## Licencia

Este proyecto se publica bajo la licencia MIT. Puedes consultar el archivo `LICENSE` para más información.