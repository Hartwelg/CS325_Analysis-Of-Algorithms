#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int binRand = 0, binCap = 0, numItems = 0, temp = 0;
    //int numTests = (rand() % 20);
    int numTests = 20;
    int binCaps[3] = {10, 20, 30};

    ofstream outfile ("binRandom.txt");
    outfile << numTests << endl;

    for (int i = 0; i < numTests; i++)
    {
        binRand = (rand() % 3);
        binCap = binCaps[binRand];
        numItems = (rand() % 20);

        outfile << binCap << endl;
        outfile << numItems << endl;
        for (int j = 0; j < numItems; j++)
        {
            temp = (rand() % numItems);
            outfile << temp << " ";
        }
        outfile << endl;
    }

    ifstream infile ("binRandom.txt");
    int FFbins = 0, FFDbins = 0, BFbins = 0;
    vector<int> weights;

    infile >> numTests;
    for (int i = 0; i < numTests; i++)
    {
        weights.clear();
        FFbins = 0, FFDbins = 0, BFbins = 0;
        infile >> binCap >> numItems;
        int *bins = new int[numItems];

        for (int i = 0; i < numItems; i++)
        {
            bins[i] = 0;
            infile >> temp;
            weights.push_back(temp);
        }

        for (vector<int>::iterator it = weights.begin(); it != weights.end(); it++)
        {
            for (int j = 0; j < numItems; j++)
            {
                if (bins[j] + *it <= binCap)
                {
                    bins[j] += *it;
                    break;
                }
            }
        }
        
        for (int j = 0; j < numItems; j++)
        {
            if (bins[j] > 0)
            {
                FFbins++;
            }
        }
        
        temp = numItems;
        for (int j = 0; j < numItems; j++)
        {
            bins[j] = 0;
        }
        for (vector<int>::iterator it = weights.begin(); it != weights.end(); ++it)
        {
            for (int j = 0; j < numItems; j++)
            {
                if (bins[j] == 0)
                {
                    bins[j] += *it;
                    break;
                }
                else
                {
                    temp = binCap - bins[j];
                    if (temp <= *it)
                    {
                        continue;
                    }
                    for (int k = 0; k < numItems; k++)
                    {
                        if (binCap - bins[k] <= temp && binCap - bins[k] != 0 && bins[k] != 0 && bins[k] + *it <= binCap)
                        {
                            temp = k;
                        }
                    }
                    if (bins[temp] + *it <= binCap)
                    {
                        bins[temp] += *it;
                        break;
                    }
                }   
            }
        }
        for (int j = 0; j < numItems; j++)
        {
            if (bins[j] > 0)
            {
                BFbins++;
            }
        }

        sort(weights.begin(), weights.end(), greater<int>());
        for (int j = 0; j < numItems; j++)
        {
            bins[j] = 0;
        }

        for (vector<int>::iterator it = weights.begin(); it != weights.end(); ++it)
        {
            for (int j = 0; j < numItems; j++)
            {
                if (bins[j] + *it <= binCap)
                {
                    bins[j] += *it;
                    break;
                }
            } 
        }
        for (int j = 0; j < numItems; j++)
        {
            if (bins[j] > 0)
            {
                FFDbins++;
            }
        }

        delete [] bins;
        cout << "Test case " << i << " First Fit: " << FFbins << ", First Fit Decreasing: " << FFDbins << ", Best Fit: " << BFbins << endl;
    }

    return 0;
}