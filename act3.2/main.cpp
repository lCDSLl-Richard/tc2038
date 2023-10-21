#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

void dijkstra(vector<vector<int>> &graph, int n)
{
    for (int src = 0; src < n; src++)
    {
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[src] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int minDist = INT_MAX, minIndex;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && dist[v] < minDist)
                {
                    minDist = dist[v];
                    minIndex = v;
                }
            }

            visited[minIndex] = true;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && graph[minIndex][v] != -1 &&
                    dist[minIndex] != INT_MAX &&
                    dist[minIndex] + graph[minIndex][v] < dist[v])
                {
                    dist[v] = dist[minIndex] + graph[minIndex][v];
                }
            }
        }

        for (int dest = 0; dest < n; dest++)
        {
            if (src != dest)
            {
                cout << "node " << src + 1 << " to node " << dest + 1 << ": ";
                if (dist[dest] == INT_MAX)
                {
                    cout << "No path" << endl;
                }
                else
                {
                    cout << dist[dest] << endl;
                }
            }
        }
    }
}

int main()
{
    int n;
    ifstream inputFile("caso_prueba.txt");

    if (!inputFile.is_open())
    {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    inputFile >> n;
    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inputFile >> graph[i][j];
        }
    }

    cout << "Dijkstra:" << endl;
    dijkstra(graph, n);

    // Cierra el archivo después de usarlo
    inputFile.close();

    return 0;
}
