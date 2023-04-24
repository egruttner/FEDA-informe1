#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MAX_SIZE = 10; // Máximo tamaño de la matriz
const int NUM_FILES = 5; // Número de archivos a generar

int main()
{
    srand(time(NULL)); // Inicializar el generador de números aleatorios con la hora actual

    for (int f = 1; f <= NUM_FILES; f++) {
        int A[MAX_SIZE][MAX_SIZE]; // Matriz A
        int B[MAX_SIZE][MAX_SIZE]; // Matriz A

        int n = rand() % MAX_SIZE + 2; // Tamaño de la matriz (aleatorio entre 1 y MAX_SIZE)

        // Inicializar la matriz A con números aleatorios entre 0 y 9
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = rand() % 50;
            }
        }

        // Inicializar la matriz B con números aleatorios entre 0 y 9
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                B[i][j] = rand() % 50;
            }
        }


        // Crear un archivo de texto y escribir los datos de la matriz
        string filename = "input" + to_string(f) + ".in";
        ofstream archivo(filename);
        archivo << to_string(n) + " " + to_string(n) + " " + to_string(n)<< endl; // Escribir el tamaño de la matriz en la primera línea del archivo
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                archivo << A[i][j] << " ";
            }
            archivo << endl;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                archivo << B[i][j] << " ";
            }
            archivo << endl;
        }

        archivo.close(); // Cerrar el archivo
    }

    return 0;
}
