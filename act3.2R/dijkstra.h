#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

/**
 * @brief Una función que ejecuta el algoritmo de Dijkstra sobre un grafo en el nodo dado
 *
 * @param graph el grafo sobre el cual ejecutar el algoritmo de dijkstra
 * @param startNode el nodo desde el cual encontrar las distancias
 * @param distances el vector dónde se guardaran las distancias a cada nodo
 *
 * @note Complejidad temporal: O(n^2)
 * @note Complejidad espacial: O(n^2)
 */
void dijkstra(std::vector<std::vector<int>> &graph, int startNode, std::vector<int> &distances)
{
  int numNodes = graph.size();
  std::vector<bool> visited(numNodes, false);

  distances.assign(numNodes, INF);
  distances[startNode] = 0;

  for (int i = 0; i < numNodes - 1; i++)
  {
    int minDistance = INF, minNode = -1;

    for (int node = 0; node < numNodes; node++)
    {
      if (!visited[node] && distances[node] < minDistance)
      {
        minNode = node;
        minDistance = distances[node];
      }
    }

    if (minNode == -1)
      break;

    visited[minNode] = true;

    for (int neighbour = 0; neighbour < numNodes; neighbour++)
    {
      if (!visited[neighbour] && graph[minNode][neighbour] != INF)
      {
        int newDistance = distances[minNode] + graph[minNode][neighbour];
        if (newDistance < distances[neighbour])
        {
          distances[neighbour] = newDistance;
        }
      }
    }
  }
}

#endif