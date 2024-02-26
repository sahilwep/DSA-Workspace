/*
// find the second smallest element in an array : 

// same approach as we solved in previous second-largest.

// CONSTRAINS : 
    0 <= t <= 1000
    0 <= n <= 1000
    0 <= A <= 1000

// NOTE : we are finding the smallest, so our value should be intMAX

// input : 
1
6
9 9 3 1 1 2
// output : 
2

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
// bruteforce : 
    int secondSmallest_1(int arr[], int n){
        sort(arr, arr+n);   // sorting the array;
        int smallest = arr[0];
        int sSmallest = 10e4;   // assigning the sSmallest as intMax..
        for(int i=0;i<n;i++){
            if(arr[i] != smallest) {
                sSmallest = arr[i];
                break;
            }
        }
        return sSmallest;
    }
// better : 
    int secondSmallest_2(int arr[], int n){
        // first half : 
        int smallest = 10e4;        // assign the smallest as highest...
        for(int i=0;i<n;i++){
            if(arr[i] < smallest) smallest = arr[i];
        }
        // second half : 
        int sSmallest = 10e4;       // assign the smallest as highest...
        for(int i=0;i<n;i++){
            if(arr[i] != smallest && arr[i] < sSmallest ){
                sSmallest = arr[i];
            }
        }
        return sSmallest;
    }
// Optimal : 
    int secondSmallest_3(int arr[], int n){
        int smallest = arr[0];
        int sSmallest = 10e4;
        for(int i=0;i<n;i++){
            if(arr[i] < smallest){
                sSmallest = smallest;
                smallest = arr[i];
            }
            else if(arr[i] != smallest && arr[i] < sSmallest){
                sSmallest = arr[i];
            }
        }

        return sSmallest;
    }

};

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        Solution obj;
        int res = obj.secondSmallest_3(arr, n);
        (res == -1) ? cout << "all elements are same!" : cout << res;
    }
    return 0;
}