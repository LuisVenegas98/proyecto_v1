#include <iostream>
#include <stdlib.h>

using namespace std;


int listIntFl = 1, listIntCl = 4;
int menu, x = 0;
int **list = new int*[listIntFl];

//int list[1][4];
char sn;

void agregar()
{
    do
    {
        list[x][0] = 1;
        list[x][1] = 1;
        list[x][2] = 3;
        list[x][3] = 1;

        
        do 
        {
            cout << "Desea agregar otro juego? si[s] no[n]";
            cin >> sn;

            if (sn != 's' && sn != 'n')
            {
                cout << "Error: esa no es una opcion";
            }

        } while (sn != 's' && sn != 'n');
        if (sn == 's')
        {
            listIntFl++;
            x = listIntFl - 1;
            list[listIntFl - 1] = new int[listIntCl];
        }
        

    } while (sn == 's');
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
    for (int i = 0; i < listIntFl; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << list[i][j] << " ! ";
        }
        cout << "\n";
    }
    cout << "modofocando cita";
}


void main()
{
    list[0] = new int[listIntCl];
    

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
            for (int i = 0; i < listIntFl; i++)
            {
                 
            }
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
            system("cls");
            eliminar();
            system("pause>null");
            break;
        }
        case 4:
        {
            system("cls");
            lista();
            system("pause>null");
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