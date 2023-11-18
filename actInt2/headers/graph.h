#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/**
 * @brief Clase que representa un grafo como una matriz de adyacencias
 */
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

/**
 * @brief Construye un nuevo Grafo dado su tamaño
 *
 * @param size la cantidad de nodos en el grafo
 */
Graph::Graph(int size)
{
  graph = vector<vector<int>>(size, vector<int>(size));
}

/**
 * @brief Constructor por copia
 *
 * @param graph el grafo a copiar
 */
Graph::Graph(Graph &graph)
{
  this->graph = graph.graph;
}

/**
 * @brief Agrega una nueva arista al grafo
 *
 * @param from el origen de la arista
 * @param to el destino de la arista
 * @param weight el peso que tiene la arista
 */
void Graph::setEdge(int from, int to, int weight)
{
  graph[from][to] = weight;
}

/**
 * @brief Obtiene los vecinos de dado nodo
 *
 * @param from el nodo desde el cual obtener los vecinos
 * @return Los vecinos del nodo
 */
vector<int> Graph::getNeighbors(int from)
{
  return graph[from];
}

/**
 * @brief Obtiene el peso de una arist
 *
 * @param from el origen de la arista
 * @param to el destino de la arista
 * @return el peso de la arista
 */
int Graph::getWeight(int from, int to)
{
  return graph[from][to];
}

/**
 * @brief Obtiene la cantidad de vértices
 *
 * @return la cantidad de vértices
 */
int Graph::size()
{
  return graph.size();
}

/**
 * @brief Convierte el grafo en una matriz legible
 *
 * @return una string con el grafo
 */
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