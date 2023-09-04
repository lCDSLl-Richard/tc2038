#include <vector>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::reverse;
using std::sort;
using std::vector;

/**
 * @brief Función para calcular el cambio de monedas de manera voraz
 *
 * Complejidad temporal: O(n)
 * Complejidad espacial: O(n)
 *
 * @param coinDenominations el arreglo con las denominaciones
 * @param target el cambio a devolver
 * @return vector<int> el vector con los valores
 */
vector<int> greedyChange(vector<int> &coinDenominations, int target)
{
  vector<int> res(coinDenominations.size(), 0);
  for (int i = 0; i < coinDenominations.size(); i++)
  {
    res[i] = target / coinDenominations[i];
    target -= coinDenominations[i] * res[i];
  }

  return res;
}

/**
 * @brief Función para calcular el cambio de monedas de manera dinámica
 *
 * Complejidad temporal: O(n * m)
 * Complejidad espacial: O(n * m)
 * n = número de denominaciones
 * m = cantidad a devolver
 *
 * @param coinDenominations El arreglo con las denominaciones
 * @param target El valor de cambio a regresar
 * @return vector<int> El vector con la cantidad de monedas de cada denominación
 */
vector<int> DPChange(vector<int> &coinDenominations, int target)
{
  vector<vector<int>> changeMatrix(coinDenominations.size() + 1, vector<int>(target + 1, 0));
  for (int i = 0; i < target + 1; i++)
    changeMatrix[0][i] = i;

  for (int i = 1; i < coinDenominations.size() + 1; i++)
  {
    for (int j = 0; j < target + 1; j++)
    {
      if (j >= coinDenominations[i - 1])
      {
        changeMatrix[i][j] = min(changeMatrix[i - 1][j],
                                 1 + changeMatrix[i][j - coinDenominations[i - 1]]);
      }
      else
      {
        changeMatrix[i][j] = changeMatrix[i - 1][j];
      }
    }
  }

  int denomination = coinDenominations.size();
  vector<int> res(denomination, 0);

  while (denomination > 0)
  {
    if (coinDenominations[denomination - 1] != 1 &&
        changeMatrix[denomination][target] == changeMatrix[denomination - 1][target])
    {
      denomination--;
      continue;
    }
    else if (target >= coinDenominations[denomination - 1] &&
             changeMatrix[denomination][target] ==
                 1 + changeMatrix[denomination][target - coinDenominations[denomination - 1]])
    {
      res[denomination - 1]++;
      target -= coinDenominations[denomination - 1];
    }
    else
    {
      break;
    }
  }

  reverse(res.begin(), res.end());
  return res;
}

int main()
{
  int denominationNumber;
  cout << "Ingrese la cantidad de denominaciones de monedas: ";
  cin >> denominationNumber;

  vector<int> coinDenominations(denominationNumber);

  for (size_t i = 0; i < denominationNumber; i++)
  {
    int denomination;
    cout << "Ingrese la denominación " << i + 1 << ": ";
    cin >> denomination;
    coinDenominations[i] = denomination;
  }
  int charged, payed;
  cout << "Ingrese la cantidad a pagar y la cantidad pagada: ";
  cin >> charged >> payed;

  sort(coinDenominations.begin(), coinDenominations.end());
  reverse(coinDenominations.begin(), coinDenominations.end());

  vector<int> numberOfCoins = greedyChange(coinDenominations, payed - charged);

  cout << "Cambio voraz: ";
  for (int i = 0; i < numberOfCoins.size(); i++)
  {
    cout << numberOfCoins[i] << " ";
  }
  cout << endl;

  reverse(coinDenominations.begin(), coinDenominations.end());
  vector<int>
      numberOfCoinsDP = DPChange(coinDenominations, payed - charged);

  cout << "Cambio dinámico: ";
  for (int i = 0; i < numberOfCoinsDP.size(); i++)
  {
    cout << numberOfCoinsDP[i] << " ";
  }
  cout << endl;
}