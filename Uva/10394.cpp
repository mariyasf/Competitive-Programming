#include<bits/stdc++.h>
#define max 20000009
using namespace std;
long long int n,ar[max]={0},r[max]={0},i,j,c;

void fun()
{
    for(i=0; i<max; i++)
    {
        ar[i]=0;
    }
    ar[0]=1;
    ar[1]=1;
    for(i=4; i<max; i+=2)
    {
        ar[i]=1;
    }
    for(i=3; i*i<max; i=i+2)
    {
        for(j=i*i; j<max; j=j+2*i)
        {
            ar[j]=1;
        }
    }
    c=1;
    for(long long int i=2; i<max; i++)
    {
        if((ar[i]==0)&&(ar[i+2]==0))
        {
            r[c++]=i;
        }
    }
}
int main()
{
    fun();

    while(cin>>n)
    {
        cout<<"("<<r[n]<<", "<<r[n]+2<<")"<<endl;
    }
}
