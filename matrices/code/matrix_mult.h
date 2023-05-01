#include <iostream>
#include <vector>
#include <functional>

using namespace std;

//PARA TOMAR EL TIEMPO
template <typename Func>
long long execution_time_ms(Func function, const vector<vector<int> > &A, const vector<vector<int> > &B, string alg) {
  auto start_time = std::chrono::high_resolution_clock::now();
  function(A, B, alg);
  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

//LEER MATRIZ
void read_matrix(vector<vector<int> > &M){
  for(auto &row : M)
    {
      for(auto &element : row)
      {
        cin>>element;
        //cout<< "dato:" << element <<endl ;
      }
    }
}

//IMPRIMIR MATRIZ
void print_matrix(const vector<vector<int> > &M){
  for(int i = 0; i < M.size(); i++){
    for(int j = 0; j < M[i].size(); j++)
      cout<<M[i][j]<<" ";
    cout<<endl;
  }
}

//MULTIPLICACION STANDARD
vector<vector<int> > standard(const vector<vector<int> > &A, const vector<vector<int> > &B) {
  int n = A.size();
  int m = A[0].size();
  int k = B[0].size();

  vector<vector<int> > C(n, vector<int>(k, 0));

  for(int i = 0; i < n; i++) 
    for(int j = 0; j < k; j++)
      for(int k = 0; k < m; k++)
        C[i][j] += A[i][k] * B[k][j];

  return C;
}

//MULTIPLICACION TRANSPUESTA
vector<vector<int> > transpose(const vector<vector<int> > &A, const vector<vector<int> > &B) {
  int n = A.size();
  int m = A[0].size();
  int k = B[0].size();

  vector<vector<int> > Bt(k, vector<int>(m, 0));

  for(int i = 0; i < k; i++) 
    for(int j = 0; j < m; j++) 
      Bt[i][j] = B[j][i];

  vector<vector<int> > C(n, vector<int>(k, 0));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < k; j++){
      int dotProduct = 0;
      for(int k = 0; k < m; k++)
        dotProduct += A[i][k] * Bt[j][k];
      C[i][j] = dotProduct;
    }

  return C;
}          





//STRASSEN
vector<vector<int> > add_matrices(const vector<vector<int> >& A, const vector<vector<int> >&B) {
    int n = A.size();
    vector<vector<int> > C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int> > subtract_matrices(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    int n = A.size();
    vector<vector<int> > C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int> > strassen(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    int n = A.size();
    if (n == 1) {
        vector<vector<int> > C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int k = n / 2;

    // Divide las matrices A y B en submatrices más pequeñas
    vector<vector<int> > A11(k, vector<int>(k)), A12(k, vector<int>(k)),
                       A21(k, vector<int>(k)), A22(k, vector<int>(k)),
                       B11(k, vector<int>(k)), B12(k, vector<int>(k)),
                       B21(k, vector<int>(k)), B22(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Calcula los 7 productos de Strassen
    vector<vector<int> > P1 = strassen(add_matrices(A11, A22), add_matrices(B11, B22));
    vector<vector<int> > P2 = strassen(add_matrices(A21, A22), B11);
    vector<vector<int> > P3 = strassen(A11, subtract_matrices(B12, B22));
    vector<vector<int> > P4 = strassen(A22, subtract_matrices(B21, B11));
    vector<vector<int> > P5 = strassen(add_matrices(A11, A12), B22);
    vector<vector<int> > P6 = strassen(subtract_matrices(A21, A11), add_matrices(B11, B12));
    vector<vector<int> > P7 = strassen(subtract_matrices(A12, A22), add_matrices(B21, B22));

    // Combina los productos de Strassen para formar la matriz resultante
    vector<vector<int> > C11(k, vector<int>(k)), C12(k, vector<int>(k)),
                   C21(k, vector<int>(k)), C22(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C11[i][j] = P1[i][j] + P4[i][j] - P5[i][j] + P7[i][j];
            C12[i][j] = P3[i][j] + P5[i][j];
            C21[i][j] = P2[i][j] + P4[i][j];
            C22[i][j] = P1[i][j] - P2[i][j] + P3[i][j] + P6[i][j];
        }
    }

    // Combina las submatrices en una sola matriz
    vector<vector<int> > C(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
    return C;
}

vector<vector<int> > strassen_llamada(const vector<vector<int> > &A, const vector<vector<int> > &B) 
{

    vector<vector<int> > C = strassen(A, B);

    return C;
}          
//FIN STRASSEN


vector<vector<int> > matrix_multiplication(const vector<vector<int> > &A, const vector<vector<int> > &B, string alg){

  if (alg=="strassen") {return strassen_llamada(A, B); }
  if (alg=="transpose") {return transpose(A, B); }
  if (alg=="standard") {return standard(A, B); }

}


