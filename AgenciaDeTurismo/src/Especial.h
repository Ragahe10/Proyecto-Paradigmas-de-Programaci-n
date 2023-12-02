#ifndef ESPECIAL_H
#define ESPECIAL_H
#include "Paquete.h"

class Especial:public Paquete
{
private:
    static float _comision; //agregar UML
    vector<Contratacion*> _contrataciones;
    
public:
    Especial(vector<Contratacion*> contrataciones);
    float MontoAPagar(vector<Cliente*> clientes);
    string GetTipo();
    void ListarInfo(vector<Cliente*> clientes);
    float GetComision();//agregar
    ~Especial();
};
#endif



