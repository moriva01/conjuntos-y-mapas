#include <iostream>
#include <vector>

using namespace std;

int buscarYContar(const vector<int> &lista, int objetivo)
{
    int contador = 0;
    for (int numero : lista) // for recorre toda la lista (seria mejor busqueda binaria)
    {
        if (numero == objetivo) // Comparacion de elementos (comparación de igualdad entre dos numeros)
        {
            contador++; // Actualizacion del contador ( se incrementa el contador, operacion de complejidad constante )
        }
    }
    return contador; // Retorno del contador (devuelve como resultado de la funcion -  complejidad constante )
}

int main()
{

    vector<int> numeros = {4, 2, 7, 4, 9, 4, 6, 4, 8, 5, 4};
    int objetivo = 4;
    int ocurrencias = buscarYContar(numeros, objetivo);//llama la funcion (conplejidad constante)
    cout << "el numero " << objetivo << " se encontro " << ocurrencias << " veces en la lista" << endl;

    return 0;
}