#include<bits/stdc++.h>
using namespace std;
#define mod 10
#define ll long long

string fact;
/// 2C2 + 3C2 + 4C2 + ...... + (n+1)C2 = 1/6 * n * (n+1) * (n+2)
int main()
{
    string s;
    fact[0]=1;
    for(int i=1; i<=10000; i++)
    {
        fact[i]=((i%mod) * (fact[i-1]%mod))%mod;
    }


    while(cin>>s)
    {
        cout<<s<<"!"<<endl;

       ll a=fact[n]%mod
    }


    return 0;
}

