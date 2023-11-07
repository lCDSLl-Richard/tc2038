#ifndef GRAPHCOLORING_H
#define GRAPHCOLORING_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * @brief Verifica si es seguro asignar el color c al nodo v
 *
 * @param v el nodo a colorear
 * @param c el color a usar
 * @return Si es seguro colorear
 *
 * @note Complejidad temporal: O(n)
 * @note Complejidad espacial: O(1)
 */
bool isSafe(int v, int c, vector<vector<int>> &graph, vector<int> &colors)
{
  for (int i = 0; i < graph.size(); i++)
  {
    if (graph[v][i] && c == colors[i])
      return false;
  }
  return true;
}

/**
 * @brief Asigna un color a cada nodo del grafo
 *
 * @param v el nodo a colorear en esta iteración
 * @param graph el grafo sobre el cuál están los nodos
 * @param colors el arreglo con los colores usados
 * @return Si hay éxito en la asignación de colores
 *
 * @note Complejidad temporal: O(n^2)
 * @note Complejidad espacial: O(1)
 */
bool graphColoring(int v, vector<vector<int>> &graph, vector<int> &colors)
{
  if (v == graph.size())
    return true;

  for (int c = 0; c < colors.size(); c++)
  {
    if (isSafe(v, c, graph, colors))
    {
      colors[v] = c;
      if (graphColoring(v + 1, graph, colors))
      {
        return true;
      }
      colors[v] = -1;
    }
  }

  return false;
}

/**
 * @brief Crea una string con la solución formateada
 *
 * @param nodes la cantidad de nodos en el grafo
 * @param colors el arreglo con los colores usados
 * @return Una string con la solución formateada
 *
 * @note Complejidad temporal: O(n)
 * @note Complejidad espacial: O(1)
 */
string printSolution(int nodes, vector<int> &colors)
{
  stringstream res;
  for (int i = 0; i < nodes; i++)
    res << "Vertice: " << i << ", Color asignado: " << colors[i] << endl;
  return res.str();
}

#endif