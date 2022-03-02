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

#define meme(a) memset(a, 0, sizeof(a))
#define MAX 10000007
bool primes[MAX];
ll temp[MAX];
ll c;

int Ceil(int a, int b)
{
    return (a + b - 1) / b;
}
int Floor2(int a, int b)
{
    return floor((double)a / (double)b);
}
void Sieve()
{
    meme(primes);
    c = 0;
    primes[0] = primes[1] = 1;
    for (ll i = 2; i * i <= MAX; i++)
    {
        if (primes[i] == 0)
        {
            for (ll j = i * i; j <= MAX; j += i)
                primes[j] = 1;
        }
    }
    for (int i = 2; i < MAX; i++)
    {
        if (primes[i] == 0)
            temp[c] = i, c++;
    }
}

void solve()
{
    Sieve();
    ll n;

    while (cin >> n && n)
    {

        n = abs(n);
        ll max = 0, count = 0, m = n;

        for (ll i = 0; i < c; i++)
        {
            if (temp[i] > n)
                break;

            if (n % temp[i] == 0)
            {

                while (n % temp[i] == 0)
                {
                    n /= temp[i];
                }

                max = temp[i], count++;
            }
        }

        if (n != 1)
        {
            max = n, count++;
        }

        if (count >= 2)
            cout << max;
        else
            cout << -1;
        cout << nl;
    }
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
