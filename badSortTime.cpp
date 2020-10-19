//badSort algorithm based on stooge sort algorithm: https://www.geeksforgeeks.org/stooge-sort/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    srand(time(0));

    int max = 10000;
    int numbers[7] = {50, 100, 150, 200, 250, 350, 500};

    double alpha = 1.0 / 3;
    string temp = "";

    cout << "enter alpha" << endl;
    getline(cin, temp);
    if (temp.at(0) == '0');
        alpha = 1 - stod(temp);

    int** arrays = new int*[7];
    for (int i = 0; i < 7; i++)
    {
        arrays[i] = new int[numbers[i]];
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < numbers[i]; j++)
        {
            arrays[i][j] = rand() % max;
        }

        auto start = chrono::high_resolution_clock::now();
        badSort(arrays[i], 0, numbers[i], alpha);
        auto end = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<microseconds>(end - start);

        cout << "array " << i + 1 << " size: " << numbers[i] << endl;
        cout << "array " << i + 1 << " time to sort: " << time.count() << " microseconds" << endl;
    }

    return 0;
}