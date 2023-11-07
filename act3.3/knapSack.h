#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>

/**
 * @brief Utiliza DP para calcular el beneficio óptimo dados un arreglo de pesos,
 * valores y un peso máximo
 *
 * @param maxWeight el peso máximo que puede cargar la mochila
 * @param weights el arreglo con los pesos de cada item
 * @param values el arreglo con los valores de cada item
 * @param matrix la matriz dónde se guardará el dp
 * @return El valor óptimo de salida
 *
 * @note Complejidad temporal: O(n*w), dónde n es la cantidad de objetos y w el peso de la mochila
 * @note Complejidad espacial: O(n*w), dónde n es la cantidad de objetos y w el peso de la mochila
 */
int knapSack(int maxWeight,
             std::vector<int> &weights,
             std::vector<int> &values,
             std::vector<std::vector<int>> &matrix)
{
  int n = weights.size();

  for (int i = 1; i <= n; i++)
  {
    for (int w = 0; w <= maxWeight; w++)
    {
      if (weights[i - 1] <= w)
      {
        matrix[i][w] = std::max(matrix[i - 1][w],
                                matrix[i - 1][w - weights[i - 1]] + values[i - 1]);
      }
      else
      {
        matrix[i][w] = matrix[i - 1][w];
      }
    }
  }

  return matrix[n][maxWeight];
}

#endif