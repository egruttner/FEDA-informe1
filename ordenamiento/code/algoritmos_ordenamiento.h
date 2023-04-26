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

//LEER VECTOR
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

//BUBBLE SORT
vector<int> bubble(const vector<int> &A) {
  int i, j, min_idx, temp;
  int n=A.size();
  
  vector<int> C = A;

  for(int i=0; i<n-1; i++) {
      for(int j=0; j<n-i-1; j++) {
          if(C[j] > C[j+1]) {
              int temp = C[j];
              C[j] = C[j+1];
              C[j+1] = temp;
          }
      }
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
//1.- Para llamar recursivamente
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

}

//2.- Encabezado de la llamada
vector<int> quicksort_llamada(const vector<int> &A) {

  int n = A.size();
  vector<int> C = A;

  quickSort(C,0,n-1); 

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
  
  //if (alg=="bubble") {return bubble(A); }

  if (alg=="selection") {return selection(A); }
  if (alg=="quicksort") {return quicksort_llamada(A); }
  if (alg=="mergesort") {return mergesort_llamada(A); }
  if (alg=="sortinterno") {return sortinterno(A); }

}
