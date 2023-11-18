#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>

#include "headers/graph.h"
#include "headers/tsp.h"
#include "headers/nearestPoint.h"
#include "headers/fordFulkerson.h"
#include "headers/kruskal.h"

using namespace std;

void solution(istream &input, ostream &output, bool ui = true)
{
  int numCities;
  if (ui)
    cout << "Ingrese el tamaño del grafo: ";
  input >> numCities;

  Graph cities(numCities);

  if (ui)
    cout << "Ingrese la matriz del grafo:\n";
  for (int i = 0; i < numCities; i++)
    for (int j = 0; j < numCities; j++)
    {
      int weight;
      input >> weight;
      cities.setEdge(i, j, weight);
    }

  vector<Edge> mst;
  kruskal(cities, mst);

  output << "El cableado más óptimo es:\n";
  for (auto node : mst)
    output << "De la ciudad "
           << (char)(node.from + 'A')
           << " a la ciudad "
           << (char)(node.to + 'A')
           << " con una distancia de "
           << node.weight
           << " km."
           << endl;
  output << endl;

  TspResult res = tsp(cities, 0);

  output << "Costo mínimo desde el nodo A a todas las ciudades: "
         << res.cost
         << endl;

  output << "Ruta seguida: ";
  for (auto node : res.route)
    output << (char)(node + 'A') << " ";
  output << endl;

  Graph fGraph(numCities);
  if (ui)
    cout << "Ingrese la matriz del grafo de flujo:\n";
  for (int i = 0; i < numCities; i++)
    for (int j = 0; j < numCities; j++)
    {
      int weight;
      input >> weight;
      fGraph.setEdge(i, j, weight);
    }

  Graph rGraph(fGraph);
  int maxFlow = fordFulkerson(fGraph, rGraph, 0, numCities - 1);

  output << "El flujo máximo de la ciudad A a la ciudad "
         << (char)(numCities - 1 + 'A')
         << " es: "
         << maxFlow
         << endl;
  output << "El grafo de Flujo máximo es: "
         << endl
         << rGraph.stringify() << endl;

  vector<Point> cityLocations(numCities);

  if (ui)
    cout << "Ingrese las coordenadas de las centrales:\n";
  for (int i = 0; i < numCities; i++)
    input >> cityLocations[i].x >> cityLocations[i].y;

  if (ui)
    cout << "Ingrese las coordenadas de la nueva central: ";
  Point newCentral;
  input >> newCentral.x >> newCentral.y;

  NearestPointRes nearestCity = nearestPoint(cityLocations, newCentral);

  output << "La central más cercana es: ("
         << cityLocations[nearestCity.index].x
         << ", "
         << cityLocations[nearestCity.index].y
         << ") con una distancia de: "
         << nearestCity.distance
         << endl;
}

#endif
