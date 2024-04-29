#include <iostream>
#include <queue>

using namespace std;

class mercado
{
private:

    queue<string> lista;// cola de mercado

public:

    void agregar_lista(string cosa)//agregar cosas a la cola
    {
        lista.push(cosa);
    }

    void sacar_cosas()//ver productos de la cola
    {
        if (lista.empty())
        {
            cout << "lista vacia" << endl;//cola vacia
            return;
        }
        cout << "productos sacados de la lista:" << endl;
        while (!lista.empty())//si cola no vacia
        {
            cout << " - " << lista.front() << endl;//ver producto
            lista.pop();
        }
    }
};

int main()
{
    mercado lista_mercado;

    
    lista_mercado.agregar_lista("leche");//datos quemados
    lista_mercado.agregar_lista("pan");
    lista_mercado.agregar_lista("huevos");
    lista_mercado.agregar_lista("tomate");

    
    lista_mercado.sacar_cosas();//ver cola

    return 0;
}
