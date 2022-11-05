#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) c.begin(), c.end()
#define nl "\n"
int dp[100005];

vector<int> v(100005);
int LIS(int i)
{
    if (dp[i] != -1)
        return dp[i];
    int mx = 1;
    for (int j = 0; j < i; j++)
    {
        if (v[i] > v[j])
        {
            mx = max(mx, LIS(j) + 1);
        }
    }
    return dp[i] = mx;
}
int32_t main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int max_count = 0;
    for (int i = 0; i < n; i++)
    {
        max_count = max(max_count, LIS(i));
    }
    cout << max_count << nl;
}
