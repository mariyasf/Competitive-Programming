#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    while(cin>>n)
    {
        int b=1,i;
        for(int i=1; b%n!=0; i++)
        {

            b=((b*10)+1)%n;

        }

        cout<<i<<endl;
    }
    return 0;
}
