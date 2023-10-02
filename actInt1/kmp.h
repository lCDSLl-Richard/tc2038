#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <vector>
using namespace std;

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