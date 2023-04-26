#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>


using namespace std;

int MAX_SIZE = 1000; // Máximo tamaño del arreglo
const int NUM_FILES = 10; // Número de archivos a generar
const int RANGO = 10000; // Rango de números


void shuffleArray(int arr[], int size) {
    random_device rd;
    mt19937 gen(rd());
    for (int i = 0; i < size; ++i) {
        int j = uniform_int_distribution<>(i, size - 1)(gen);
        swap(arr[i], arr[j]);
    }
}

void writeArrayToFile(int arr[], int size, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << size << endl; // Escribir el tamaño del vector en la primera línea del archivo

        for (int i = 0; i < size; ++i) {
            file << arr[i] << " " <<endl;
        }
        file.close();
        cout << "Archivo " << filename << " generado correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo " << filename << "." << endl;
    }
}



int main()
{

    int opcion;//En esta variable estará almacenado el nombre ingresado.
    cout << "1-desordenado_repetido 2-desordenado_unico 3-ordenado_repetido 4-ordenado_reversa" << endl;
    cin >> opcion; //Se lee el nombre

    switch(opcion)
    {
        case 1: cout<<"desordenado_repetido"<<endl; break;
        case 2: cout<<"desordenado_unico"<<endl; break;
        case 3: cout<<"ordenado_repetido"<<endl; break;
        case 4: cout<<"ordenado_reversa"<<endl; break;

        /*
        
        --parcialmente ordenados
        int main() {
            int nums[] = {5, 8, 2, 10, 1, 7, 4, 6, 3, 9};

            std::partial_sort(nums, nums + 5, nums + 10);

            for (int i = 0; i < 10; ++i) {
                std::cout << nums[i] << " ";
            }

            return 0;
        }

        En este ejemplo, creamos un array de enteros desordenado llamado nums con 10 elementos. Luego, usamos partial_sort para ordenar los primeros 5 elementos del array, dejando el resto en cualquier orden. Finalmente, imprimimos el array para ver el resultado.
        ** -> acepta diagonal

        --semiordenados
        int main() {
            int nums[] = {5, 8, 2, 10, 1, 7, 4, 6, 3, 9};

            std::nth_element(nums, nums + 5, nums + 10);

            for (int i = 0; i < 10; ++i) {
                std::cout << nums[i] << " ";
            }

            return 0;
        }

        En este ejemplo, creamos un array de enteros desordenado llamado nums con 10 elementos. Luego, usamos nth_element para ordenar el elemento en la posición 5 del array, dejando los elementos antes del quinto en cualquier orden y los elementos después del quinto también en cualquier orden. Finalmente, imprimimos el array para ver el resultado.
        */

        default: cout<<"desordenado_repetido"<<endl; break;
    }

    srand(time(NULL)); // Inicializar el generador de números aleatorios con la hora actual

    if (opcion==1) //desordenado_repetido
    {
        for (int f = 1; f <= NUM_FILES; f++) {
            int A[MAX_SIZE];// Vector A

            int n = rand() % MAX_SIZE + 2; // Tamaño de la matriz (aleatorio entre 1 y MAX_SIZE)

            for (int i = 0; i < n; i++) {
                A[i] = rand() % RANGO;
            }

            // Crear un archivo de texto y escribir los datos del vector
            string filename = "input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(n)<< endl; // Escribir el tamaño del vector en la primera línea del archivo
            
            for (int i = 0; i < n; i++) {
                archivo << A[i] << " "<<endl;
            }

            archivo.close(); // Cerrar el archivo

            MAX_SIZE = MAX_SIZE+1000;
        }
    }

    if (opcion==2) //desordenado_unico
    {        
        for (int i = 1; i <= NUM_FILES; ++i) {
            int arr[MAX_SIZE];
            for (int j = 0; j < MAX_SIZE; ++j) {
                arr[j] = j + 1;
            }
            shuffleArray(arr, MAX_SIZE);
            string filename = "input" + to_string(i) + ".txt";
            writeArrayToFile(arr, MAX_SIZE, filename);

            MAX_SIZE = MAX_SIZE+1000;

        }

    }

    if (opcion==3) //ordenado_repetido
    {
        for (int f = 1; f <= NUM_FILES; f++) {
            int A[MAX_SIZE];// Vector A

            int n = rand() % MAX_SIZE + 2; // Tamaño del vector (aleatorio entre 1 y MAX_SIZE)

            for (int i = 0; i < n; i++) {
                A[i] = rand() % RANGO;
            }

            // Crear un archivo de texto y escribir los datos del vector
            string filename = "input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(n)<< endl; // Escribir el tamaño del vector en la primera línea del archivo
            sort(A, A + n);
            for (int i = 0; i < n; i++) {
                archivo << A[i] << " "<<endl;
            }

            archivo.close(); // Cerrar el archivo
        }

    }

    if (opcion==4) //ordenado_reversa
    {
        for (int f = 1; f <= NUM_FILES; f++) {
            int A[MAX_SIZE];// Vector A

            int n = rand() % MAX_SIZE + 2; // Tamaño del vector (aleatorio entre 1 y MAX_SIZE)

            for (int i = 0; i < n; i++) {
                A[i] = rand() % RANGO;
            }

            // Crear un archivo de texto y escribir los datos del vector
            string filename = "input" + to_string(f) + ".txt";
            ofstream archivo(filename);
            archivo << to_string(n)<< endl; // Escribir el tamaño del vector en la primera línea del archivo
            sort(A, A + n,greater<int>());

            for (int i = 0; i < n; i++) {
                archivo << A[i] << " "<<endl;
            }

            archivo.close(); // Cerrar el archivo
        }

    }

    return 0;
}
