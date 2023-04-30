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
  string algoritmo_seleccionado;
  string outfile_name;

  cout<<"INICIO"<<endl;

  //TIPOS DE PRUEBAS
  switch(atoi(argc[1])){
    case 4: algoritmo_seleccionado = "sortinterno"; break;
    case 3: algoritmo_seleccionado = "quicksort"; break;
    case 2: algoritmo_seleccionado = "mergesort"; break;
    case 1: algoritmo_seleccionado = "selection"; break;

    default: algoritmo_seleccionado = ""; break;
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

    outfile_name = "csv/" + algoritmo_seleccionado + "_results.csv";
    ofstream outfile(outfile_name,std::ios::app);

    double mm_total_time = 0;
    int numero_de_experimentos=1;
    for(int j = 0; j < numero_de_experimentos; j++){ 
      long long single_execution_time = execution_time_ms(vector_ordena, M_A, algoritmo_seleccionado);
      mm_total_time += single_execution_time;
    }
    double mm_avg_time = mm_total_time / numero_de_experimentos;
    outfile << n << "," << mm_avg_time <<endl;
    outfile.close(); 

  }
  else
  //SINO CREA EL ENCABEZADO PARA GUARDAR EL CSV
  {
    outfile_name = "csv/" + algoritmo_seleccionado + "_results.csv";
    ofstream outfile(outfile_name);
    outfile << "n,tiempo[ms]\n";
  }


}
