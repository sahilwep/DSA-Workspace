/*

// Hashing for pair - 1

// Observations: 
    * We are given an array of distinct integer and a sum, we have to check if there is a pair with a given sum in the array.
    * If there is such pair we need to return 1, else return 0.


// Intrusion: 
    // Bruteforce Approach: 
        * we will use nested loop to find such pair.
        * TC: O(n^2)


*/

#include <bits/stdc++.h>
using namespace std;

// bruteforce approach:
int sumExists(int arr[], int n, int sum) {
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == sum){
                return 1;
            }
        }
    }
    return 0;
}


int main() {

    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        int arr[N];

        for (int i = 0; i < N; i++) cin >> arr[i];
        int sum;
        cin >> sum;

        cout << sumExists(arr, N, sum) << endl;
    }
    return 0;
}