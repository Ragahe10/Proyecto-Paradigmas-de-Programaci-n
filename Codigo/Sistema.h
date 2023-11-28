#include "Reserva.cpp"

class Sistema
{
private:
    vector<Paquete *> _paquetes;
    vector<Reserva *> _reservas;
    Paquete *buscarPaquete(int codPaquete);
    Reserva *buscarReserva(int codReserva);
    //consultar si el listado de agente lo ponemos aquí 
public:
    Sistema(vector<Paquete *> paquetes);
    void RealizarReserva(Agente *agente, int codPaquete, vector<Cliente *> clientes, Fecha caduca);
    void PagarReserva(float monto, int codReserva);
    void AgregarClientesReserva(vector<Cliente *> clientes, int codReserva);
    bool CancelarReserva(int codReserva);
    float RecudacionMensual(int mes, int anio);
    float BonificacionAgente(int codAgente);
    void ListaInfoReservaByCodigo(int codReserva);
    void EliminarReservasVencidas();
    int CantidadReservas();
    ~Sistema();
};

