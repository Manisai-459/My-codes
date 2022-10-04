#include <bits/stdc++.h>
using namespace std;
class palindrome
{
    string x;

public:
    void get()
    {
        cout << "Enter string : ";
        getline(cin, x);
    }
    int palindrome_check();
};
int palindrome::palindrome_check()
{
    int count = 0, n = x.length(), add = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] != '-')
        {
            count = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (x[i] == x[j])
                {
                    x[j] = '-';
                    count++;
                }
            }
            add += count % 2;
            if (add > 1)
                return 0;
        }
    }
    return 1;
}
int main()
{
    palindrome str;
    str.get();
    if (str.palindrome_check())
        cout << "Yes";
    else
        cout << "No";
    return 0;
}