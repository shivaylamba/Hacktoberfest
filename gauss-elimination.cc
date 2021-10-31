#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

template<typename T>
using Array = std::vector<T>;

template<typename T>
using Matrix = Array<Array<T>>;

const double EPS = 1e-9;

int solve(Matrix<double> A, Array<double> & x) {
    int n = (int) A.size();
    int m = (int) A[0].size() - 1;

    Array<double> pos (m, -1);
    for (int col = 0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i = row; i<n; ++i)
            if (abs(A[i][col]) > abs(A[sel][col]))
                sel = i;
        if (abs (A[sel][col]) < EPS)
            continue;
        for (int i = col; i <= m; ++i)
            std::swap(A[sel][i], A[row][i]);
        pos[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row) {
                double c = A[i][col] / A[row][col];
                for (int j = col; j <= m; ++j)
                    A[i][j] -= A[row][j] * c;
            }
        ++row;
    }

    x.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (pos[i] != -1)
            x[i] = A[pos[i]][m] / A[pos[i]][i];
    for (int i=0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j<m; ++j)
            sum += x[j]*A[i][j];
        if (abs(sum - A[i][m]) > EPS)
            return 0;
    }

    for (int i = 0; i < m; ++i)
        if (pos[i] == -1)
            return 3;
    return 1;
}

int main(int argc, char** argv) {
    Matrix<double> augmented_A = {
        {1, 1, 1, 1, 1, 1, 11.2345},
        {1, -2, 3, -4, 5, -6, 8.497},
        {2, 2, 0, -2, 0, 1, 21.9405},
        {-4, 0, 10, 0, 5, -11, -37.9855},
        {0, 1, -1, 2, -1, 0, .856},
        {1, -9, 0, 0, 0, -20, .99}
    };
    Array<double> x;

    solve(augmented_A, x);

    for(int i = 0; i < x.size(); ++i) {
        std::cout << "x" << (i + 1) << " = " << x[i] << std::endl; 
    }

    return 0;
}