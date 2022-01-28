#include <bits/stdc++.h>
using namespace std;
int LCS[10][10], i, j, len1, len2;
int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2; // GGTCAG AGTCG
    len1 = s1.size();
    len2 = s2.size();
    for (i = 1; i <= len1; i++)
        for (j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    int index = LCS[len1][len2];
    i = len1, j = len2;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s3 += s1[i - 1];
            i--, j--, index--;
        }
        else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(s3.begin(), s3.end());
    cout << "Given string: " << s1 << " " << s2 << "\n";
    cout << "Length of LCS is " << LCS[len1][len2] << endl; // 4
    cout << "LCS output: " << s3 << endl;                   // GTCG
    return 0;
}