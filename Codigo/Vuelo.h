#ifndef VUELO_H
#define VUELO_H
#include "Hotel.cpp"

class Vuelo : public Contratacion
{
private:
    string _linea;
    string _operador;
    Fecha _fSalida;
    Fecha _fLlegada;
    Hora _hSalida;
    Hora _hLlegada;
    float _tarifaMenor;
    float _tarifaAdulto;

public:
    Vuelo(string linea, string operador, Fecha salida, Fecha llegada, Hora hSalida, Hora hLlegada, float menor, float adulto);
    float GetMonto(vector<Cliente *> clientes);
    void ListarInfo(vector<Cliente*> clientes);
    ~Vuelo();
};

#endif
