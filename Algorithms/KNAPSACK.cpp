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
ll max(ll a, ll b) { return a > b ? a : b; }
ll knapSack(vll profit, vll weight, ll capacity, ll items)
{
    ll store[items + 1][capacity + 1];
    for (ll i = 0; i <= items; i++)
    {
        for (ll j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                store[i][j] = 0;
            else if (profit[i - 1] <= j)
                store[i][j] = max(weight[i - 1] + store[i - 1][j - profit[i - 1]], store[i - 1][j]);
            else
                store[i][j] = store[i - 1][j];
        }
    }
    return store[items][capacity];
}
void solve()
{
    ll capacity, items;
    cin >> capacity >> items;

    vll profit(items), weight(items);

    for (int i = 0; i < items; i++)
    {
        cin >> profit[i] >> weight[i];
    }
    ll max = knapSack(profit, weight, capacity, items);
    cout << max << nl;
}
int32_t main()
{
    fast;

    solve();
    return 0;
}


/**
Input:

4 5
1 8
2 4
3 0
2 5
2 3

Output:
13
*/
