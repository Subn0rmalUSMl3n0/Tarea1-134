#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct Pieza {
        char simbolo; /*tipo de pieza y su caracter*/
        int x,y; /* posicion en el tablero [0,7]*[0,7]*/
};
struct Tablero {
        int cantidad_piezas; /*numero de piezas en juego*/
        Pieza* piezas_tablero; /*lista de piezas en tablero*/
};
Tablero tablerito;

Pieza* LecturaTexto(int &no_piezas) {
    ifstream text; 
    text.open("tablero.txt"); /* abre el archivo tablero.txt para lectura*/
    if (!text.is_open()) {
        cerr << "Error al abrir tablero.txt" << endl;
    }
    text >> no_piezas; /*obtiene la primera linea del .txt y consigue la cantidad de piezas en juego*/
    tablerito.cantidad_piezas = no_piezas; /* se actualiza la cantidad de piezas del struct Tablero*/
    Pieza* pieza = new Pieza[no_piezas]; /*para modificar los parámetros de struct pieza*/
    char temp[2]; /* se crea un string temporal para alojar cada caracter del .txt y el caracter nulo*/
    int k = 0;
    for (int i = 0; i < 8; ++i) { /*mide cada fila de las 8 del tablero*/
        for (int j = 0; j < 8; ++j) { /*mide cada columna de las 8 del tablero*/
            text >> temp[0]; /*El caracter del texto se va al string temporal*/
            int p = strcmp(temp, "."); /*Si el struct temporal es un punto, retorna 0, si no, retorna otro valor...*/
            if(p != 0) { /*...haciendo que este if solo se cumpla para caracteres distintos del punto*/
                pieza[k].simbolo = temp[0]; 
                pieza[k].x = i;
                pieza[k].y = j; /*la pieza numero k del struct pieza, recibe a la vez su simbolo y sus coordenadas*/
                cout << pieza[k].simbolo << " " << pieza[k].x << " , " << pieza[k].y << endl;
                ++k; /* la proxima vez que haya una pieza, se registrara en un nuevo arreglo del struct*/
            };
        };    
    };
    return pieza;
};

int main() {
    int no_piezas; /*Numero de piezas en juego*/
    tablerito.piezas_tablero = LecturaTexto(no_piezas); /*invoca a la funcion, y devuelve los arreglos de simbolos y coordenadas de las piezas*/

    cout<< tablerito.piezas_tablero[0].simbolo << endl;
    cout << tablerito.piezas_tablero[0].x << endl;
    cout << tablerito.piezas_tablero[0].y << endl;
    cout << tablerito.cantidad_piezas << endl;
    return 0;
};

