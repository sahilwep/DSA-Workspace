/*
// Maximum Circular Subarray Sum:

    * What is Circular subarray: 
    * All circular subarray are: 
        * Normal : {10}, {5}, {-5}, {10, 5}, {-5, 5}, {10, 5, -5}
        * Only Circular : {5, -5, 10}, {-5, 10}, {-5, 10, 5}

    I/p : arr[] = {5, -2, 3, 4}
                   +      +  +
    O/p : 12


    I/p : arr[] = {2, 3, -4}
                   +  +
    O/p : 5


    I/p : arr[] = {8, -4, 3, -5, 4}
                   +             +
    O/p : 12
    

    I/p : arr[] = {-3, 4, 6, -2}
                       +  +
    O/p : 10


    I/p : arr[] = {-8, 7, 6}
                       +  +
    O/p : 13


    I/p : arr[] = {3, -4, 5, 6, -8, 7}
                   +   +  +  +      +
    O/p : 17

// Naive Solution:
    * TC : O(n^2)
    * AS : O(1)

// Efficient Solution:
    * Take a maximum of following two:
        * Maximum sum of normal subarray (Easy : Kadane)
        * Maximum sum of circular subarray (With kandans)
            * {x0, x1,...xi, x(i+1)......x(j+1), xj, x(j+1).......x(n-1)}   
                + + + + + +                          + + + + + + + + +  
            * Adding previous values & the end values.

    * TC : O(n)
    * AS : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution:
int normalMaxSum(int arr[], int n){
    int res = arr[0];
    int maxEnding = arr[0];
    for(int i=1;i<n;i++){
        maxEnding = max( maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int maxCircularSum(int arr[], int n){
    int max_normal = normalMaxSum(arr, n);      // first we get the sum part from the normal subarray
    // checking if our all the element is negative, as max_normal < 0
    if(max_normal < 0){
        return max_normal;
    }

    // Performing Circular subarray sum: 
    int arr_sum = 0;    
    // inverting the value : from +ve to negative
    for(int i=0;i<n;i++){
        arr_sum += arr[i];  // getting the array sum
        arr[i] = -arr[i];   // inverting the value of an array.
    }
    int max_circular = arr_sum + normalMaxSum(arr, n);  // Fro finding the max_circular, we are adding the max_sum with our flipped normalMaxSum(arr, n)
    return max(max_normal, max_circular);   // at last we compare the maximum sum with the (normal_sum, max_sum)
}


// Naive solution
int maxCircularSum_(int arr[], int n){
    int res = arr[0];   // let assume the first index element is the max sum value itself.
    for(int i=0;i<n;i++){
        int curr_max = arr[i]; 
        int curr_sum = arr[i]; 
        for(int j=1;j<n;j++){
            // using modular arithmetic to compute the circular index
            int index = (i + j) % n;  //  : This calculates the index within the circular array. The modulo operation (%) ensures that the index wraps around to the beginning of the array if it goes beyond the array size.
            curr_sum = curr_sum + arr[index];   //  This line accumulates the sum of the current subarray by adding the element at the calculated index index to the curr_sum variable.
            curr_max = max(curr_max, curr_sum);     //  This line compares the current subarray sum curr_sum with the previously found maximum subarray sum curr_max. The larger value is stored in curr_max.
        }
        res = max(res, curr_max);   //   After iterating through all subarray starting at arr[i], this line compares the maximum subarray sum found for this element (curr_max) with the overall maximum sum res found so far. The larger value is stored in res.
    }
    return res;
}

int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << maxCircularSum(arr, n);

    return 0;
}