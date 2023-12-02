//============================================================================
// Name        : AgenciaDeTurismo.cpp
// Author      : RamiroHerrera
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Sistema.h"

int main()
{
    // Agentes:
    Agente Lucas("Lucas", "Alarcon");
    Agente Martin("Martin", "Catan");

    vector<Agente *> agentes;
    agentes.push_back(&Lucas);
    agentes.push_back(&Martin);

    // Clientes:
    Cliente JuanRuiz("Juan", "Ruiz", 111222, Fecha(1, 1, 2000), "123456");
    Cliente GuilloValle("Guillermo", "Valle", 222333, Fecha(1, 2, 2000), "321654");
    Cliente EnzoP("Enzo", "Peralta", 333444, Fecha(1, 3, 2000), "456789");
    Cliente NicoP("Nico", "Peralta", 333444, Fecha(1, 4, 2000), "123456");

    vector<Cliente *> clientes;
    clientes.push_back(&JuanRuiz);
    clientes.push_back(&GuilloValle);
    clientes.push_back(&EnzoP);

    vector<Cliente *> nuevosCli;
    nuevosCli.push_back(&NicoP);

    // Trayectos
    Trayecto trayecto1("Tucuman", "Cordoba", 3, 1500);
    Trayecto trayecto2("Cordoba", "Bs.As", 3, 1000);
    Trayecto trayecto3("Bs.As", "Bariloche", 3, 1800);

    vector<Trayecto *> trayectos;
    trayectos.push_back(&trayecto1);
    trayectos.push_back(&trayecto2);
    trayectos.push_back(&trayecto3);

    // Contrataciones
    Hotel LasSierras("Los Sierras", "Cordoba", Fecha(1, 1, 2024), Fecha(15, 1, 2024), 1500);
    Vuelo Vuelo01("Fly Emirates", "Guille Valle", Fecha(1, 1, 2024), Fecha(15, 1, 2024), Hora(15, 30, 0), Hora(10, 0, 0), 1000, 1200);

    vector<Contratacion *> contrataciones;
    contrataciones.push_back(&LasSierras);
    contrataciones.push_back(&Vuelo01);

    // Paquetes
    Propio tourTuc_Bariloche("Bariloche", trayectos, Fecha(15, 01, 2024), 50, 0.15);
    Especial ViajeCordoba(contrataciones);

    vector<Paquete *> paquetes;
    paquetes.push_back(&tourTuc_Bariloche);
    paquetes.push_back(&ViajeCordoba);

    // Prueba del Sistema:
    Sistema MiSistema(paquetes, agentes, trayectos);

    MiSistema.RealizarReserva(1, 1, clientes, Fecha(30, 12, 2023)); // Reserva paquete propio
    MiSistema.AgregarClientesReserva(nuevosCli, 1);
    MiSistema.PagarReserva(14620, 1);

    MiSistema.RealizarReserva(1, 2, clientes, Fecha(30, 12, 2023)); // reserva paquete especial
    MiSistema.AgregarClientesReserva(nuevosCli, 2);
    MiSistema.PagarReserva(115440, 2);

    MiSistema.RealizarReserva(1, 1, nuevosCli, Fecha(26, 11, 2023)); // reserva ya caducada
    MiSistema.RealizarReserva(1, 2, nuevosCli, Fecha(30, 11, 2023)); // Reserva para cancelar

    MiSistema.BajaTrayecto(1);
    MiSistema.AltaAgente("Javier", "Mas");
    MiSistema.AltaTrayecto("Cordoba","Mendoza",3,1700);
    MiSistema.AltaPaquetePropio("Mendoza",vector<int>(1,4),Fecha(15,12,2023),20,0.1);
    MiSistema.RealizarReserva(2,3,clientes,Fecha(1,1,2024));
    MiSistema.PagarReserva(10000,5);

    /*MiSistema.ListarReservas();

    cout << "Cancelo reserva 4:\n";
    if (MiSistema.CancelarReserva(4))
    {
        cout << "Reserva cancelada con exito!\n";
    }
    else
    {
        cout << "no se pudo cancelar\n";
    }

    cout << "Elimino reserva 3 :\n";
    MiSistema.EliminarReservasVencidas();

    cout << "Vuelvo a mostrar\n";

    MiSistema.ListarReservas();*/

    MiSistema.InfoReservaByCodigo(5);

    cout << "Bonificacion Lucas:" << MiSistema.BonificacionAgente(1, 12, 2023) << endl;
    cout << "Recaudacion men 11/2023: " << MiSistema.RecudacionMensual(12, 2023) << endl;
    cout << "------ FIN PROGRAMA PRUEBA ------\n";
    return 0;
}
