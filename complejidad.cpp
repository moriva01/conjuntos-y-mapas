#include <iostream>
#include <vector>

using namespace std;

int buscarYContar(const vector<int> &lista, int objetivo)
{
    int contador = 0;
    for (int numero : lista)
    {
        if (numero == objetivo)
        {
            contador++;
        }
    }
    return contador;
}

int main()
{

    vector<int> numeros = {4, 2, 7, 4, 9, 4, 6, 4, 8, 5, 4};
    int objetivo = 4;
    int ocurrencias = buscarYContar(numeros, objetivo);
    cout << "el numero " << objetivo << " se encontro " << ocurrencias << " veces en la lista" << endl;

    return 0;
}