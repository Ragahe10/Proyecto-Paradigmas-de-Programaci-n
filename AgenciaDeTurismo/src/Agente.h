#ifndef AGENTE_H
#define AGENTE_H
#include "Reserva.h"


class Agente
{
private:
    static int _autonumerico;
    bool _activo;
    int _codigo;
    string _nombre;
    string _apellido;
    vector<Reserva *> _reservas;
public:
    Agente(string nombre,string apellido);
    bool EstaActivo();
    void Desactivar();
    int GetCodigo();
    void ListarInfo();
    float GetBonificacion(int mes, int year);
    void AgregarReserva(Reserva * reserva);
    ~Agente();
};



#endif







