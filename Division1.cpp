/*
    INSTITUTO POLITÉCNICO NACIONAL
    ESCUELA SUPERIOR DE CÓMPUTO
    ASIGNATURA:
        ANÁLISIS DE ALGORITMOS
    GRUPO: 
        3CV11
    PROFESOR: 
        LUNA BENOSO BENJAMÍN
    ALUMNO: 
        STEINER VÁZQUEZ ANTHONY FRANCIS
    TÍTULO: 
        PRÁCTICA 3: FUNCIONES RECURSIVAS VS ITERATIVAS
    ARCHIVO: Division1.cpp
    DESARROLLO:
        Implementación de 1 algoritmo iterativo que resuelva el problema de la división entre 2 números enteros.
    ENTREGA: 
        28/03/2022
*/

// librerías
#include <iostream>

/**
 * Función para calcular la división entre 2 números enteros n/div.
 * 
 * @param n Dividendo
 * @param div Divisor
 * @param res Residuo
 * @param ct Contador para contar la cantidad de operaciones que realiza este algoritmo
 * @return double - valor de la división n/div
 */
double Division1(int n, int div, int& res, int& ct)
{
    ct++;
    double q{0}; //inicialización de la variable auxiliar q con 0
    while(n>=div) //iteramos hasta que n sea menor a div
    {
        ct++;
        ct++;
        n = n-div; //le vamos restando div a n
        ct++;
        q++; //aumentamos el valor de q en 1 por cada vez
    }
    ct++;
    ct++;
    res = n; //al termino de iterar en n queda el valor del residuo, por lo tanto se lo asignamos a res
    ct++;
    return q; //retornamos q
}

/**
 * @brief Función main
 * @return 0 - valor de retorno de la función main
 */
int main()
{
    int contador{}; //variable para el contador
    int n; //variable donde vamos a guardar el dividendo
    int div; //variable donde vamos a guardar el divisor
    std::cin >> n >> div; //pedimos por consola ambos valores
    int res{0}; //inicializamos con 0 nuestra variable donde guardaremos el residuo
    auto cociente = Division1(n,div,res, contador); //calculamos la división de n/div mediante Divisor1
    std::cout << "La división entre " << n << " y "<< div << " es: " << cociente << " con residuo: " << res<< "\n"; //imprimimos el resultado y el valor del residuo
    std::cout << "El algoritmo Division1 hizo: " << contador << " operaciones.\n"; //imprimimos cuantas operaciones hizo el algoritmo
    return 0; //retornamos 0
}