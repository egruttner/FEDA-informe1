#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MAX_SIZE = 1000; // Máximo tamaño del arreglo
const int NUM_FILES = 10; // Número de archivos a generar
const int RANGO = 10000; // Rango de números

int main()
{


    srand(time(NULL)); // Inicializar el generador de números aleatorios con la hora actual

    //DESORDENADOS
    for (int f = 1; f <= NUM_FILES; f++) {
        int A[MAX_SIZE];// Vector A

        int n = rand() % MAX_SIZE + 2; // Tamaño de la matriz (aleatorio entre 1 y MAX_SIZE)

        for (int i = 0; i < n; i++) {
            A[i] = rand() % RANGO;
        }

        // Crear un archivo de texto y escribir los datos del vector
        string filename = "input" + to_string(f) + ".in";
        ofstream archivo(filename);
        archivo << to_string(n)<< endl; // Escribir el tamaño del vector en la primera línea del archivo
        
        for (int i = 0; i < n; i++) {
            archivo << A[i] << " "<<endl;
        }

        archivo.close(); // Cerrar el archivo
    }

    //ORDENADOS
    for (int f = NUM_FILES; f <= NUM_FILES+10; f++) {
        int A[MAX_SIZE];// Vector A

        int n = rand() % MAX_SIZE + 2; // Tamaño del vector (aleatorio entre 1 y MAX_SIZE)

        for (int i = 0; i < n; i++) {
            A[i] = rand() % RANGO;
        }

        // Crear un archivo de texto y escribir los datos del vector
        string filename = "input" + to_string(f) + ".txt";
        ofstream archivo(filename);
        archivo << to_string(n)<< endl; // Escribir el tamaño del vector en la primera línea del archivo
        

        sort(A + n/2, A + n);


        for (int i = 0; i < n; i++) {
            archivo << A[i] << " "<<endl;
        }

        archivo.close(); // Cerrar el archivo
    }



    return 0;
}
