/*
// Find the only odd Occurring number

    I/p: arr[] = {4, 3, 4, 4, 4, 5, 5}
    O/p: 3

    I/p: arr[] = {8, 7, 7, 8, 8}
    O/p: 8

    // we need to find those number that is appearing odd number of times..

// Naive solution: 
    * We will iterate from 0 to n: 
        * initialize count = 0
        * start inner loop from 0 to n
            * check if arr[i] == arr[j] count++
    * At end of every iteration of outer loop check the condition if count is divisible by odd, then return that arr[i];
    * TC : O(n^2)

// Efficient solution: 
    * We can do this question with using hashing, which takes O(n) TC & SC, But we will do this question With using bit logic...
    * The idea of the efficient solution is to use bitwise XOR operator..
        * Bitwise XOR : Same bits is 0, & different bits are 1...
                    x ^ 0 = x
                    x ^ y = y ^ x       Commutative property
                    x ^ (y ^ z) = (x ^ y) ^ z       Associative property
                    x ^ x = 0

        x ^ x ^ x ^ x ^ x  = x             x ^ x ^ x ^ x ^ x = 0
        -----------------                  -----------------
            odd times                          even times

    * Take XOR of all the numbers: 
        * example: 
             arr[] = {4, 3, 4, 4, 4, 5, 5}
                   = 4 ^ 3 ^ 4 ^ 4 ^ 4 ^ 5 ^ 5
                   = 4 ^ 4 ^ 4 ^ 4 ^ 3 ^ 5 ^ 5
                   = (4 ^ 4 ^ 4 ^ 4)^ 3 ^ (5 ^ 5)
                   = 0 ^ 3 ^ 0
                   = 3 ^ 0
                   = 3
                 
    * TC : O(n)
    * AS : O(1)

*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Efficient Solution: 
int oddOccurring(int arr[], int n){
    int res = arr[0];
    for(int i=1;i<n;i++){
        res = res ^ arr[i];
    }
    return res;
}

// Naive Solution: 
int oddOccurring_(int arr[], int n){
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }
        if(cnt % 2 != 0) return arr[i];
    }
    return 0;
}

int main(void){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];

        cout << oddOccurring(arr, n) << endl;
    }
    
    return 0;
}