#include <bits/stdc++.h>

using namespace std;

#define ll long long int

vector<ll> adjlist[50001];
ll vis[50001] = {0};

void DFS(ll source)
{
    if (vis[source] != 0)
        return;

    vis[source] = 1;
    for (int i = 0; i < adjlist[source].size(); i++)
    {
        if (vis[adjlist[source][i]] == 0)
            DFS(adjlist[source][i]);
    }
}

int main()
{
    int c = 1, n, e;

    while (cin >> n >> e)
    {
        if (n == 0 && e == 0)
            break;

        while (e--)
        {
            ll u, v;
            cin >> u >> v;

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        ll cc = 0;

        for (int i = 0; i < n; i++)
        {
            if (vis[i + 1] == 0)
            {
                cc++;
                DFS(i + 1);
            }
        }

        cout << "Case " << c++ << ": " << cc << endl;

        for (int i = 0; i <= n; i++)
        {
            adjlist[i].clear();
        }
        memset(vis, 0, sizeof(vis));
    }

    return 0;
}
