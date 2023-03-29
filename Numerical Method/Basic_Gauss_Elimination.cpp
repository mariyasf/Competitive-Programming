#include <bits/stdc++.h>
#define vv vector<double>

using namespace std;

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

// Function to perform Gauss elimination on a matrix
vv gaussElimination(vector<vv> matrix)
{
    int n = matrix.size();
    vv x(n);

    // Applying Gauss Elimination
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double ratio = matrix[j][i] / matrix[i][i];
            cout << ratio << ' ';
            for (int k = 0; k <= n; k++)
            {
                matrix[j][k] -= ratio * matrix[i][k];
                cout << matrix[j][k] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    // Back substitution
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= matrix[i][j] * x[j];
        }
        x[i] /= matrix[i][i];
    }

    return x;
}

int main()
{
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

    // Printing the matrix before Gauss elimination
    cout << "\nMatrix before Gauss Elimination:\n";
    printMatrix(matrix);

    // Applying Gauss elimination
    vv solution = gaussElimination(matrix);

    // Printing the solution
    cout << "Solution:\n";
    string x = "XYZ";
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " = " << solution[i] << endl;
    }

    return 0;
}
1) N significant digits 
2) Horner's Rule
3) Bisection Method
4) 