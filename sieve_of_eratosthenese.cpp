#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n, int m)
{
    vector<bool> prime(m + 1, true);
    prime[1] = false;
    for (int i = 2; i <= sqrt(m); i++)
    {
        if (prime[i] == false)
            continue;
        for (int j = i * i; j <= m; j += i)
            prime[j] = false;
    }
    for (int i = n; i <= m; i++)
        if (prime[i])
            cout << i << endl;
}
int main()
{
    countPrimes(10, 47);
    return 0;
}