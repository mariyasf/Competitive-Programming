#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    while(n--)
    {
        int c,r;
        cin>>c>>r;
        int ans=c-r;
        set<ll>s;
        set<ll>::iterator it;

        for(it=s.begin(); it!=s.end(); it++)
        {
            cout<<*it<<" ";
        }

    }
    return 0;
}

