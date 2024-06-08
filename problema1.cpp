#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

// Estamos definiendo una estructura para la fecha
struct Fecha
{
    int dia;
    int mes;
    int anio;
};

// Se esta utilizando un enum para definir el tipo de contacto
enum class TipoContacto
{
    URGENTE,
    RECORDATORIO,
    PERSONAL
};

// Se esta creando una clase Nota
class Nota
{
private:
    string descripcion;
    Fecha fecha;
    enum TipoContacto tipo;

public:
    Nota(string descripcion, Fecha fecha, TipoContacto tipo)
    {
        this->descripcion = descripcion;
        this->fecha = fecha;
        this->tipo = tipo;
    }

    // Getters y Setters
    string GetDescripcion()
    {
        return descripcion;
    }

    void SetDescripcion(string descripcion)
    {
        this->descripcion = descripcion;
    }

    Fecha GetFecha()
    {
        return fecha;
    }

    void SetFecha(Fecha fecha)
    {
        this->fecha = fecha;
    }

    TipoContacto GetTipo()
    {
        return tipo;
    }

    void SetTipo(TipoContacto tipo)
    {
        this->tipo = tipo;
    }
};

class Agenda
{
private:
    list<Nota> *notas_;

public:
    Agenda(list<Nota> *notas)
    {
        this->notas_ = notas;
    }

    void VerNotasUrgentes()
    {
        cout << "Notas urgentes:" << endl
             << endl;
        for (Nota &nota : *notas_)
        {
            if (nota.GetTipo() == TipoContacto::URGENTE)
            {
                cout << "Descripcion: " << nota.GetDescripcion() << endl;
                cout << "Fecha: " << nota.GetFecha().dia << "/" << nota.GetFecha().mes << "/" << nota.GetFecha().anio << endl
                     << endl;
            }
        }
    }

    void VerNotasRecordatorio()
    {
        cout << "Notas de recordatorio:" << endl
             << endl;
        for (Nota &nota : *notas_)
        {
            if (nota.GetTipo() == TipoContacto::RECORDATORIO)
            {
                cout << "Descripcion: " << nota.GetDescripcion() << endl;
                cout << "Fecha: " << nota.GetFecha().dia << "/" << nota.GetFecha().mes << "/" << nota.GetFecha().anio << endl;
            }
        }
    }

    void VerNotasPersonales()
    {
        cout << "Notas personales:" << endl
             << endl;
        for (Nota &nota : *notas_)
        {
            if (nota.GetTipo() == TipoContacto::PERSONAL)
            {
                cout << "Descripcion: " << nota.GetDescripcion() << endl;
                cout << "Fecha: " << nota.GetFecha().dia << "/" << nota.GetFecha().mes << "/" << nota.GetFecha().anio << endl;
            }
        }
    }

    void VerTodasLasNotas()
    {
        cout << "Todas las notas:" << endl
             << endl;
        for (Nota &nota : *notas_)
        {
            cout << "Descripcion: " << nota.GetDescripcion() << endl;
            cout << "Fecha: " << nota.GetFecha().dia << "/" << nota.GetFecha().mes << "/" << nota.GetFecha().anio << endl;
        }
    }

    int ContarNotasUrgentes()
    {
        int contador = 0;
        for (Nota &nota : *notas_)
        {
            if (nota.GetTipo() == TipoContacto::URGENTE)
            {
                contador++;
            }
        }
        return contador;
    }

    int ContarNotasRecordatorio()
    {
        int contador = 0;
        for (Nota &nota : *notas_)
        {
            if (nota.GetTipo() == TipoContacto::RECORDATORIO)
            {
                contador++;
            }
        }
        return contador;
    }

    int ContarNotasPersonales()
    {
        int contador = 0;
        for (Nota &nota : *notas_)
        {
            if (nota.GetTipo() == TipoContacto::PERSONAL)
            {
                contador++;
            }
        }
        return contador;
    }

    int ContarTodasLasNotas()
    {
        return notas_->size();
    }

    void VerNotasPorTipo(TipoContacto tipo)
    {
        switch (tipo)
        {
        case TipoContacto::URGENTE:
            VerNotasUrgentes();
            break;
        case TipoContacto::RECORDATORIO:
            VerNotasRecordatorio();
            break;
        case TipoContacto::PERSONAL:
            VerNotasPersonales();
            break;
        }
    }

    int ContarNotasPorTipo(TipoContacto tipo)
    {
        switch (tipo)
        {
        case TipoContacto::URGENTE:
            return ContarNotasUrgentes();
        case TipoContacto::RECORDATORIO:
            return ContarNotasRecordatorio();
        case TipoContacto::PERSONAL:
            return ContarNotasPersonales();
        }
        return 0;
    }

    string ObtenerDescripcionMasLarga()
    {
        string descripcionMasLarga = "";
        for (Nota &nota : *notas_)
        {
            if (nota.GetDescripcion().length() > descripcionMasLarga.length())
            {
                descripcionMasLarga = nota.GetDescripcion();
            }
        }
        return descripcionMasLarga;
    }

    string ObtenerPrimerNotaUrgente()
    {
        for (Nota &nota : *notas_)
        {
            if (nota.GetTipo() == TipoContacto::URGENTE)
            {
                return nota.GetDescripcion();
            }
        }
        return "no hay notas urgentes";
    }

    int ContarNotasPorFinDeSemana()
    {
        int contador = 0;
        for (Nota &nota : *notas_)
        {
            if (nota.GetFecha().dia % 7 == 0)
            {
                contador++;
            }
        }
        return contador;
    }
};

int main()
{
    list<Nota> notas;
    int cantidadNotas;

    string descripcion;
    Fecha fecha;
    // int dia, mes, anio;
    int tipo;

    /*fstream archivo;
    archivo.open("C://Users//LlanosJL70//OneDrive//Documentos//AUXILIATURA 2024//ING. MOLINA//data1//input.txt", ios::in);
    // string archivo = archivo.ate;
    string linea[27];*/

    // std::ifstream archivo("C://Users//LlanosJL70//OneDrive//Documentos//AUXILIATURA 2024//ING. MOLINA//data1//input.txt");
    ifstream archivo("C://Users//LlanosJL70//OneDrive//Documentos//AUXILIATURA 2024//ING. MOLINA//inputs//input5.txt");
    if (!archivo.is_open())
    {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    // int cantidadNotas;
    archivo >> cantidadNotas;

    // list<Nota> notas(cantidadNotas);

    for (int i = 0; i < cantidadNotas; i++)
    {
        // cout << "Nota " << i << endl;
        archivo >> fecha.dia;
        archivo >> fecha.mes;
        archivo >> fecha.anio;
        archivo >> descripcion;
        archivo >> tipo;

        Nota *nota = new Nota(descripcion, fecha, static_cast<TipoContacto>(tipo));
        notas.push_back(*nota);
    }

    Agenda agenda = Agenda(&notas);
    // agenda.VerNotasUrgentes();
    cout << "Contar notas urgentes: " << agenda.ContarNotasUrgentes() << endl;
    cout << "Contar notas recordatorio: " << agenda.ContarNotasRecordatorio() << endl;
    cout << "Contar notas personales: " << agenda.ContarNotasPersonales() << endl;
    cout << "Contar notas por tipo: " << agenda.ContarNotasPorTipo(TipoContacto::URGENTE) << endl;

    cout << "Contar todas las notas: " << agenda.ContarTodasLasNotas() << endl;
    cout << "Descripcion mas larga: " << agenda.ObtenerDescripcionMasLarga() << endl;
    cout << "Primer nota urgente: " << agenda.ObtenerPrimerNotaUrgente() << endl;

    cout << "Total de notas por fin de semana: " << agenda.ContarNotasPorFinDeSemana() << endl;
    archivo.close();

    // archivo.close();

    /*Fecha fecha1 = {1, 1, 2021};
    Nota *nota1 = new Nota("Comprar leche", fecha1, TipoContacto::URGENTE);

    notas.push_back(*nota1);
    Agenda agenda = Agenda(&notas);
    agenda.VerNotasUrgentes();*/
    return 0;
}
