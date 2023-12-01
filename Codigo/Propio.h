#ifndef PROPIO_H
#define PROPIO_H
#include "Trayecto.cpp"

class Propio : public Paquete
{
private:
    static float _comision;//AGREGAR UML
    string _destino;
    vector<Trayecto *> _trayectos;
    int _cantidadDias;
    Fecha _salida;
    int _cupoMax;
    int _cupoRestante;
    float _descuento;
public:
    Propio(string destino, vector<Trayecto *> trayectos, Fecha salida, int cupo, float descuento);
    float MontoAPagar(vector<Cliente *> clientes);
    string GetTipo();
    float GetComision();//AGREAR uml
    void ListarInfo(vector<Cliente *> clientes);
    bool HayCupo(int CantClientes);
    void ActualizarCupo(int cantClientes);
    ~Propio();
};

#endif