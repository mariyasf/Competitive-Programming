#include <bits/stdc++.h>
using namespace std;
int arr[100], c = 0;

void activity(int a[], int b[], int n)
{
    int i = 0, j = 0;

    arr[0] = i + 1;
    c = 1;

    for (int j = 1; j < n; j++)
    {
        if (a[j] >= b[i])
        {
            arr[c++] = j + 1;
            i = j;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(b, b + n);
    activity(a, b, n);

    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << ' ';
    }
}