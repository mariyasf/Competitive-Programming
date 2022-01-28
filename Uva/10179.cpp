
#include<bits/stdc++.h>
using namespace std;

int fun(int n)
{
    int result = n;
   int l=sqrt(n);
    for (int i=2; i<=l; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }

    if (n > 1)
        result -= result / n;
    return result;
}
int main()
{
    int n;
    while(cin>>n,n)
    {
        cout<<fun(n)<<endl;

    }
    return 0;
}
