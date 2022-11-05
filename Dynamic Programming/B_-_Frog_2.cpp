/*                Problem ID : B_-_Frog_2.cpp */
/*             Date: 2022-11-05 11:42:36 */
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
ll Max(ll a, ll b)
{
    return (a >= b ? a : b);
}
int h[100005];
int dp[100005];

int cost(int i, int m)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int _cost = INT_MAX;
    for (int j = 1; j <= m; j++)
    {
        if (i - j >= 0)
            _cost = min(_cost, cost(i - j, m) + abs(h[i] - h[i - j]));
    }

    return dp[i] = _cost;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    cout << cost(n - 1, m) << nl;
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

    // test();
    solve();
    return 0;
}
