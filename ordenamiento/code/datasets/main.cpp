#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include <filesystem>
#include <sys/stat.h>

using namespace std;

int SIZE = 5000; // Tamaño mínimo de vector, que aumentará en 10000 por cada generación
int NUM_FILES = 20; // Número de archivos a generar
int RANGO = 10000; // Rango de números

void shuffleArray(int arr[], int size) {
    random_device rd; //se utiliza para generar un valor aleatorio que se utilizará como semilla para el generador de números aleatorios.
    mt19937 gen(rd()); //es un generador de números aleatorios basado en el algoritmo Mersenne Twister
    for (int i = 0; i < size; ++i) {
        int j = uniform_int_distribution<>(i, size - 1)(gen);
        swap(arr[i], arr[j]);
    }
}


int main()
{

    int opcion; //opción de desorden seleccionada por el usuario
    string operacion = "";
    string folderName = "opcion";

    cout << "1-desordenado_repetido 2-desordenado_unico 3-ordenado_repetido 4-ordenado_reversa 5-parcialmente_ordenado 6-semi_ordenado" << endl;
    cin >> opcion; //Se lee la opción a usar para crear dataset

    srand(time(NULL)); // Inicializar el generador de números aleatorios con la hora actual

    if (opcion==1) //desordenado_repetido
    {
        operacion = "desordenado_repetido";
        //Crea carpeta para guardar datasets
        folderName = operacion + "-" + to_string(NUM_FILES) + "-" + to_string(RANGO);
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }
        for (int f = 1; f <= NUM_FILES; f++) {

            srand(time(0)); // Inicializar el generador de números aleatorios con la hora actual

            int A[SIZE];// Vector A

            for (int i = 0; i < SIZE; i++) {
                A[i] = rand() % RANGO;
            }

            // Crear un archivo de texto y escribir los datos del vector
            string filename = folderName + "/input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(SIZE)<< endl; // Escribir el tamaño del vector en la primera línea del archivo
            
            for (int i = 0; i < SIZE; i++) {
                archivo << A[i] << " "<<endl;
            }

            archivo.close(); // Cerrar el archivo

            SIZE = SIZE+5000;
        }
    }

    if (opcion==2) //desordenado_unico
    {        
        operacion = "desordenado_unico";
        //Crea carpeta para guardar datasets
        folderName = operacion + "-" + to_string(NUM_FILES) + "-" + to_string(RANGO);
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }        
        for (int f = 1; f <= NUM_FILES; ++f) {
            int A[SIZE];// Vector A

            for (int i = 0; i < SIZE; i++) {
                A[i] = i + 1;
            }

            //Carga arreglo con datos ordenados únicos

            shuffleArray(A, SIZE); //Llama a función para desordenar

            // Crear un archivo de texto y escribir los datos del vector
            string filename = folderName + "/input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(SIZE)<< endl; // Escribir el tamaño del vector en la primera línea del archivo
            
            for (int i = 0; i < SIZE; i++) {
                archivo << A[i] << " "<<endl;
            }

            archivo.close(); // Cerrar el archivo

            SIZE = SIZE+1000;
        }

    }

    if (opcion==3) //ordenado_repetido
    {
        operacion = "ordenado_repetido";
        //Crea carpeta para guardar datasets
        folderName = operacion + "-" + to_string(NUM_FILES) + "-" + to_string(RANGO);
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }        
        for (int f = 1; f <= NUM_FILES; f++) {
            int A[SIZE];// Vector A

            for (int i = 0; i < SIZE; i++) {
                A[i] = rand() % RANGO;
            }

            // Crear un archivo de texto y escribir los datos del vector
            string filename = folderName + "/input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(SIZE)<< endl; // Escribir el tamaño del vector en la primera línea del archivo
            sort(A, A + SIZE);
            for (int i = 0; i < SIZE; i++) {
                archivo << A[i] << " "<<endl;
            }

            archivo.close(); // Cerrar el archivo
            
            SIZE=SIZE + 10000;
        }

    }

    if (opcion==4) //ordenado_reversa
    {
        operacion = "ordenado_reversa"; 
        //Crea carpeta para guardar datasets
        folderName = operacion + "-" + to_string(NUM_FILES) + "-" + to_string(RANGO);
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }        
        for (int f = 1; f <= NUM_FILES; f++) {
            int A[SIZE];// Vector A

            for (int i = 0; i < SIZE; i++) {
                A[i] = rand() % RANGO;
            }

            // Crear un archivo de texto y escribir los datos del vector
            string filename = folderName + "/input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(SIZE)<< endl; // Escribir el tamaño del vector en la primera línea del archivo
            sort(A, A + SIZE,greater<int>());

            for (int i = 0; i < SIZE; i++) {
                archivo << A[i] << " "<<endl;
            }

            archivo.close(); // Cerrar el archivo

            SIZE = SIZE + 10000;
        }

    }

    if (opcion==5) //ordenado_reversa
    {
        operacion = "parcialmente_ordenado";
        //Crea carpeta para guardar datasets
        folderName = operacion + "-" + to_string(NUM_FILES) + "-" + to_string(RANGO);
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }
        for (int f = 1; f <= NUM_FILES; f++) {
            int A[SIZE];// Vector A

            for (int i = 0; i < SIZE; i++) {
                A[i] = rand() % RANGO;
            }

            // Crear un archivo de texto y escribir los datos del vector
            string filename = folderName + "/input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(SIZE)<< endl; // Escribir el tamaño del vector en la primera línea del archivo

            std::partial_sort(A, A + SIZE/2, A + SIZE);

            for (int i = 0; i < SIZE; i++) {
                archivo << A[i] << " "<<endl;
            }

            archivo.close(); // Cerrar el archivo

            SIZE = SIZE + 10000;
        }

    }

    if (opcion==6) //ordenado_reversa
    {
        operacion = "semi_ordenado";
        //Crea carpeta para guardar datasets
        folderName = operacion + "-" + to_string(NUM_FILES) + "-" + to_string(RANGO);
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }        
        for (int f = 1; f <= NUM_FILES; f++) {
            int A[SIZE];// Vector A

            for (int i = 0; i < SIZE; i++) {
                A[i] = rand() % RANGO;
            }

            // Crear un archivo de texto y escribir los datos del vector
            string filename = folderName + "/input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(SIZE)<< endl; // Escribir el tamaño del vector en la primera línea del archivo

            std::nth_element(A, A + SIZE/2, A + SIZE);

            for (int i = 0; i < SIZE; i++) {
                archivo << A[i] << " "<<endl;
            }

            archivo.close(); // Cerrar el archivo

            SIZE = SIZE + 10000;
        }

    }


    return 0;
}
