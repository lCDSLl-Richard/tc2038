// Actividad 2.4 Suffix Array
// Ricardo Adolfo Fernández Alvarado - A01704813
// Damariz Licea Carrisoza - A01369045
// Compilar con g++ -std=c++11 main.cpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief
 * Función que genera un arreglo de sufijos ordenado de una string
 *
 * @note Complejidad temporal: O(n^2 log n)
 * @note Complejidad espacial: O(n)
 *
 * @param str la string de la cual generar los sufijos
 * @param suffixArr el arreglo dponde guardar los sufijos
 */
void generateSuffixArray(string str, vector<pair<int, string>> &suffixArr)
{
  for (int i = 0; i < str.length(); i++)
  {
    suffixArr[i] = {i, str.substr(i, str.length() - i)};
  }

  sort(suffixArr.begin(), suffixArr.end(),
       [](const pair<int, string> &a, const pair<int, string> &b)
       { return a.second < b.second; });
}

int main()
{
  string input;
  cout << "Ingrese una string: ";
  cin >> input;

  vector<pair<int, string>> suffixArr(input.length());

  generateSuffixArray(input, suffixArr);

  cout << "\nSufijos ordenados:\n";
  for (int i = 0; i < input.length(); i++)
  {
    if (suffixArr[i].first < 10)
      cout << " ";

    cout << suffixArr[i].first << ": " << suffixArr[i].second << "\n";
  }

  return 0;
}