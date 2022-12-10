#include <bits/stdc++.h>
using namespace std;
int g[100][100];
int min_vertex(int *dist, bool *visited, int n) // ! finds the minimum distance vertex from the set of vertices that are not selected
{
    int min_val = INT_MAX, min_v;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false && min_val > dist[i])
        {
            min_val = dist[i];
            min_v = i;
        }
    }
    return min_v;
}
// ! u = selected vertex , v = remaining all non visited vertex
// ! if ( d[u] + g[u][v] < d[v]) : d[v] = d[u] + g[u][v]
// ! here d[u] = represenets the distance of vertex 'u' from sourse node - recursively
void djkstra_algo(int sourse, int n)
{
    int dist[n];                // ! keeps track about the distance - form sourse to every vertex
    bool visited[n];            // ! keeps track about the visited and non visited vertices
    for (int i = 0; i < n; i++) // ! initially all vertices are at infinity and no node is visited
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[sourse] = 0;
    for (int i = 1; i < n; i++)
    {
        int u = min_vertex(dist, visited, n); // ! return the vertex with minimum path
        visited[u] = true;                    // ! making that vertex as visited
        for (int j = 0; j < n; j++)
        {
            // ! relaxing the nodes connected to vertex 'u'
            // ! we do not go through visited vertices
            if (visited[j] == false && g[u][j] && dist[u] + g[u][j] < dist[j])
                dist[j] = dist[u] + g[u][j]; // ! updating the distance
        }
        for (int j = 0; j < n; j++)
        {
            if (dist[j] == INT_MAX)
                cout << "-"
                     << " ";
            else
                cout << dist[j] << " ";
        }
        cout << endl;
    }
    cout << "Shortest distance for " << sourse << " node to all nodes" << endl;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "no path"
                 << " ";
        else
            cout << sourse << " --> " << i << " = " << dist[i] << endl;
    }
}
int main()
{
    int n, k;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter Adjacensy matrix" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    cout << "Enter sourse vertex : ";
    cin >> k;
    djkstra_algo(k, n);
    return 0;
}
