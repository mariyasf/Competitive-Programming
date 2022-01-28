#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int arr[MAX]= {0}, Prime[MAX], c = 0;

void Sieve()
{
    int i, j;
    for(i = 3; i < MAX; i += 2)
    {
        if(arr[i] == 0)
        {
            Prime[c++] = i;
            for(j = 3; i*j < MAX; j += 2)
                arr[i*j] = 1;
        }
    }
}
int main()
{
    Sieve();
    int n, i;

    while(cin>>n,n)
    {
        int x, y, flag = 0;
        for(i = 0; i < c; i++)
        {
            y = n-Prime[i];
            if(Prime[i] > n/2)	break;
            if(arr[Prime[i]] == 0 && arr[y] == 0)
            {
                cout<<n<<" = "<<Prime[i]<<" + "<<y<<endl;
                flag = 1;
                break;
            }
        }
        if(!flag)
            cout<<"Goldbach's conjecture is wrong.";
    }
    return 0;
}
