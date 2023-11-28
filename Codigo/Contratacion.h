#include "Cliente.cpp"

class Cliente;

class Contratacion
{
private:
    static int _autonumerico;
    int _codigo;
public:
    Contratacion();
    virtual float GetMonto(vector<Cliente*> clientes) = 0;
    virtual void ListarInfo(vector<Cliente*> clientes);
    virtual ~Contratacion();
};



