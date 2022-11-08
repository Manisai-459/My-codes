#include <bits/stdc++.h>
using namespace std;
int a[100][100], q[100], R = -1, F = 0;
void enqueue(int x)
{
    R++;
    q[R] = x;
}
int isempty()
{
    if (F > R)
        return 0;
    return 1;
}
int dequeue()
{
    int x = q[F];
    F++;
    return x;
}
void BFS(int n, char *e, int s)
{
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[s] = 1;
    enqueue(s);
    while (isempty())
    {
        int x = dequeue();
        cout << e[x] << " ";
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && a[x][i] == 1)
            {
                enqueue(i);
                visited[i] = 1;
            }
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
        cin >> e[i];
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
        cout << "\n1 . BFS traversal" << endl;
        cout << "2 . Exit" << endl;
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter which node do you want as source node : ";
            cin >> s;
            for (int i = 0; i < n; i++)
                if (e[i] == s)
                {
                    x = i;
                    break;
                }
            cout << "BFS traversal with sourse node " << e[x] << " is : ";
            BFS(n, e, x);
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