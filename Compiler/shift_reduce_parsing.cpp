// Write a C/C++  program to configure a Shift Reduce Parser on input  a-(a+a).Using the Grammer
// S->S+S
// S->S-S
// S->(S)
// S->a

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct grammar
{
    string LHS;
    string RHS;
};

int main()
{

    int number_of_p;
    cout << "Enter the number of productions\n";
    cin >> number_of_p;

    cout << "Enter productions\n";
    vector<grammar> prod;
    char check;
    for (int i = 0; i < number_of_p; ++i)
    {
        string s;

        cin >> s;
        if (i == 0)
            check = s[0];
        string lhs = s.substr(0, 1);
        string rhs = s.substr(3, (int)s.size() - 3);
        prod.push_back({lhs, rhs});
    }

    string in;
    char stack[100];
    cout << "Enter the  input string\n";
    cin >> in;

    int idx = 0, stpos = 0;
    stack[stpos] = in[idx];
    idx++;
    stpos++;
    cout << "Stack\tInput\tAction";

    int r = 0, c = 0;

    string lreduce = "", rreduce = "";
    do
    {
        r = 1;
        string prtn = "Reduced";
        while (r != 0)
        {

            cout << "\n"
                 << '$';
            for (int rep = 0; rep < stpos; rep++)
            {

                cout << stack[rep];
            }
            cout << "\t";

            for (int rep = idx; rep < (int)in.size(); rep++)
            {
                cout << in[rep];
            }
            cout << '$';
            if (r == 2)
            {
                prtn = "";
                prtn = "Reduced";
            }
            else
            {
                prtn = "";
                prtn = "Shifted";
            }

            r = 0;
            for (int k = 0; k < stpos; k++)
            {
                string temp;
                for (int l = k; l < stpos; l++)
                {
                    temp += stack[l];
                }
                // cout << "\t" << temp << " ";
                for (int m = 0; m < number_of_p; m++)
                {
                    if (temp == prod[m].RHS)
                    {
                        // cout << "\t" << temp << " ";
                        rreduce = temp;
                        for (int l = k; l < 10; l++)
                        {
                            stack[l] = '\0';
                            stpos--;
                        }
                        stpos = k;
                        for (int i = 0; i < (int)prod[m].LHS.size(); i++)
                        {
                            stack[stpos] = prod[m].LHS[i];
                            stpos++;
                        }
                        r = 2;
                    }
                }
            }
            

            if (strlen(stack) == 1 && r == 0 && stack[0] == check && idx == (int)in.size())
            {
                prtn = "";
                prtn = "Accepted";
            }
            if (prtn == "Reduced")
                cout << "\t" << prtn << ' ' << stack[stpos - 1] << "->" << rreduce;
            else
            {
                cout << "\t" << prtn;
            } 
        }

        stack[stpos] = in[idx];

        idx++;
        stpos++;

    } while (strlen(stack) != 1 && stpos != (int)in.size());

    if (strlen(stack) == 1)
    {
        cout << "\n String Accepted\n";
    }
    else
    {
        cout << "\n Invalid String\n";
    }
}
