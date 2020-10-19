//merge sort algorithm from: https://www.geeksforgeeks.org/merge-sort/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
    //read arrays from data.txt
    ifstream infile ("data.txt");
    string line;
    int number1 = 0, number2 = 0;

    infile >> number1;
    int* array1 = new int[number1];
    
    for (int i = 0; i < number1; i++)
    {
        infile >> array1[i];
    }

    infile >> number2;
    int* array2 = new int[number2];
    
    for (int i = 0; i < number2; i++)
    {
        infile >> array2[i];
    }

    //sort arrays
    mergeSort(array1, 0, number1 - 1);
    mergeSort(array2, 0, number2 - 1);

    // output sorted arrays to merge.out
    ofstream outfile ("merge.out");
    if (outfile.is_open())
    {
        for (int i = 0; i < number1; i++)
        {
            outfile << array1[i] << " ";
        }
        outfile << endl;
        for (int i = 0; i < number2; i++)
        {
            outfile << array2[i] << " ";
        }
    }

    return 0; 
} 