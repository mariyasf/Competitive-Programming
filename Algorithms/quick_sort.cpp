#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[e], pindex = s;
    for (int i = s; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            // swap(arr[pindex++], arr[i]);

            int temp = arr[pindex];
            arr[pindex] = arr[i];
            arr[i] = temp;
            pindex++;
        }
    }
    int temp = arr[pindex];
    arr[pindex] = arr[e];
    arr[e] = temp;

    // swap(arr[pindex], arr[e]);
    return (pindex);
}

void QuickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    if (s < e)
    {
        int p = partition(arr, s, e);
        QuickSort(arr, s, p - 1);
        QuickSort(arr, p + 1, e);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nBefore Sort: \n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    QuickSort(arr, 0, n - 1);

    cout << "\nSorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
