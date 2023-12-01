#ifndef RESERVA_H
#define RESERVA_H
#include "Propio.cpp"

class Agente;

class Reserva
{
private:
    static int autonumerico;
    int _codigo;
    Paquete *_paquete;
    Fecha _reserva;
    Fecha _caducaReserva;
    bool _confirmacion;
    float _montoPagado;
    vector<Cliente *> _clientes;
    Agente *_agente;

public:
    Reserva(Agente *agente, Paquete *paquete, vector<Cliente *> clientes, Fecha caduca);
    float MontoSenia();
    float MontoTotalPaquete();
    float GetGanancia(); //agregar a UML
    int GetCodigo();
    float PagarReserva(float monto);
    void AgregarCliente(Cliente *cliente);
    int GetCantidadClientes();
    Fecha GetFechaReserva();
    //int GetCodigoAgente();
    Fecha GetFechaCaduca();
    void ListarInfo();
    bool EstaVigente();
    bool GetConfirmacion(); // Verifica si la reserva fue pagada
    bool HayCupo(int cantClientes);
    void ActualizarCupo(int cantClientes);
    int GetCodigoPaquete();
    string GetTipo();
    Agente * GetAgente();
    ~Reserva();
};

int Reserva::GetCodigoPaquete()
{
    return _paquete->GetCodigo();
}

Agente * Reserva::GetAgente()
{
    return _agente;
}



#endif 