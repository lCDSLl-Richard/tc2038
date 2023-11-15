#ifndef TSP_H
#define TSP_H

#include <vector>
#include <algorithm>

#include "graph.h"

#define INF std::numeric_limits<int>::max();

using namespace std;

struct TspResult
{
  int cost;
  vector<int> route;
};

TspResult tsp(Graph &graph, int start = 0)
{
  int numCities = graph.size();
  vector<int> vertex;

  for (int i = 0; i < numCities; i++)
  {
    if (i != start)
      vertex.push_back(i);
  }

  TspResult res;
  res.cost = INF;

  do
  {
    int currentPathWeight = 0;

    int k = start;
    vector<int> currentPath;
    currentPath.push_back(start);

    for (int i = 0; i < vertex.size(); i++)
    {
      currentPathWeight += graph.getWeight(k, vertex[i]);
      k = vertex[i];
      currentPath.push_back(k);
    }
    currentPathWeight += graph.getWeight(k, start);

    if (currentPathWeight < res.cost)
    {
      res.cost = currentPathWeight;
      res.route = currentPath;
    }

  } while (next_permutation(vertex.begin(), vertex.end()));

  res.route.push_back(start);
  return res;
}

#endif