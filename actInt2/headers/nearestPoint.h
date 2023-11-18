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