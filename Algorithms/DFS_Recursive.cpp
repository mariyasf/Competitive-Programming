//Recursive

#include <bits/stdc++.h>
     
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
#define MOD 1000000007
 
ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; //kings move - U, D, R, L, LU, RU, LD, RD

vector <ll> adjlist[500005];   
ll vis[500005]={0}; 

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


int main() {  
	fasterInOut; 
	memset(vis, 0, sizeof(vis));
	return 0; 
}
