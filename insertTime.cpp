//insertion sort algorithm from: https://www.geeksforgeeks.org/insertion-sort/
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

void insertionSort(int array[], int number)  
{  
    int i = 0, key = 0, j = 0;  
    for (i = 1; i < number; i++) 
    {
        key = array[i];
        j = i - 1;
		
		while (j >= 0 && array[j] > key) 
        {  
            array[j + 1] = array[j];  
            j = j - 1;
        }
        array[j + 1] = key;  
    }
}

int main()  
{  
    srand(time(0));

    int max = 10000;
    int numbers[7] = {5000, 10000, 15000, 20000, 25000, 35000, 50000};
    
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
        insertionSort(arrays[i], numbers[i]);
        auto end = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<microseconds>(end - start);

        cout << "array " << i + 1 << " size: " << numbers[i] << endl;
        cout << "array " << i + 1 << " time to sort: " << time.count() << " microseconds" << endl;
    }

    return 0;
}