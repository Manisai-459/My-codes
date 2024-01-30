#include <bits/stdc++.h>
using namespace std;
string solution(string s)
{
    int n = s.length();
    int i = 0, r = 0, max = 0;
    while (i < n)
    {
        int st = i, e = i;
        while (e + 1 < n && s[e] == s[e + 1])
            e += 1;
        i = e + 1;
        while (st - 1 >= 0 && e + 1 < n && s[st - 1] == s[e + 1])
        {
            st -= 1;
            e += 1;
        }
        cout << s.substr(st, e - st + 1) << endl;
        if ((e - st + 1) > max)
        {
            r = st;
            max = e - st + 1;
        }
    }
    return s.substr(r, max);
}
int main()
{
    string s;
    cin >> s;
    cout << solution(s);
    return 0;
}