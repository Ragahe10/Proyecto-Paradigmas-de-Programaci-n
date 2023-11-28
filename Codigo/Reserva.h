#include "Agente.cpp"

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
    Reserva(Agente *agente,Paquete *paquete,vector<Cliente *> clientes,Fecha caduca);
    int GetCodigo();
    float MontoSenia();
    float MontoTotalPaquete(); 
    float PagarReserva(float monto);
    bool GetConfirmacion(); // Verifica si la reserva fue pagada
    void AgregarCliente(Cliente * cliente);
    int GetCantidadClientes();
    Fecha GetFechaReserva();
    Fecha GetFechaCaduca();
    bool EstaActiva();
    Agente * GetAgente();
    Paquete * GetPaquete();
    void ListarInfo();
    ~Reserva();
};



