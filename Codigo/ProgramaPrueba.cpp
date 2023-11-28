#include "Sistema.cpp"

int main()
{
    // Agentes:
    Agente Lucas("Lucas", "Alarcon");

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

    // Paquete Propio:
    Trayecto trayecto1("Tucuman", "Cordoba", 3, 1500);
    Trayecto trayecto2("Cordoba", "Bs.As", 3, 1000);
    Trayecto trayecto3("Bs.As", "Bariloche", 3, 1800);

    vector<Trayecto *> trayectoTuc_Bar;
    trayectoTuc_Bar.push_back(&trayecto1);
    trayectoTuc_Bar.push_back(&trayecto2);
    trayectoTuc_Bar.push_back(&trayecto3);

    Propio tourTuc_Bariloche("Bariloche", trayectoTuc_Bar, Fecha(15, 01, 2024), 50, 0.15);

    // Paquete Especial
    Hotel LasSierras("Los Sierras", "Cordoba", Fecha(1, 1, 2024), Fecha(15, 1, 2024), 1500);
    Vuelo Vuelo01("Fly Emirates", "Guille Valle", Fecha(1, 1, 2024), Fecha(15, 1, 2024), Hora(15, 30, 0), Hora(10, 0, 0), 1000, 1200);

    vector<Contratacion *> contrataciones;
    contrataciones.push_back(&LasSierras);
    contrataciones.push_back(&Vuelo01);

    Especial ViajeCordoba(contrataciones);

    // Vector de Paquetes:
    vector<Paquete *> paquetes;
    paquetes.push_back(&tourTuc_Bariloche);
    paquetes.push_back(&ViajeCordoba);

    // Prueba del Sistema:
    Sistema MiSistema(paquetes);

    MiSistema.RealizarReserva(&Lucas, 1, clientes, Fecha(30, 12, 2023)); // Reserva paquete propio
    MiSistema.AgregarClientesReserva(nuevosCli, 1);
    MiSistema.PagarReserva(14620, 1);

    MiSistema.RealizarReserva(&Lucas, 2, clientes, Fecha(30, 12, 2023)); // reserva paquete especial
    MiSistema.AgregarClientesReserva(nuevosCli, 2);
    MiSistema.PagarReserva(115440, 2);

    // Prubea de funciones del sistema:

    MiSistema.RealizarReserva(&Lucas, 1, nuevosCli, Fecha(26, 11, 2023)); // reserva ya caducada
    MiSistema.RealizarReserva(&Lucas, 2, nuevosCli, Fecha(30, 11, 2023)); //Reserva para cancelar

    for (int i = 1; i <= MiSistema.CantidadReservas(); i++)
    {
        MiSistema.ListaInfoReservaByCodigo(i);
        cout << "\n";
    }


    cout << "Elimino reserva 3 :\n";
    MiSistema.EliminarReservasVencidas();

    cout<<"Cancelo reserva 4:\n";
    if (MiSistema.CancelarReserva(4))
    {
        cout<<"Reserva cancelada con exito!\n";
    }else
    {
        cout<<"no se pudo cancelar\n";
    }
    
    cout << "Vuelvo a mostrar\n";

    for (int i = 1; i <= MiSistema.CantidadReservas(); i++)
    {
        MiSistema.ListaInfoReservaByCodigo(i);
        cout << "\n";
    }

    cout << "Bonificacion Lucas:" << MiSistema.BonificacionAgente(1) << endl;
    cout << "Recaudacion men 11/2023: " << MiSistema.RecudacionMensual(11, 2023) << endl;

    return 0;
}