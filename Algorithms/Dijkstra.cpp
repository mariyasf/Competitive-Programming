
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long int>
#define vpii vector<pair<int, int>>
#define spii set<pair<int, int>>
#define all(x) x.begin(), x.end()
#define mp(x, y) make_pair(x, y)
#define rall(x) x.rbegin(), x.rend()
#define inf 10e7

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, e;
    cin >> n >> e;
    vi dist(n + 1, inf);

    vector<vpii> graph(n + 1);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].pb({v, w});
        // graph[v].pb({u, w});
    }

    int src;
    cin >> src;

    dist[src] = 0;
    spii s;

    //{wt,src};

    s.insert({0, src});

    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);

        for (auto it : graph[x.ss])
        {
            if (dist[it.ff] > dist[x.ss] + it.ss)
            {
                s.erase({dist[it.ff], it.ff});
                dist[it.ff] = dist[x.ss] + it.ss;
                s.insert({dist[it.ff], it.ff});
            }
        }
    }

    for (auto i = 1; i <= n; i++)
    {
        if (dist[i] < inf)
        {
            cout << dist[i] << ' ';
        }
        else
            cout << -1 << ' ';
    }

    return 0;
}
// INPUT

// 6 8
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 6 1
// 5 4 2
// 5 6 5
// 1

// OUTPUT

//  0 2 3 8 6 9
