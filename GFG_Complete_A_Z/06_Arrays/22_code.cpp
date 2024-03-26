/*
// Maximum length Even-odd Subarray:

    I/p : {10, 12, 14, 7, 8}
    O/p : 3

    I/p : {7, 10, 13, 14}
    O/p : 4

    I/p : {10, 12, 18, 4}
    O/p : 1

// Naive Solution: 
    * We will use nested loop: 
    * We will initialize res = 1
    * Inside the outer loop:    
        * we initialize the counter as 1,
        * Started inner loop:
            * We check the condition where, the current element is odd & previous is even, or current is even or previous is odd, & at the end we can increase the counter
            * else we break the subarray
            * At end we will store the counter value with max(res, curr) function.
    * TC : O(n^2)
    * AS : O(1)

// Efficient Solution:
    * Solution with complexity O(n), based on "Kadane's Algorithm",
    * Like kadane's algorithm we begin traversing from the second element,
    * For every element we have two cases, either we extend the previous subarray, or we start a new subarray.
    * We extend the subarray, if the current element is alternating with the previous element.
    * Else we create an new subarray.f
    * TC : O(n)
    * AS : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution: 
int evenOdd(int arr[], int n){
    int res = 1;
    int curr = 1;   // subarray size, initially as 1
    for(int i=1;i<n;i++){
        if((arr[i] % 2 == 0 && arr[i-1]% 2 != 0) || (arr[i] % 2 != 0 && arr[i-1] % 2 == 0)) {
            curr++; // extending the subarray
            res = max(res, curr);   // storing the max length of subarray.
        } else {
            curr = 1;   // creating new subarray
        }
    }
    return res;
}

// Naive Solution: 
int evenOdd_(int arr[], int n){
    int res = 1;
    for(int i=0;i<n;i++){
        int curr = 1;
        for(int j=i+1;j<n;j++){
            if((arr[j] % 2 == 0 && arr[j-1]% 2 != 0) || (arr[j] % 2 != 0 && arr[j-1]%2 == 0)) {
                curr++;
            } else {
                break;
            }
        }
        res = max(res, curr);
    }
    return res;
}


int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << evenOdd(arr, n);

    return 0;
}