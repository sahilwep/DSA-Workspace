/*
// Frequencies of Limited Range Array Elements


// Observations: 
    * We are given an array of size n.
    * The integer can be from 1 to p, & some number can be repeated from or absent
    * we have to count the frequency of all the element lies in range 1 to n


// Intrusion: 
    * We will use map data structure to store the frequency...
    * then we can print the frequency from 1 to N

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int n, int P) {
        unordered_map<int, int> mp; // declared map data structure to store the frequency.
        // storing the frequency:
        for(int i=0;i<n;i++){
            mp[arr[i]]++;   // storing frequency of every element in map.
        }
        // storing frequency from 1 to N
        for(int i=1;i<=n;i++){
            arr[i-1] = mp[i];   // storing frequency of 1 to N, in array.
        }

    }
};


int main() {
    long long t;

    cin >> t;
    while (t--) {

        int N, P;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> P;
        Solution ob;
        ob.frequencyCount(arr, N, P);

        for (int i = 0; i < N; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}