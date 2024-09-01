/*

// First Repeating Element


// Observations: 
    * We are given an array of size n, we have to find the first repeating element, & return that index.


// Intrusion: 
    * We can hash all the values in the hashmap.
    * By iterating in the array, we can find the first element that is repeating, & return their index.
    * TC: O(n)
    * AS: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> mp;    // using map to store the hash.
        
        // hash all the value of array in map
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        // finding the first element that has repeating & return the index of it.
        int maxValIdx = -1; // if repeating values are not found, we will return -1
        for(int i=0;i<n;i++){
            if(mp[arr[i]] > 1){
                maxValIdx = i+1;
                break;
            }
        }
        
        return maxValIdx;
    }
};

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.firstRepeated(arr) << endl;
    }

    return 0;
}