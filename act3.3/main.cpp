#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int knapSack(int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    int n = wt.size();

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    ifstream inputFile("input3.txt");

    int N;
    inputFile >> N;

    vector<int> profit(N);
    vector<int> weight(N);

    cout << "Beneficios:" << endl;
    for (int i = 0; i < N; i++)
    {
        inputFile >> profit[i];
        cout << profit[i] << endl;
    }

    cout << "Pesos:" << endl;
    for (int i = 0; i < N; i++)
    {
        inputFile >> weight[i];
        cout << weight[i] << endl;
    }

    int W;
    cout << "Peso máximo de la mochila" << endl;
    inputFile >> W;

    inputFile.close();

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    int result = knapSack(W, weight, profit, dp);

    cout << "Beneficio óptimo: " << result << endl;

    cout << "Matriz generada:" << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    return 0;
}