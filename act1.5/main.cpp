#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::map;
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

vector<int> DPChange(vector<int> &coinDenominations, int target, map<int, int> cache) {}

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
}