#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Graph
{
private:
  vector<vector<int>> graph;

public:
  Graph(int);
  Graph(Graph &);

  void setEdge(int, int, int);
  vector<int> getNeighbors(int);
  int getWeight(int, int);
  int size();

  string stringify();
};

Graph::Graph(int size)
{
  graph = vector<vector<int>>(size, vector<int>(size));
}

Graph::Graph(Graph &graph)
{
  this->graph = graph.graph;
}

void Graph::setEdge(int from, int to, int weight)
{
  graph[from][to] = weight;
}

vector<int> Graph::getNeighbors(int from)
{
  return graph[from];
}

int Graph::getWeight(int from, int to)
{
  return graph[from][to];
}

int Graph::size()
{
  return graph.size();
}

string Graph::stringify()
{
  stringstream ss;

  for (auto row : graph)
  {
    for (auto node : row)
      ss << node << " ";
    ss << endl;
  }

  return ss.str();
}
#endif