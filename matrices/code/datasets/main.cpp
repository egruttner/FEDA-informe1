#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <filesystem>
#include <sys/stat.h>

using namespace std;

int MAX_SIZE = 512; // Máximo tamaño de la matriz
int NUM_FILES = 10; // Número de archivos a generar
int RANGO = 10000; // Rango de números



int random_power_of_2(int max) {
    int n = rand() % max + 1;
    int power_of_2 = 1;
    while (power_of_2 < n) {
        power_of_2 <<= 1;
    }
    return power_of_2;
}


int main()
{
    int opcion; //opción de generación seleccionada por el usuario
    string operacion = "";
    string folderName = "opcion";

    cout << "1-cuadradas_potencia_dos 2-diferente_tamano" << endl;
    cin >> opcion; //Se lee la opción a usar para crear dataset

    srand(time(NULL)); // Inicializar el generador de números aleatorios con la hora actual

    if (opcion==1) //cuadradas
    {
        operacion = "cuadradas_potencia_dos";
        //Crea carpeta para guardar datasets
        folderName = operacion + "-" + to_string(NUM_FILES) + "-" + to_string(RANGO);
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }
        for (int f = 1; f <= NUM_FILES; f++) {
            int A[MAX_SIZE][MAX_SIZE]; // Matriz A
            int B[MAX_SIZE][MAX_SIZE]; // Matriz A

            int n = random_power_of_2(MAX_SIZE);

            cout<< n <<endl;

            // Inicializar la matriz A con números aleatorios entre RANGO
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    A[i][j] = rand() % RANGO;
                }
            }

            // Inicializar la matriz B con números aleatorios entre RANGO
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    B[i][j] = rand() % RANGO;
                }
            }

            // Crear un archivo de texto y escribir los datos de la matriz
            string filename = folderName + "/input" + to_string(f) + ".txt";
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


    }

    if (opcion==2) //de diferentes tamaños para algoritmos tradicionales
    {
        operacion = "diferente_tamano";
        //Crea carpeta para guardar datasets
        folderName = operacion + "-" + to_string(NUM_FILES) + "-" + to_string(RANGO);
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }

        for (int f = 1; f <= NUM_FILES; f++) {
            int A[MAX_SIZE][MAX_SIZE]; // Matriz A
            int B[MAX_SIZE][MAX_SIZE]; // Matriz A

            int n = rand() % MAX_SIZE + 2; // Tamaño de la matriz (aleatorio entre 2 y MAX_SIZE)
            int m = rand() % MAX_SIZE + 2; // Tamaño de la matriz (aleatorio entre 2 y MAX_SIZE)
            int k = rand() % MAX_SIZE + 2; // Tamaño de la matriz (aleatorio entre 2 y MAX_SIZE)


            // Inicializar la matriz A con números aleatorios entre RANGO
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    A[i][j] = rand() % RANGO;
                }
            }

            // Inicializar la matriz B con números aleatorios entre RANGO
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < k; j++) {
                    B[i][j] = rand() % RANGO;
                }
            }

            // Crear un archivo de texto y escribir los datos de la matriz
            string filename = folderName + "/input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(n) + " " + to_string(m) + " " + to_string(k)<< endl; // Escribir el tamaño de la matriz en la primera línea del archivo
            
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


    }





    return 0;
}
