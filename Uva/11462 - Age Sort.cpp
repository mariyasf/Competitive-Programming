#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    while(cin>>n,n)
    {
        vector<ll>v(n);
        for(int i=0; i<n; i++)
            cin>>v[i];

        sort(v.begin(),v.end());

        for(int i=0; i<n; i++)
        {
            cout<<v[i];
            if(i<n-1)cout<<" ";
        }

        cout<<endl;

    }
    return 0;
}
