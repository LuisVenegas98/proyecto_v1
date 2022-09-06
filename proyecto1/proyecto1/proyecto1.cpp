#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h> //Segun con esto puedo hacer lineas de distintos colores. Edit: pos si

using namespace std;


int listIntFl = 1;
int menu, x = 0, cl;
bool b = false;
string sn;

//Tablas para los articulos
int **listInt = new int*[listIntFl];
float** listFl = new float*[listIntFl];
string** listStr = new string*[listIntFl];

void agregar()
{
    b = true;
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

        cout << "\nIngrese el precio unitario:\n";      //Valor del juego
        cin >> listFl[x][0];
        
        listFl[x][1] = listFl[x][0] * .16;            //Cuanto es de impuestos
        listFl[x][2] = listFl[x][0] + listFl[x][1];   //Total con impuestos
        
        do 
        {
            cout << "Desea agregar otro juego? si[s] no[n]\n";
            cin >> sn;

            sn.erase(sn.begin() + 1, sn.end());

            if (sn != "s" && sn != "n")
            {
                cout << "Error: esa no es una opcion\n";
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "                        Paimon\n";
    for (int i = 1; i <= 56; i++)
    {
        cout << "\xC4";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << " \n \xA8Qu\x82 tal si exploramos el \xA0rea de adelante m\xA0s tarde? \n";
}
void eliminar()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "                        Paimon\n";
    for (int i = 1; i <= 56; i++)
    {
        cout << "\xC4";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << " \n \xA8Qu\x82 tal si exploramos el \xA0rea de adelante m\xA0s tarde? \n";
}
void lista()
{
    if (b == false) // validar si hay registros
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "Aun no hay juegos registrados.\n" << "Presiona enter para continuar...";
        return;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "No.\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "Nombre del videojuego\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "A\xA4o de lanzamiento\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "Clasificacion\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "Caracteristicas\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "Descripcion\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "Genero\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "Precio unitario\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "Impuesto (16\x25)\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "Total\t\t\n\n";

    for (int i = 0; i < x; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << listInt[i][0] << " \xB3 "; //Numero del articulo
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        cout << listStr[i][0] << " \xB3 "; //Nombre del videojuego
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << listInt[i][1] << " \xB3 "; //Año de lanzamiento
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        cout << listStr[i][1] << " \xB3 "; //Escribir caracteristicas
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << listStr[i][2] << " \xB3 "; //Escribir descripcion
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        cout << listStr[i][3] << " \xB3 "; //Genero del juego
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << listStr[i][4] << " \xB3 "; //Valor del juego
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        cout << listFl[i][0] << " \xB3 ";  //Precio unitario
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << listFl[i][1] << " \xB3 ";  //Impuestos
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        cout << listFl[i][2];              //Total con impuestos
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
            cout  << "Error: esa no es una opcion.\n" << "Presiona enter para continuar...\n";
            system("pause>null");
            break;
        }
        }


    } while (menu != 6);
    system("pause>null");
}