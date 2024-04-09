#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
/*pasar el string tablerito a un arreglo, y arreglar fn Coordenada*/
using namespace std;

char* LecturaTexto(int& no_piezas) {
    ifstream text; /* abre el archivo tablero.txt para lectura*/
    text.open("tablero.txt");
    if (!text.is_open()) {
        cerr << "Error al abrir tablero.txt" << endl;
    }
    text >> no_piezas;    /*obtiene la primera linea del .txt y consigue la cantidad de piezas en juego*/
    string temptablero;
    string temp;
    for (int i=0; i<8; i++) {
        text >> temp; /*se lee el texto de la i-esima fila del .txt y se guarda en temp*/
        temptablero= temptablero + temp; /*tablero aloja la fila actual de temp antes de que se pierda, con un espacio entre medias pues solo puede trabajarse en una linea 1x64, no una matriz 8x8*/
    };
    char* CharPanchito= new char[temptablero.length()+1]; /*Crea un char array dinamico para pasar el tablero de string a char*/
    int j = 0;
    while(j < temptablero.length()){
        CharPanchito[j] = temptablero[j]; /*para cada simbolo del tablerito, se pasa a charpanchito*/
        j++;
    };
    CharPanchito[j] = '\0'; /*se agrega el caracter nulo a charpanchito, para que no de errores*/
    text.close(); /*se cierra el .txt*/
    return CharPanchito;
};

void SimboloCoordenada(char* tablerito, int no_piezas) {
    char piezas[no_piezas+1];
    int i= 0;
    string punto = ".";
    char ji[] = "pene";
    cout << no_piezas << tablerito << endl; /*printea la cantidad de piezas en juego*/
};
int main() {
    int no_piezas; /*Numero de piezas en juego*/
    char* tablerito; /*tablero del .txt*/
    tablerito = LecturaTexto(no_piezas); /* inicia la funcion y devuelve los valores actualizados*/

    struct Pieza {
        char simbolo; /*tipo de pieza y su caracter*/
        int x,y; /* posicion en el tablero [0,7]*[0,7]*/
    };
    struct Tablero {
        int cantidad_piezas; /*numero de piezas en juego*/
        Pieza* piezas_tablero; /*lista de piezas en tablero*/
    };
    Pieza pieza; /*para modificar los parámetros de struct pieza*/
    SimboloCoordenada(tablerito, no_piezas);
    
    Tablero tablero; /*para modificar los parámetros de struct tablero*/
    tablero.cantidad_piezas = no_piezas; /*traspasa de string a int*/
    return 0;
};

