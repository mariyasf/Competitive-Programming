#include <bits/stdc++.h>

using namespace std;

#define ll long long
// ll bigmod(ll b, ll p, ll m)
// {
//     if (p == 0)
//         return 1;
//     ll ans = bigmod(b, p / 2, m);
//     ans = (ans * ans) % m;
//     if (p % 2 == 1)
//         ans = (ans * b) % m;
//     return ans;
// }

ll bigmod(ll n, ll p, ll m)
{
    if (p <= 0)
        return 1;

    if (p % 2 == 0)
    {
        ll ans = bigmod(n, p / 2, m);

        return ((ans % m) * (ans % m)) % m;
    }

    else
    {
        ll ans = bigmod(n, p - 1, m);

        return ((n % m) * (ans % m)) % m;
    }
}

int main()
{
    ll b, p, m;
    while (cin >> b >> p >> m)
    {

        cout << bigmod(b, p, m) << endl;
    }
    return 0;
}
