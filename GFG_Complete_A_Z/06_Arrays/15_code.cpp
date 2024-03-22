/*
// Maximum difference problem with order:

    maximum value of arr[j] - arr[i] such that j > i

    I/p: arr[] = {2, 3, 10, 6, 4, 8, 1}
    O/p: 6

    I/p: arr[] = {7, 9, 5, 6, 3, 2}
    O/p: 2

    I/p: arr[] = {10, 20, 30}
    O/p: 20

    I/p: arr[] = {30, 10, 8, 2}
    O/p: -2

// Naive Solution:
    arr[] = 2 3 10 6 4 8 1
    O/p : 8
    
    * Store res = arr[1] - arr[0]
    * First iteration from i=0 < (n-1):
        * Second iteration from j=i+1  < (n):
            * inside the second iteration we subtract all the arr[j] value with, previously selected arr[i]
            * Using the max function, if we found any subtracted value as maximum, we update our result instantly.
    * At the end, we can return result.
    * TC : O(n^2)

// better Solution: 
    arr[] = 2 3 10 6 4 8 1
    O/p : 8

    res = arr[1] - arr[0]
    minValue = arr[0]

    for i : res = max(res, arr[i] - minValue)
            minValue = min(minValue, arr[i])

    i = 1 : res = max(1, 3-2) = 1
            minValue = min(2, 3) = 2
            
    i = 2 : res = max(1, 10-2) = 8
            minValue = min(2, 3) = 2

            
    i = 3 : res = max(8, 6-2) = 8
            minValue = min(2, 6) = 2
    
    i = 4 : res = max(8, 4-2) = 8
            minValue = min(2, 4) = 2

    i = 5 : res = max(8, 8-2) = 8
            minValue = min(2, 8) = 2

    i = 6 : res = max(8, 1-2) = 8
            minValue = min(2, 1) = 1

    res = 8 -> max diff is 8

    * TC : O(n)

*/

#include<bits/stdc++.h>
using namespace std;

// Better solution: 
int maxDiff(int arr[], int n){
    int res = arr[1] - arr[0];
    int minValue = arr[0];
    for(int i=1;i<n;i++){
        res = max(res, arr[i] - minValue);
        minValue = min(minValue, arr[i]);
    }
    return res;
}


// Naive Solution: 
int maxDiff_1(int arr[], int n){
    int res = arr[1] = arr[0];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++) {
            res = max(res, (arr[j] - arr[i]));
        }
    }
    return res;
}



int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << maxDiff(arr, n);

    return 0;
}
