#include <iostream>
#include <vector>
#include <math.h>

/* Laberinto Backtracking
 * Ricardo Adolfo Fernández Alvarado A01704813
 * Damariz Licea Carrisoza A01369045
 */

using namespace std;

bool yesGo(int **arr, int x, int y, int nR, int nC)
{
    if (x < nR && y < nC && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool recorringMaze(int **arr, int x, int y, int nR, int nC, int **solutionArr)
{
    if (x == nR - 1 && y == nC - 1)
    {
        solutionArr[x][y] = 1;
        return true;
    }

    if (yesGo(arr, x, y, nR, nC))
    {
        solutionArr[x][y] = 1;
        if (x == nR - 1 && y == nC - 1)
        {
            return true;
        }
        if (recorringMaze(arr, x + 1, y, nR, nC, solutionArr))
        {
            return true;
        }
        if (recorringMaze(arr, x, y + 1, nR, nC, solutionArr))
        {
            return true;
        }
        solutionArr[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int nR, nC;
    cout << "Ingresa el numero de filas: ";
    cout << "Ingresa el numero de columnas: ";
    cin >> nR >> nC;
    if (nR <= 0 || nC <= 0)
    {
        cout << "El numero de columnas o filas no es valido" << endl;
        return 0;
    }

    int **arr = new int *[nR];
    for (int i = 0; i < nR; i++)
    {
        arr[i] = new int[nC];
    }
    for (int i = 0; i < nR; i++)
    {
        for (int j = 0; j < nC; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **solutionArr = new int *[nR];
    for (int i = 0; i < nR; i++)
    {
        solutionArr[i] = new int[nC];
        for (int j = 0; j < nC; j++)
        {
            solutionArr[i][j] = 0;
        }
    }
    if (recorringMaze(arr, 0, 0, nR, nC, solutionArr))
    {
        cout << "Si hay solucion" << endl;
        for (int i = 0; i < nR; i++)
        {
            for (int j = 0; j < nC; j++)
            {
                cout << solutionArr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No hay solucion" << endl;
    }

    return 0;
}