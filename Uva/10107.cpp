
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[1001],t,n=0,c=0;

    while( cin>>t)
    {
        a[c]=t;
        n++;
        c++;
        for(int i =0; i<n-1; i++)

            for(int j =0; j<n-i-1; j++)

                if(a[j]<a[j+1])
                    swap(a[j],a[j+1]);



        if(n%2==1)
        {
            int mid=n/2;
            cout<<a[mid]<<endl;
        }

        else
        {
            int mid=n/2;
            cout<<(a[mid]+a[mid-1])/2<<endl;
        }



    }

    return 0;
}
