#include <iostream>
#include <vector>
#include <math.h>

// Laberinto Backtracking
// Ricardo Adolfo Fernández Alvarado A01704813
// Damariz Licea Carrisoza A01369045

using namespace std;

/**
 * @brief keepGoing is a function that checks if the position is valid or not to move
 * @param arr is the array of the maze
 * @param x helping to move in the rows
 * @param y helping to move in the columns
 * @param nR is number of rows
 * @param nC is number of columns
 * @return true if the position is valid, false if not
 * Time complexity O(1)
 */
bool keepGoing(int **arr, int x, int y, int nR, int nC)
{
    if (x < nR && y < nC && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

/**
 * @brief recorringMaze is a function that checks if there is a solution or not, and if there is a solution it fills the array with the solution
 * @param arr is the array of the maze
 * @param x helping to move in the rows
 * @param y helping to move in the columns
 * @param nR is number of rows
 * @param nC is number of columns
 * @param solutionArr is the array that will be filled with the solution
 * @return true if there is a solution, false if not
 * Time complexity O(2^n)
 * It follows the order first right then down
 */

bool solveMaze(int **arr, int x, int y, int nR, int nC, int **solutionArr)
{
    if (x == nR - 1 && y == nC - 1)
    {
        solutionArr[x][y] = 1;
        return true;
    }

    if (keepGoing(arr, x, y, nR, nC))
    {
        solutionArr[x][y] = 1;
        if (x == nR - 1 && y == nC - 1)
        {
            return true;
        }
        if (solveMaze(arr, x + 1, y, nR, nC, solutionArr))
        {
            return true;
        }
        if (solveMaze(arr, x, y + 1, nR, nC, solutionArr))
        {
            return true;
        }
        solutionArr[x][y] = 0;
        return false;
    }
    return false;
}

/**
 * @brief main is the function that calls the other functions
 * @param nR you enter the number of rows
 * @param nC you enter the number of columns
 * @return int
 * Time complexity O(1)
 */

int main()
{
    int nR, nC;
    cout << "Ingresa el numero de filas y columnas: ";
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

    cout << "Ingresa los valores del laberinto: " << endl;
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
    if (solveMaze(arr, 0, 0, nR, nC, solutionArr))
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