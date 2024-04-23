#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

namespace matrix_rr {
    void printmatrix(vector<vector<double>> A, int n) // Outputs the matrix
    {
        int p = n;
        int q = n+1;

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                cout << setw(7) << setprecision(4) << A[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    void RowReduce(vector<vector<double>> A, int n)
    {
        const int nrows = n; // number of rows
        const int ncols = n+1; // number of columns

        int lead = 0;

        while (lead < nrows) {
            float d, m;

            for (int r = 0; r < nrows; r++) { // for each row ...
                /* calculate divisor and multiplier */
                d = A[lead][lead];
                m = A[r][lead] / A[lead][lead];

                for (int c = 0; c < ncols; c++) { // for each column ...
                    if (r == lead)
                        A[r][c] /= d;               // make pivot = 1
                    else
                        A[r][c] -= A[lead][c] * m;  // make other = 0
                }
            }

            lead++;
            printmatrix(A, n);
        }
    }
}