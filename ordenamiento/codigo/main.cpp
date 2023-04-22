#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string.h>
#include "algoritmos_ordenamiento.h"
using namespace std;

int main(int argv, char* argc[]) {
  srand(time(NULL)); 

  int n;
  int m;
  int k;
  int N;
  int n_1;
  int i;
  int num_of_experiments;
  string algoritmo_seleccionado;
  string outfile_name;
  string column_names;

  cout<<"INICIO"<<endl;

  //TIPOS DE PRUEBAS
  switch(atoi(argc[1])){
    case 5: algoritmo_seleccionado = "sortinterno_mm"; break;
    case 4: algoritmo_seleccionado = "quicksort_mm"; break;
    case 3: algoritmo_seleccionado = "selection_mm"; break;
    case 2: algoritmo_seleccionado = "bubble_mm"; break;
    default: algoritmo_seleccionado = "mergesort_mm"; break;
  }

  if((argv > 2) && (strcmp(argc[2],"--test") == 0)){
    //LEE EL TAMAÑO DEL VECTOR
    cin>>n;

    //DEFINE MATRICES DE ENTRADA
    vector<int> M_A(n);   //MATRIZ A
    vector<int> result;  //MATRIZ RESULTADO

    //LEE VECTOR
    read_vector(M_A);
    
    //IMPRIME VECTOR EN OUTPUT
    cout<< "Vector inicial:"<<endl;
    print_vector(M_A);

    cout<<"Algoritmo seleccionado: "<< algoritmo_seleccionado<<endl;

    //EJECUTA CON EL ALGORITMO SELCCIONADO
    result = vector_ordena(M_A, algoritmo_seleccionado);
    cout<< "Resultado:"<<endl;

    //IMPRIME SALIDA EN OUTPUT
    print_vector(result);

    return 0;
  }


  outfile_name = algoritmo_seleccionado + "_results.csv";
  ofstream outfile(outfile_name);
  
  column_names = "n,tiempo[ms]\n";
  outfile << column_names;

  //Parámetros de ejecución
  i = 100;//100
  n_1 = 1;
  N = 1000; //1000
  num_of_experiments = 10; //10

  for(int n = n_1; n <= N; n += i){
    //cout<<n<<endl;
    double mm_total_time = 0;
    vector<int> V_A(n);
    for(int j = 0; j < num_of_experiments; j++){ 
      long long single_execution_time = execution_time_ms(vector_ordena, V_A, algoritmo_seleccionado);
      mm_total_time += single_execution_time;
    }
    double mm_avg_time = mm_total_time / num_of_experiments;
    outfile << n << "," << mm_avg_time <<endl;
  }
  outfile.close(); 
  return 0;



}
