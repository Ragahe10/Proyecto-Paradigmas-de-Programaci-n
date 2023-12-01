#ifndef TRAYECTO_H
#define TRAYECTO_H
#include "Especial.cpp"

class Trayecto
{
private:
    static int _autonumerico;
    int _codigo;
    bool _activo;
    string _ciuedadOrigen;
    string _ciudadDestino;
    int _cantidadDeDias;
    float _costo;

public:
    Trayecto(string origen, string destino, int dias, float costo);
    int GetCodigo();
    float GetCosto();
    int GetCantidadDias();
    void ListarInfo();
    bool EstaActivo();
    void Desactivar();
    ~Trayecto();
};

#endif






