#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, j, count = 0;
    cout << "Enter no of set elements : ";
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        j = x % n;
        if (a[j] == 0)
        {
            a[j] = x;
            count++;
        }
        else
        {
            int d;
            for (int k = 0; k < n; k++)
            {
                d = (j + k) % n;
                if (a[d] == x)
                    break;
                else if (a[d] == 0)
                {
                    a[d] = x;
                    count++;
                    break;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}