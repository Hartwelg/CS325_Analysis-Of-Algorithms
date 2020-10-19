//badSort algorithm based on stooge sort algorithm: https://www.geeksforgeeks.org/stooge-sort/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void badSort(int array[], int l, int r, double alpha)
{
    if (l >= r)
    {
        return;
    }
    if (r - l + 1 == 2)
    {
        if (array[l] > array[r])
        {
            swap(array[l], array[r]);
        }
    }
    if (r - l + 1 > 2)
    {
        int m = 0;
        if (alpha < 1.0 / 3)
            m = ceil((r - l + 1) * alpha);
        else
            m = ((r - l + 1) * alpha);

        badSort(array, l, r - m, alpha);
        badSort(array, l + m, r, alpha);
        badSort(array, l, r - m, alpha);
    }
}

int main()
{
    int n1 = 0, n2 = 0;
    double alpha = 1.0 / 3;
    string temp = "";
    cout << "enter alpha" << endl;
    getline(cin, temp);
    if (temp.at(0) == '0');
        alpha = 1 - stod(temp);

    ifstream infile ("data.txt");
    string line;

    infile >> n1;
    int* array1 = new int[n1];

    for (int i = 0; i < n1; i++)
    {
        infile >> array1[i];
    }

    infile >> n2;
    int* array2 = new int[n2];
    
    for (int i = 0; i < n2; i++)
    {
        infile >> array2[i];
    }

    badSort(array1, 0, n1 - 1, alpha);
    badSort(array2, 0, n2 - 1, alpha);
    
    ofstream outfile ("bad.out");
    if (outfile.is_open())
    {
        for (int i = 0; i < n1; i++)
        {
            outfile << array1[i] << " ";
        }
        outfile << endl;
        for (int j = 0; j < n2; j++)
        {
            outfile << array2[j] << " ";
        }
        outfile << endl;
    }

    return 0;
}