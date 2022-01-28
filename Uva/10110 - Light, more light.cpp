#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;

    while(cin>>n, n)
    {
        long long s=sqrt(n);

        if(s*s==n)cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
