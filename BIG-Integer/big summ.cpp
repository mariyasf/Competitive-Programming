#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b,ans;

    cin>>a>>b;
    int sum,carry=0;
    ///a==b
    while(a.empty()==0 && b.empty()==0)
    {
        sum=(a.back()-'0') + (b.back()-'0')+carry;
        ans.push_back((sum%10) + '0');

        carry=sum/10;
        a.pop_back();
        b.pop_back();

    }

    ///a>b
    while(a.empty()==0)
    {
        sum=(a.back()-'0') +carry;
        ans.push_back((sum%10) + '0');

        carry=sum/10;
        a.pop_back();


    }
    ///a<b
    while(b.empty()==0)
    {
        sum=(b.back()-'0')+carry;
        ans.push_back((sum%10) + '0');

        carry=sum/10;

        b.pop_back();

    }

    if(carry>0) ans.push_back(carry + '0');

    reverse(ans.begin(), ans.end());

    cout<<ans<<endl;

    return 0;
}


