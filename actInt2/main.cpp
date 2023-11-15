#include <iostream>

#include <map>
#include <fstream>

#include "solution.cpp"
#include "headers/argHelper.h"

using namespace std;

int main(int argc, char *argv[])
{
  map<string, string> flags;
  processFlags(argc, argv, flags);

  ifstream inFile;
  ofstream outFile;

  if (flags["-i"] != "")
  {
    inFile.open(flags["-i"]);
    if (!inFile.is_open())
    {
      cout << "No se pudo abrir el archivo de entrada\n";
      exit(1);
    }
  }

  if (flags["-o"] != "")
  {
    outFile.open(flags["-o"]);
    if (!outFile.is_open())
    {
      cout << "No se pudo abrir el archivo de salida\n";
      exit(1);
    }
  }

  if (inFile.is_open() && outFile.is_open())
    solution(inFile, outFile, false);
  else if (inFile.is_open())
    solution(inFile, cout, false);
  else if (outFile.is_open())
    solution(cin, outFile);
  else
    solution(cin, cout);

  inFile.close();
  outFile.close();
  return 0;
}