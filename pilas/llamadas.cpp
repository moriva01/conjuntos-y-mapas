#include <iostream>
#include <stack> //para usar pilas pues

using namespace std;

struct llamada
{ // strucutra de la llamada
    string numero;
    string fecha;
    string hora;

    llamada(string num, string fec, string hor)
    {

        this->numero = num;
        this->fecha = fec;
        this->hora = hor;
    } // constructor
};

class llamadas
{
private:
    stack<llamada> registro; // la pila de llamdas

public:
    void agregar_llamada(string num, string fec, string hor)
    {
        llamada llamada_aux(num, fec, hor);
        registro.push(llamada_aux);
    }

    void ver_llamadas()
    {
        if (registro.empty())//si no hay llamadas
        {
            cout << "llamadas vacias" << endl;
            return;
        }
        cout << "---------- llamadas recientes:" << endl;
        while (!registro.empty())// si la pila no esta vacia (si hay llamadas pues)
        {
            llamada llamada_actual = registro.top();//sacar la llamada
            cout << "numero: " << llamada_actual.numero << "-- fecha: " << llamada_actual.fecha << "-- hora: " << llamada_actual.hora << endl;
            registro.pop();
        }
    }
};

int main()
{
    llamadas registro;//objeto llamadas

    registro.agregar_llamada("123456789", "2024-04-28", "10:00");//datos quemados
    registro.agregar_llamada("987654321", "2024-04-28", "09:00");
    registro.agregar_llamada("456123789", "2024-04-28", "08:00");

   
    registro.ver_llamadas();//ver llamadas

    return 0;
}
