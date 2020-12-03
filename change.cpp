#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int maxDenom(int coins[], int n, int size)
{
    int coin = 0, i = size;
    while (i > -1)
    {
        coin = coins[i];
        if (n < coins[i])
        {
            i--;
        }
        else
        {
            coin = coins[i];
            break;
        }
    }
    return coin;
}
int makeChange(int coins[], int c, int k, int n, vector<int>& denoms, vector<int>& numUsed)
{
    int maxCoin = 0;
    while (n > 0)
    {
        maxCoin = maxDenom(coins, n, k);
        if (maxCoin == -1)
        {
            cout << "no change to be made" << endl;
        }
        else
        {
            n -= maxCoin;
            denoms.push_back(maxCoin);
        }
    }

    return 0;
}

int main()
{
    ifstream infile ("data.txt");
    int c = 0, k = 0, n = 0;
    //c = base, k = power, n = amount to make change for
    while (true)
    {
        infile >> c >> k >> n;

        int* coins = new int[k + 1];
        vector<int> usedDenoms;
        vector<int> numUsed;
        for (int i = 0; i < k + 1; i++)
        {
            coins[i] = pow(c, i);
        }

        makeChange(coins, c, k, n, usedDenoms, numUsed);

        for (int j = 0; j < usedDenoms.size(); j++)
        {
            int temp = usedDenoms.at(j), count = 0;
            for (int k = 0; k < usedDenoms.size(); k++)
            {
                if (usedDenoms[k] == temp)
                {
                    count++;
                    if (count > 1)
                    {
                        usedDenoms.erase(usedDenoms.begin() + k);
                    }
                }
            }
            numUsed.push_back(count);
            
        }
        
        ofstream outfile ("change.txt", ios::app);
        if (outfile.is_open())
        {
            for (int l = 0; l < usedDenoms.size(); l++)
            {
                outfile << usedDenoms[l] << " " << numUsed[l] << endl;
            }
        }

        if (infile.eof())
        {
            break;
        }
    }
    
    return 0;
}