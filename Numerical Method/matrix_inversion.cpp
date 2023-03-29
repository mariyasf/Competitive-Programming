#include <bits/stdc++.h>
using namespace std;

#define vv vector<int>
const int row = 3, col = 3, n = 4; 

double determinant = 0;

// Function to print a matrix
void printMatrix(vector<vv> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
vv inversematrix(vector<vv> matrix)
{
    vv B(n - 1);
    vector<vv> A(n, vv(n + 1)), cofactor(n, vv(n + 1)), At(n, vv(n + 1));

    cout << "\nCoefficient Matrix A: \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            A[i][j] = matrix[i][j];
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "\nConstant Matrix B: \n";
    for (int i = 0; i < row; i++)
    {
        B[i] = matrix[i][3];
        cout << B[i] << "\n";
    }

    // finding determinant
    for (int j = 0; j < col; j++)
        determinant += (A[0][j] * (A[1][(j + 1) % 3] * A[2][(j + 2) % 3] - A[1][(j + 2) % 3] * A[2][(j + 1) % 3]));

    cout << "Determinant of A: " << determinant << endl;

    if (determinant == 0)
    {
        cout << "Given matrix does not have an inverse\n";
        exit(1);
    }
    else
    {
        cout << "A^-1 exists.\n";
    }

    // transpose matrix
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            At[j][i] = A[i][j];
    cout << "Transpose Matrix At: \n";

    // adjoint matrix
    cout << "Adjoint Matrix Adj(A): \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cofactor[i][j] = At[(i + 1) % 3][(j + 1) % 3] * At[(i + 2) % 3][(j + 2) % 3] - At[(i + 1) % 3][(j + 2) % 3] * At[(i + 2) % 3][(j + 1) % 3];
            cout << cofactor[i][j] << "\t";
        }
        cout << endl;
    }

    // matrix after multiplication
    cout << "\tAdj(A) * B: \n";
    vv X(3);
    for (int i = 0; i < row; i++)
    {
        int x = 0;
        for (int j = 0; j < col; j++)
            x += cofactor[i][j] * B[j];
        X[i] = x;
        cout << X[i] << endl;
    }
    return X;
}
int main()
{
    cout << "Given equations: \n";
    cout << "3x + y + 2z = 3\n2x - 3y - z = -3\nx + 2y + z = 4\n";

    int n = 3;
    vector<vv> matrix(n, vv(n + 1));

    // Taking input from user
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix : \n";
    printMatrix(matrix);

    // Applying matrix inversion method
    vv X = inversematrix(matrix);

    cout << "\nMatrix X:\n";
    string x = "XYZ";

    for (int i = 0; i < row; i++)
        cout << x[i] << " = " << (X[i] / determinant) << ", ";
}