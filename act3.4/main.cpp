#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXN = 100;

int N;                 // Número de nodos en el grafo
int graph[MAXN][MAXN]; // Matriz de adyacencias
int color[MAXN];       // Almacena el color asignado a cada nodo

/**
 * @brief Verifica si es seguro asignar el color c al nodo v
 *
 * @param v
 * @param c
 * @return true
 * @return false
 */

bool isSafe(int v, int c)
{
    for (int i = 0; i < N; i++)
    {
        if (graph[v][i] && c == color[i])
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Asigna un color a cada nodo del grafo
 *
 * @param v
 * @return true
 * @return false
 */

bool graphColoring(int v)
{
    if (v == N)
    {
        return true;
    }

    for (int c = 0; c < N; c++)
    {
        if (isSafe(v, c))
        {
            color[v] = c;
            if (graphColoring(v + 1))
            {
                return true;
            }
            color[v] = -1;
        }
    }

    return false;
}

/**
 * @brief Imprime la solución del problema
 *
 */

void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        cout << "Vertice: " << i << ", Color asignado: " << color[i] << endl;
    }
}

/**
 * @brief Función principal
 */

int main()
{
    ifstream inputFile("cp1.txt");

    if (!inputFile)
    {
        cerr << "Error con el archivo de entrada." << endl;
        return 1;
    }

    inputFile >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            inputFile >> graph[i][j];
        }
    }

    inputFile.close();

    for (int i = 0; i < N; i++)
    {
        color[i] = -1;
    }

    if (graphColoring(0))
    {
        cout << "Asignacion de colores exitosa:" << endl;
        printSolution();
    }
    else
    {
        cout << "No es posible asignar colores a los nodos." << endl;
    }

    return 0;
}