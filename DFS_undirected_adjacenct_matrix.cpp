#include <bits/stdc++.h>
using namespace std;
int a[100][100], visited[100];
void DFS(int n, int s, char *e)
{
    if (visited[s] == 0)
    {
        cout << e[s] << " ";
        visited[s] = 1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && a[s][i] == 1)
                DFS(n, i, e);
        }
    }
}
int main()
{
    int n, x;
    cout << "Enter number of vertices : ";
    cin >> n;
    char e[n], s;
    cout << "Enter " + to_string(n) + " names of vertices\n";
    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
        visited[i] = 0;
    }
    cout << "Enter adjacency matrix\n    ";
    for (int i = 0; i < n; i++)
        cout << e[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << e[i] << " - ";
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    do
    {
        int ch;
        cout << "\n1 . DFS traversal" << endl;
        cout << "2 . Exit" << endl;
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            for (int i = 0; i < n; i++)
                visited[i] = 0;
            cout << "Enter which node do you want as source node : ";
            cin >> s;
            for (int i = 0; i < n; i++)
                if (e[i] == s)
                {
                    x = i;
                    break;
                }
            cout << "DFS traversal with sourse node " << e[x] << " is : ";
            DFS(n, x, e);
            break;
        }
        case 2:
            return 0;
        default:
            cout << "Enter displayed choices only\n";
        }
    } while (1);
    return 0;
}