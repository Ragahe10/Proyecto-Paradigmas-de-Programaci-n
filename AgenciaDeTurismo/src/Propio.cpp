#include "Propio.h"

float Propio::_comision = 0.15;

Propio::Propio(string destino, vector<Trayecto *> trayectos, Fecha salida, int cupo, float descuento) : Paquete(),_cantidadDias(0)
{
    _destino = destino;
    _trayectos = trayectos;
    _salida = salida;
    _cupoMax = cupo;
    _cupoRestante = cupo;
    _descuento = descuento;
    for (Trayecto * T : trayectos)
    {
        _cantidadDias += T->GetCantidadDias();
    }
}

float Propio::MontoAPagar(vector<Cliente *> clientes)
{
    float monto = 0;
    for (Trayecto *T : _trayectos)
    {
        monto += T->GetCosto();
    }
    monto *= clientes.size();

    monto -= monto * _descuento;

    return monto;
}

string Propio::GetTipo()
{
    return "Propio";
}

void Propio::ActualizarCupo(int cantClientes)
{
    _cupoRestante -= cantClientes;
}

bool Propio::HayCupo(int CantClientes)
{
    bool cupoDisponible = false;
    if (_cupoRestante >= CantClientes)
    {
        cupoDisponible = true;
        ActualizarCupo(CantClientes);
    }
    return cupoDisponible;
}

float Propio::GetComision()
{
    return _comision;
}

void Propio::ListarInfo(vector<Cliente *> clientes)
{
    Paquete::ListarInfo(clientes);
    cout << "-Destino: " << _destino << endl;
    cout << "-Cupo Maximo: " << _cupoMax << endl;
    cout << "-Cupo Restante: "<< _cupoRestante<< endl;
    cout << "-Fecha de salida: " << _salida << endl;
    cout << "-Trayectos: " << endl;
    for (Trayecto *T : _trayectos)
    {
        T->ListarInfo();
        cout << "\n";
    }
    cout << "-Total de dias: " << _cantidadDias << endl;
    cout << "-Total a pagar -----> $" << MontoAPagar(clientes) << endl;
    cout << "***** ****** ****** ****** *****" << endl;
}

Propio::~Propio()
{
}
