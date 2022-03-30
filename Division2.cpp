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
    ARCHIVO: Division2.cpp
    DESARROLLO:
        Implementación de 1 segundo algoritmo iterativo que resuelva el problema de la división entre 2 números enteros.
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
double Division2(int n, int div, int& res, int& ct)
{
    ct++;
    int dd{div}; //inicialización de la variable auxiliar dd con div
    ct++;
    int q{}; //inicialización de la variable auxiliar q con 0
    ct++;
    res = n; //asignamos n a la variable res
    while(dd<=n) //iteramos mientras dd sea menor o igual a n
    {
        ct++;
        ct++;
        dd*=2; //duplicamos su valor en cada iteración
    }
    ct++;
    while(dd>div) //iteramos hasta que dd sea menor o igual a div
    {
        ct++;
        ct++;
        dd/=2; //reducimos a la mitad en cada iteración el valor de dd
        ct++;
        q*=2; //duplicamos el valor de q en cada iteración
        if(dd<=res) //checamo se dd es menor o igual a res
        {
            ct++;
            ct++;
            res-=dd; //en tal caso le restamos dd
            ct++;
            q++; // y aumentado 1 al valor de q
        }
        ct++;
    }
    ct++;
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
    auto cociente = Division2(n,div,res,contador); //calculamos la división de n/div mediante Divisor2
    std::cout << "La división entre " << n << " y "<< div << " es: " << cociente << " con residuo: " << res<< "\n"; //imprimimos el resultado y el valor del residuo
    std::cout << "El algoritmo Division2 hizo: " << contador << " operaciones.\n"; //imprimimos cuantas operaciones hizo el algoritmo
    return 0; //retornamos 0
}