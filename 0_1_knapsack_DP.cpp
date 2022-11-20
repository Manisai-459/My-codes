#include <bits/stdc++.h>
using namespace std;
class knapsack_0_1
{
public:
    int knapsack_01(int n, int *w, int *p, int W)
    {
        int dp[n + 1][W + 1];
        for (int i = 0; i <= W; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int k = 0; k < n; k++)
        {
            for (int j = 1; j < w[k]; j++)
                dp[k + 1][j] = dp[k][j];
            for (int j = w[k]; j <= W; j++)
                dp[k + 1][j] = (dp[k][j] > (p[k] + dp[k][j - w[k]])) ? dp[k][j] : p[k] + dp[k][j - w[k]];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
                cout << dp[i][j] << "\t";
            cout << endl;
        }
        return dp[n][W];
    }
};
int main()
{
    int n;
    cout << "Enter number of items : ";
    cin >> n;
    int p[n], w[n], W;
    for (int i = 0; i < n; i++)
    {
        cout << "Object " << (i + 1) << endl;
        cout << "profit : ";
        cin >> p[i];
        cout << "weight : ";
        cin >> w[i];
    }
    cout << "Enter Maximum weight of the bag : ";
    cin >> W;
    knapsack_0_1 obj;
    cout << "Maximum profit : " << obj.knapsack_01(n, w, p, W);
    return 0;
}