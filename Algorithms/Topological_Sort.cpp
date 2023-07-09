#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> visited;
vector<vector<int>> matrix;

void dfs(int node, stack<int> &st)
{
    visited[node] = 1;
    for (int neighbor : matrix[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, st);
        }
    }
    st.push(node);
}

int main()
{
    cin >> n >> e;

    visited.resize(n + 1, 0);
    matrix.resize(n + 1);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        matrix[u].push_back(v);
    }

    stack<int> st;

    for (int node = 1; node <= n; node++)
    {
        if (!visited[node])
        {
            dfs(node, st);
        }
    }

    vector<int> result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
 
    for (int node : result)
    {
        cout << node << ' ';
    }

    return 0;
}

/**
Input:
7 7
4 3
3 2
2 5
2 6
5 1
6 7
1 7

OutPut:
4 3 2 6 5 1 7
*/