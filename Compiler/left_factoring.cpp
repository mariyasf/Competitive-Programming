// Write a program  for remove left Factoring.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int l, n, m = 9999999999, mini, ma = 0;
    string s[100], st, ch, sc = "", result, fs, maxi, rs = "";
    vector<string> ss, sp;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        st = s[i];
        sc = "";

        for (int j = 0; j < st.length(); j++)
        {
            if (i == 1)
            {
                fs = st[0];
            }
            if (st[j] == '=')
            {
                l = j;
            }
        }

        if (i == 1)
        {

            for (int k = l + 1; k < st.length(); k++)
            {
                if (st[k] == '|')
                {
                    ss.push_back(sc);
                    sc = "";
                }
                if (st[k] != '|')
                {
                    ch = st[k];
                    sc = sc + ch;
                }
            }
            ss.push_back(sc);
        }
    }

    for (int k = 0; k < ss.size(); k++)
    {
        mini = ss[k].size();
        m = min(m, mini);
        maxi = ss[k];
    }

    for (int i = 0; i < m; i++)
    {

        char current = ss[0][i];

        for (int j = 1; j < ss.size(); j++)
        {
            if (ss[j][i] != current)
            {
                break;
            }
            result.push_back(current);
        }
    }

    for (int j = 0; j < ss.size(); j++)
    {
        maxi = ss[j];
        for (int k = 0; k < maxi.length(); k++)
        {

            if (k >= result.length())
            {
                rs = rs + maxi[k];
            }
        }
        if (j != ss.size() - 1)
        {
            rs = rs + '|';
        }
    }

    cout << fs << "->" << result << fs << "'" << endl;
    cout << fs << "'"
         << "->" << rs << endl;

    for (int i = 2; i <= n; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}
