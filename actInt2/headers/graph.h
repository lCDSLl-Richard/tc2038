#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

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

  int maxDigits = 1;
  for (auto row : graph)
    for (int num : row)
    {
      int numDigits = 1;
      while (num /= 10)
        numDigits++;
      maxDigits = max(maxDigits, numDigits);
    }

  for (auto row : graph)
  {
    for (auto node : row)
      ss << setw(maxDigits) << node << " ";
    ss << endl;
  }

  return ss.str();
}
#endif