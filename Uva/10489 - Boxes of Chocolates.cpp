#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,b,ans=0;
        cin>>n>>b;

        while(b--)
        {
            int k , sum=1;
            cin>>k;

            while(k--)
            {
                int a;
                cin>>a;
                sum*=a;
                sum%=n;
            }

            ans+=sum;
            ans%=n;
        }
        cout<<ans<<endl;
    }
    return 0;
}

