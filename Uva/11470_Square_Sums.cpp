/*                Problem ID : 11470_Square_Sums.cpp */
/*             Date: 2023-09-22 09:54:50 */
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
#define mpsc map<char, ll>
#define mpsi map<string, ll>
#define pq priority_queue<ll>
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
ll Max(ll a, ll b)
{
    return (a >= b ? a : b);
}

int32_t main()
{
    fast;

    ll n;
    ll c = 1;
    while (cin >> n, n)
    {
        int arr[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << "Case " << c++ << ": ";
        vll str;

        for (int i = 0; i < n / 2; i++)
        {
            ll sum = 0;
            for (int j = i; j < n - i; j++)
            {
                sum += arr[i][j];
            }
            // cout << sum << ' ';
            for (int j = i + 1; j < n - i; j++)
            {
                sum += arr[j][i];
            }
            for (int j = i + 1; j < n - i; j++)
            {
                sum += arr[j][n - i - 1];
            }
            // cout << sum << ' ';
            for (int j = i + 1; j < n - i - 1; j++)
            {
                sum += arr[n - i - 1][j];
            }
            // cout << sum << ' ';
            str.pb(sum);
        }
        if (n % 2)
            str.pb(arr[n / 2][n / 2]);
        for (int i = 0; i < str.size() - 1; i++)
            cout << str[i] << ' ';
        cout << str[str.size() - 1] << endl;
    }

    return 0;
}
