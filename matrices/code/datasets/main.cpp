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

int n,m,k;

int A[1024][1024];
int B[1024][1024];


/*
1.- Cuadradas -> 10x10 -> 1000x1000
2.- Cuadradas potencia de 2 -> 2x2 -> 1024x1024
3.- Rectangulares 1 -> 
A
100x100
100x200
...
100x1000

B
100x100
200x100
...
1000x100

4.- Rectangulares 2 -> 
A
100x100
100x200
...
100x1000

B
100x100
200x200
...
1000x1000

5.- Rectangulares 3 -> 
A
100x100
200x200
...
1000x1000

B
100x100
200x100
...
1000x100

*/

int main()
{
    int opcion; //opción de generación seleccionada por el usuario
    string operacion = "";
    string folderName = "opcion";

    cout << "1-cuadradas 2-cuadradas_potencia_de_dos 3.-rectangular1 4.-rectangular2 5.-rectangular3" << endl;
    cin >> opcion; //Se lee la opción a usar para crear dataset

    srand(time(NULL)); // Inicializar el generador de números aleatorios con la hora actual

    if (opcion==1) //cuadradas
    {
        int n=100;
        int m=100;
        int k=100;

        //Crea carpeta para guardar datasets
        folderName="input1";
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }
        for (int f = 1; f <= NUM_FILES; f++) {

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
                for (int j = 0; j < m; j++) {
                    archivo << A[i][j] << " ";
                }
                archivo << endl;
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < k; j++) {
                    archivo << B[i][j] << " ";
                }
                archivo << endl;
            }

            archivo.close(); // Cerrar el archivo

            n=n+100;
            m=m+100;
            k=k+100;
        }

    }



    if (opcion==2) //cuadradas potencia dos
    {

        operacion = "cuadradas_potencia_de_dos";
        int potencia = 1;

        int n=2;
        int m=2;
        int k=2;

        //Crea carpeta para guardar datasets
        folderName="input2";
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }
        for (int f = 1; f <= NUM_FILES; f++) {

            n=pow(2,potencia);

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

            potencia++;

        }

    }

    if (opcion==3) //cuadradas
    {
        int n=100;
        int m=100;
        int k=100;

        //Crea carpeta para guardar datasets
        folderName="input3";
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }
        for (int f = 1; f <= NUM_FILES; f++) {

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
                for (int j = 0; j < m; j++) {
                    archivo << A[i][j] << " ";
                }
                archivo << endl;
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < k; j++) {
                    archivo << B[i][j] << " ";
                }
                archivo << endl;
            }

            archivo.close(); // Cerrar el archivo

            //n=n+100;
            m=m+100;
            //k=k+100;
        }

    }

    if (opcion==4) //cuadradas
    {
        int n=100;
        int m=100;
        int k=100;

        //Crea carpeta para guardar datasets
        folderName="input4";
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }
        for (int f = 1; f <= NUM_FILES; f++) {

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
                for (int j = 0; j < m; j++) {
                    archivo << A[i][j] << " ";
                }
                archivo << endl;
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < k; j++) {
                    archivo << B[i][j] << " ";
                }
                archivo << endl;
            }

            archivo.close(); // Cerrar el archivo

            //n=n+100;
            m=m+100;
            k=k+100;
        }

    }

    if (opcion==5) //cuadradas
    {
        int n=100;
        int m=100;
        int k=100;

        //Crea carpeta para guardar datasets
        folderName="input5";
        if (mkdir(folderName.c_str(), 0777) != 0) {
            cout << "Error al crear la carpeta." << endl;
        }
        for (int f = 1; f <= NUM_FILES; f++) {

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
                for (int j = 0; j < m; j++) {
                    archivo << A[i][j] << " ";
                }
                archivo << endl;
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < k; j++) {
                    archivo << B[i][j] << " ";
                }
                archivo << endl;
            }

            archivo.close(); // Cerrar el archivo

            n=n+100;
            m=m+100;
            //k=k+100;
        }

    }




    return 0;
}
