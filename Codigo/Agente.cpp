#include "Agente.h"

int Agente::_autonumerico = 0;

Agente::Agente(string nombre, string apellido)
{
    _autonumerico++;
    _codigo = _autonumerico;
    _activo = true;
    _nombre = nombre;
    _apellido = apellido;
}

int Agente::GetCodigo()
{
    return _codigo;
}

void Agente::ListarInfo()
{
    cout << "-Agente: " << endl;
    cout << "\t-Codigo agente: " << _codigo << endl;
    cout << "\t-Nombre: " << _nombre << " " << _apellido << endl;
}

float Agente::GetBonificacion(int mes, int anio)
{
    float bonificacion = 0;
    for (Reserva *R : _reservas)
    {
        if (R->GetConfirmacion() && R->GetFechaReserva().getMes() == mes && R->GetFechaReserva().getAnio() == anio)
        {
            bonificacion += R->MontoTotalPaquete() * 0.1;
        }
    }
    return bonificacion;
}

void Agente::AgregarReserva(Reserva *reserva)
{
    _reservas.push_back(reserva);
}

bool Agente::EstaActivo()
{
    return _activo;
}

void Agente::Desactivar()
{
    _activo = false;
}

Agente::~Agente()
{
}
