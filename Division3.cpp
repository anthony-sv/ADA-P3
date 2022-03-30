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
    ARCHIVO: Division3.cpp
    DESARROLLO:
        Implementación de 1 algoritmo recursivo que resuelva el problema de la división entre 2 números enteros.
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
 * @param ct Contador para contar la cantidad de operaciones que realiza este algoritmo
 * @return double - valor de la división n/div
 */
double Division3(int n, int div,int& ct)
{
    if(div>n) //checamos si div es mayor a n
    {
        ct++;
        ct++;
        return 0; //en tal caso retornamos 0
    }
    else //caso contrario
    {
        ct++;
        ct++;
        ct++;
        return 1 + Division3(n-div,div,ct); //retornamos 1 + la llamada recursiva ahora con tamaño n-div
    }
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
    auto cociente = Division3(n,div,contador); //calculamos la división de n/div mediante Divisor3
    std::cout << "La división entre " << n << " y "<< div << " es: " << cociente << "\n"; //imprimimos el resultado y el valor del residuo
    std::cout << "El algoritmo Division3 hizo: " << contador << " operaciones.\n"; //imprimimos cuantas operaciones hizo el algoritmo
    return 0; //retornamos 0
}