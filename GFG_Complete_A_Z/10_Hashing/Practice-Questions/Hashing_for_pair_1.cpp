/*

// Hashing for pair - 1

// Observations: 
    * We are given an array of distinct integer and a sum, we have to check if there is a pair with a given sum in the array.
    * If there is such pair we need to return 1, else return 0.


// Intrusion: 
    // Bruteforce Approach: 
        * we will use nested loop to find such pair.
        * TC: O(n^2)

    // Hashing Approach: 
        * If we carefully observe: we are given sum,
        * As we have to find two element that sum up the target, if we think in that way:
            * target - arr[i] -> (arr[j] we will look this in map)
            * If target value exist, we will return 1, at end we will return 0
            * arr[i] + arr[j] = sum
        * TC: O(n)
        * AS: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

// Hashing Approach: 
int sumExists(int arr[], int n, int sum){
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        int need = sum - arr[i];    // The value that we are looking for
        // If needed value is found in hashmap
        if(mp.find(need) != mp.end()){
            return 1;
        }
        // if need value is not found: insert value into hashmap:
        mp[arr[i]] = i;
    }

    return 0;
}

// bruteforce approach:
int sumExists_Brute(int arr[], int n, int sum) {
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