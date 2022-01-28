#include <bits/stdc++.h>

using namespace std;

#define ll long long int
vector<ll> adjlist[21];
ll vis[100]; // max node constraint should be in the size

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

    int c = 1;
    ll common_border, n;
    while (cin >> common_border)
    {

        for (int i = 0; i < common_border; i++)
        {
            cin >> n;
            adjlist[1].push_back(n);
            adjlist[n].push_back(1);
        }

        for (int i = 1; i < 19; i++)
        {
            cin >> common_border;

            if (common_border == 0)
                continue;

            for (int j = 0; j < common_border; j++)
            {
                cin >> n;
                adjlist[i + 1].push_back(n);
                adjlist[n].push_back(i + 1);
            }
        }

        int count;
        cin >> count;
        cout << "Test Set #" << c++ << endl;

        for (int i = 0; i < count; i++)
        {
            int source, target;
            cin >> source >> target;
            BFS(source);
            printf("%2d to %2d: %d", source, target, vis[target]);
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < 21; i++)
        {
            adjlist[i].clear();
        }
    }

    return 0;
}
