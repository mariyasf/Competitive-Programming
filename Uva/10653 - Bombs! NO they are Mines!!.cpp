#include <bits/stdc++.h>
#define ll long long
using namespace std;

int vx[4] = {0, 0, 1, -1}, vy[4] = {1, -1, 0, 0};

int row, col;
ll adjlist[1001][1001];
ll vis[1001][1001]; // max node constraint should be in the size

bool ok(int u, int v)
{
    return (u >= 0 && v >= 0 && u < row && v < col && adjlist[u][v] != 1);
}

void BFS(ll source1, ll source2)
{
    memset(vis, -1, sizeof(vis)); // -1 = unvisited
    vis[source1][source2] = 0;    // visited

    queue<ll> qx, qy;
    qx.push(source1);
    qy.push(source2);

    while (!qx.empty() && !qy.empty())
    {
        ll v = qx.front(), u = qy.front();
        qx.pop(), qy.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = v + vx[i], y = u + vy[i];

            if (ok(x, y))
            { // vis[2] == -1?
                if (vis[x][y] == -1)
                {
                    qx.push(x), qy.push(y);

                    vis[x][y] = vis[v][u] + 1;
                }
            }
        }
    }
}

int main()
{

    while (cin >> row >> col && row && col)
    {
        memset(adjlist, 0, sizeof(adjlist));

        int t;

        cin >> t;

        while (t--)
        {
            int r, n;
            cin >> r >> n;

            for (int i = 0; i < n; i++)
            {
                int m;
                cin >> m;
                adjlist[r][m] = 1;
            }
        }
      

        int startx, starty, endx, endy;
        cin >> startx >> starty >> endx >> endy;

        BFS(startx, starty);

        cout << vis[endx][endy] << endl;
    }

    return 0;
}
