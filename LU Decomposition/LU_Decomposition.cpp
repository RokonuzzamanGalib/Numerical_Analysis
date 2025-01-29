#include <iostream>
#include <iomanip>

using namespace std;

#define N 3  

void LU_Decomposition(double A[N][N], double L[N][N], double U[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                L[i][j] = 1; 
            else
                L[i][j] = 0;

            U[i][j] = A[i][j]; 
        }
    }

  
    for (int k = 0; k < N; k++) {
        for (int i = k + 1; i < N; i++) {
            double factor = U[i][k] / U[k][k]; 
            L[i][k] = factor;
            for (int j = k; j < N; j++) {
                U[i][j] -= factor * U[k][j];
            }
        }
    }
}


void printMatrix(double mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(8)  << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
 
    double A[N][N] = {{2, 3, 1},{4, 7, 3}, {6, 18, 5}};
    double L[N][N], U[N][N];

    
    cout << "   Matrix (A): " << endl;
    printMatrix(A);
    cout<<"\n\tA=L*U"<<endl;

    LU_Decomposition(A, L, U);

    cout << " \nLower Triangular Matrix (L): " << endl;
    printMatrix(L);

    cout << "\n Upper Triangular Matrix (U): " << endl;
    printMatrix(U);

    return 0;
}
