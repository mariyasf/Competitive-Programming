#include<bits/stdc++.h>
using namespace std;

/**
            .............BIG MULTIPLY START HERE.............
    */

string multiplie(string a,int x)
{
    string mul_ans;
    int mul,carry=0;

    for(int i=a.size()-1; i>=0; i--)
    {
        mul=(x * (a[i]-'0'))+carry;
        mul_ans.push_back(mul%10 +'0');
        carry=mul/10;
    }

    if(carry>0) mul_ans.push_back(carry +'0');

    reverse( mul_ans.begin(), mul_ans.end());
    return  mul_ans;


}
/**
            .............BIG SUM START HERE.............
    */
string summ(string a,string b)
{
    string  ans;
    int carry=0,sum;
    while(a.empty()==0 && b.empty()==0)
    {
        sum=(a.back()-'0')+(b.back()-'0')+carry;
        ans.push_back(sum%10+'0');
        carry=sum/10;
        a.pop_back(),b.pop_back();

    }
    while(a.empty()==0)
    {
        sum=(a.back()-'0')+carry;

        ans.push_back(sum%10+'0');
        carry=sum/10;

        a.pop_back();

    }
    while( b.empty()==0)
    {
        sum=(b.back()-'0')+carry;

        ans.push_back(sum%10+'0');
        carry=sum/10;
        b.pop_back();

    }
    if(carry>0)ans.push_back(carry+'0');
    reverse(ans.begin(),ans.end());

    return ans;

}

int main()
{
    string a,b,ans1,ans2,s1="0",s,a1;
    int x=1;
    while(cin>>a>>b)
    {
        int x,k=1,f=0;

        for(int i=b.size()-1; i>=0; i--)
        {
            x=b[i]-'0';
            s=multiplie(a,x);

            for(int j=1; j<k; j++)
            {
                s.push_back('0');
            }

            k++;

            ans2= summ(ans2,s);

        }
        for(int i=0; i<ans2.size(); i++)
        {
            if(ans2[i]>'0')f=1;
            }
        if(f)cout<<ans2<<endl;
        else cout<<0<<endl;


        ans2="0";
    }




    return 0;
}
