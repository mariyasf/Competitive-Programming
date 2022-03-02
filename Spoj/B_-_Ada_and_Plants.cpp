// https://www.spoj.com/problems/ADAPLANT/

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
    cin >> n >> m;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    mpl mp;
    set<ll> s;
    for (int i = 0; i <= min(n - 1, m + 1); i++)
    {
        mp[v[i]]++;
        s.insert(v[i]);
    }
    auto a = *(s.begin()), b = *(s.rbegin());
    ll ans = abs(a - b);
    // cout << ans << ' ' << a << ' ' << c << nl;

    ll left = 0, right = m + 2;
    while (right < n)
    {
        if (mp[v[left]] == 1)
        {
            s.erase(v[left]);
        }

        mp[v[left]]--;

        s.insert(v[right]);
        mp[v[right]]++;

        a = *(s.begin()), b = *(s.rbegin());
        ll res = abs(a - b);

        ans = max(ans, res);
        left++, right++;
    }
    cout << ans << nl;
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
