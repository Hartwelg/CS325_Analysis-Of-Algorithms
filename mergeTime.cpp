//merge sort algorithm from: https://www.geeksforgeeks.org/merge-sort/
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r) 
{ 
    int i = 0, j = 0, k = 0; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
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
        mergeSort(arrays[i], 0, numbers[i]);
        auto end = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<microseconds>(end - start);

        cout << "array " << i + 1 << " size: " << numbers[i] << endl;
        cout << "array " << i + 1 << " time to sort: " << time.count() << " microseconds" << endl;
    }
    return 0; 
}