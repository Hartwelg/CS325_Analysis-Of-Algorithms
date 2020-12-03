//maxSub algorithm based on Kadane's algorithm: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
#include <iostream>

using namespace std;

int maxSub(int array[], int n)
{
    int curMax = 0, thisMax = 0;
    for (int i = 0; i < n; i++)
    {
        thisMax = thisMax + array[i];
        if(thisMax < 0)
        {
            thisMax = 0;
        }
        if(curMax < thisMax)
        {
            curMax = thisMax;
        }
    }
    return curMax;
}

int main()
{
    int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;
    for (int i = 0; i < n - 1; i++)
    {
        cout << array[i] << ", ";
    }
    cout << array[7] << endl;

    cout << maxSub(array, n) << endl;
}