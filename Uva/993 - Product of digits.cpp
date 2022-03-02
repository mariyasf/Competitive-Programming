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

void solve()
{
    ll n, m;
    cin >> n;
    vi v;
    m = n;
    if (n == 1)
    {
        cout << n << nl;
        return;
    }
    for (int i = 9; i >= 2; i--)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                v.pb(i);
                n /= i;
            }
        }
    }
    ll ans = 1;
    for (int i = 0; i < v.size(); i++)
    {
        ans *= v[i];
    }
    if (ans == m)
    {
        sort(all(v));
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << nl;
    }
    else
        cout << -1 << nl;
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
