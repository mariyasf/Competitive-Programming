
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vpii vector<pair<int, int>>
#define spii set<pair<int, int>>
#define all(x) x.begin(), x.end()
#define mp(x, y) make_pair(x, y)
#define rall(x) x.rbegin(), x.rend()
#define inf 999

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, e;
    cin >> n >> e;
    vvi edges;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.pb({u, v, w});
        // graph[v].pb({u, w});
    }

    int src;
    cin >> src;
    vi dist(n, inf);

    dist[src] = 0;

    for (auto i = 0; i < n - 1; i++)
    {
        for (auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];

            dist[v] = min(dist[v], w + dist[u]);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';

    return 0;
}
// INPUT

// 7  10
// 1 2 6
// 1 3 5
// 1 4 5
// 2 5 -1
// 3 2 -2
// 3 5 1
// 4 3 -2
// 4 6 -1
// 5 7 3
// 6 7 3
// 1

// OUTPUT

//  0 1 3 5 0 4 3
