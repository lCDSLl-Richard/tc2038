#ifndef LCS_H
#define LCS_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief
 * Encuentra la subsecuencia común más larga entre dos strings
 *
 * @param str1 la primera string sobre la que se buscará la subsecuencia
 * @param str2 la segunda string sobre la que se buscará la subsecuencia
 * @return pair<int, int> un par con el índice final de la subsecuencia y su longitud
 *
 * @note m = `str1.length()` n = `str2.length()`
 * @note Complejidad temporal: O(m*n)
 * @note Complejidad espacial: O(m*n)
 */
pair<int, int> LCS(const string &str1, const string &str2)
{
  int m = str1.length();
  int n = str2.length();

  vector<vector<int>> lcsMatrix(m + 1, vector<int>(n + 1, 0));

  int maxLen = 0;
  int endIndex = 0;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1;
        if (lcsMatrix[i][j] > maxLen)
        {
          maxLen = lcsMatrix[i][j];
          endIndex = i - 1;
        }
      }
      else
      {
        lcsMatrix[i][j] = 0;
      }
    }
  }

  return {endIndex, maxLen};
}

#endif