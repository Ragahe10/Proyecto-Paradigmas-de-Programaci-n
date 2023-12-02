#include "Sistema.h"

Sistema::Sistema(vector<Paquete *> paquetes, vector<Agente *> agentes, vector<Trayecto *> trayecto)
{
    _paquetes = paquetes;
    _agentes = agentes;
    _trayectos = trayecto;
}

//----- Metodos para trayectos -----//

Trayecto *Sistema::buscarTrayecto(int codTrayecto)
{
    for (Trayecto *T : _trayectos)
    {
        if (T->GetCodigo() == codTrayecto)
            return T;
    }
    return nullptr;
}

void Sistema::AltaTrayecto(string origen, string destino, int dias, float costo)
{
    Trayecto *trayecto = new Trayecto(origen, destino, dias, costo);
    _trayectos.push_back(trayecto);
}

void Sistema::BajaTrayecto(int codTrayecto)
{
    Trayecto *trayecto = buscarTrayecto(codTrayecto);
    if (trayecto)
        trayecto->Desactivar();
}

//----- Metodo para paquetes -----//

Paquete *Sistema::buscarPaquete(int codPaquete)
{
    for (Paquete *P : _paquetes)
    {
        if (P->GetCodigo() == codPaquete)
            return P;
    }
    return nullptr;
}

void Sistema::AltaPaqueteEspecial(vector<Contratacion *> contrataciones)
{
    Especial *paquete = new Especial(contrataciones);
    _paquetes.push_back(paquete);
}

void Sistema::AltaPaquetePropio(string destino, vector<int> codigoTrayectos, Fecha salida, int cupo, float descuento)
{
    vector<Trayecto *> trayectos;

    for (int i = 0; i < (int)codigoTrayectos.size(); i++)
    {
        Trayecto *trayectoBuscado = buscarTrayecto(codigoTrayectos[i]);
        if (trayectoBuscado && trayectoBuscado->EstaActivo())
            trayectos.push_back(trayectoBuscado);
    }

    Propio *paquete = new Propio(destino, trayectos, salida, cupo, descuento);

    _paquetes.push_back(paquete);
}

void Sistema::BajaPaquete(int codPaquete)
{
    Paquete *paquete = buscarPaquete(codPaquete);
    if (paquete)
        paquete->Desactivar();
}

//------ Metodos de Agente -----//
Agente *Sistema::buscarAgente(int codAgente)
{
    for (Agente *A : _agentes)
    {
        if (A->GetCodigo() == codAgente)
            return A;
    }
    return nullptr;
}

void Sistema::AltaAgente(string nombre, string apellido)
{
    Agente *nuevoAgente = new Agente(nombre, apellido);
    _agentes.push_back(nuevoAgente);
}

void Sistema::BajaAgente(int codAgente)
{
    Agente *agente = buscarAgente(codAgente);
    if (agente)
        agente->Desactivar();
}

float Sistema::BonificacionAgente(int codAgente, int mes, int year)
{
    Agente *agente = buscarAgente(codAgente);
    if (!agente || !agente->EstaActivo())
        return 0;
    return agente->GetBonificacion(mes, year);
}

//----- Metodos para reservas -----//

Reserva *Sistema::buscarReserva(int codReserva)
{
    for (Reserva *R : _reservas)
    {
        if (R->GetCodigo() == codReserva)
            return R;
    }
    return nullptr;
}

void Sistema::RealizarReserva(int codAgente, int codPaquete, vector<Cliente *> clientes, Fecha caduca)
{
    Paquete *paquete = buscarPaquete(codPaquete);
    Agente *agente = buscarAgente(codAgente);

    if (paquete && paquete->EstaActivo() && paquete->HayCupo(clientes.size()) && agente && agente->EstaActivo())
    {
        Reserva *nuevaReserva = new Reserva(agente, paquete, clientes, caduca);
        agente->AgregarReserva(nuevaReserva);
        _reservas.push_back(nuevaReserva);
    }
}

void Sistema::AgregarClientesReserva(vector<Cliente *> clientes, int codReserva)
{
    Reserva *reserva = buscarReserva(codReserva);

    if (reserva && reserva->EstaVigente() && reserva->HayCupo(clientes.size()))
    {
        for (Cliente *C : clientes)
        {
            reserva->AgregarCliente(C);
        }
    }
}

void Sistema::PagarReserva(float monto, int codReserva) // Charlar para mejorarlo
{
    Fecha fechaActual;
    Reserva *reserva = buscarReserva(codReserva);

    if (reserva)
    {
        if (reserva->EstaVigente())
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
    else
    {
        cout << "No existe reserva" << endl;
    }
}

bool Sistema::CancelarReserva(int codReserva)
{
    for (auto it = _reservas.begin(); it != _reservas.end(); it++)
    {
        if ((*it)->GetCodigo() == codReserva)
        {
            int cantidadClientes = (*it)->GetCantidadClientes();
            (*it)->ActualizarCupo(-cantidadClientes);
            it = _reservas.erase(it);
            return true;
        }
    }
    return false;
}

void Sistema::EliminarReservasVencidas()
{
    for (Reserva *R : _reservas)
    {
        if (!R->EstaVigente())
            CancelarReserva(R->GetCodigo());
    }
}

void Sistema::ListarInfoReserva(Reserva *reserva)
{
    cout << "\n***** ---------- _ _ _ Informacion Reserva _ _ _ ---------- *****" << endl;
    reserva->GetAgente()->ListarInfo();
    reserva->ListarInfo();
}

void Sistema::ListarReservas()
{
    for(Reserva * R : _reservas)
    {
        ListarInfoReserva(R);
    }
}

void Sistema::InfoReservaByCodigo(int codReserva)
{
    Reserva * R = buscarReserva(codReserva);

    if (R)
    {
        ListarInfoReserva(R);
    }else
    {
        cout<<"No existe reserva"<<endl;
    }    
}

int Sistema::GetCantidadReservas()
{
    return _reservas.size();
}

// Modificar UML
float Sistema::RecudacionMensual(int mes, int anio)
{
    float totalMes = 0;
    for (Reserva *R : _reservas)
    {
        if (R->GetConfirmacion() && (R->GetFechaReserva().getMes() == mes && R->GetFechaReserva().getAnio() == anio))
            totalMes += R->GetGanancia();
    }
    return totalMes;
}

Sistema::~Sistema()
{

    for (Trayecto *T : _trayectos)
    {
        delete T;
    }

    for (Agente *A : _agentes)
    {
        delete A;
    }

    for (Paquete *P : _paquetes)
    {
        delete P;
    }

    for (Reserva *R : _reservas)
    {
        delete R;
    }
}
