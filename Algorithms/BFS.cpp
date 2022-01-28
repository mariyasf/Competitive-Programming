#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ull unsigned long long int
#define pi acos(-1)
#define MOD 1000000007

ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; // kings move - U, D, R, L, LU, RU, LD, RD

vector<ll> adjlist[10];
ll vis[10]; // max node constraint should be in the size

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
            { // vis[2] == -1?
                q.push(adjlist[v][i]);
                vis[adjlist[v][i]] = vis[v] + 1;
            }
        }
    }
}

int main()
{
    ll node, edge, x, y;
    cin >> node >> edge;
    while (edge--)
    {
        cin >> x >> y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    BFS(1); // 1 = source, source can be any node

    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << "Shortest Path From 1 is " << vis[n] << endl;
    }

    //  for(int i = 1; i <= node; i++) {
    //     cout << i << " -> ";
    //     for(int j = 0; j < adjlist[i].size(); j++) {
    //         cout << adjlist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}