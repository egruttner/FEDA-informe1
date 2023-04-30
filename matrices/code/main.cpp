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
  int N;
  int n_1;
  int i;
  int num_experimentos;

  string algoritmo_seleccionado;
  string nombre_archivo_salida;

  //TIPOS DE PRUEBAS
  switch(atoi(argc[1])){
    case 3: algoritmo_seleccionado = "strassen"; break;
    case 2: algoritmo_seleccionado = "transpose"; break;
    default: algoritmo_seleccionado = "standard"; break;
  }

  cout<<"INICIO"<<endl;

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

    return 0;
  }

  //GENERA SALIDA ARCHIVO CSV PARA GRAFICAR
  nombre_archivo_salida = "csv/" + algoritmo_seleccionado + "_results.csv";
  ofstream outfile(nombre_archivo_salida);
  outfile <<  "n,tiempo[ms]\n";

  //Parámetros de ejecución
  n_1 = 0;
  N = 1000; //1000
  i = 100;
  num_experimentos = 10; //10


/*
//Parámetros de ejecución
  n_1 = 0;
  N = 10000; //1000
  i = 100;//100 incremento
  numero_de_experimentos = 10; //10
*/

  for(int n = n_1; n <= N; n += i)
  {
    cout<<n<<endl;
    double mm_total_time = 0;
    vector<vector<int> > M_A(n,vector<int>(n,0)), M_B(n,vector<int>(n,0));
    for(int j = 0; j < num_experimentos; j++){ 
      long long single_execution_time = execution_time_ms(matrix_multiplication, M_A, M_B, algoritmo_seleccionado);
      mm_total_time += single_execution_time;
    }
    double mm_avg_time = mm_total_time / num_experimentos;
    outfile << n << "," << mm_avg_time <<endl;

  }
  outfile.close(); 
  return 0;
}
