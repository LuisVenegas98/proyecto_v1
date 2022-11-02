#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h> 
#include <iomanip>
#include <conio.h>
#include <fstream>

using namespace std;


int listIntFl = 1;
int menu, x = 0, cl, mod;
bool b = false;
string sn;

//Tablas para los articulos
int** listInt = new int* [listIntFl];
float** listFl = new float* [listIntFl];
string** listStr = new string * [listIntFl];

void color(int a)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void lista(int y, int j)
{
    if (b == false) // validar si hay registros
    {
        color(14);
        cout << "No hay juegos registrados. Presiona una tecla para continuar...";
        return;
    }

    color(11);
    cout << " ID  \xB3 ";
    color(15);
    cout << "Nombre del videojuego     \xB3 ";
    color(11);
    cout << "A\xA4o de lanza. \xB3 ";
    color(15);
    cout << "Clasf \xB3 ";
    color(11);
    cout << left << setw(40) << "Caracteristicas" << setfill(' ') << " \xB3 ";
    color(15);
    cout << left << setw(50) << "Descripcion" << setfill(' ') << " \xB3 ";
    color(11);
    cout << left << setw(30) << "Genero" << setfill(' ') << " \xB3 ";
    color(15);
    cout << "Precio  \xB3 ";
    color(11);
    cout << "Impuesto (16\x25)  \xB3 ";
    color(15);
    cout << "Total    \xB3 \n\n\n";


    for (int i = j; i < y; i++)
    {
        color(3);
        cout << " " << left << setw(3) << listInt[i][0] << setfill(' ') << " \xB3 "; //Numero del articulo
        color(8);
        cout << left << setw(25) << listStr[i][0] << setfill(' ') << " \xB3 "; //Nombre del videojuego
        color(3);
        cout << left << setw(13) << listInt[i][1] << setfill(' ') << " \xB3 "; //Año de lanzamiento
        color(8);
        cout << left << setw(5) << listStr[i][1] << setfill(' ') << " \xB3 "; //Clasificacion
        color(3);
        cout << left << setw(40) << listStr[i][2] << setfill(' ') << " \xB3 "; //Caracteristicas
        color(8);
        cout << left << setw(50) << listStr[i][3] << setfill(' ') << " \xB3 "; //Descripcion
        color(3);
        cout << left << setw(30) << listStr[i][4] << setfill(' ') << " \xB3 "; //Genero del juego
        color(8);
        cout << left << "$" << setw(6) << listFl[i][0] << setfill(' ') << " \xB3 ";  //Precio unitario
        color(3);
        cout << left << "$" << setw(14) << listFl[i][1] << setfill(' ') << " \xB3 ";  //Impuestos
        color(8);
        cout << left << "$" << setw(7) << listFl[i][2] << setfill(' ') << " \xB3 ";  //Total con impuestos
        cout << "\n\n";
    }
}

void blocN(int y, int j)
{
    string listaJuegos = "Videojuegos.txt";
    ofstream fichero; //fichero solo de salida.

    //abrimos el fichero
    fichero.open(listaJuegos.c_str()); //Esto es un puntero que apunta en que parte estamos dentro del fichero. Es como cuando pinchas con el raton en una parte del mismo para indicar que escriba en el. Hay metodos de cambiar este cursor pero no vienen al caso te dejaré videos al final.

    if (b == false) // validar si hay registros
    {
        fichero << "No hay juegos registrados.";
        return;
    }

    fichero << " ID  | ";
    fichero << "Nombre del videojuego     | ";
    fichero << "Año de lanza. | ";
    fichero << "Clasf | ";
    fichero << left << setw(40) << "Caracteristicas" << setfill(' ') << " | ";
    fichero << left << setw(50) << "Descripcion" << setfill(' ') << " | ";
    fichero << left << setw(30) << "Genero" << setfill(' ') << " | ";
    fichero << "Precio  | ";
    fichero << "Impuesto (16\x25)  | ";
    fichero << "Total    | \n\n\n";


    for (int i = j; i < y; i++)
    {
        fichero << " " << left << setw(3) << listInt[i][0] << setfill(' ') << " | "; //Numero del articulo
        fichero << left << setw(25) << listStr[i][0] << setfill(' ') << " | "; //Nombre del videojuego
        fichero << left << setw(13) << listInt[i][1] << setfill(' ') << " | "; //Año de lanzamiento
        fichero << left << setw(5) << listStr[i][1] << setfill(' ') << " | "; //Clasificacion
        fichero << left << setw(40) << listStr[i][2] << setfill(' ') << " | "; //Caracteristicas
        fichero << left << setw(50) << listStr[i][3] << setfill(' ') << " | "; //Descripcion
        fichero << left << setw(30) << listStr[i][4] << setfill(' ') << " | "; //Genero del juego
        fichero << left << "$" << setw(6) << listFl[i][0] << setfill(' ') << " | ";  //Precio unitario
        fichero << left << "$" << setw(14) << listFl[i][1] << setfill(' ') << " | ";  //Impuestos
        fichero << left << "$" << setw(7) << listFl[i][2] << setfill(' ') << " | ";  //Total con impuestos
        fichero << "\n\n";
    }

    //antes de salir cerramos el fichero
    fichero.close();
}

//registros
void nombreJ(int k)
{
    int c = 0;
    color(11);
    cout << "Ingrese el nombre del juego:\n";       //Nombre del videojuego
    color(15);
    cin.ignore();
    getline(cin, listStr[k][0]);
    c = listStr[k][0].length();
    if (c > 25)
    {
        listStr[k][0].erase(listStr[k][0].begin() + 25, listStr[k][0].end());
    }
}

void anioJ(int k)
{
    color(11);
    cout << "\nIngrese el a\xA4o de lanzamineto:\n";  //Año de lanzamiento
    do
    {
        color(15);
        cin >> listInt[k][1];

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            listInt[k][1] = 0;
        }

        if (listInt[k][1] < 1950 || listInt[k][1] > 2050)
        {
            color(12);
            cout << "\x1b[1A" << "\x1b[2K";
            cout << "\rError: esa no es una fecha valida.\n";
        }
    } while (listInt[k][1] < 1950 || listInt[k][1] > 2050);
}

void clasJ(int k)
{
    color(11);
    cout << "\nClasificacion del juego\n";     //clasificacion
    color(3);
    cout << "[1]. Todos (E)\n" <<
        "[2]. Todos +10 (E10+)\n" <<
        "[3]. Adolescentes (T)\n" <<
        "[4]. Maduro +17 (M)\n" <<
        "[5]. Solo Adultos +18 (A)\n" <<
        "[6]. Aun sin calificar (RP)\n";

    int e = 0;

    do
    {
        color(15);
        cl = _getche() - '0';
        cout << endl;

        switch (cl)
        {
        case 1:
        {
            listStr[k][1] = "E";
            break;
        }
        case 2:
        {
            listStr[k][1] = "E10+";
            break;
        }
        case 3:
        {
            listStr[k][1] = "T";
            break;
        }
        case 4:
        {
            listStr[k][1] = "M";
            break;
        }
        case 5:
        {
            listStr[k][1] = "A";
            break;
        }
        case 6:
        {
            listStr[k][1] = "RP";
            break;
        }
        default:
        {
            color(12);
            cout << "\x1b[1A" << "\x1b[2K";
            cout << "\rError: Esa no es una opcion\n";
            e++;
        }
        }
    } while (cl <= 0 || cl >= 7);

    if (e > 0)
    {
        for (int i = 0; i <= e; i++)
        {
            cout << "\x1b[1A" << "\x1b[2K";
        }
        cout << cl << endl;
    }
}

void caracJ(int k)
{
    int c = 0;
    color(11);
    cout << "\nCaracteristicas del juego:\n";       //Escribir caracteristicas
    cin.ignore();
    color(15);
    getline(cin, listStr[k][2]);
    c = listStr[k][2].length();
    if (c > 40)
    {
        listStr[k][2].erase(listStr[k][2].begin() + 40, listStr[k][2].end());
    }
}

void descJ(int k)
{
    int c = 0;
    color(11);
    cout << "\nDescripcion del juego:\n";           //Escribir descripcion
    color(15);
    cin.ignore();
    getline(cin, listStr[k][3]);
    c = listStr[k][3].length();
    if (c > 50)
    {
        listStr[k][3].erase(listStr[k][3].begin() + 50, listStr[k][3].end());
    }
}

void generoJ(int k)
{
    int c = 0;
    color(11);
    cout << "\nGenero del juego:\n";                //Genero del juego
    color(15);
    cin.ignore();
    getline(cin, listStr[k][4]);
    c = listStr[k][4].length();
    if (c > 30)
    {
        listStr[k][4].erase(listStr[k][4].begin() + 30, listStr[k][4].end());
    }
}

void precioJ(int k)
{
    color(11);
    cout << "\nIngrese el precio unitario:\n";      //Valor del juego
    color(15);

    do
    {
        color(15);
        cin >> listFl[k][0];

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            listFl[k][0] = -1;
        }

        if (listFl[k][0] < 0)
        {
            color(12);
            cout << "\x1b[1A" << "\x1b[2K";
            cout << "\rError: ese no es un presio valido.\n";
        }
    } while (listFl[k][0] < 0);

    listFl[k][1] = listFl[k][0] * .16;            //Cuanto es de impuestos
    listFl[k][2] = listFl[k][0] + listFl[k][1];   //Total con impuestos
}


//Menu principal
void agregar()
{
    b = true;
    int c = 0;

    do
    {
        system("cls");
        listInt[x][0] = x + 1; //Numero del articulo

        nombreJ(x);

        anioJ(x);
        
        clasJ(x);
        
        caracJ(x);

        descJ(x);

        generoJ(x);

        precioJ(x);
        
        system("cls");
        color(10);
        cout << "Juego agregado con exito! \1\n";
        do
        {
            color(11);
            cout << "Desea agregar otro juego? si[s] no[n]\n";
            cin.ignore();
            sn = _getch();

            sn.erase(sn.begin() + 1, sn.end());

            if (sn != "s" && sn != "n" && sn != "S" && sn != "N")
            {
                system("cls");
                color(12);
                cout << "Error: esa no es una opcion.\n";
            }

        } while (sn != "s" && sn != "n" && sn != "N" && sn != "S");

        listIntFl++;
        x = listIntFl - 1;
        listInt[listIntFl - 1] = new int[2];
        listFl[listIntFl - 1] = new float[3];
        listStr[listIntFl - 1] = new string[5];

    } while (sn == "s" || sn == "S");
}

void modificar()
{
    do
    {
        int cat = 0;
        system("cls");
        if (b == false) // validar si hay registros
        {
            color(14);
            cout << "No hay juegos registrados. Presiona una tecla para continuar...";
            system("pause>n");
            return;
        }

        lista(x, 0);

        color(10);
        cout << "Ingresa el ID del juego que desea modificar. Salir[0]\n";
        color(15);
        cin >> mod;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            mod = -1;
        }

        if (mod > 0 && mod <= listIntFl)
        {
            do
            {
                system("cls");
                lista(mod, mod - 1);
                color(11);
                cout << "Que desesa modificar?\n";
                color(3);
                cout << "[1]. Nombre del juego\n" <<
                    "[2]. A\xA4o de lanzamineto:\n" <<
                    "[3]. Clasificacion del juego\n" <<
                    "[4]. Caracteristicas del juego\n" <<
                    "[5]. Descripcion del juego\n" <<
                    "[6]. Precio unitario\n" <<
                    "[0]. Regresar\n";

                cat = _getch() - '0';

                switch (cat)
                {
                case 1:
                {
                    system("cls");
                    nombreJ(mod - 1);
                    break;
                }
                case 2:
                {
                    system("cls");
                    anioJ(mod - 1);
                    break;
                }
                case 3:
                {
                    system("cls");
                    clasJ(mod - 1);
                    break;
                }
                case 4:
                {
                    system("cls");
                    caracJ(mod - 1);
                    break;
                }
                case 5:
                {
                    system("cls");
                    descJ(mod - 1);
                    break;
                }
                case 6:
                {
                    system("cls");
                    precioJ(mod - 1);
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    color(12);
                    cout << "\x1b[1A" << "\x1b[2K";
                    cout << "\rError: Esa no es una opcion\n";
                }
                }
            } while (cl < 0 || cl >= 7);

        }

        else if (mod != 0)
        {
            system("cls");
            color(12);
            cout << "Error: no existe un juego con ese ID. Presiona una tecla para continuar";
            system("pause>null");
        }

        if (x == 0)
        {
            b = false;
        }
    } while (mod != 0);
}

void eliminar()
{
    do
    {
        system("cls");
        if (b == false) // validar si hay registros
        {
            color(14);
            cout << "No hay juegos registrados. Presiona una tecla para continuar...";
            system("pause>n");
            return;
        }

        lista(x, 0);

        color(10);
        cout << "Ingresa el ID del juego que desea eliminar. Salir[0]\n";
        color(15);
        cin >> mod;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            mod = -1;
        }

        if (mod > 0 && mod <= listIntFl)
        {
            system("cls");
            lista(mod, mod - 1);
            do
            {
                color(14);
                cout << "Seguro que quieres eliminar este juego? Si[s] No[n]\n";
                sn = _getch();

                if (sn == "s" || sn == "S")
                {
                    for (int i = mod - 1; i < listIntFl - 1; i++)
                    {
                        listStr[i][0] = listStr[i + 1][0];
                        listStr[i][1] = listStr[i + 1][1];
                        listStr[i][2] = listStr[i + 1][2];
                        listStr[i][3] = listStr[i + 1][3];
                        listStr[i][4] = listStr[i + 1][4];
                        listInt[i][1] = listInt[i + 1][1];
                        listFl[i][0] = listFl[i + 1][0];
                        listFl[i][1] = listFl[i + 1][1];
                        listFl[i][2] = listFl[i + 1][2];
                    }

                    int** listInt = new int* [listIntFl - 1];
                    float** listFl = new float* [listIntFl - 1];
                    string** listStr = new string * [listIntFl - 1];

                    listIntFl--;
                    x--;
                }
                else if (sn != "s" && sn != "n" && sn != "S" && sn != "N")
                {
                    system("cls");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "Error: esa no es una opcion.\n";
                }
            } while (sn != "s" && sn != "n" && sn != "N" && sn != "S");
            
        }

        else if (mod != 0)
        {
            system("cls");
            color(12);
            cout << "Error: no existe un juego con ese ID. Presiona una tecla para continuar";
            system("pause>null");
        }

        if (x == 0)
        {
            b = false;
        }
    } while (mod != 0);
}

void main()
{
    listInt[0] = new int[2];
    listFl[0] = new float[3];
    listStr[0] = new string[5];

    do
    {
        system("cls");
        color(11);
        cout << "============MENU PRINCIPAL============\n";
        color(10);
        cout << "\t[1]. Agregar juego\n" <<
            "\t[2]. Modificar juego\n" <<
            "\t[3]. Eliminar juego\n" <<
            "\t[4]. Lista de juegos vigentes\n" <<
            "\t[5]. Limpiar pantalla\n" <<
            "\t[0]. Salir\n";

        //color(15);
        menu = _getch() - '0';

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
            break;
        }
        case 3:
        {
            system("cls");
            eliminar();
            break;
        }
        case 4:
        {
            system("cls");
            lista(x, 0);
            system("pause>n");
            break;
        }
        case 5:
        {
            system("cls");
            system("pause>null");
            break;
        }
        case 0:
        {
            blocN(x, 0);
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
            cout << "Error: esa no es una opcion.\n" << "Presiona enter para continuar...\n";
            system("pause>null");
            break;
        }
        }
    } while (menu != 0);
}