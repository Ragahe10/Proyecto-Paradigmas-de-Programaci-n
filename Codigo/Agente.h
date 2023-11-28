#include "Propio.cpp"

class Agente
{
private:
    static int _autonumerico;
    int _codigo;
    string _nombre;
    string _apellido;
public:
    Agente(string nombre,string apellido);
    int GetCodigo();
    void ListarInfo();
    ~Agente();
};

void Agente::ListarInfo()
{
    cout<<"\t-Codigo agente:"<<_codigo<<endl;
    cout<<"\t-Nombre: "<< _nombre <<_apellido<<endl;
}


