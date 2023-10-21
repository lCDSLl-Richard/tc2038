#ifndef FLOYD_H
#define FLOYD_H

#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

using namespace std;

/**
 * @brief Una función que ejecuta el algoritmo de Floyd-Warshall sobre un grafo
 *
 * @param graph el grafo sobre el cual ejecutar el algoritmo. La respuesta se escribe sobre esta misma matriz
 *
 * @note Complejidad temporal: O(n^3)
 * @note Complejidad espacial: O(n^2)
 */
void floyd(vector<vector<int>> &graph)
{
  int numNodes = graph.size();

  for (int i = 0; i < numNodes; i++)
    for (int j = 0; j < numNodes; j++)
      for (int k = 0; k < numNodes; k++)
        if (graph[j][i] != INF && graph[i][k] != INF &&
            graph[j][i] + graph[i][k] < graph[j][k])
          graph[j][k] = graph[j][i] + graph[i][k];
}

#endif