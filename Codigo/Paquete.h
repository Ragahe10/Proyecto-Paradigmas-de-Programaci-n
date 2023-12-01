#ifndef PAQUETE_H
#define PAQUETE_H
#include "Vuelo.cpp"

class Paquete
{
private:
    static int _autonumerico;
    int _codigo;
    bool _activo;
public:
    Paquete();
    int GetCodigo();
    bool EstaActivo();
    void Desactivar();
    virtual float MontoAPagar(vector<Cliente *> clientes) = 0;
    virtual string GetTipo() = 0;
    virtual float GetComision() = 0;//agregarAUML;
    virtual void ListarInfo(vector<Cliente*> clientes);
    virtual bool HayCupo(int CantClientes);  
    virtual void ActualizarCupo(int cantClientes);
    virtual ~Paquete();
};



#endif