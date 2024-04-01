/*
// Maximum Sum Subarray
    * We have to find the element's of a contiguous subarray of numbers that has the largest sum.

// What is subarray?
    subarray of {1, 2, 3}
    : {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 2, 3}
    Note : {1, 3} are not subarray of contiguous element.

// Example:
    I/p: arr[] = {2, 3, -8, 7, -1, 2, 3}
    O/p: 11

    I/p: arr[] = {5, 8, 3}
    O/p: 16

    I/p: arr[] = {-6, -1, -8}
    O/p: -1

// Naive Solution:
    * we assign our res = arr[0]
    * In outer loop from 0 --to--> n-1:
        * let sum = 0
        * In Inner loop from j=i--to--> n-1:
            * sum = sum + arr[j]
            * res = max(res, sum)
    * Using the comparision with max() function we can get the MaxSum of subarray
    * TC : O(n^2)
    * SC : O(1)

// Efficient Solution: 
    * We traverse the array from left to right:
        * For every element we find out the maximum sum of sub array that must end with this element.
        * Our overall result is going to be maximum of all these values.

        arr:              { -5,  1,  -2,  3,  -1,  2, -2 } 
                            |   |    |   |    |   |   |
        maxEnding          -5   1   -1   3    2   4   2
                                                   |
                                                 Result
    * Idea is to extend the sub-array or start a new subarray:
    * We can use maxEnding of prev element + current element to extend the sub array,
    * or we can use current element to start a new subarray.
    * Using max(), with these two we can take the max value.
            MaxEnding[i] = max((maxEnding[i-1] + arr[i]), arr[i])
    * TC : O(n)
    * AS : O(1)

*/      

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution:
int maxSubarray(int arr[], int n){
    int res = arr[0];   // initialize our res = arr[0], let say default max.
    int maxEnding = arr[0]; // maxEnding is arr[0], because there is nothing before it.
    // iterating from 1 --to--> n-1
    for(int i=1;i<n;i++){
        maxEnding = max((maxEnding + arr[i]), arr[i]);  // getting max from (maxEnding + arr[i]) or arr[i], whatever the max value, we take it as our maxEnding
        res = max(res, maxEnding);  // compare res with maxEnding & store in res. 
    }
    return res;
}

// Naive Solution:
int maxSubarray_(int arr[], int n){
    int res = arr[0];
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<3;j++){
            sum = sum + arr[j];
            res = max(res, sum);
        }
    }
    return res;
}


int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << maxSubarray(arr, n);

    return 0;
}