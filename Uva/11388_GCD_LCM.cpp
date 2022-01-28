#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int g,l;
        cin>>g>>l;
        int a=g;

        if(l%g==0) cout<<a<<" "<<l<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
