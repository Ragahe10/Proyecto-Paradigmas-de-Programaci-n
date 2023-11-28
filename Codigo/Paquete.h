#include "Vuelo.cpp"

class Paquete
{
private:
    static int _autonumerico;
    int _codigo;
public:
    Paquete();
    int GetCodigo();
    virtual float MontoAPagar(vector<Cliente *> clientes) = 0;
    virtual string GetTipo() = 0;
    virtual void ListarInfo(vector<Cliente*> clientes);
    virtual bool HayCupo(int CantClientes);  
    virtual void ActualizarCupo(int cantClientes);
    virtual ~Paquete();
};
