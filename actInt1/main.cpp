#include <iostream>
#include <fstream>
#include <vector>
#include "kmp.h"
#include "lcs.h"

using namespace std;

int main()
{

  for (int i = 1; i < 3; i++)
  {
    string text;
    ifstream textFile;
    textFile.open("transmission0" + to_string(i) + ".txt");

    while (textFile.peek() != EOF)
      text += textFile.get();

    textFile.close();

    cout << "Transmisión 0" << i << endl;
    for (int j = 1; j < 4; j++)
    {
      ifstream patternFile;
      string pattern;
      patternFile.open("mcode0" + to_string(j) + ".txt");
      while (patternFile.peek() != EOF)
        pattern += patternFile.get();

      patternFile.close();

      vector<int> positions = KMP(pattern, text);

      cout << "Patrón 0 " << j << endl;
      if (positions.size() > 0)
        cout << "(true) Patrón encontrada en la posición: " << positions[0] << endl;
      else
        cout << "(false) Patrón no encontrado en la transmisión" << endl;
    }
    cout << endl;
  }

  cout << "Búsqueda de palíndromos\n";
  for (int i = 1; i < 3; i++)
  {
    string text;
    ifstream textFile;
    textFile.open("transmission0" + to_string(i) + ".txt");

    while (textFile.peek() != EOF)
      text += textFile.get();

    textFile.close();

    cout << "Transmisión 0" << i << endl;
    for (int j = 1; j < 4; j++)
    {
      ifstream patternFile;
      string pattern;
      patternFile.open("mcode0" + to_string(j) + ".txt");

      while (patternFile.peek() != EOF)
        pattern += patternFile.get();
      patternFile.close();

      pattern = palindromize(pattern);

      vector<int> positions = KMP(pattern, text);

      cout << "Patrón 0 " << j << endl;
      if (positions.size() > 0)
        cout << "(true) Patrón encontrada en la posición: " << positions[0] << endl;
      else
        cout << "(false) Patrón no encontrado en la transmisión" << endl;
    }
    cout << endl;
  }

  cout << "LCS\n";
  ifstream trans1File("transmission01.txt"), trans2File("transmission02.txt");
  string trans1, trans2;

  while (trans1File.peek() != EOF)
    trans1 += trans1File.get();

  while (trans2File.peek() != EOF)
    trans2 += trans2File.get();

  pair<int, int> lcs = LCS(trans1, trans2);
  string lcsString = trans1.substr(lcs.first - lcs.second + 1, lcs.second);

  if (lcsString.size() > 0)
    cout << "Subcadena encontrada: "
         << lcsString
         << " en indices "
         << lcs.first << " "
         << lcs.first + lcs.second << endl;
  else
    cout << "No se encontró la subcadena entre archivos" << endl;

  return 0;
}