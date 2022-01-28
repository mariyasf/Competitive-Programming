
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    long long int n,s,flag=0,j,sum=0;

    while(cin>>n,n)
    {

        int a=sqrt(n);
        sum=0;
        flag=0;
        for(int i=2; i<=a; i++)
        {
            if(n%i==0)
                flag++;
        }
        s=(pow(2,(n-1))*(pow(2,n)-1));
        if(n==2||n==3||n==5||n==7||n==19||n==31||n==13||n==17)
            cout<<"Perfect: "<<s<<"!\n";
        else
        {
            if(flag==0)
                cout<<"Given number is prime. But, NO perfect number is available.\n";
            else
                cout<<"Given number is NOT prime! NO perfect number is available.\n";
        }
    }
}
