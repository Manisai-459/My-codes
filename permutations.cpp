#include <bits/stdc++.h>
using namespace std;
void permutate(int k, vector<int> &a)
{
    if (k == a.size())
    {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = k; i < a.size(); i++)
    {
        swap(a[i], a[k]);
        permutate(k + 1, a);
        swap(a[i], a[k]);
    }
}
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i + 1) << " : ";
        cin >> arr[i];
    }
    permutate(0, arr);
    return 0;
}