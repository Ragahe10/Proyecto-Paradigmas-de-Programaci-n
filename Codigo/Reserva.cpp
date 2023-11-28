#include "Reserva.h"

int Reserva::autonumerico = 0;

Reserva::Reserva(Agente *agente,Paquete *paquete,vector<Cliente *> clientes,Fecha caduca): 
_reserva(Fecha()), _caducaReserva(caduca)
{
    autonumerico++;
    _codigo = autonumerico;
    _paquete = paquete;
    _montoPagado = 0;
    _confirmacion = false;
    _clientes = clientes;
    _agente = agente;
}

float Reserva::MontoSenia()
{
    return _paquete->MontoAPagar(_clientes) * 0.30;
}

float Reserva::MontoTotalPaquete()
{
    return _paquete->MontoAPagar(_clientes);
}

int Reserva::GetCodigo()
{
    return _codigo;
}

float Reserva::PagarReserva(float monto)
{

    if (monto >= MontoSenia() && _montoPagado == 0)
    {
        _montoPagado = monto; // Pago de seña
    }
    else
    {
        if (_montoPagado == 0)
        {
            return -1; // No le alcanza para seañar
        }
        else
        {
            _montoPagado += monto; // Ya pago la seña. Ahora paga un monto del resto del saldo o el saldo completo.
        }
    }
    return MontoTotalPaquete() - _montoPagado; // le decimos cuando talta pagar
}

bool Reserva::GetConfirmacion()
{
    if (MontoTotalPaquete() <= _montoPagado)
    {
        _confirmacion = true;
    }
    return _confirmacion;
}


void Reserva::AgregarCliente(Cliente *cliente)
{
    _clientes.push_back(cliente);   
}



Fecha Reserva::GetFechaReserva()
{
    return _reserva;
}


Agente * Reserva::GetAgente()
{
    return _agente;
}

Paquete * Reserva::GetPaquete()
{
    return _paquete;
}

Fecha Reserva::GetFechaCaduca()
{
    return _caducaReserva;
}

void Reserva::ListarInfo()
{
    cout<<"---------- Informacio Reserva ----------"<<endl;
    cout<<"-Codigo Reserva: "<<_codigo<<endl;
    cout<<"-Fecha: "<< _reserva <<endl;
    cout<<"-Agente: "<<endl;
    _agente->ListarInfo();
    cout<<"\n";
    _paquete->ListarInfo(_clientes);
    cout<<"\n";
    cout<<"-Listado de Pasajeros:"<<endl;
    for (Cliente * cli : _clientes)
    {
        cli->ListarInfo();
        cout<<"\n";
    }
    cout<<"-Fecha caducidad: "<<_caducaReserva<<endl;
    cout<<"-Monto senia minima         ------>$"<< MontoSenia()<<endl;
    cout<<"-Monto pagado               ------>$"<<_montoPagado<<endl;
    cout<<"-Faltante senia minima      ------>$"<< MontoSenia() - _montoPagado<<endl;
    cout<<"-Faltante confirmar reserva ------>$"<< MontoTotalPaquete() - _montoPagado<<endl;
    cout<<"_ ----- ------ ------ ------ ----- ------ ------ ------ ------ _"<<endl;
}

Reserva::~Reserva()
{
}