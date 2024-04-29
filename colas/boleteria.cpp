#include <iostream>
#include <queue>

using namespace std;

class boleteria
{
private:
    queue<string> fila; // cola de fila

public:
    void ingresar_fila(string nombre) // ingrea persona a la fila
    {
        fila.push(nombre);
    }

    void siguente_fila() // ver el siguiente en la fila (comprar entradfas9)
    {
        if (!fila.empty()) // cola no vacia
        {
            string persona = fila.front();
            fila.pop();
            cout << "----------- felicidades - " << persona << " compraste tu boleta" << endl; // para que se sepa de quien es turno
        }
        else
        {
            cout << "fila vacia, todos compraron entradas" << endl;
        }
    }

    void ver_fila() // ver quien esta en la fila
    {
        cout << "concierto Karol g:" << endl;
        if (fila.empty()) // si lista vacia
        {
            cout << "nadie en la fila" << endl;
            return;
        }
        queue<string> temp = fila; // fila temporal (cola9)
        int i = 1;
        while (!temp.empty())
        {
            cout << i << "-- " << temp.front() << " - tiempo estimado de " << i * 20 << " minutos" << endl; // npmbre persona y tiempo de espera
            temp.pop();
            i++;
        }
    }
};

int main()
{
    boleteria fila_karol;

    fila_karol.ingresar_fila("tatiana"); // datos quemados
    fila_karol.ingresar_fila("mafe");
    fila_karol.ingresar_fila("carlos");

    fila_karol.ver_fila(); // ver fila

    fila_karol.siguente_fila(); // ver quien va comprando entrada
    fila_karol.siguente_fila();
    fila_karol.siguente_fila();
    fila_karol.siguente_fila(); // todos compraron entradas

    return 0;
}
