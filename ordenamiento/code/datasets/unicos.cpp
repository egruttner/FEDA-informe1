#include <iostream>
#include <fstream>
#include <random>

using namespace std;

const int ARRAY_SIZE = 10;
const int NUM_FILES = 5;

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
        for (int i = 0; i < size; ++i) {
            file << arr[i] << " " <<endl;
        }
        file.close();
        cout << "Archivo " << filename << " generado correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo " << filename << "." << endl;
    }
}

int main() {
    for (int i = 1; i <= NUM_FILES; ++i) {
        int arr[ARRAY_SIZE];
        for (int j = 0; j < ARRAY_SIZE; ++j) {
            arr[j] = j + 1;
        }
        shuffleArray(arr, ARRAY_SIZE);
        string filename = "array_" + to_string(i) + ".txt";
        writeArrayToFile(arr, ARRAY_SIZE, filename);
    }
    return 0;
}
