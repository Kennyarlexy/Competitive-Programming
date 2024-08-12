

// C++ program to find the sum of XOR of
// all subarray of the array
 
#include <iostream>
#include <vector>
using namespace std;
 
// Function to calculate the sum of XOR
// of all subarrays
int findXorSum(int arr[], int n)
{
    // variable to store
    // the final sum
    int sum = 0;
 
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {
            xorr = xorr ^ arr[j];
            sum += xorr;
        }
    }
 
    return sum;
}
 
// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << findXorSum(arr, n);
 
    return 0;
}