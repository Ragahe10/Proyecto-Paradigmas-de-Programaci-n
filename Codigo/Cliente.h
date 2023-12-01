#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <vector>
#include "Fecha.cpp"
#include "Hora.cpp"
using namespace std;

class Cliente
{
private:
    string _nombre;
    string _apellido;
    int _dni;
    Fecha _nacimiento;
    string _pasaporte;
public:
    Cliente(string nombre,string apellido,int dni, Fecha nacimiento, string pasaporte);
    void ListarInfo();
    int GetEdad();
    ~Cliente();
};

#endif
