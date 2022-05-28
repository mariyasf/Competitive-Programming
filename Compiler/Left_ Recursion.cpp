// Write a  program  for  Left  Recursion
#include <bits/stdc++.h>
using namespace std;
int main()
{

    string production;

    while (cin >> production)
    {
        char non_terminal, beta, alpha, sym;
        int index = 3;

        cout << "GRAMMAR IS : " << production << endl;
        non_terminal = production[0];
        if (non_terminal == production[index])
        {
            sym = production[index + 1];
            alpha = production[index + 2];
            while (production[index] != 0 && production[index] != '|')
            {
                index++;
            }

            if (production[index] != 0)
            {
                beta = production[index + 1];
                printf("Grammar without left recursion:\n");
                printf("\t%c->%c%c\'", non_terminal, beta, non_terminal);
                printf("\n\t%c\'->%c%c%c\'|e\n", non_terminal, sym, alpha, non_terminal);
            }
            else
                printf(" can't be reduced\n");
        }
        else
            printf(" is not left recursive.\n");
        index = 3;
    }
}
