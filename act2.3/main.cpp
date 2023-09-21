// Actividad 2.3
// Ricardo Adolfo Fernández Alvarado - A01704813
// Damariz Licea Carrisoza - A01369045
// Compilar con g++ -std=c++11 main.cpp -o app

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * @brief
 * Función para generar una matriz a partir de un archivo de texto.
 *
 * Complejidad temporal: O(n)
 * Complejidad espacial: O(n)
 * @param file el archivo de texto
 * @param matrix
 * @param rowSize
 */
void generateMatrix(ifstream &file, vector<vector<char>> &matrix, int rowSize)
{
  matrix.push_back(vector<char>(rowSize));
  int row = 0;
  int column = 0;
  while (file.peek() != EOF)
  {
    if (column == rowSize)
    {
      matrix.push_back(vector<char>(rowSize, rowSize));
      column = 0;
      row++;
    }

    matrix[row][column] = file.get();
    column++;
  }
}

/**
 * @brief
 * Función para sumar todas las columnas de un matriz.
 *
 * Complejidad temporal: O(n^2)
 * Complejidad espacial: O(n)
 * @param matrix la matriz a sumar
 * @param columnSums un vector con los valores de las sumas de las columnas
 */
void sumMatrixColumns(vector<vector<char>> &matrix, vector<int> &columnSums)
{
  for (int i = 0; i < matrix.size(); i++)
    for (int j = 0; j < matrix[i].size(); j++)
      columnSums[j] += matrix[i][j];

  for (int i = 0; i < columnSums.size(); i++)
    columnSums[i] = columnSums[i] % 256;

  cout << endl;
}

/**
 * @brief
 * Función para crear hashes a partir de un arreglo de número
 *
 * Complejidad temporal O(n)
 * Complejidad espacial O(n)
 * @param values los valores a hashear
 * @return vector<string> un vector con los hashes en string
 */
vector<string> createHash(vector<int> &values)
{
  vector<string> hash;

  for (int i = 0; i < values.size(); i++)
  {
    stringstream ss;
    if (values[i] < 16)
      ss << "0";
    ss << uppercase << hex << values[i++];

    if (values[i] < 16)
      ss << "0";
    ss << uppercase << hex << values[i];
    hash.push_back(ss.str());
  }

  return hash;
}

int main()
{
  int rowSize;
  cout << "Ingresa el tamaño de la tabla: ";
  cin >> rowSize;
  if (rowSize % 4 != 0 || rowSize < 16 || rowSize > 64)
  {
    cout << "El tamaño de la tabla debe ser multiplo de 4 y estar entre 16 y 64" << endl;
    return -1;
  }

  string fileName;
  cout << "Ingresa el nombre del archivo de entrada: ";
  cin >> fileName;

  ifstream file(fileName);

  if (!file.is_open())
  {
    cout << "Archivo " << fileName << " no encontrado." << endl;
    return -1;
  }

  vector<vector<char>> table;
  generateMatrix(file, table, rowSize);

  cout << "Matriz generada a partir del archivo:" << endl;
  for (auto row : table)
  {
    for (char value : row)
    {
      if (value == '\n')
        cout << '-';
      else
        cout << value;
    }
    cout << endl;
  }

  vector<int> columnSums(rowSize, 0);
  sumMatrixColumns(table, columnSums);

  cout << "Suma de la columnas de la tabla:" << endl;
  for (auto sum : columnSums)
    cout << sum << " ";
  cout << endl
       << endl;

  cout << "Hash de la string:" << endl;
  vector<string> hash = createHash(columnSums);
  for (auto s : hash)
    cout << s << " ";
  cout << endl;

  file.close();

  return 0;
}