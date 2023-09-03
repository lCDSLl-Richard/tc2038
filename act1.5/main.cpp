#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::min;
using std::reverse;
using std::sort;
using std::vector;

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

  // for (int i = 0; i < coinDenominations.size() + 1; i++)
  // {
  //   for (int j = 0; j < target + 1; j++)
  //   {
  //     cout << changeMatrix[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int denomination = coinDenominations.size();
  vector<int> res(denomination);

  while (denomination > 0)
  {
    if (changeMatrix[denomination][target] == changeMatrix[denomination - 1][target])
    {
      denomination--;
      continue;
    }
    else if (changeMatrix[denomination][target] ==
             1 + changeMatrix[denomination][target - coinDenominations[denomination]])
    {
      res[denomination]++;
      target -= coinDenominations[denomination];
    }
    else
    {
      break;
    }
  }

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

  for (int i = 0; i < numberOfCoins.size(); i++)
  {
    cout << numberOfCoins[i] << " ";
  }
  cout << endl;

  reverse(coinDenominations.begin(), coinDenominations.end());
  vector<int>
      numberOfCoinsDP = DPChange(coinDenominations, payed - charged);

  for (int i = 0; i < numberOfCoinsDP.size(); i++)
  {
    cout << numberOfCoinsDP[i] << " ";
  }
  cout << endl;
}