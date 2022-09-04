#include <iostream>

using namespace std;

int menu;

void agregar()
{
    cout << "agendando cita";
}
void modificar()
{
    cout << "modofocando cita";
}
void eliminar()
{
    cout << "modofocando cita";
}
void lista()
{
    cout << "modofocando cita";
}


void main()
{
    do
    {
        system("cls");

        cout << "============MENU PRINCIPAL============\n" <<
            "\t[1]. Agregar articulo\n" <<
            "\t[2]. Modificar articulo\n" <<
            "\t[3]. Eliminar articulo\n" <<
            "\t[4]. Lista de articulos vigentes\n" <<
            "\t[5]. Limpiar pantalla\n" <<
            "\t[6]. Salir\n";

        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            agregar();
            break;
        }
        case 2:
        {
            modificar();
            break;
        }
        case 3:
        {
            eliminar();
            break;
        }
        case 4:
        {
            lista();
            break;
        }
        case 5:
        {
            system("cls");
            system("pause>null");
            break;
        }
        case 6:
        {
            cout << "Saliendo del sistema";
            break;
        }
        default:
        {
            cout << "Error vuelve a intentar...";
            break;
        }
        }


    } while (menu != 6);
    system("pause>null");
}