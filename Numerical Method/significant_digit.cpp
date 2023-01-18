#include <bits/stdc++.h>
using namespace std;
#define ll long long
string test(string s, string tmp)
{
    if (s[tmp.size()] > '5' && s[tmp.size()] <= '8')
    {
        tmp[tmp.size() - 1]++;
    }
    else if (s[tmp.size()] == '9')
    {
        ll len = tmp.size() - 1, f = 0;
        while (len > -1)
        {
            if (tmp[len] == '9')
            {
                f = 1;
                tmp[len] = '0';
            }
            else if (tmp[len] >= '0' && tmp[len] <= '8')
            {
                tmp[len]++;
                f = 0;
                break;
            }
            len--;
        }
        string Tmp = to_string(f);
        if (f)
            Tmp += tmp, tmp = Tmp;
    }
    else if (s[tmp.size()] == '5')
    {
        if ((s[tmp.size() - 1] - '0') % 2)
        {
            tmp[tmp.size() - 1]++;
        }
    }
    return tmp;
}
void solve()
{
    string s, tmp = "";
    cout << "Take a number as a string: ";
    cin >> s;

    ll n;
    cout << "Take the significant digit: ";
    cin >> n;

    ll pos = s.find(".");
    string Tmp = "";

    if (s[0] == '0')
    {
        Tmp = "0.";
        ll i = 2, c = 0;

        while (i < s.size())
        {
            if (c >= n)
                break;
            if (s[i] - '0' > 0)
                c++;
            Tmp += s[i];

            i++;
        }
        if (i < s.size())
        {
            tmp = "";
            tmp = test(s, Tmp);
        }
    }
    else
    {
        string Tmp = s.substr(0, pos + 1);
        ll ind = (n - (Tmp.size() - 1));

        ll tmppos = pos;

        for (int i = pos + 1; i <= pos + ind; i++)
        {
            Tmp += s[i];
            tmppos++;
        }
        tmp = test(s, Tmp);
    }
    cout << "Final Result: " << tmp << endl;
}
int main()
{
    int Count = 1;
    while (1)
    {
        cout << "\tTest Case: " << Count++ << endl;
        solve();
    }
}

/*
Bankers Condition:
    1) n + 1 < 5 no change
    2) n + 1 > 5 add 1 to the nth significant digit
    3) n + 1 = 5; n odd then increase by 1 otherwise no change
    
*/