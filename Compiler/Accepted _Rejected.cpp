// 1.STRING TEST { W STARTS WITH "a" }
// 2. If a statement is comment print as "comment" else print "not comment"

#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a = 0, c = 0, b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0 && s[i] == 'a' || s[i] == 'A')
        {
            cout << "Accepted" << endl;
            return 0;
        }
    }
    cout << "Rejected" << endl;
    return 0;
}