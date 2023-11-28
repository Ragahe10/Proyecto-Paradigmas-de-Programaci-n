#include "Agente.h"

int Agente::_autonumerico=0;

Agente::Agente(string nombre,string apellido)
{
    _autonumerico++;
    _codigo = _autonumerico;
    _nombre = nombre;
    _apellido = apellido;
}

int Agente::GetCodigo()
{
    return _codigo;
}

Agente::~Agente()
{
}
