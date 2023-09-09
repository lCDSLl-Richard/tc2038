#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
  int n, m;

  cout << "Ingrese las dimensiones de la matriz: ";
  cin >> n >> m;

  if (n < 1 || m < 1)
  {
    cout << "Error: las dimensiones de la matriz son inválidas.\n";
    return -1;
  }

  vector<vector<int>> labyrinth(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int buffer;
      cin >> buffer;
      if (buffer != 0 && buffer != 1)
      {
        cout << "Error: el valor ingresado no es válido.\n";
        return -1;
      }
      labyrinth[i][j] = buffer;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << labyrinth[i][j] << " ";
    }
    cout << "\n";
  }
}