#include <vector>
#include <iostream>
#include <limits>
#include "dijkstra.h"
#include "floyd.h"

using namespace std;

int main()
{
  int graphSize;

  cout << "Ingrese el tamaño de su grafo: ";
  cin >> graphSize;

  cout << "Ingrese los pesos de las conexiones\n";

  vector<vector<int>> graph(graphSize, vector<int>(graphSize));

  for (int i = 0; i < graphSize; i++)
    for (int j = 0; j < graphSize; j++)
    {
      int buffer;
      cin >> buffer;
      graph[i][j] = buffer == -1 ? INF : buffer;
    }

  cout << "Dijkstra results:" << endl;
  for (int i = 0; i < graphSize; i++)
  {
    vector<int> distances;
    dijkstra(graph, i, distances);
    for (int j = 0; j < distances.size(); j++)
    {
      if (j == i)
        continue;
      cout << "From node "
           << i + 1 << " to node "
           << j + 1 << ": ";
      if (distances[j] == INF)
        cout << "No path\n";
      else
        cout << distances[j] << endl;
    }
  }

  cout << "\nFloyd results:" << endl;
  vector<vector<int>> res(graph);
  floyd(res);
  for (auto i : res)
  {
    for (auto j : i)
    {
      if (j == INF)
        cout << "No path ";
      else
        cout << j << " ";
    }
    cout << endl;
  }
}