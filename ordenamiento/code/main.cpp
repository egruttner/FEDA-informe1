#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string.h>
#include "algoritmos_ordenamiento.h"
#include <fstream>

using namespace std;

int main(int argv, char* argc[]) {
  srand(time(NULL)); 

  int n;
  int numero_de_experimentos;
  string dir_csv;
  string algoritmo_seleccionado;
  string nombre_archivo_salida;

  cout<<"INICIO"<<endl;

  //TIPOS DE PRUEBAS
  switch(atoi(argc[1])){
    case 4: algoritmo_seleccionado = "sortinterno"; break;
    case 3: algoritmo_seleccionado = "quicksort"; break;
    case 2: algoritmo_seleccionado = "mergesort"; break;
    case 1: algoritmo_seleccionado = "selection"; break;

    default: algoritmo_seleccionado = ""; break;
  }

  switch(atoi(argc[3])){
    case 1: dir_csv = "csv/csv1/"; break;
    case 2: dir_csv = "csv/csv2/"; break;
    case 3: dir_csv = "csv/csv3/"; break;
    case 4: dir_csv = "csv/csv4/"; break;

    default: dir_csv = ""; break;
  }

  //SI ENTRA CON PARÁMETROS, REALIZA EL TEST
  if((argv > 2) && (strcmp(argc[2],"--test") == 0)){

    //LEE EL TAMAÑO DEL VECTOR
    cin>>n;

    //DEFINE MATRICES DE ENTRADA
    vector<int> M_A(n);   //MATRIZ A
    vector<int> result;  //MATRIZ RESULTADO

    //LEE VECTOR
    read_vector(M_A);
    
    //IMPRIME VECTOR EN OUTPUT
    cout<<"Algoritmo seleccionado: "<< algoritmo_seleccionado<<endl;
    cout<< "Vector inicial:"<<endl;
    print_vector(M_A);

    //EJECUTA CON EL ALGORITMO SELCCIONADO
    result = vector_ordena(M_A, algoritmo_seleccionado);
    cout<< "Resultado:"<<endl;

    //IMPRIME SALIDA EN OUTPUT
    print_vector(result);

    nombre_archivo_salida = dir_csv + algoritmo_seleccionado + "_results.csv";
    ofstream outfile(nombre_archivo_salida,std::ios::app);

    double mm_total_time = 0;
    int numero_de_experimentos=1;
    for(int j = 0; j < numero_de_experimentos; j++){ 
      long long single_execution_time = execution_time_ms(vector_ordena, M_A, algoritmo_seleccionado);
      mm_total_time += single_execution_time;
    }
    double mm_avg_time = mm_total_time / numero_de_experimentos;
    outfile << n << "," << mm_avg_time <<endl;
    outfile.close(); 
    
    return 0;
  }
  else
  //SINO CREA EL ENCABEZADO PARA GUARDAR EL CSV
  {
    nombre_archivo_salida = dir_csv + algoritmo_seleccionado + "_results.csv";
    ofstream outfile(nombre_archivo_salida);
    outfile << "n,tiempo[ms]\n";

    return 0;
  }


}
