#include "Hotel.h"

Hotel::Hotel(string nombre, string ubicacion, Fecha checkIn, Fecha checkOut, float precio) : Contratacion(), _check_in(checkIn), _check_out(checkOut)
{
    _nombre = nombre;
    _ubicacion = ubicacion;
    _cantidadNoches = checkOut - checkIn;
    _precioNoche = precio;
}

float Hotel::GetMonto(vector<Cliente *> clientes)
{
    return _cantidadNoches * _precioNoche * clientes.size();
}

void Hotel::ListarInfo(vector<Cliente*> clientes)
{
    Contratacion::ListarInfo(clientes);
    cout << "\t-Hotel: " << _nombre << endl;
    cout << "\t-Ubicacion: " << _ubicacion << endl;
    cout << "\t-Fecha de llegada: " << _check_in << endl;
    cout << "\t-Fecha de salida: " << _check_out << endl;
    cout << "\t-Cantidad de noches: " << _cantidadNoches << endl;
    cout << "\t-Precio -----> $" << GetMonto(clientes) << endl;
}

Hotel::~Hotel()
{
}