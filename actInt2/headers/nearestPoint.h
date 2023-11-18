#ifndef NEARESTPOINT_H
#define NEARESTPOINT_H

#include <vector>
#include <cmath>

#define FLOAT_INF std::numeric_limits<float>::max();

using namespace std;

struct Point
{
  int x, y;
};

struct NearestPointRes
{
  int index;
  float distance;
};

float calculateDistance(Point &a, Point &b)
{
  return sqrt(pow(b.x - a.x, 2) + pow(b.y - b.x, 2));
}

/**
 * @brief Calcula el punto más cercano dado un conjunto de puntos y un punto
 * nuevo
 *
 * @param points el vector con los puntos almacenados
 * @param point el punto nuevo
 * @return Una struct con el índice del punto más cercano y la distancia al
 * mismo
 */
NearestPointRes nearestPoint(vector<Point> &points, Point &point)
{
  int nearestPoint = 0;
  float nearestDistance = FLOAT_INF;
  for (int i = 0; i < points.size(); i++)
  {
    float newDistance = calculateDistance(points[i], point);

    if (newDistance < nearestDistance)
    {
      nearestDistance = newDistance;
      nearestPoint = i;
    }
  }

  return {nearestPoint, nearestDistance};
}

#endif