#include <iostream>
#include <queue>

using namespace std;

class impresiones
{
private:
    queue<string> cola_impresion;         // cola de impresion
    queue<string> impresiones_realizadas; // cola de impresiones hechas

public:
    void agregar_impresiones(string archivo) // agregar archivos a la cola
    {
        cola_impresion.push(archivo);
    }

    void impresion_archivos() // imprimir archivos
    {
        if (cola_impresion.empty()) // si cola vacia
        {
            cout << "lista vacia" << endl;
            return;
        }

        string archivo = cola_impresion.front(); // toma el archivo de la cola de impresion
        cola_impresion.pop();
        impresiones_realizadas.push(archivo);
        cout << "imprimiendo archivo -- " << archivo << endl;
    }

    void ver_cola_impresion()
    {
        cout << "archivos en la cola de impresion: " << endl;
        if (cola_impresion.empty()) // si cola vacia
        {
            cout << "cola vacia" << endl;
            return;
        }
        int i = 1;                                    // moverse por la cola de impresion
        queue<string> cola_temporal = cola_impresion; // cola temporal
        while (!cola_temporal.empty())                // si cola no vacia
        {
            cout << i << ". " << cola_temporal.front() << endl; // ver que esta en la cola
            cola_temporal.pop();
            i++;
        }
    }
    void ver_impreso()
    {
        cout << "archivos impresos: " << endl;
        if (impresiones_realizadas.empty())//si cola vacia
        {
            cout << "no hay impresiones" << endl;
            return;
        }

        int i = 1;//moverse por la cola
        queue<string> cola_temporal = impresiones_realizadas;//cola temporal de impresiones
        while (!cola_temporal.empty())//si cola no vacia
        {
            cout << i << ". " << cola_temporal.front() << endl;//ver que hay en la cola
            cola_temporal.pop();
            i++;
        }
    }
};

int main()
{
    impresiones sistema_impresion;

    
    sistema_impresion.agregar_impresiones("proyecto_fisica");//datos quemados
    sistema_impresion.agregar_impresiones("proyecto_logica");
    sistema_impresion.agregar_impresiones("proyecto_calculo");

 
    sistema_impresion.impresion_archivos();//imprimir archivo cola



    sistema_impresion.ver_cola_impresion();//ver que esta en cola
    sistema_impresion.ver_impreso(); //ver que se imprimio

    return 0;
}
