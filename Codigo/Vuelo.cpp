#include "Vuelo.h"

Vuelo::Vuelo(string linea, string operador, Fecha salida, Fecha llegada, Hora hSalida, Hora hLlegada, float menor, float adulto) : Contratacion(), _fSalida(salida), _fLlegada(llegada), _hSalida(hLlegada), _hLlegada(hLlegada)
{
    _linea = linea;
    _operador = operador;
    _tarifaMenor = menor;
    _tarifaAdulto = adulto;
}

float Vuelo::GetMonto(vector<Cliente *> clientes)
{
    float monto = 0;
    for (Cliente *cli : clientes)
    {
        if (cli->GetEdad() < 18)
        {
            monto += _tarifaMenor;
        }
        else
        {
            monto += _tarifaAdulto;
        }
    }
    return monto;
}

void Vuelo::ListarInfo(vector<Cliente*> clientes)
{
    Contratacion::ListarInfo(clientes);
    cout << "\t-AeroLinea: " << _linea << endl;
    cout << "\t-Operador: " << _operador << endl;
    cout << "\t-Fecha salida: " << _fSalida << endl;
    cout << "\t-Fecha llegada: " << _fLlegada << endl;
    cout << "\t-Hora salida: " << _hSalida << endl;
    cout << "\t-Hora llegada: " << _hLlegada << endl;
    cout << "\t-Precio -----> $" << GetMonto(clientes)<< endl;

}

Vuelo::~Vuelo()
{
}