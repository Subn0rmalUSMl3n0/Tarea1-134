#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
/*pasar el string tablerito a un arreglo, y arreglar fn Coordenada*/
using namespace std;

char* LecturaTexto(string& no_piezas, string& tablerito) {
    ifstream text; /* abre el archivo tablero.txt para lectura*/
    text.open("tablero.txt");
    if (!text.is_open()) {
        cerr << "Error al abrir tablero.txt" << endl;
    }
    getline(text,no_piezas);    /*obtiene la primera linea del .txt y consigue la cantidad de piezas en juego*/

    string temp;
    for (int i=0; i<8; i++) {
        text >> temp; /*se lee el texto de la i-esima fila del .txt y se guarda en temp*/
        tablerito= tablerito + temp; /*tablero aloja la fila actual de temp antes de que se pierda, con un espacio entre medias pues solo puede trabajarse en una linea 1x64, no una matriz 8x8*/
    };
    char* CharPanchito= new char[tablerito.length()+1]; /*Crea un char temporal para pasar el tablero de string a char*/
    int j = 0;
    while(j < tablerito.length()){
        CharPanchito[j] = tablerito[j]; /*para cada simbolo del tablerito, se pasa a charpanchito*/
        j++;
    };
    CharPanchito[j] = '\0'; /*se agrega el caracter nulo a charpanchito, para que no de errores*/
    text.close(); /*se cierra el .txt*/
    return CharPanchito;
};

void SimboloCoordenada(string tablerito, string no_piezas) {
    (string) tablerito;
    char piezas[stoi(no_piezas)+1];
    int i= 0;
    string punto = ".";
    char ji[] = "pene";
    return ;
};
int main() {
    string no_piezas; /*Numero de piezas en juego*/
    string tablerito; /*Tablero traspuesto del .txt a un string*/
    char* Charpanchito;
    Charpanchito = LecturaTexto(no_piezas,tablerito); /* inicia la funcion y devuelve los valores actualizados*/

    struct Pieza {
        char simbolo; /*tipo de pieza y su caracter*/
        int x,y; /* posicion en el tablero [0,7]*[0,7]*/
    };
    struct Tablero {
        int cantidad_piezas; /*numero de piezas en juego*/
        Pieza* piezas_tablero; /*lista de piezas en tablero*/
    };
    Pieza pieza; /*para modificar los parámetros de struct pieza*/
    SimboloCoordenada(tablerito,no_piezas);
    
    Tablero tablero; /*para modificar los parámetros de struct tablero*/
    tablero.cantidad_piezas = stoi(no_piezas); /*traspasa de string a int*/
    cout << tablero.cantidad_piezas << Charpanchito << endl; /*printea la cantidad de piezas en juego*/
    return 0;
};

