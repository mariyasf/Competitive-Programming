#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


ll bigmod(ll n,ll p,ll m)
{
    if(p<=0) return 1;
    if(p%2==0)
    {
        ll ans=bigmod(n,p/2,m);
        return ((ans%m)*(ans%m))%m;
    }
    else
    {
        ll ans=bigmod(n,p-1,m);
        return ((n%m)*(ans%m))%m;

    }

}

/// 2C2 + 3C2 + 4C2 + ...... + (n+1)C2 = 1/6 * n * (n+1) * (n+2)
int main()
{
    int t,c=1;
    cin>>t;
    ll b=bigmod(3,mod-2,mod);
    while(t--)
    {

        ll n;
        cin>>n;
        ll a=((n%mod) * (n+1)%mod) % mod;
        a=(a * (n+2)%mod) % mod;
        ll ans=(a * b)%mod;
        cout<<"Case "<<c++<<": "<<ans<<endl;

    }
    return 0;
}

