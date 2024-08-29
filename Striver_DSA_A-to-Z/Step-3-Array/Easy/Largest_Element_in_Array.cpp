/*

// Largest Element in Array


// Observations: 
    * We are given an array, & we need to find the largest element from the array.


// Intrusion: 
    // Approach 1: We can solve this by using Bruteforce Approach: 
        * sort the array, & return the last element of an array
        * TC: O(n^2) -> TLE


    // Approach 2: We can solve this by sorting: 
        * sort the array, & return the last element of an array
        * TC: O(nlogn)


    // Approach 3: we can use pointer that:
        * pointer will maintain the largest element in an array.
        * TC: O(n)


*/

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    // Approach 1: Bruteforce -> TLE
    int largest_Brute(vector<int> &arr) {
        int maxVal = arr[0];
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i] > arr[j]){
                    maxVal = max(maxVal, arr[i]);
                }
            }
        }
        return maxVal;
    }
    // Approach 2: Sorting -> (n*logn)
    int largest_Sorting(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int max = arr[n - 1];
        return max;
    }
    // Approach 3: we can use pointer -> (n)
    int largest(vector<int> &arr) {
        int max = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return max;
    }
};

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.largest(arr) << endl;
    }
    return 0;
}