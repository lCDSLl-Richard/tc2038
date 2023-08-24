#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using std::vector;

/**
 * @brief Junta dos subarreglos ordenados y crea un solo arreglo ordenado.
 * Complejidad temporal de O(n).
 * Complejidad espacial de O(n).
 *
 * @param vec el vector dónde ocurre el ordenamiento
 * @param start el índice dónde comienza el primer subarreglo
 * @param mid el índice dónde termina el primer subarreglo y comienza el segundo subarreglo
 * @param end el índice dónde termina el segundo subarreglo
 */
void merge(vector<double> &vec, int start, int mid, int end)
{

  vector<double> left, right;

  for (int i = start; i < mid + 1; i++)
  {
    left.push_back(vec[i]);
  }

  for (int i = mid + 1; i < end + 1; i++)
  {
    right.push_back(vec[i]);
  }

  int leftIndex = 0, rightIndex = 0, vecIndex = start;

  while (leftIndex < left.size() && rightIndex < right.size())
  {
    if (left[leftIndex] > right[rightIndex])
    {
      vec[vecIndex] = left[leftIndex];
      leftIndex++;
    }
    else
    {
      vec[vecIndex] = right[rightIndex];
      rightIndex++;
    }
    vecIndex++;
  }

  while (leftIndex < left.size())
  {
    vec[vecIndex] = left[leftIndex];
    leftIndex++;
    vecIndex++;
  }

  while (rightIndex < right.size())
  {
    vec[vecIndex] = right[rightIndex];
    rightIndex++;
    vecIndex++;
  }
}

/**
 * @brief Ordena un arreglo de doubles usando el algoritmo de Merge Sort.
 * Complejidad temporal de O(nlog(n)).
 * Complejidad espacial de O(n).
 *
 * @param vec el vector a ordenar
 * @param start dónde comienza el vector
 * @param end el último índice del vector
 */
void mergeSort(vector<double> &vec, int start, int end)
{
  if (start >= end)
    return;

  int mid = start + (end - start) / 2;

  mergeSort(vec, start, mid);
  mergeSort(vec, mid + 1, end);

  merge(vec, start, mid, end);
}

/**
 * @brief Ordena un arreglo de doubles usando Merge Sort.
 * Complejidad temporal de O(nlog(n)).
 * Complejidad espacial de O(n).
 *
 * @param vec el vector a ordenar
 */
void mergeSort(vector<double> &vec)
{
  mergeSort(vec, 0, vec.size() - 1);
}

#endif