#include<bits/stdc++.h>
using namespace std;

map<char,int>freq;
bool check()
{
    int f=0;
    for(auto it:freq)
    {
        if(it.second)
        {
            f=it.second;
            break;
        }
    }
    for(auto it:freq)
    {
        if(it.second && it.second != f)
        {
           return false;
        }
    }
    return true;
}
int main()
{
    string word;
    cin>>word;

    for(int i=0; i<word.size(); i++)
    {
        freq[word[i]]++;
    }

    for(auto i:freq)
    {
        char ch = i.first;
        int c=0;
        if(i.second)
        {
            freq[ch]--;

            if(check())
            {
                cout<<"true"<<endl;
                return 0;
            }
            freq[ch]++;
            cout<<endl;
        }
    }
    cout<<"false"<<endl;

}
