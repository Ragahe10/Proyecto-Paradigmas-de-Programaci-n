#include "Cliente.h"

Cliente::Cliente(string nombre,string apellido,int dni, Fecha nacimiento, string pasaporte):_nacimiento(nacimiento)
{
    _nombre=nombre;
    _apellido = apellido;
    _dni = dni;
    _pasaporte = pasaporte;
}

int Cliente::GetEdad()
{
    Fecha fechaActual;
    int edad = fechaActual.getAnio() - _nacimiento.getAnio();
    if (_nacimiento.getMes() < fechaActual.getMes() || ( _nacimiento.getMes() == fechaActual.getMes() && _nacimiento.getDia() < fechaActual.getDia())) 
    {
        edad--;
    }
    return edad;
}

void Cliente::ListarInfo()
{
    cout<<"\t-Nombre completo: "<<_nombre<<_apellido<<endl;
    cout<<"\t-DNI: "<< _dni<< endl ;
    cout<<"\t-Fecha nacimiento: "<<_nacimiento<<endl;
    cout<<"\t-Pasaporte:"<<_pasaporte<<endl;
}

Cliente::~Cliente()
{
}
