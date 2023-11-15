#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include <vector>
#include <queue>
#include "graph.h"

#define INF std::numeric_limits<int>::max();
using namespace std;

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