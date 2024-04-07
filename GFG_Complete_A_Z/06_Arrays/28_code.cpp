/*
// Prefix Sum
    * Given a fixed array and multiple range sum quires, how to answer the quires efficiently.

    I/p : arr[] = {2, 8, 3, 9, 6, 5, 4}
        Quires: getSum(0, 2)
                getSum(1, 3)
                getSum(2, 6)
    O/p : 13 20 27

// Naive Solution: 
    * TC : O(n)
    * AS : O(1)

// Efficient Solution: 
    * We are going to pre-process the array for getting the TC : O(1): 
            arr = [2, 8, 3, 9, 6, 5, 4]
        * Step 1: Precompute Prefix Sum array:
                pSum = [2, 10, 13, 22, 28, 33, 37]
                pSum[i] = Summation of arr[i] from 0 to i 
        * Step 2: We can get the sum in TC O(1).

                              |-----> pSum[r], if l = 0
                getsSum(l, r)=|
                              |-----> pSum[r] - pSum[l-1], otherwise

    * Example:
            arr = [2, 8, 3, 9, 6, 5, 4]
            pSum = [2, 10, 13, 22, 28, 33, 37]
        
        getSum(0, 2): pSum[2]
                    = 13

        getSum(1, 3): pSum[3] - pSum[1-1]
                    =  22 - 2
                    =  20
        getSum(2, 6): pSum[6] - pSum[1]
                    = 37 - 10
                    = 27
    * TC : O(1)
    * AS : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution: O(1)
int getSum(int arr[], int l, int r){
    if(l == 0) return arr[r];
    return arr[r] - arr[l-1];
}

// Naive Solution: O(n)
int getSum_(int arr[], int start, int end){
    int res = 0;
    for(int i=start;i<=end;i++){
        res += arr[i];
    }
    return res;
}

int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    
    // Preprocessing for pSum array: 
    int pSum[n];
    pSum[0] = arr[0];
    for(int i=1;i<n;i++){
        pSum[i] = arr[i] + pSum[i-1];
    }

    // function call for pSum array:
    int t;
    cin >> t;
    while(t--){
        int s, e;
        cin >> s >> e;
        cout << getSum(pSum, s, e) << " ";
    }

    // // function call for naive solution: 
    // int t;
    // cin >> t;
    // while(t--){
    //     int s, e;
    //     cin >> s >> e;
    //     cout << getSum(arr, s, e) << " ";
    // }

    return 0;
}