#include <vector>
#include <iostream>
#include "mergeSort.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
  int size;
  cout << "Ingresa el tamaño de tu arreglo: ";
  cin >> size;
  vector<double> vec(size);

  for (int i = 0; i < size; i++)
  {
    double buffer;
    cout << "Ingresa el número " << i + 1 << " de tu arreglo: ";
    cin >> buffer;
    vec[i] = buffer;
  }

  cout << "Tu arreglo es: [ ";
  for (int i = 0; i < size; i++)
    cout << vec[i] << " ";
  cout << "]" << endl;

  mergeSort(vec);

  cout << "Tu arreglo ordenado es: [ ";
  for (int i = 0; i < size; i++)
    cout << vec[i] << " ";
  cout << "]" << endl;
}