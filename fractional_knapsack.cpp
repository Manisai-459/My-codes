#include <bits/stdc++.h>
using namespace std;
typedef struct items
{
    int p, w;
    float p_w;
} sack;
int partition(sack *a, int l, int r)
{
    int pivot = l;
    while (l <= r)
    {
        if (pivot == l)
        {
            if (a[pivot].p_w > a[r].p_w)
            {
                a[l].p = a[r].p + a[l].p - (a[r].p = a[l].p);
                a[l].w = a[r].w + a[l].w - (a[r].w = a[l].w);
                a[l].p_w = a[r].p_w + a[l].p_w - (a[r].p_w = a[l].p_w);
                pivot = r;
            }
            else
                r--;
        }
        else
        {
            if (a[l].p_w > a[pivot].p_w)
            {
                a[l].p = a[pivot].p + a[l].p - (a[pivot].p = a[l].p_w);
                a[l].w = a[pivot].w + a[l].w - (a[pivot].w = a[l].w);
                a[l].p_w = a[pivot].p_w + a[l].p_w - (a[pivot].p_w = a[l].p_w);
                pivot = l;
            }
            else
                l++;
        }
    }
    return pivot;
}
void quick_sort(sack *a, int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }
}
int main()
{
    int n, W;
    float p = 0;
    cout << "Enter no of items : ";
    cin >> n;
    cout << "Enter weight of knapsack : ";
    cin >> W;
    sack *a = new sack[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit of P" << i + 1 << ": ";
        cin >> a[i].p;
        cout << "Enter weight of W" << i + 1 << ": ";
        cin >> a[i].w;
        a[i].p_w = (float)a[i].p / a[i].w;
    }
    quick_sort(a, 0, n - 1); // ! O(nlogn)
    int i = n - 1;
    while (W && i>=0) // ! O(n)
    {
        if (a[i].w > W)
        {
            p += ((float)a[i].p / a[i].w) * W;
            break;
        }
        p += a[i].p;
        W -= a[i].w;
        i--;
    }
    cout << "Maximum profit : " << p;
    return 0;
}
