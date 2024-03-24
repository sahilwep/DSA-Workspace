/*
// Maximum Consecutive 1's in a Binary Array.

    I/p: arr[] = {0, 1, 1, 0, 1, 0}
    O/p: 2

    I/p: arr[] = {1, 1, 1, 1}
    O/p: 4

    I/p: arr[] = {0, 0, 0}
    O/p: 0

    I/p: arr[] = {1, 0, 1, 1, 1, 1, 0, 1, 1}
    O/p: 4

// Naive Solution:
    * In outer loop we stat from 0--to-->n-1:
        * In Inner loop every time we start counter & whenever we find the 0, we break out from the inner loop
    * at end we store the result using comparision with max(curr, prev)
    * TC : O(n^2)

// Efficient Solution: 
    * We can start check every element as if it is 0
    * If it's not zero, we increase the counter i.e cnt , & store the result using max(res, cnt) inside the res.
    * TC : O(n)
    * AS : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution: 
int maxOnce(int arr[], int n){
    int res = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            cnt = 0;
        } else {
            cnt++;
            res = max(res, cnt);
        }
    }
    return res;
}

// Naive Solution: 
int maxOnce_(int arr[], int n){
    int res = 0;
    for(int i=0;i<n;i++){
        int curr = 0;
        for(int j=i;j<n;j++){
            if( arr[j] == 1){
                curr++;
            } else break;
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

    cout << maxOnce(arr, n);

    return 0;
}