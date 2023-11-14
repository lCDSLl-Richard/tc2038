#include <iostream>

#include "graph.h"
#include "tsp.h"
#include "nearestPoint.h"

using namespace std;

int main(int argc, char *argv[])
{
  istream &input = cin;
  int numCities;
  input >> numCities;

  Graph cities(numCities);

  for (int i = 0; i < numCities; i++)
    for (int j = 0; j < numCities; j++)
    {
      int weight;
      input >> weight;
      cities.addEdge(i, j, weight);
    }

  cout << cities.stringify();

  TspResult res = tsp(cities, 0);

  cout << "Min cost from node 0: " << res.cost << endl;

  cout << "Route followed: ";
  for (auto node : res.route)
    cout << (char)(node + 'A') << " ";
  cout << endl;

  Graph data(numCities);
  for (int i = 0; i < numCities; i++)
    for (int j = 0; j < numCities; j++)
    {
      int weight;
      input >> weight;
      cities.addEdge(i, j, weight);
    }

  cout << cities.stringify();

  vector<Point> cityLocations(numCities);

  for (int i = 0; i < numCities; i++)
    input >> cityLocations[i].x >> cityLocations[i].y;

  Point newCentral;
  input >> newCentral.x >> newCentral.y;

  NearestPointRes nearestCity = nearestPoint(cityLocations, newCentral);

  cout << "The nearest point is: ("
       << cityLocations[nearestCity.index].x
       << ", "
       << cityLocations[nearestCity.index].y
       << ") with a distance of "
       << nearestCity.distance
       << endl;

  return 0;
}