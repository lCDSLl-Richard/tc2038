#include <iostream>
#include <fstream>
#include <vector>
#include "graphColoring.h"

using namespace std;

int main()
{
    int nodes; // Número de nodos en el grafo

    ifstream inputFile("Casos/cp6.txt");

    if (!inputFile)
    {
        cerr << "Error con el archivo de entrada." << endl;
        return 1;
    }

    inputFile >> nodes;

    vector<vector<int>> graph(nodes, vector<int>(nodes)); // Matriz de adyacencias
    vector<int> colors(nodes, -1);

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            inputFile >> graph[i][j];
        }
    }

    inputFile.close();

    if (graphColoring(0, graph, colors))
    {
        cout << "Asignacion de colores exitosa:" << endl;
        cout << printSolution(nodes, colors);
    }
    else
    {
        cout << "No es posible asignar colores a los nodos." << endl;
    }

    return 0;
}