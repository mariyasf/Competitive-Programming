#include<bits/stdc++.h>
using namespace std;
#define max 1000001

int a[max]=0;
int main()
{
    int n;
    while(cin>>n)
    {
        int c=0;

        int sq=sqrt(n);
        if(sq*sq<n) sq++;

        for(int i=1; i<=sq; i++)
        {
            for(int j=i+1; j<=sq; j++)
            {
                if(gcd(i,j))
                {
                    int x=j*j-i*i;
                    int y=2*j*i;
                    int z=j*j+i*i;
                    if(z>n) break;

                }
            }
        }
    }

    return 0;
}
