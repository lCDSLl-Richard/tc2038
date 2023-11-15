#ifndef FLAGPROCESSOR_H
#define FLAGPROCESSOR_H

#include <map>
#include <string>
#include <iostream>

using namespace std;

void processFlags(int argc, char *argv[], map<string, string> &flags)
{
  for (int i = 1; i < argc; i++)
  {
    if (argv[i][0] == '-')
    {
      if (i + 1 < argc && argv[i + 1][0] != '-')
      {
        flags[argv[i]] = argv[i + 1];
        i++;
      }
    }
  }
}

#endif