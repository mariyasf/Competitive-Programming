#include <bits/stdc++.h>
using namespace std;
int mat[10], seq[10][10], new_mat[10][10];
void print_optimal(int i, int j)
{
    if (i == j)
        printf("A%d", i + 1);
    else
    {
        printf("(");
        print_optimal(i, seq[i][j]);
        print_optimal(seq[i][j] + 1, j);
        printf(")");
    }
}
int main()
{
    int n, i, j, k, len, cost;
    cin >> n; // 4
    for (i = 0; i < n; i++)
        cin >> mat[i]; // 10 100 5 50
    for (len = 1; len < n; len++)
        for (i = 0; i < n - len; i++)
        {
            j = i + len;
            new_mat[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                cost = new_mat[i][k] + new_mat[k + 1][j] + (mat[i] * mat[k + 1] * mat[j + 1]);
                if (cost < new_mat[i][j])
                {
                    new_mat[i][j] = cost;
                    seq[i][j] = k;
                }
            }
        }
    cout << "Minimum number of multiplications is: " << new_mat[0][n - 2]; // 7500
    printf("\nMultiplication Sequence : ");
    print_optimal(0, n - 2); //((A1A2)A3)
    return 0;
}