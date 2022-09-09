#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h> //Segun con esto puedo hacer lineas de distintos colores. Edit: pos si
#include <iomanip>

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
    int c = 0;
    do
    {
        system("cls");
        listInt[x][0] = x + 1; //Numero del articulo

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "Ingrese el nombre del juego:\n";       //Nombre del videojuego
        cin.ignore();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        getline(cin, listStr[x][0]);
        c = listStr[x][0].length();
        if (c > 25)
        {
            listStr[x][0].erase(listStr[x][0].begin() + 25, listStr[x][0].end());
        }
        

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\nIngrese el a\xA4o de lanzamineto:\n";  //Año de lanzamiento
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cin >> listInt[x][1];

        do
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            cout << "\nClasificacion del juego\n";     //clasificacion
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "[1]. Todos (E)\n" <<
                "[2]. Todos +10 (E10+)\n" <<
                "[3]. Adolescentes (T)\n" <<
                "[4]. Maduro +17 (M)\n" <<
                "[5]. Solo Adultos +18 (A)\n" <<
                "[6]. Aun sin calificar (RP)\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "Error: Esa no es una opcion\n";
                    break;
                }  
            }
        } while (cl <= 0 && cl >= 7);
        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\nCaracteristicas del juego:\n";       //Escribir caracteristicas
        cin.ignore();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        getline(cin, listStr[x][2]);
        c = listStr[x][2].length();
        if (c > 40)
        {
            listStr[x][2].erase(listStr[x][2].begin() + 40, listStr[x][2].end());
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\nDescripcion del juego:\n";           //Escribir descripcion
        cin.ignore();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        getline(cin, listStr[x][3]);
        c = listStr[x][3].length();
        if (c > 50)
        {
            listStr[x][3].erase(listStr[x][3].begin() + 50, listStr[x][3].end());
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\nGenero del juego:\n";                //Genero del juego
        cin.ignore();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        getline(cin, listStr[x][4]);
        c = listStr[x][4].length();
        if (c > 30)
        {
            listStr[x][4].erase(listStr[x][4].begin() + 30, listStr[x][4].end());
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\nIngrese el precio unitario:\n";      //Valor del juego
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cin >> listFl[x][0];
        
        listFl[x][1] = listFl[x][0] * .16;            //Cuanto es de impuestos
        listFl[x][2] = listFl[x][0] + listFl[x][1];   //Total con impuestos
        
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "Juego agregado con exito! \1\n";
        do 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            cout << "Desea agregar otro juego? si[s] no[n]\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cin >> sn;

            sn.erase(sn.begin() + 1, sn.end());

            if (sn != "s" && sn != "n")
            {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "Error: esa no es una opcion.\n";
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
        cout << "Aun no hay juegos registrados. " << "Presiona enter para continuar...";
        return;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << " No. \xB3 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "Nombre del videojuego     \xB3 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "A\xA4o de lanza. \xB3 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "Clasf \xB3 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << left << setw(40) << "Caracteristicas" << setfill(' ') << " \xB3 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << left << setw(50) << "Descripcion" << setfill(' ') << " \xB3 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << left << setw(30) << "Genero" << setfill(' ') << " \xB3 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "Precio  \xB3 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "Impuesto (16\x25)  \xB3 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "Total    \xB3 \n\n\n";


    for (int i = 0; i < x; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << " " << left << setw(3) << listInt[i][0] << setfill(' ') << " \xB3 "; //Numero del articulo
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        cout << left << setw(25) << listStr[i][0] << setfill(' ') << " \xB3 "; //Nombre del videojuego
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << left << setw(13) << listInt[i][1] << setfill(' ') << " \xB3 "; //Año de lanzamiento
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        cout << left << setw(5) << listStr[i][1] << setfill(' ') << " \xB3 "; //Clasificacion
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << left << setw(40) << listStr[i][2] << setfill(' ') << " \xB3 "; //Caracteristicas
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        cout << left << setw(50) << listStr[i][3] << setfill(' ') << " \xB3 "; //Descripcion
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << left << setw(30) << listStr[i][4] << setfill(' ') << " \xB3 "; //Genero del juego
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        cout << left << "$" << setw(6) << listFl[i][0] << setfill(' ') << " \xB3 ";  //Precio unitario
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << left << "$" << setw(14) << listFl[i][1] << setfill(' ') << " \xB3 ";  //Impuestos
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        cout << left << "$" << setw(7) << listFl[i][2] << setfill(' ') << " \xB3 ";  //Total con impuestos
        cout << "\n\n";
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
            for (int i = 0; i < 3; i++)
            {
                Sleep(700);
                cout << ". ";     
            }
            Sleep(400);
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
}