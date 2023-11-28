#include "Paquete.cpp"

class Especial:public Paquete
{
private:
    static float _comision;
    vector<Contratacion*> _contrataciones;
    
public:
    Especial( vector<Contratacion*> contrataciones);
    float MontoAPagar(vector<Cliente*> clientes);
    string GetTipo();
    void ListarInfo(vector<Cliente*> clientes);
    ~Especial();
};



