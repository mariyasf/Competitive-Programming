#include <bits/stdc++.h>
#define ll long long
using namespace std;

int vx[] = {0, 0, 1, 1, -1, -1, 1, -1};
int vy[] = {1, -1, 1, -1, 1, -1, 0, 0};

int n;
char adjlist[1001][1001];
ll vis[1001][1001]; // max node constraint should be in the size

bool ok(int u, int v)
{
    return (u >= 0 && v >= 0 && u <= n && v <= n && adjlist[u][v] == '1');
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

        for (int i = 0; i < 8; i++)
        {
            int x = v + vx[i], y = u + vy[i];

            if (ok(x, y))
            { // vis[2] == -1?

                qx.push(x), qy.push(y);

                // vis[x][y] = vis[v][u] + 1;
                adjlist[x][y] = '0';
            }
        }
    }
}

int main()
{

    int count = 1, c = 0;

    while (cin >> n)
    {
        c = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> adjlist[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (adjlist[i][j] == '1')
                    c++, BFS(i, j);
            }
        }
        cout << "Image number " << count++ << " contains " << c << " war eagles." << endl;
    }

    return 0;
}
