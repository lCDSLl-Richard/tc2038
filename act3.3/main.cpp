#include <iostream>
#include <vector>
#include "knapSack.h"

using namespace std;

int main()
{
    cout << "Ingrese la cantidad de objetos: ";
    int nItems;
    cin >> nItems;

    vector<int> profits(nItems);
    vector<int> weights(nItems);

    cout << "\nBeneficios:" << endl;
    for (int i = 0; i < nItems; i++)
        cin >> profits[i];

    cout << "\nPesos:" << endl;
    for (int i = 0; i < nItems; i++)
        cin >> weights[i];

    int maxWeight;
    cout << "\nPeso máximo de la mochila: ";
    cin >> maxWeight;

    vector<vector<int>> matrix(nItems + 1, vector<int>(maxWeight + 1, 0));
    int result = knapSack(maxWeight, weights, profits, matrix);

    cout << "Beneficio óptimo: " << result << endl;

    cout << "Matriz generada:" << endl;
    for (auto row : matrix)
    {
        for (auto value : row)
            cout << value << " ";
        cout << endl;
    }

    return 0;
}