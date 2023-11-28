#include "Sistema.h"

Paquete *Sistema::buscarPaquete(int codPaquete)
{
    for (Paquete *P : _paquetes)
    {
        if (P->GetCodigo() == codPaquete)
        {
            return P;
        }
    }
    return nullptr;
}

Reserva *Sistema::buscarReserva(int codReserva)
{
    for (Reserva *R : _reservas)
    {
        if (R->GetCodigo() == codReserva)
        {
            return R;
        }
    }

    return nullptr;
}

Sistema::Sistema(vector<Paquete *> paquetes)
{
    _paquetes = paquetes;
}

void Sistema::RealizarReserva(Agente *agente, int codPaquete, vector<Cliente *> clientes, Fecha caduca)
{
    Paquete *paquete = buscarPaquete(codPaquete);

    if (paquete && paquete->HayCupo(clientes.size()))//preguntar si mostrar los mensajes 
    {
        Reserva *nuevaReserva = new Reserva(agente, paquete, clientes, caduca);
        _reservas.push_back(nuevaReserva);
    }
}

void Sistema::PagarReserva(float monto, int codReserva)
{
    Fecha fechaActual;
    Reserva *reserva = buscarReserva(codReserva);

    if (reserva->EstaActiva())
    {
        float saldo = reserva->PagarReserva(monto);

        if (saldo == -1)
        {
            cout << "Monto insuficiente para realizar seña" << endl;
        }
        else
        {
            cout << "Saldo restante para confirmar reserva:" << saldo << endl;
        }
    }
    else
    {
        cout << "La reserva Caduco el dia:" << reserva->GetFechaCaduca() << endl;
    }

}

void Sistema::AgregarClientesReserva(vector<Cliente *> clientes, int codReserva)
{
    Reserva *reserva = buscarReserva(codReserva);

    if (reserva && reserva->EstaActiva()  && reserva->GetPaquete()->HayCupo(clientes.size()))
    {
        for (Cliente *C : clientes)
        {
            reserva->AgregarCliente(C);
        }
    }
}

bool Sistema::CancelarReserva(int codReserva)
{

    for (auto it = _reservas.begin(); it != _reservas.end(); it++)
    {
        if ((*it)->GetCodigo() == codReserva)
        {
            int cantClientesReserva = (*it)->GetCantidadClientes();
            (*it)->GetPaquete()->ActualizarCupo(-cantClientesReserva);
            it = _reservas.erase(it);
            return true;
        }
    }
    return false;
}

float Sistema::RecudacionMensual(int mes, int anio)
{
    float totalMes = 0;
    for (Reserva *R : _reservas)
    {
        if (R->GetConfirmacion() && (R->GetFechaReserva().getMes() == mes && R->GetFechaReserva().getAnio() == anio))
        {
            if (R->GetPaquete()->GetTipo() == "Propio")
            {
                totalMes += R->MontoTotalPaquete()*0.15;
            }else
            {
                totalMes += R->MontoTotalPaquete()*0.30;
            }
        }
    }
    return totalMes;
}

float Sistema::BonificacionAgente(int codAgente)
{
    float comision = 0;
    for (Reserva * R: _reservas)
    {
        if (R->GetConfirmacion() && R->GetCodigoAgente() == codAgente)
        {
            comision += R->MontoTotalPaquete()*0.1;
        }
    }
    return comision;
}

void Sistema::ListaInfoReservaByCodigo(int codReserva)
{
    Reserva * reserva = buscarReserva(codReserva);
    if (reserva)
    {
       reserva->ListarInfo(); 
    }else
    {
        cout<<"NO SE ENCONTRO RESERVA"<<endl;
    }
}

void Sistema::EliminarReservasVencidas()
{
    for (Reserva * R : _reservas)
    {
        if (!R->EstaActiva())
        {
            CancelarReserva(R->GetCodigo());
        }
    } 
}

int Sistema::GetCantidadReservas()
{
    return _reservas.size();
}

Sistema::~Sistema()
{
    for (Reserva * R : _reservas)
    {
        delete R;
    }
}
