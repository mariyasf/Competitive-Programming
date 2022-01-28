// without recursion 


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    while (cin >> a >> b && a && b)
    {
        b++;
        ll ans = 1, count = 1;
        for (ll i = b; i <= a; i++)
        {
            ans *= i;
            ans /= count;
            count++;
        }
        cout << a << " things taken " << b - 1 << " at a time is " << ans << " exactly." << endl;
    }
}
