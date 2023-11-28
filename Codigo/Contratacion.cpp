#include "Contratacion.h"

int Contratacion::_autonumerico = 0;

Contratacion::Contratacion()
{
    _autonumerico++;
    _codigo = _autonumerico;
}

void Contratacion::ListarInfo(vector<Cliente*> clientes)
{
    cout<<"\t-Codigo contratacion: "<< _codigo<<endl;
}

Contratacion::~Contratacion()
{
}