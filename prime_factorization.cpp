#include <bits/stdc++.h>
using namespace std;
int prime_factorization(int n)
{
    vector<int> a(n + 1, -1);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (a[i] != -1)
            continue;
        a[i] = i;
        for (int j = i * i; j <= n; j += i)
        {
            if (a[j] == -1)
                a[j] = i;
        }
    }
    cout << "prime factors of " << n << " : ";
    int l = a[n];
    while (n != 1)
    {

        if (a[n] == -1)
        {
            cout << n << " " << n << endl;
            n /= n;
        }
        else
        {
            cout << n << " " << a[n] << endl;
            n /= a[n];
        }
    }
    return l;
}
int main()
{
    cout << "\nLeast prime factor : " << prime_factorization(243243);
    return 0;
}