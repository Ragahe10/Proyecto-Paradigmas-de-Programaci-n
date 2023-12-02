#ifndef SISTEMA_H
#define SISTEMA_H
#include "Agente.h"

class Sistema
{
private:
    vector<Trayecto *> _trayectos;
    vector<Agente *> _agentes;
    vector<Paquete *> _paquetes;
    vector<Reserva *> _reservas;

    Trayecto *buscarTrayecto(int codTrayecto);
    Paquete *buscarPaquete(int codPaquete);
    Reserva *buscarReserva(int codReserva);
    Agente *buscarAgente(int codAgente);

    void ListarInfoReserva(Reserva * reserva);

public:
    Sistema(vector<Paquete *> paquetes, vector<Agente *> agentes, vector<Trayecto *> trayecto);

    //----- Metodos para administrar trayectos ------//
    void AltaTrayecto(string origen, string destino, int dias, float costo);
    void BajaTrayecto(int codTrayecto);

    //----- Metodos para administrar los agentes ------//
    void AltaAgente(string nombre, string apellido);
    void BajaAgente(int codAgente);
    float BonificacionAgente(int codAgente, int mes, int year);


    //----- Metodos para administrar paquetes ------//
    void AltaPaquetePropio(string destino, vector<int> codigoTrayectos, Fecha salida, int cupo, float descuento);
    void AltaPaqueteEspecial(vector<Contratacion *> contrataciones);
    void BajaPaquete(int codPaquete);

    //----- Metodos Para administras las reserva -----//
    void RealizarReserva(int codAgente, int codPaquete, vector<Cliente *> clientes, Fecha caduca); // pasar id agente
    void AgregarClientesReserva(vector<Cliente *> clientes, int codReserva);
    void PagarReserva(float monto, int codReserva);
    bool CancelarReserva(int codReserva);
    void ListarReservas();
    void InfoReservaByCodigo(int codReserva);
    void EliminarReservasVencidas();
    int GetCantidadReservas();

    float RecudacionMensual(int mes, int anio);
    
    ~Sistema();
};





#endif
