/*

//  Longest Sub-Array with Sum K

//  Problem Statement: 
    -> Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. It is guaranteed that a valid subarray exists.


// Examples:

    Input: arr[] = [10, 5, 2, 7, 1, 9], k = 15
    Output: 4
    Explanation: The subarray [5, 2, 7, 1] has a sum of 15 and length 4.

    Input: arr[] = [-1, 2, -3], k = -2
    Output: 3
    Explanation: The subarray [-1, 2, -3] has a sum of -2 and length 3.

    Input: arr[] = [1, -1, 5, -2, 3], k = 3
    Output: 4
    Explanation: The subarray [1, -1, 5, -2] has a sum of 3 and a length 4.



// Approach:
    -> We will be using map
    -> TC: O(n)


*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        int n = arr.size();
        int prefSum = 0;
        int maxLength = 0;
        unordered_map<int, int> mp;
        
        
        for(int i=0;i<n;i++){
            prefSum += arr[i];  // generate prefix
            
            int checkVal = prefSum - k; // this value we need to check in map
            
            // if we get prefixSum equal to 'k'
            if(prefSum == k){
                maxLength = i + 1;  // store maxLen as i + 1 (what if this subarray will find at starting few elements)
                // But we need longest one, this is why we will check further options...
            }
            
            if(mp.find(checkVal) != mp.end()){  // If we found check value in map:
                maxLength = max(maxLength, (i - mp[checkVal]));     // store the longest ones in our maxLength result.
            }
            
        
            // last if prefixSum is not in our map, store it with given index.
            // We only store the first occurrence to ensure the subarray length is maximized.
            if(mp.find(prefSum) == mp.end()){
                mp[prefSum] = i;
            }
        }
        
        return maxLength;
    }
};



int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

