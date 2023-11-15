#include <iostream>

#include "headers/graph.h"
#include "headers/tsp.h"
#include "headers/nearestPoint.h"
#include "headers/fordFulkerson.h"

using namespace std;

int main(int argc, char *argv[])
{
  istream &input = cin;
  int numCities;
  cout << "Ingrese el tamaño del grafo: ";
  input >> numCities;

  Graph cities(numCities);

  cout << "Ingrese la matriz del grafo:\n";
  for (int i = 0; i < numCities; i++)
    for (int j = 0; j < numCities; j++)
    {
      int weight;
      input >> weight;
      cities.setEdge(i, j, weight);
    }

  TspResult res = tsp(cities, 0);

  cout << "Costo mínimo desde el nodo A a todas las ciudades: "
       << res.cost
       << endl;

  cout << "Ruta seguida: ";
  for (auto node : res.route)
    cout << (char)(node + 'A') << " ";
  cout << endl;

  Graph fGraph(numCities);
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

  cout << "El flujo máximo de la ciudad A a la ciudad "
       << (char)(numCities - 1 + 'A')
       << " es: "
       << maxFlow
       << endl;
  cout << "El grafo de Flujo máximo es: "
       << endl
       << rGraph.stringify() << endl;

  vector<Point> cityLocations(numCities);

  cout << "Ingrese las coordenadas de las centrales:\n";
  for (int i = 0; i < numCities; i++)
    input >> cityLocations[i].x >> cityLocations[i].y;

  cout << "Ingrese las coordenadas de la nueva central: ";
  Point newCentral;
  input >> newCentral.x >> newCentral.y;

  NearestPointRes nearestCity = nearestPoint(cityLocations, newCentral);

  cout << "La central más cercana es: ("
       << cityLocations[nearestCity.index].x
       << ", "
       << cityLocations[nearestCity.index].y
       << ") con una distancia de: "
       << nearestCity.distance
       << endl;

  return 0;
}