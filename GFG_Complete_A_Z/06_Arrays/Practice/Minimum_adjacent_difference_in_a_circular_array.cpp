/*

// Minimum adjacent difference in a circular array


// Observations: 
    * We are given an array of size n arranged in circular fashion,
    * Our task is to find the minimum absolute difference b/w adjacent element.

// Example:
    * Input:
    Arr[] = {8,-8,9,-9,10,-11,12},  n = 7
    Output: 4
        Explanation: The absolute difference 
        between adjacent elements in the given 
        array are as such: 16 17 18  19 21 23 4
        (first and last). Among the calculated 
        absolute difference the minimum is 4.

// Intrusion: 
    * We are given circular array: 
        * We need to find the absolute difference of adjacent elements of an array.
        * then we have to return the minimum of them..

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minAdjDiff(int arr[], int n){
        int solu = abs(arr[n-1] - arr[0]);  // as array is circular we are getting the last & first connected node abs difference..
        for(int i=1;i<n;i++){
            int temp = abs((arr[i-1] - arr[i]));
            solu = min(temp, solu);
        }
        return solu;
    }
};

int main()
{
    int t;
    cin>>t; 
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++)  cin>>arr[i];
        Solution ob;

        cout << ob.minAdjDiff(arr, n) << endl;
    }
    return 0;
}