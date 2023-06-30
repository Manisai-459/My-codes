#include <bits/stdc++.h>
using namespace std;
void backtrack(vector<vector<int>> &out, vector<int> &c, vector<int> &ar, int t, int start)
{
    if (t == 0)
        out.push_back(c);
    else if (t < 0)
        return;
    else
    {
        for (int i = start; i < ar.size(); i++)
        {
            c.push_back(ar[i]);
            backtrack(out, c, ar, t - ar[i], i);
            c.pop_back();
        }
    }
}
int main()
{
    vector<int> ar, c;
    vector<vector<int>> out;
    int n, t;
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ar.push_back(x);
    }
    cout << "Enter target : ";
    cin >> t;
    sort(ar.begin(), ar.end());
    backtrack(out, c, ar, t, 0);
    for (auto x : out)
    {
        for (int y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}