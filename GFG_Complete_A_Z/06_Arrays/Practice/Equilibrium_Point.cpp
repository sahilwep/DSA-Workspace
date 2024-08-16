/*

// Equilibrium Point


// Observation: 
    * we are given an array, which we have to find the equilibrium point..
    * a equilibrium point is index where the left side of sum of array is equal to right side sum


// Key Observations: 
    * We can find the equilibrium point by using prefix sum & suffix sum array that we maintain...
    * if the index of suffix sum & prefix sum is equal, we return that index as equilibrium point.
    * Else we return -1, as there is no equilibrium point in given array.

// Example Observations:

    Input: arr[] = [1, 3, 5, 2, 2]
    prefixSum[] = [1, 4, 9, 11, 13]
    suffixSum[] = [13, 12, 9 , 4, 2]
            equilibrium point indx = 3

    Input: arr[] = [1, 2, 3]
    prefixSum[] = [1, 3, 6]
    suffixSum[] = [6, 5, 3]
            return -1

    Input: arr[] = [1]
    prefixSum[] = [1]
    suffixSum[] = [1]
            equilibrium point indx = 0

    Input: arr[] = [1, 3, 3, 7, 3, 2, 2]
    prefixSum[] = [1, 4, 7, 14, 17, 19, 21]
    suffixSum[] = [21, 20 , 17, 14, 7, 4, 2]
            equilibrium point indx = 4


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int equilibriumPoint(vector<long long> &arr) {
        // making two array that contains prefix sum & suffix sum
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        vector<int> suffix(n);
        suffix[n-1] = arr[n-1];

        // storing prefix & suffix sum:
        for(int i=1;i<n;i++) prefix[i] = arr[i] + prefix[i-1];  // prefix sum
        for(int i=n-2;i>=0;i--) suffix[i] = arr[i] + suffix[i+1];   // suffix sum

        // comparing the prefix & suffix sum, as if they have any equal value, we return that index as equilibrium point, else we return -1
        for(int i=0;i<prefix.size();i++){
            if(prefix[i] == suffix[i]) return i+1;
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        vector<long long> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}