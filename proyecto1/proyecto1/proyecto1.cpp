#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h> //Segun con esto puedo hacer lineas de distintos colores

using namespace std;

int listIntFl = 1;
int menu, x = 0, cl;
string sn;

//Tablas para los articulos
int **listInt = new int*[listIntFl];
float** listFl = new float*[listIntFl];
string** listStr = new string*[listIntFl];

//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 

void agregar()
{
    do
    {
        listInt[x][0] = x + 1; //Numero del articulo

        cout << "Ingrese el nombre del juego:\n";       //Nombre del videojuego
        cin.ignore();
        getline(cin, listStr[x][0]);

        cout << "\nIngrese el a\xA4o de lanzamineto:\n";  //Año de lanzamiento
        cin >> listInt[x][1];

        do
        {
            cout << "\nClasificacion del juego\n" <<      //clasificacion
                "[1]. Todos (E)\n" <<
                "[2]. Todos +10 (E10+)\n" <<
                "[3]. Adolescentes (T)\n" <<
                "[4]. Maduro +17 (M)\n" <<
                "[5]. Solo Adultos +18 (A)\n" <<
                "[6]. Aun sin calificar (RP)\n";
            cin >> cl;
            switch (cl)
            {
                case 1:
                {
                    listStr[x][1] = "E";
                    break;
                }
                case 2:
                {
                    listStr[x][1] = "E10+";
                    break;
                }
                case 3:
                {
                    listStr[x][1] = "T";
                    break;
                }
                case 4:
                {
                    listStr[x][1] = "M";
                    break;
                }
                case 5:
                {
                    listStr[x][1] = "A";
                    break;
                }
                case 6:
                {
                    listStr[x][1] = "RP";
                    break;
                }
                default:
                    cout << "Error: Esa no es una opcion";
                    break;
            }
        } while (cl <= 0 && cl >= 7);
        
        cout << "\nCaracteristicas del juego:\n";       //Escribir caracteristicas
        //cin >> listStr[x][2];
        cin.ignore();
        getline(cin, listStr[x][2]);

        cout << "\nDescripcion del juego:\n";           //Escribir descripcion
        //cin >> listStr[x][3];
        cin.ignore();
        getline(cin, listStr[x][3]);

        cout << "\nGenero del juego:\n";                //Genero del juego
        cin >> listStr[x][4];

        cout << "\nIngrese el precio unitario:\n";      //valor del juego
        cin >> listFl[x][0];
        
        listFl[x][1] = listFl[x][0] * .16;            //cuanto es de impuestos
        listFl[x][2] = listFl[x][0] + listFl[x][1];   // total con impuestos
        
        do 
        {
            cout << "Desea agregar otro juego? si[s] no[n]\n";
            cin >> sn;

            sn.erase(sn.begin() + 1, sn.end());

            if (sn != "s" && sn != "n")
            {
                //system("color 04");
                cout << "\033[0;4 Error: esa no es una opcion\n";
            }

        } while (sn != "s" && sn != "n");

        listIntFl++;
        x = listIntFl - 1;
        listInt[listIntFl - 1] = new int[2];
        listFl[listIntFl - 1] = new float[3];
        listStr[listIntFl - 1] = new string[5];

    } while (sn == "s");
}

void modificar()
{
    cout << "modificando cita";
}
void eliminar()
{
    cout << "eliminando cita";
}
void lista()
{
    system("color 03");
    cout << "No.\t\t";
    for (int i = 0; i < x; i++)
    {
        cout << listInt[i][0] << " ! " <<
        listStr[i][0] << " ! " <<
        listInt[i][1] << " ! " <<
        listStr[i][1] << " ! " <<
        listStr[i][2] << " ! " <<
        listStr[i][3] << " ! " <<
        listStr[i][4] << " ! " <<
        listFl[i][0] << " ! " <<
        listFl[i][1] << " ! " <<
        listFl[i][2];
        cout << "\n";
    }
}


void main()
{
    listInt[0] = new int[2];
    listFl[0] = new float[3];
    listStr[0] = new string[5];
    

    do
    {
        system("cls");
        system("color 02");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "============MENU PRINCIPAL============\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\t[1]. Agregar articulo\n" <<
            "\t[2]. Modificar articulo\n" <<
            "\t[3]. Eliminar articulo\n" <<
            "\t[4]. Lista de articulos vigentes\n" <<
            "\t[5]. Limpiar pantalla\n" <<
            "\t[6]. Salir\n";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            system("cls");
            agregar();
            break;
        }
        case 2:
        {
            system("cls");
            modificar();
            system("pause>null");
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
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout  << "Error: esa no es una opcion... presiona enter para continuar\n";
            system("pause>null");
            break;
        }
        }


    } while (menu != 6);
    system("pause>null");
}