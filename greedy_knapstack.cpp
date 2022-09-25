#include <bits/stdc++.h>
using namespace std;
#define m 100
class knapstack
{
    int wi, n;
    int w[m], v[m], k[m];

public:
    float total()
    {
        cout << "Enter weight and no of objects : ";
        cin >> wi >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> w[i] >> v[i];
            k[i] = 0;
        }
        float x = 0;
        int item = -1;
        while (wi > 0)
        {
            item = -1;
            for (int i = 0; i < n; i++)
            {
                if ((k[i] == 0) && (item == -1 || (float)v[i] / w[i] > (float)v[item] / w[item]))
                    item = i;
            }
            k[item] = 1;
            wi -= w[item];
            if (wi < 0)
            {
                x += (1 + (float)wi / w[item]) * v[item];
                wi = 0;
            }
            else
                x += v[item];
        }
        return x;
    }
};
int main()
{
    knapstack obj;
    float n = obj.total();
    cout << n;
    return 0;
}