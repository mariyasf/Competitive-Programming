#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int line_cmt = 0, box_cmt = 0, p_nl = 0;
    while (getline(cin, str))
    {
        line_cmt = 0, p_nl = 0;
        if (str == " ")
            continue;
        for (int i = 0; i < str.size(); i++)
        {
            if (line_cmt && str[i] == '\n')
            {
                line_cmt = 0;
            }
            else if (box_cmt && str[i] == '*' && str[i + 1] == '/')
            {
                box_cmt = 0;
                i++;
            }
            else if (line_cmt || box_cmt)
                continue;
            else if (str[i] == '/' && str[i + 1] == '/')
            {
                line_cmt = 1;
                i++;

                continue;
            }
            else if (str[i] == '/' && str[i + 1] == '*')
            {
                box_cmt = 1;
                i++;
            }
            else if (!line_cmt && !box_cmt)
            {
                cout << str[i];
                p_nl = 1;
            }
        }
        if (!box_cmt && p_nl)
            cout << endl;
    }
    return 0;
}