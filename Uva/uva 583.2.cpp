#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    while(cin>>n,n)
    {
        cout<<n<<" = ";

        if(n<0)
        {
            cout<<" = -1 x ";
            n=-n;
        }

        int l=sqrt(n);
        for(int i=2; i<l; i++)
        {
            if(n%i==0)
            {
                cout<<i<<" ";
                n/=i;
                t=i;

            }
        }
        cout<<n<<endl;
    }


    return 0;
}
