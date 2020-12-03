//knapsack algorithm referenced from lecture slides and https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int knapSack(int w, int num[], int val[], int n)
{
    int bag[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                bag[i][j] = 0;
            }
            else if (num[i - 1] <= j)
            {
                bag[i][j] = max(val[i - 1] + bag[i - 1][j - num[i - 1]], bag[i - 1][j]);
            }
            else
            {
                bag[i][j] = bag[i - 1][j];
            }
        }
    }

    for (int k = 0; k < w + 1; k++)
    {
        for (int l = 0; l < w; l++)
        {
            cout << setw(3) << left <<  bag[l][k] << " ";
        }
        cout << endl;
    }

    cout << "max value: " << bag[n][w] << endl;
    cout << "composition (weight, value): " << "[" << num[n - 1] << ", " << val[n - 1] << "] + [" << w - num[n - 1] << ", " << bag[n - 1][w - num[n - 1]] << "]" << endl;
    // cout << "Optimal subset(s): "  << val[n - 1] << " + " << bag[n - 1][w - num[n - 1]] << endl;
    return 0;
}

int main()
{
    ifstream infile ("data.txt");
    int weight = 6;
    int* itemNum = new int[weight - 1];
    int* itemVal = new int[weight - 1];

    for (int i = 0; i < weight - 1; i++)
    {
        infile >> itemNum[i];
        infile >> itemVal[i];
    }

    knapSack(weight, itemNum, itemVal, weight - 1);

    return 0;
}