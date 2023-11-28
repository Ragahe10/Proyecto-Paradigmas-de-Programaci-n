#include "Especial.h"

float Especial::_comision = 0.3;

Especial::Especial(vector<Contratacion *> contrataciones)
{
    _contrataciones = contrataciones;
}

float Especial::MontoAPagar(vector<Cliente *> clientes)
{
    float monto = 0;
    for (Contratacion *contra : _contrataciones)
    {
        monto += contra->GetMonto(clientes);
    }
    monto = monto + monto * _comision;
    return monto;
}

string Especial::GetTipo()
{
    return "Especial";
}

bool Especial::HayCupo(int CantClientes)
{
    return true;
}

void Especial::ListarInfo(vector<Cliente *> clientes)
{
    Paquete::ListarInfo(clientes);
    cout << "-Contrataciones: " << endl;
    for (Contratacion *contr : _contrataciones)
    {
        contr->ListarInfo(clientes);
        cout << "\n";
    }
    cout << "Total a pagar -----> $" << MontoAPagar(clientes) << endl;
    cout << "***** ****** ****** ****** *****" << endl;
}

Especial::~Especial()
{
}
