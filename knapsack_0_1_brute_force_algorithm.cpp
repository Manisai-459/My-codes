#include <iostream>
using namespace std;
#define max(a, b) (a > b) ? a : b
int knapsack_0_1(int W, int n, int *w, int *v)
{
    if (n == -1 || W == 0) // ! if no objects or knapsack is filled -- break
        return 0;
    if (w[n] > W) // ! if weight is more than remaining knapsack space check for another weight
        return knapsack_0_1(W, n - 1, w, v);
    // ! either u consider the object or do not consider - in both cases check the maximum
    return max(v[n] + knapsack_0_1(W - w[n], n - 1, w, v), knapsack_0_1(W, n - 1, w, v));
}
int main()
{
    int n, W;
    cout << "Enter no of objects : ";
    cin >> n;
    cout << "Enter max weight of knapsack : ";
    cin >> W;
    int wt[n], v[n];
    cout << "Enter weight and its corresponding value" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value of object " << (i + 1) << " : ";
        cin >> v[i];
        cout << "Enter weight of object " << (i + 1) << " : ";
        cin >> wt[i];
    }
    cout << "Max profit : " << knapsack_0_1(W, n - 1, wt, v); // ! O(2^n) exponential complexity and O(N) space complexity for n stacks spaces(recursions)
}
