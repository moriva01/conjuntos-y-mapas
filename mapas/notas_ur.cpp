#include <iostream>
#include <map>

using namespace std;

class notas_ur
{
private:
    map<string, map<string, double>> registro_notas; // estudiante, asignatura nota

public:
    double promedio_asignatura(string asig) // promedio de una asignatura
    {
        double notas = 0.0;
        int num_est = 0;
        for (const auto &par : registro_notas)
        {
            if (par.second.find(asig) != par.second.end())
            {
                notas += par.second.at(asig);
                num_est++;
            }
        }
        return num_est > 0 ? notas / num_est : 0.0;
    }

    double promedio(string est) // toma las notas, las suma y las divide
    {
        if (registro_notas.find(est) != registro_notas.end())
        {
            double notas = 0.0;
            int num_asig = 0;
            for (const auto &par : registro_notas[est])
            {
                notas += par.second;
                num_asig++;
            }
            return notas / num_asig;
        }
        else
        {
            return 0.0; // si no encuentra nada
        }
    }

    void ver_nota(string est, string asig) // busca la nota y la imprime
    {
        if (registro_notas.find(est) != registro_notas.end() && registro_notas[est].find(asig) != registro_notas[est].end())
        {
            cout << "estudiante : " << est << " asignatura : " << asig << " nota: "
                 << registro_notas[est][asig] << endl;
        }
        else
        {
            cout << "no tenemos un regisro para ese estudiante" << endl;
        }
    }

    void ingresar_nota(string est, string asig, double nota) // ingresar nota al mapa
    {
        registro_notas[est][asig] = nota;
    }
};

int main()
{
    notas_ur registro;

    registro.ingresar_nota("ivan", "matematicas", 3.5); // algunas notas
    registro.ingresar_nota("daniel", "fisica", 4.0);
    registro.ingresar_nota("mafe", "matematicas", 4.2);
    registro.ingresar_nota("ivan", "fisica", 3.8);
    registro.ingresar_nota("ivan", "quimica", 4.5);

    while (true)
    {
        int eleccion;
        string asignatura, estudiante;
        double nota;
        cout << "------------- notas UR----------------------" << endl;
        cout << "1- ingresar nota" << endl;
        cout << "2- ver nota" << endl;
        cout << "3- ver promedio estudiante" << endl;
        cout << "4- ver promedio asignatura" << endl;
        cout << "5- salir" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            cout << "digite nombre del estudiante: ";
            cin >> estudiante;
            cout << "digite nombre de la asignatura: ";
            cin >> asignatura;
            cout << "digite nota de la asignatura: ";
            cin >> nota;
            registro.ingresar_nota(estudiante, asignatura, nota);
            break;

        case 2:
            cout << "digite nombre del estudiante: ";
            cin >> estudiante;
            cout << "digite nombre de la asignatura: ";
            cin >> asignatura;
            registro.ver_nota(estudiante, asignatura);
            break;

        case 3:
            cout << "digite nombre del estudiante: ";
            cin >> estudiante;
            cout << "promedio de notas de" << estudiante << "  : " << registro.promedio(estudiante) << endl;
            break;

        case 4:
            cout << "digite nombre de la asignatura: ";
            cin >> asignatura;
            cout << "promedio de notas en " << asignatura << "  : " << registro.promedio_asignatura(asignatura) << endl;
            break;

        case 5:
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}
