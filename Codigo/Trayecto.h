#include "Especial.cpp"

class Trayecto
{
private:
    static int _autonumerico;
    int _codigo;
    string _ciuedadOrigen;
    string _ciudadDestino;
    int _cantidadDeDias;
    float _costo;

public:
    Trayecto(string origen, string destino, int dias, float costo);
    float GetCosto();
    int GetCantidadDias();
    void ListarInfo();
    ~Trayecto();
};






