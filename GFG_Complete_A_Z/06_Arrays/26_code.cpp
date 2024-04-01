/*
// Sliding Window Technique:
    // Find the maximum sum of k consecutive elements:


    I/p : arr[] = {1, 8, 30, -5, 20, 7}
                         ----------             max sum position
    k = 3
    O/p : 45

    I/p : arr[] = {5, -10, 6, 90 3}
                           -----
    k = 2
    O/p : 96


// Naive solution: 
    * TC : O(n*k) times
    // Observation : 

                    arr = [10, 5, -2, 20, 1],    k = 3,     res = 23

        i = 0, curr = 0, res = 0
            j = 0
                curr = curr + arr[i+j] => curr = curr + arr[0+0] -> curr = 10
                res =  max(res, 10) -> res = 10, because the previous res is near to the -infinity.
            j = 1
                curr = curr + arr[0+1] => curr = 10 + 5 ->  curr = 15
                res = max(res, curr) => 15
            j = 2
                curr = curr + arr[0+2] => curr = 15 - 2 -> curr = 13
                res = max(res, 13) => 15

        i = 1, curr = 0, curr = 15
            j = 0
                curr = curr + arr[1 + 0] => curr = 0 + 5 -> curr = 5
                res = max(res, curr) -> 15
            j = 1
                curr = curr + arr[1 + 1] => curr = 5 + -2 -> curr = 3
                res = max(res, curr) -> 15
            j = 2 
                curr = curr + arr[1 + 2] => curr = 3 + 20 -> curr = 23
                res = max(res, curr) => max(15, 32) -> res = 23

        i = 2, curr = 0, curr = 23 * fails to enter, because there is lesser number than k at last of the list.
        
        * So res = 23

// Efficient Solution:
// Sliding Windows: 
    * Compute the sum of current window using the sum of previous window in O(1) Time.

        [ 1 | 8 | 30 | -5 | 20 | 7 ]         k = 4
         -----------------
        Initially: curr = 1+8+30+(-5) = 34,         res = 34

    I'st slide: 
        [ 1 | 8 | 30 | -5 | 20 | 7 ]
             ------------------
        curr = 34 + 20 - 1 = 53,        res = 53    
        * here adding 20 next item, & removing first or previous item.
    
    2'nd slide:
        [ 1 | 8 | 30 | -5 | 20 | 7 ]
                 ------------------
        curr = 53 + 7 - 8 = 52,     res = 53

    * At end res = 53
    * In this window sliding, we can use other operations also, like division, subtraction, xor, etc..
    * In case of subtraction: we can subtract upcoming element to the window i.e next element & add the last element the previous window, while sliding.
    * Similary, for product, we can divide the first element of previous window, & multiply the last element of the current window.
    
    * complexity : 
        * TC : O(n), we are running loop for k times, & we are running loop for n-k times.  
        * AS : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution:
int maxSum(int arr[], int n, int k){
    // making the window of size k
    int curr = 0;
    for(int i=0;i<k;i++){
        curr = curr + arr[i];
    }
    // after making the window, we start computing: 
    int res = curr; // making res, to compare new window with the previous windows.
    for(int i=k;i<n;i++){
        curr = curr + arr[i] - arr[i - k];  // we are adding the window's next element &  subtracting the window's previous element
        res = max(curr, res);   // this will compare the new_window sum with previous_window sum
    }
    return res;
}

// Naive solution:
int maxSum_(int arr[], int n, int k){
    int res = INT_MIN;  //initialize our result as -infinite
    // condition (i+k-1 < n) restrict the last values of the list lesser than k.
    for(int i=0;i+k-1<n;i++){
        int curr = 0;   // getting the curr sum for every inner computation.
        for(int j=0;j<k;j++){
            curr = curr +  arr[i+j];    // sum with adding (i & j) index.
            res = max(res, curr);   // string result by comparing with max().
        }
    }
    return res;
}


int main(void){

    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << maxSum(arr, n, k);

    return 0;
}