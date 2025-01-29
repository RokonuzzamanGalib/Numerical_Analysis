#include <iostream>
#include <iomanip>

using namespace std;

#define N 3

void gaussElimination(double A[N][N+1]) {
    
    for (int i = 0; i < N; i++) {
        double pivot = A[i][i];
        for (int j = i; j < N + 1; j++) {
           A[i][j] = A[i][j] / pivot;
        }

        for (int k = i + 1; k < N; k++) {
            double factor = A[k][i];
            for (int j = i; j < N + 1; j++) {
              A[k][j] = A[k][j] - factor * A[i][j];
            }
        }
    }

    double solution[N];
    for (int i = N - 1; i >= 0; i--) {
        solution[i] = A[i][N];
        for (int j = i + 1; j < N; j++) {
           solution[i] = solution[i] - A[i][j] * solution[j];
        }
    }


    cout << "Solution:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

int main() {
 
    double A[N][N + 1] = {
        {2, 3, 1, 5},
        {4, 7, 3, 10},
        {6, 18, 5, 15}
    };

    gaussElimination(A);

    return 0;
}
