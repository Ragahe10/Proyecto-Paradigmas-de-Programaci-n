#include "Paquete.h"

int Paquete::_autonumerico = 0;

Paquete::Paquete()
{
    _autonumerico++;
    _codigo = _autonumerico;
}

int Paquete::GetCodigo()
{
    return _codigo;
}

void Paquete::ListarInfo(vector<Cliente*> clientes)
{
    cout << "***** Informacion Paquete ******" << endl;
    cout << "-Codigo paquete: " << _codigo << endl;
}

bool Paquete::HayCupo(int CantClientes)
{
    return true;
}

void Paquete::ActualizarCupo(int cantClientes){ }

Paquete::~Paquete()
{
}
