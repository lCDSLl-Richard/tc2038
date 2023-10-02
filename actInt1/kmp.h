#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief
 * Retorna el palíndromo de un string
 *
 * @param maliciousCode el código a palindromizar
 * @return string el palíndromo
 * @note Complejidad temporal: O(n)
 * @note Complejidad espacial: O(1)
 */
string palindromize(string maliciousCode)
{
  string palindrome = "";
  int length = maliciousCode.length();
  for (int i = length - 1; i >= 0; i--)
  {
    palindrome += maliciousCode[i];
  }
  return palindrome;
}

/**
 * @brief
 * Genera el arreglo LPS de una string
 *
 * @param pattern la string para generar el arreglo LPS
 * @return vector<int> el vector LPS de la string
 * @note Complejidad temporal: O(n)
 * @note Complejidad espacial: O(n)
 */
vector<int> computeLPSArray(const string &pattern)
{
  int patternLength = pattern.length();
  vector<int> lps(patternLength, 0);
  int prevSuffLen = 0;

  int i = 1;
  while (i < patternLength)
  {
    if (pattern[i] == pattern[prevSuffLen])
    {
      prevSuffLen++;
      lps[i] = prevSuffLen;
      i++;
    }
    else
    {
      if (prevSuffLen != 0)
      {
        prevSuffLen = lps[prevSuffLen - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

/**
 * @brief
 * Aplicación del algoritmo KMP para encontrar un patrón en un texto
 *
 * @param pattern el patrón a buscar
 * @param text el texto sobre el cual buscar el patrón
 * @return vector<int> los índices de inicio de las ocurrencias del patrón en el texto
 *
 * @note n = `text`, m = `pattern`
 * @note Complejidad temporal: O(n + m).
 * @note Complejidad espacial: O(m).
 */
vector<int> KMP(const string &pattern, const string &text)
{
  int patternLength = pattern.length();
  int textLength = text.length();
  vector<int> lps = computeLPSArray(pattern);
  vector<int> positions; // Store the starting positions of pattern matches

  int i = 0; // Index for text[]
  int j = 0; // Index for pattern[]

  while (i < textLength)
  {
    if (pattern[j] == text[i])
    {
      i++;
      j++;
    }

    if (j == patternLength)
    {
      // Pattern found, add starting position to positions
      positions.push_back(i - j);
      j = lps[j - 1];
    }
    else if (i < textLength && pattern[j] != text[i])
    {
      if (j != 0)
      {
        j = lps[j - 1];
      }
      else
      {
        i++;
      }
    }
  }

  return positions;
}

#endif