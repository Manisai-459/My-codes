#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    void heapify_to_max(int *a, int n)
    {
        int l, r, m;
        for (int i = n / 2; i >= 0; i--)
        {
            l = 2 * i + 1;
            m = r = 2 * i + 2;
            if (l < n && r < n)
            {
                if (a[l] > a[r])
                    m = l;
                if (a[i] < a[m])
                    a[m] = a[i] + a[m] - (a[i] = a[m]);
            }
            else if (l < n)
            {
                if (a[i] < a[l])
                    a[l] = a[i] + a[l] - (a[i] = a[l]);
            }
        }
    }
    void heapify_to_min(int *a, int n)
    {
        int l, r, m;
        for (int i = n / 2; i >= 0; i--)
        {
            m = l = 2 * i + 1;
            r = 2 * i + 2;
            if (l < n && r < n)
            {
                if (a[l] > a[r])
                    m = r;
                if (a[i] > a[m])
                    a[m] = a[i] + a[m] - (a[i] = a[m]);
            }
            else if (l < n)
            {
                if (a[i] > a[m])
                    a[m] = a[i] + a[m] - (a[i] = a[m]);
            }
        }
    }
    void display(int *a, int n)
    {
        cout << "Elements are : ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    friend class temp;
};
int main()
{
    heap h;
    int n;
    cout << "Enter N : ";
    cin >> n;
    int *a = new int[n];
    cout << "Enter " << n << " Elements : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Before : ";
    h.display(a, n);
    h.heapify_to_max(a, n);
    cout << "\nconverting to max heap" << endl;
    h.display(a, n);
    h.heapify_to_min(a, n);
    cout << "\nconverting to min heap" << endl;
    h.display(a, n);
    h.heapify_to_min(a, n);
    return 0;
}