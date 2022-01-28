#include <bits/stdc++.h>

using namespace std;

#define ll long long int

vector<ll> adjlist[50001];
ll vis[50001] = {0}, cnt;

void DFS(ll source)
{
    if (vis[source] != 0)
        return;

    vis[source] = 1;
    for (int i = 0; i < adjlist[source].size(); i++)
    {
        if (vis[adjlist[source][i]] == 0)
        {
            cnt++;
            DFS(adjlist[source][i]);
        }
    }
}

int main()
{

    int c = 0, t, n, e;
    cin >> t;

    while (t--)
    {
        cin >> n >> e;

        while (e--)
        {
            ll u, v;
            cin >> u >> v;

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        ll Mutual = 0;

        for (int i = 0; i < n; i++)
        {
            cnt = 1;
            if (vis[i + 1] == 0)
            {
                DFS(i + 1);
            }
            // cout << cnt << ' ';
            Mutual = max(Mutual, cnt);
        }
        // cout << endl;

        cout << Mutual << endl;

        for (int i = 0; i <= n; i++)
        {
            adjlist[i].clear();
        }
        memset(vis, 0, sizeof(vis));
    }

    return 0;
}
