#include "Trayecto.cpp"

class Propio : public Paquete
{
private:
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
    void ListarInfo(vector<Cliente *> clientes);
    bool HayCupo(int CantClientes);
    void ActualizarCupo(int cantClientes);
    ~Propio();
};
