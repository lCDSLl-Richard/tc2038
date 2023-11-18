#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include <vector>
#include <queue>
#include "graph.h"

#define INF std::numeric_limits<int>::max();
using namespace std;

/**
 * @brief Aplica BFS sobre un grafo y guarda los nodos padre dentro de la
 * búsqueda. Adaptado para funcionar con Ford-Fulkerson
 *
 * @param graph el grafo sobre el cuál aplicar la búsqueda
 * @param parent el arreglo dónde se guardan los padres de cada nodo
 * @param source el nodo desde el cuál sale el flujo
 * @param sink el nodo al cuál llega el flujo
 * @return Si se encontró cierto nodo en el grafo
 *
 */
bool bfs(Graph &graph, vector<int> &parent, int source, int sink)
{
  int gSize = graph.size();
  vector<bool> visited(gSize, false);
  queue<int> q;

  q.push(source);
  visited[source] = true;
  parent[source] = -1;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (int v = 0; v < gSize; v++)
    {
      if (!visited[v] && graph.getWeight(u, v) > 0)
      {
        q.push(v);
        parent[v] = u;
        visited[v] = true;

        if (v == sink)
          return true;
      }
    }
  }
  return false;
}

/**
 * @brief Aplica el algoritmo Ford-Fulkerson sobre un grafo.
 *
 * @param graph el grafo original
 * @param rGraph el grafo que represental el flujo residual
 * @param source el comienzo del flujo
 * @param sink el destino del flujo
 * @return el flujo máximo del grafo
 *
 * @note Complejidad temporal: O(fE^2); f -> flujo max; E -> aristas;
 * @note Complejidad espacial: O(V + E); V -> vértices
 */
int fordFulkerson(Graph &graph, Graph &rGraph, int source, int sink)
{
  int gSize = graph.size();
  vector<int> parent(gSize, -1);
  int maxFlow = 0;

  while (bfs(rGraph, parent, source, sink))
  {
    int pathFlow = INF;

    for (int v = sink; v != source; v = parent[v])
    {
      int u = parent[v];
      pathFlow = min(pathFlow, rGraph.getWeight(u, v));
    }

    for (int v = sink; v != source; v = parent[v])
    {
      int u = parent[v];
      rGraph.setEdge(u, v, rGraph.getWeight(u, v) - pathFlow);
      rGraph.setEdge(v, u, rGraph.getWeight(v, u) + pathFlow);
    }

    maxFlow += pathFlow;
  }

  return maxFlow;
}

#endif