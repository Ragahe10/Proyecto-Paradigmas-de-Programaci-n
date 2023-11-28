#include "Contratacion.cpp"

class Hotel : public Contratacion
{
private:
    string _nombre;
    string _ubicacion;
    Fecha _check_in;
    Fecha _check_out;
    int _cantidadNoches;
    float _precio;
public:
    Hotel(string nombre, string ubicacion, Fecha checkIn, Fecha checkOut,float precio);
    float GetMonto(vector<Cliente*> clientes);
    void ListarInfo(vector<Cliente*> clientes);
    ~Hotel();
};








