#include <bits/stdc++.h>

using namespace std;

#define ll long long int

map<long long int, int> m;
vector<ll> adjlist[100];
ll vis[50];

void BFS(ll source)
{
    memset(vis, -1, sizeof(vis)); // -1 = unvisited
    vis[source] = 0;              // visited

    queue<ll> q;
    q.push(source);

    while (!q.empty())
    {
        ll v = q.front();
        q.pop();
        for (int i = 0; i < adjlist[v].size(); i++)
        {
            if (vis[adjlist[v][i]] == -1)
            {
                q.push(adjlist[v][i]);
                vis[adjlist[v][i]] = vis[v] + 1;
            }
        }
    }
}

int main()
{
    int c = 1, cc = 1;

    while (1)
    {
        int nc, cc = 1;

        cin >> nc;
        if (!nc)
            return 0;

        while (nc--)
        {
            ll x, y;
            cin >> x >> y;

            if (m[x] == 0)
            {
                m[x] = cc++;
            }

            if (m[y] == 0)
            {
                m[y] = cc++;
            }
            ll u = m[x], v = m[y];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        ll root, ttl;
        while (cin >> root >> ttl)
        {
            if (root == 0 && ttl == 0)
                break;
            BFS(m[root]);
            long long cnt = 0;

            for (long long i = 1; i < cc; i++)
            {
                if (vis[i] > ttl || vis[i] == -1)
                    cnt++;
            }
            cout << "Case " << c++ << ": " << cnt << " nodes not reachable from node "
                 << root << " with TTL = " << ttl << '.' << endl;
        }
        for (int i = 0; i <= cc; i++)
        {
            adjlist[i].clear();
        }
        m.clear();
    }

    return 0;
}


