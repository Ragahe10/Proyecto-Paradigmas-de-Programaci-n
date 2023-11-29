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
    Reserva(Agente *agente, Paquete *paquete, vector<Cliente *> clientes, Fecha caduca);
    float MontoSenia();
    float MontoTotalPaquete();
    int GetCodigo();
    float PagarReserva(float monto);
    void AgregarCliente(Cliente *cliente);
    int GetCantidadClientes();
    Fecha GetFechaReserva();
    int GetCodigoAgente();
    Fecha GetFechaCaduca();
    void ListarInfo();
    bool EstaActiva();
    bool GetConfirmacion(); // Verifica si la reserva fue pagada
    bool HayCupo(int cantClientes);
    void ActualizarCupo(int cantClientes);
    string GetTipo();
    ~Reserva();
};

