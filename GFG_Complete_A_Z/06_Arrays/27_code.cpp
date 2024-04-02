/*
// Subarray with given sum:
    * We have to find out the subarray with the given sum.
    * There are no negative element in an array.

    I/p: [1, 4, 20, 3, 10, 5]
    sum = 33
    O/p: yes

    I/p: [1, 4, 0, 0, 3, 10, 5]
    sum = 7
    O/p: yes


    I/p: [2, 4]
    sum = 3
    O/p: No

// Naive Solution: 
    * We can compute subarray sum with using nested loop:
    * TC : O(n^2)

// Efficient Solution: 
    * We will use sliding window technique, In previous question we got a fixed size window, like we got k, but here in this question we don't have something like that.
    * We will maintain variable size window
    * We will use sliding window technique with a window of variable size.
    * Example: 
                   
                I/p: [1, 4, 20, 3, 10, 5]
                sum = 33
    
            * While current is smaller than sum, extend window by increasing end
                    start = 0, end = 0,   curr = 1
                    start = 0, end = 1,   curr = 5
                    start = 0, end = 2,   curr = 25
                    start = 0, end = 3,   curr = 28
                    start = 0, end = 4,   curr = 38         : here curr is grater than the sum, So:
            * While current is grater shrink the window size by increasing start.
                    start = 1, end = 4,   curr = 37
                    start = 2, end = 4,   curr = 33

    * TC : O(n)
    * AS : O(1)


*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution: O(n)
bool isSubSum(int arr[], int n, int sum){
    int curr = 0;
    int start = 0;
    for(int end = 0;end < n;end++){
        curr = curr + arr[end];     // condition to increase the window size..
        // condition to decrease the window size: when the current window size become bigger than the given sum
        while(sum < curr){
            curr = curr - arr[start];
            start++;
        }
        // condition when sum & curr is equal
        if(curr == sum){
            return true;
        }

    }
    return false;   // else there is no subarray that has equal to sum.
}

// Naive solution: O(n^2)
bool isSubSum_(int arr[], int n, int sum){
    for(int i=0;i<n;i++){
        int curr = 0;
        for(int j=i;j<n;j++){
            curr = curr + arr[j];
            if(curr == sum){
                return true;
            }
        }
    }
    return false;
}

int main(void){

    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    int res = isSubSum(arr, n, sum);
    (res == 1) ? cout << "Yes" : cout << "No";

    return 0;
}