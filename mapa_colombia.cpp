#include <iostream>
#include <map>
#include <set>

using namespace std;

class mapa_colombia
{
private:
    map<string, pair<string, string>> mapa_col; // mapa capital clima
    map<string, set<string>> climas_ciudades;   // mapa ciudades, climas

public:
    set<string> buscar_clima(string cli)
    {
        if (climas_ciudades.find(cli) != climas_ciudades.end()) // busca dentro del mapa y lo devuelve
        {
            return climas_ciudades[cli];
        }
        else
        {
            return {};
        }
    }

    pair<string, string> buscar_departamento(string dep)
    {
        if (mapa_col.find(dep) != mapa_col.end()) // lo busca dentro del mapa y lo devuelve si lo encuentra
        {
            return mapa_col[dep];
        }
        else
        {
            return make_pair("N/a", "N/a");
        }
    }

    void ingresar_departamento(string dep, string cap, string cli)
    {
        mapa_col[dep] = make_pair(cap, cli); // mapa va a tener departamento como clave, contiene capital y clima
        climas_ciudades[cli].insert(cap);    // climas va a tener una capital
    }
};

int main()
{
    mapa_colombia mapaaa; // objeto mapa de coplombia

    mapaaa.ingresar_departamento("antioquia", "medellin", "templado"); // ingresar algunos departamentos
    mapaaa.ingresar_departamento("bogota", "bogota", "templado");
    mapaaa.ingresar_departamento("atlantico", "barranquilla", "caliente");
    mapaaa.ingresar_departamento("valle", "cali", "caliente");

    while (true)
    {
        int eleccion, clima;
        string dep, cap, cli, consultar_departamento, consultar_clima;
        set<string> clima_ciudades;
        pair<string, string> capital_clima;
        cout << "------------------------ Agustin Codazi -- mapa de Colombia---------------------" << endl;
        cout << "1- insertar departamento" << endl;
        cout << "2- consultar departamento" << endl;
        cout << "3- consultar clima" << endl;
        cout << "4- salir" << endl;
        cin>>eleccion;

        switch (eleccion)
        {
        case 1:

            cout << "digita el nombre del departamento:";
            cin >> dep;
            cout << "digita la capital del departamento:";
            cin >> cap;

            cout << "selecciona el clima de la capital " << endl
                 << "1- frio" << endl
                 << "2- templado" << endl
                 << "3- moderado" << endl
                 << "4- caliente" << endl;

            cin >> clima;

            if (clima = 1)
            {
                cli = "frio";
            }
            if (clima = 2)
            {
                cli = "templado";
            }
            if (clima = 3)
            {
                cli = "moderado";
            }
            if (clima = 4)
            {
                cli = "caliente";
            }

            mapaaa.ingresar_departamento(dep, cap, cli);
            cout << "departamento ingresado correctamente" << endl;
            break;

        case 2:

            cout << "digita el nombre del departamento: ";
            cin >> consultar_departamento;
            capital_clima = mapaaa.buscar_departamento(consultar_departamento);
            cout << "departamento:  " << consultar_departamento << " capital: " << capital_clima.first << endl;
            cout << "Clima " << capital_clima.second << endl;
            break;

        case 3:

            cout << "digita el tipo de clima: ";
            cin >> consultar_clima;
            clima_ciudades = mapaaa.buscar_clima(consultar_clima);
            cout << "ciudades con clima "<< consultar_clima << " : ";

            for (const auto &ciudad : clima_ciudades)
            {
                cout << ciudad << " ";
            }
            cout << endl;
            break;

        case 4:

            return 0;
            break;

        default:
            break;
        }
    }
    return 0;
}
