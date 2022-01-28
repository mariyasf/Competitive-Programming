#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,a[100];
    while(cin>>n,n)
    {
        a[0]=1;
        a[1]=2;
        for(i=2; i<=n; i++)
            a[i]=a[i-1]+a[i-2];
        cout<<a[n-1]<<endl;
    }
    return 0;
}

