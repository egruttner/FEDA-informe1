#include <iostream>
#include <vector>
#include <functional>

using namespace std;

//PARA TOMAR EL TIEMPO
template <typename Func>
long long execution_time_ms(Func function, const vector<int> &A, string alg) {
  auto start_time = std::chrono::high_resolution_clock::now();
  function(A, alg);
  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

//LEER VECTOR DESDE INPUT
void read_vector(vector<int> &M){
  for(auto &row : M)
    {
        cin>>row;
    }
}

//IMPRIMIR VECTOR
void print_vector(const vector<int> &M){
  int n=M.size();

  cout.flush();

  for(int i = 0; i < n; i++){
      cout<<M[i]<<" ";
    cout<<endl;
  }
}

//SELECTION SORT
vector<int> selection(const vector<int> &A) {

  int i, j, min_idx, temp;
  int n=A.size();
  
  vector<int> C = A;

  for (i = 0; i < n-1; i++) {
      min_idx = i;
      for (j = i+1; j < n; j++)
          if (C[j] < C[min_idx])
              min_idx = j;

      temp = C[i];
      C[i] = C[min_idx];
      C[min_idx] = temp;

  }

  return C;

}
        

//MERGESORT
//0.- Función extra para hacer merge
void merge(vector<int>& v, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

//1.- Para llamar recursivamente
void mergeSort(vector<int>& v, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);

        // Merge the two subvectors without using merge() function
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = v[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = v[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                v[k] = L[i];
                i++;
            }
            else {
                v[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            v[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            v[k] = R[j];
            j++;
            k++;
        }
    }
}


//2.- Encabezado de la llamada
vector<int> mergesort_llamada(const vector<int> &A) {

  int n = A.size();
  vector<int> C = A;

  mergeSort(C, 0, n - 1);

  return C;
}          


//QUICKSORT

//
void swap(vector<int>& vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

// Función para ordenar un vector utilizando Quicksort
void quicksort(vector<int>& vec, int inicio, int fin) {
    if (inicio < fin) {
        // Escoge el último elemento del vector como pivote
        int pivote = vec[(inicio+fin)/2];

        // Particiona el vector alrededor del pivote
        int i = inicio - 1;
        for (int j = inicio; j <= fin - 1; j++) {
            if (vec[j] < pivote) {
                i++;
                swap(vec, i, j);
            }
        }
        swap(vec, i + 1, fin);

        // Recursivamente ordena las dos mitades del vector
        int p = i + 1;
        quicksort(vec, inicio, p - 1);
        quicksort(vec, p + 1, fin);
    }
}


//2.- Encabezado de la llamada
vector<int> quicksort_llamada(const vector<int> &A) {

  int n = A.size();
  vector<int> C = A;
  quicksort(C,0,n-1); 
  return C;
}          


//SORTINTERNO
vector<int> sortinterno(const vector<int> &A) {

  int n = A.size();
  vector<int> C = A;

  sort(C.begin(),C.end());

  return C;
}    

//CENTRO DE LLAMADA DE FUNCIONES
vector<int> vector_ordena(const vector<int> &A, string alg){

  if (alg=="selection") {return selection(A); }
  if (alg=="quicksort") {return quicksort_llamada(A); }
  if (alg=="mergesort") {return mergesort_llamada(A); }
  if (alg=="sortinterno") {return sortinterno(A); }

}
