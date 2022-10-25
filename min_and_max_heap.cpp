#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    void max_heapify(int *a, int n, int i)
    {
        int l = 2 * i + 1, r = 2 * i + 2, max = i;
        if (l < n && a[max] < a[l])
            max = l;
        if (r < n && a[max] < a[r])
            max = r;
        if (max != i)
        {
            a[max] = a[i] + a[max] - (a[i] = a[max]);
            max_heapify(a, n, max);
        }
    }
    void min_heapify(int *a, int n, int i)
    {
        int l = 2 * i + 1, r = 2 * i + 2, min = i;
        if (l < n && a[min] > a[l])
            min = l;
        if (r < n && a[min] > a[r])
            min = r;
        if (min != i)
        {
            a[min] = a[i] + a[min] - (a[i] = a[min]);
            min_heapify(a, n, min);
        }
    }
    void heapify(int *a, int n)
    {
        cout << "max heap : ";
        for (int i = n / 2; i >= 0; i--)
            max_heapify(a, n, i);
        print(a, n);
        cout << endl;
        cout << "min heap : ";
        for (int i = n / 2; i >= 0; i--)
            min_heapify(a, n, i);
        print(a, n);
    }
    void print(int *a, int n)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
};
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    heap obj;
    obj.heapify(a, n);
    return 0;
}