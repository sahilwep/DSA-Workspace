/*
// Optimized Binary Search: 
    * The idea is to make jumps and slow the speed when we get closer to the target element.

// TC : O(logn)


*/

#include<bits/stdc++.h>
using namespace std;

int BinarySearchOptimized(int arr[], int n, int x){
    int k = 0;  // fist pointer..
    // at every iteration of b, we wil split the value of b into half, this will move left...
    for(int b = n/2;b>=1;b /= 2){
        // if finding value is smaller or equal, then we will increase k, this will move right... 
        while( (k+b) < n && arr[k+b] <= x){
            k = k + b;  // increasing k...
        }
        if(arr[k] == x) return k;   // now k index will become the finding index value...
    }
    return -1;  // else return -1...
}   

int main(void){
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << BinarySearchOptimized(arr, n, x);


    return 0;
}