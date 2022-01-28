#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define mx 1000
map<ll, int> m;

vector<ll> adjlist[mx];
ll vis[mx];

void DFS(ll source)
{
    if (vis[source] != 0)
        return;

    vis[source] = 1;
    for (int i = 0; i < adjlist[source].size(); i++)
    {
        if (vis[adjlist[source][i]] == 0)
        { 
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
        char node;
        cin >> node;
        n = node - 'A', c = 0;

        string s;
        getline(cin, s);
        while (getline(cin, s))
        {
            if (s.length() == 0)
            {
                break;
            }

            ll x = s[0] - 'A', y = s[1] - 'A';
            adjlist[x].push_back(y);
            adjlist[y].push_back(x);
        }

        for (int i = 0; i <= n; i++)
        {
            
            if (vis[i] == 0)
            {
                c++;
                
                DFS(i);
            }
        }
        // cout << endl;
        cout << c << endl;
        if (t)
            cout << endl;

        for (int i = 0; i < mx; i++)
        {
            adjlist[i].clear();
        }

        memset(vis, 0, sizeof(vis));
    }

    return 0;
}
