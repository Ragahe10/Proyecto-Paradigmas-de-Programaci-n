#include "Trayecto.h"

int Trayecto::_autonumerico = 0;

Trayecto::Trayecto(string origen, string destino, int dias, float costo)
{
    _autonumerico++;
    _activo = true;
    _codigo = _autonumerico;
    _ciuedadOrigen = origen;
    _ciudadDestino = destino;
    _cantidadDeDias = dias;
    _costo = costo;
}

float Trayecto::GetCosto()
{
    return _costo;
}

bool Trayecto::EstaActivo()
{
    return _activo;
}

void Trayecto::Desactivar()
{
    _activo = false;
}

int Trayecto::GetCodigo()
{
    return _codigo;
}

int Trayecto::GetCantidadDias()
{
    return _cantidadDeDias;
}

void Trayecto::ListarInfo()
{
    cout<<"\t-Codigo trayecto: "<< _codigo<<endl;
    cout<<"\t-Origen: "<< _ciuedadOrigen <<endl;
    cout<<"\t-Destino: "<< _ciudadDestino <<endl;
    cout<<"\t-Cantidad de dias: "<< _cantidadDeDias <<endl;
    cout<<"\t-Precio unitario -----> $"<< _costo <<endl;
}

Trayecto::~Trayecto()
{
    
}