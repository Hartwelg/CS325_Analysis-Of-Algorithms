//insertion sort algorithm from: https://www.geeksforgeeks.org/insertion-sort/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
    //read arrays from data.txt
    ifstream infile ("data.txt");
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
    insertionSort(array1, number1);
    insertionSort(array2, number2);

    //output sorted arrays to insert.out
    ofstream outfile ("insert.out");
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
    cout << endl;
    
    return 0;
}