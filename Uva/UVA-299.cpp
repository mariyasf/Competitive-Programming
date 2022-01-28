#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i =0; i<n; i++)
        {
            cin>>a[i];
        }
        int c=0;


        for(int i =0; i<n; i++)
        {

            for(int j =0; j<n-i-1; j++)
            {
                if(a[j]>a[j+1])
                {
                    int t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    c++;
                }


            }
        }
        cout<<"Optimal train swapping takes "<<c<<" swaps.\n";


    }

    return 0;
}
