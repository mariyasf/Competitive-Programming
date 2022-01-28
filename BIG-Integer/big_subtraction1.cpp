#include <bits/stdc++.h>
using namespace std;

string sub(string a, string b)
{
    string res = "";

    if (a.size() < b.size())
        swap(a, b);

    if (a.size() == b.size())
    {
        bool flag = true;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] < b[i])
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
            swap(a, b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0, c = 0;
    //for (int i = b.size() - 1; i >= 0; i--, c++)
    for (int i = 0; i < b.size(); i++)
    {
        int sub = ((a[i] - '0') - (b[i] - '0')) - carry;

        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;

        res.push_back(sub + '0');
    }

    for (int i = b.size(); i < a.size(); i++)
    {
        int sub = (a[i] - '0') - carry;

        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;

        res.push_back(sub + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    while (1)
    {
        string a, b;
        cin >> a >> b;

        cout << "Subtration of 2 number : " << sub(a, b) << endl;
    }
    return 0;
}