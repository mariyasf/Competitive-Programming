#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define all(c) c.begin(), c.end()
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long int>
#define vpii vector<pair<int, int>>
#define mpi map<int, int>
#define mpl map<ll, ll>
#define mpsi map<string, ll>
#define maap(x, y) make_pair(x, y)
#define rall(x) x.rbegin(), x.rend()
#define nl "\n"
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define YES cout << "YES" << endl;
int Ceil(int a, int b)
{
    return (a + b - 1) / b;
}
int Floor2(int a, int b)
{
    return floor((double)a / (double)b);
}

ll cnt = 0;
void merge(ll *arr, ll start, ll mid, ll end)
{
    ll size = end - start + 1;
    ll temp[size];

    ll i = start, j = mid + 1, k = 0;

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
            cnt += (mid + 1 - i);
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
void mergeSort(ll *arr, ll left, ll right)
{

    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
void solve()
{
    ll n;
    cin >> n;
    ll v[n];
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    cnt = 0;
    mergeSort(v, 0, n - 1);
    cout << cnt << nl;
}
void test()
{
    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solve();
    }
}

int32_t main()
{
    fast;

    test();
    // solve();
    return 0;
}
