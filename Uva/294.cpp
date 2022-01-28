#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;

    cin>>n;

    while(n--)
    {
        int num,s=0;

       cin>>a>>b;

        for(int i=a;i<=b;i++)
        {
            int c=0;

            for(int j=1;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    c++;

                }
            }

            int tmp=sqrt(i);

            if(tmp==sqrt(i))
            {
                c=c*2-1;
            }
            else
            {
                c=c*2;
            }

            if(c>s)
            {
                s=c;
                num=i;
            }
        }

        cout<<"Between "<<a<<" and "<<b<<", "<<num<<" has a maximum of "<<s<<" divisors.\n";
    }

    return 0;
}
