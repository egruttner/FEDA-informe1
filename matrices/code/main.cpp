#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string.h>
#include "matrix_mult.h"
using namespace std;

int main(int argv, char* argc[]) {
  srand(time(NULL)); 

  int n;
  int m;
  int k;
  int numero_de_experimentos;
  string dir_csv;
  string algoritmo_seleccionado;
  string nombre_archivo_salida;

  cout<<"INICIO"<<endl;

  //TIPOS DE PRUEBAS
  switch(atoi(argc[1])){
    case 1: algoritmo_seleccionado = "standard"; break;
    case 2: algoritmo_seleccionado = "transpose"; break;
    case 3: algoritmo_seleccionado = "strassen"; break;

    default: algoritmo_seleccionado = ""; break;
  }

  switch(atoi(argc[3])){
    case 1: dir_csv = "csv/csv1/"; break;
    case 2: dir_csv = "csv/csv2/"; break;
    case 3: dir_csv = "csv/csv3/"; break;
    case 4: dir_csv = "csv/csv4/"; break;
    case 5: dir_csv = "csv/csv5/"; break;

    default: dir_csv = ""; break;
  }


  if((argv > 2) && (strcmp(argc[2],"--test") == 0)){

    //PARÁMETROS DE ENTRADA CON DIMENSIONES DE MATRICES
    cin>>n>>m>>k;

    //IMPRIME PARÁMETROS EN OUTPUT
    cout<< "n:" << n <<endl;
    cout<< "m:" << m <<endl;
    cout<< "k:" << k <<endl;
    
    //DEFINE MATRICES DE ENTRADA
    vector<vector<int> > M_A(n,vector<int>(m,0));   //MATRIZ A
    vector<vector<int> > M_B(m,vector<int>(k,0));   //MATRIZ B
    vector<vector<int> > result;  //MATRIZ RESULTADO

    //LEE MATRICES
    read_matrix(M_A);
    read_matrix(M_B);
    
    //IMPRIME MATRICES EN OUTPUT
    cout<< "Matriz A:"<<endl;
    print_matrix(M_A);
    cout<< "Matriz B:"<<endl;
    print_matrix(M_B);
    
    //EJECUTA CON EL ALGORITMO SELCCIONADO
    result = matrix_multiplication(M_A, M_B, algoritmo_seleccionado);
    cout<< "Resultado:"<<endl;

    //IMPRIME SALIDA EN OUTPUT
    print_matrix(result);

    nombre_archivo_salida = dir_csv + algoritmo_seleccionado + "_results.csv";
    ofstream outfile(nombre_archivo_salida,std::ios::app);

    double mm_total_time = 0;
    
    int numero_de_experimentos=1;

    for(int j = 0; j < numero_de_experimentos; j++){ 
      long long single_execution_time = execution_time_ms(matrix_multiplication, M_A, M_B, algoritmo_seleccionado);
      mm_total_time += single_execution_time;
    }
    double mm_avg_time = mm_total_time / numero_de_experimentos;

    if (atoi(argc[3])==3 || atoi(argc[3])==4)
    {
      outfile << m << "," << mm_avg_time <<endl;
    }
    else
    {
      outfile << n << "," << mm_avg_time <<endl;
    }

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
