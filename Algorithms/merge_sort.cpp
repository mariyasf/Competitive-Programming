#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{
    int size = end - start + 1;
    int temp[size];

    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];

            k += 1, i += 1;
        }
        else
        {
            temp[k] = arr[j];
            k += 1, j += 1;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        k += 1, i += 1;
    }

    while (j <= end)
    {
        temp[k] = arr[j];
        k += 1, j += 1;
    }

    for (int j = start; j <= end; j++)
    {
        arr[j] = temp[j - start];
    }
}
void mergeSort(int *arr, int left, int right)
{

    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Befor Sort: " << endl;
    for (int i = 0; i < n; i++)

    {
        cout << arr[i] << ' ';
    }

    mergeSort(arr, 0, n - 1);

    cout << endl
         << "After Sort: " << endl;
    for (int i = 0; i < n; i++)

    {
        cout << arr[i] << ' ';
    }
}