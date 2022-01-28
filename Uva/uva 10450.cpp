#include<bits/stdc++.h>
using namespace std;

#define mx 52
int main()
{
    long long int a,b,ar[mx];

    ar[0]=ar[1]=1;
    for(int i=2;i<mx;i++)
        ar[i]=ar[i-1]+ar[i-2];
        cin>>a;
    for(int i=1;i<=a;i++)
    {
        cin>>b;
       cout<<"Scenario #"<<i<<":\n"<<ar[b+1]<<"\n\n";
    }
    return 0;
}
