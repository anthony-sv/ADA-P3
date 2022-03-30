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
    ARCHIVO: BusquedaEn3Bloques.cpp
    DESARROLLO:
        Implementación de 2 algoritmos, uno recursivo y otro iterativo que parta un arreglo en 3, 
        y busque un elemento mediante estas particiones.
    ENTREGA: 
        28/03/2022
*/

// librerías
#include <iostream>
#include <vector>

/**
 * Función para buscar un elemento en un arreglo mediante una partición en 3, de manera recursiva.
 * 
 * @param A Arreglo donde vamos a buscar
 * @param busca Elemento que vamos a buscar en el arreglo
 * @param inicio 1era posición del arreglo
 * @param final Última posición del arreglo
 * @param ct Contador para contar la cantidad de operaciones que realiza este algoritmo
 * @return int - índice del elemento encontrado en el arreglo
 */
int BusquedaEn3BloquesRecursiva(std::vector<int> A, int busca, int inicio, int final, int &ct)
{
    if (inicio > final) //checamos que no hayamos intercambiado los indices de inicio y final
    {
        ct++;
        ct++;
        return -1; //retornamos -1
    }
    else //caso contrario
    {
        ct++;
        ct++;
        int i{((final - inicio) / 3) + inicio}; //inicializamos i, que es la 1ra parte del arreglo
        ct++;
        int j{((2 * (final - inicio)) / 3) + inicio}; //inicializamos j, que es la 2nda parte del arreglo
        if (busca == A[i]) //checamos si el elemento que buscamos está en la posición i
        {
            ct++;
            ct++;
            return i; //en tal caso retornamos i
        }
        else if (busca == A[j]) //checamos si el elemento que buscamos está en la posición j
        {
            ct++;
            ct++;
            ct++;
            return j; //en tal caso retornamos j
        }
        else if (busca > A[j]) //checamos que esté en el intervalo (j,final]
        {
            ct++;
            ct++;
            ct++;
            ct++;
            inicio = j + 1; //en tal caso actualizamos el valor de inicio a j+1
            ct++;
            return BusquedaEn3BloquesRecursiva(A, busca, inicio, final, ct); //retornamos la llamada recursiva con este cambio
        }
        else if (busca > A[i]) //checamos que esté en el intervalo (i,j)
        {
            ct++;
            ct++;
            ct++;
            ct++;
            ct++;
            inicio = i + 1; //actualizamos el valor de inicio a i+1
            ct++;
            final = j - 1; //actualizamos el valor de final a j-1
            ct++;
            return BusquedaEn3BloquesRecursiva(A, busca, inicio, final, ct); //retornamos la llamada recursiva con estos cambios
        }
        else //solo queda que esté en intervalo [inicio,i)
        {
            ct++;
            ct++;
            ct++;
            ct++;
            ct++;
            final = i - 1; //actualizamos el valor de final a i-1
            ct++;
            return BusquedaEn3BloquesRecursiva(A, busca, inicio, final, ct); //retornamos la llamada recursiva con este cambio
        }
    }
}

/**
 * Función para buscar un elemento en un arreglo mediante una partición en 3, de manera iterativa.
 * 
 * @param A Arreglo donde vamos a buscar
 * @param busca Elemento que vamos a buscar en el arreglo
 * @param ct Contador para contar la cantidad de operaciones que realiza este algoritmo
 * @return int - índice del elemento encontrado en el arreglo
 */
int BusquedaEn3BloquesIterativa(std::vector<int> A, int busca, int& ct)
{
    ct++;
    int inicio = 0; //variable auxiliar para poner el valor de inicio donde empezaremos a buscar en el arreglo
    ct++; 
    int final = A.size() - 1; //variable auxiliar para poner el valor de término donde terminaremos de buscar en el arreglo
    ct++;
    int i; //declaración de nuestra variable i
    ct++;
    int j; //declaración de nuestra variable j
    while (inicio <= final) // checamos que inicio no sea mayor a final
    {
        ct++;
        ct++;
        int i = ((final - inicio) / 3) + inicio; //le damos el valor a i, de la 1ra 3ra parte del arreglo
        ct++;
        int j = ((2 * (final - inicio)) / 3) + inicio; //le damos el valor a i, de la 2nda 3ra parte del arreglo
        if (busca == A[i]) //checamos si el elemento que buscamos está en la posición i
        {
            ct++;
            ct++;
            return i; //en tal caso retornamos i
        }
        else if (busca == A[j]) //checamos si el elemento que buscamos está en la posición j
        {
            ct++;
            ct++;
            ct++;
            return j; //en tal caso retornamos j
        }
        else if (busca > A[j]) //checamos que esté en el intervalo (j,final]
        {
            ct++;
            ct++;
            ct++;
            ct++;
            inicio = j + 1; //en tal caso actualizamos el valor de inicio a j+1
        }
        else if (busca > A[i]) //checamos que esté en el intervalo (i,j)
        {
            ct++;
            ct++;
            ct++;
            ct++;
            ct++;
            inicio = i + 1; //actualizamos el valor de inicio a i+1
            ct++;
            final = j - 1; //actualizamos el valor de final a j-1
        }
        else //solo queda que esté en intervalo [inicio,i)
        {
            ct++;
            ct++;
            ct++;
            ct++;
            ct++;
            final = i - 1; //actualizamos el valor de final a i-1
        }
    }
    ct++;
    ct++;
    return -1; //en caso contrario simplemente retornamos -1
}


/**
 * @brief Función main
 * @return 0 - valor de retorno de la función main
 */
int main()
{
    int contadorR{}; //variable para el contador del caso recursivo
    int contadorI{}; //variable para el contador del caso iterativo
    std::vector<int> A = {2, 3, 5, 7, 10, 10, 11, 15, 17, 20, 25, 30, 32, 36, 40}; //vector donde vamos a buscar
    int valor; //variable auxiliar donde guardaremos el valor que vamos a buscar
    std::cin >> valor; //pedimos por consola el valor a buscar en el arreglo
    auto indiceRec = BusquedaEn3BloquesRecursiva(A, valor, 0, A.size() - 1,contadorR); //calculamos el indice con el algoritmo recursivo
    std::cout << "-----------------En el caso recursivo-----------------\n"; //impresión para separación de casos
    if (indiceRec == -1) //checamos si el indice es -1
    {
        std::cout << "No se encontró el valor: " << valor << " en el arreglo A.\n"; //En tal caso no lo encontró, e imprimimos algo para notificarlo
    }
    else
    {
        std::cout << "Se encontró el valor: " << valor << " en la posición: " << indiceRec << "\n"; //caso contrario lo encontró e imprimos algo para notificar
    }
    std::cout << "El algoritmo Recursivo hizo: " << contadorR << " operaciones.\n"; //impresión de la cantidad de operaciones que hizo el algoritmo recursivo
    std::cout << "-----------------En el caso iterativo-----------------\n"; //impresión para separación de casos
    auto indiceIt = BusquedaEn3BloquesIterativa(A, valor, contadorI);
    if (indiceIt == -1)
    {
        std::cout << "No se encontró el valor: " << valor << " en el arreglo A.\n"; //En tal caso no lo encontró, e imprimimos algo para notificarlo
    }
    else
    {
        std::cout << "Se encontró el valor: " << valor << " en la posición: " << indiceIt << "\n"; //caso contrario lo encontró e imprimos algo para notificar
    }
    std::cout << "El algoritmo Iterativo hizo: " << contadorI << " operaciones.\n"; //impresión de la cantidad de operaciones que hizo el algoritmo iterativo
    return 0; //retornamos 0
}