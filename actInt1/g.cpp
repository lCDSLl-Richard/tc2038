#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

void isPatInDoc(string pat, string txt)
{
    int patLength = pat.length();
    int docLength = txt.length();

    if (patLength > docLength)
    {
        cout << "El patron sobrepasa la cadena" << endl;
        return;
    }

    bool found = false;

    for (int i = 0; i <= docLength - patLength; i++)
    {
        int j;

        for (j = 0; j < patLength; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == patLength)
        {
            cout << "(true) " << i << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "(false) Cadena no encontrada en el archivo de transmision" << endl;
    }
}

string palindromize(string maliciousCode)
{
    string palindrome = "";
    int length = maliciousCode.length();
    for (int i = length - 1; i >= 0; i--)
    {
        palindrome += maliciousCode[i];
    }
}

vector<pair<int, int>> findPatternInTrans(string pattern, string transmission)
{
    vector<pair<int, int>> positions;
    int lenTransmission = transmission.length();
    int patternLength = pattern.length();
    int i = 0;

    while (i < lenTransmission)
    {
        int j = 0;
        int k = i;

        while (k < lenTransmission && j < patternLength && transmission[k] == pattern[j])
        {
            j++;
            k++;
        }

        if (j == patternLength)
        {
            positions.push_back(make_pair(i, k - 1));
        }

        if (j == 0)
        {
            i++;
        }
        else
        {
            i = k - j + 1;
        }
    }

    return positions;
}

vector<pair<int, int>> searchPalindromeInTrans(const string &maliciousString, const string &transmission)
{
    string mCodePalindrome = palindromize(maliciousString);
    return findPatternInTrans(mCodePalindrome, transmission);
}
