#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>

#include "graph.h"

using namespace std;

struct Edge
{
  int from, to, weight;
};

bool compareEdges(const Edge &a, const Edge &b)
{
  return a.weight < b.weight;
}

int findParent(vector<int> &parent, int i)
{
  if (parent[i] == -1)
    return i;

  return findParent(parent, parent[i]);
}

void unionSets(vector<int> &parent, int x, int y)
{
  int xRoot = findParent(parent, x);
  int yRoot = findParent(parent, y);

  parent[xRoot] = yRoot;
}

/**
 * @brief Aplica el algoritmo de Kruskal sobre un grafo
 *
 * @param graph el grafo sobre el cual aplicar el algoritmo
 * @param result el arreglo dónde se va a guardar el resultado
 *
 * Complejidad Temporal: O(E * logV)
 * Complejidad Espacial: O(V + E)
 */
void kruskal(Graph &graph, vector<Edge> &result)
{
  int vertexes = graph.size();
  vector<Edge> edges;

  for (int i = 0; i < vertexes; i++)
    for (int j = 0; j < vertexes; j++)
      edges.push_back({i, j, graph.getWeight(i, j)});

  sort(edges.begin(), edges.end(), compareEdges);

  vector<int> parent(vertexes, -1);

  for (const Edge &edge : edges)
  {
    int x = findParent(parent, edge.from);
    int y = findParent(parent, edge.to);

    if (x != y)
    {
      result.push_back(edge);
      unionSets(parent, x, y);
    }
  }
}

#endif