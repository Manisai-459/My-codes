#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum;
    cin >> n;
    int a[n];
    cout << "Enter " << n << " Elements : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter sum : ";
    cin >> sum;
    int curr_sum = a[0], l = 0;
    for (int i = 1; i <= n; i++)
    {
        while (curr_sum > sum && l < i - 1)
        {
            curr_sum -= a[l];
            l++;
        }
        if (curr_sum == sum)
        {
            cout << l << " - " << i - 1;
            return 0;
        }
        if (i < n)
            curr_sum += a[i];
    }
    cout << "Sub array not found";
    return 0;
}