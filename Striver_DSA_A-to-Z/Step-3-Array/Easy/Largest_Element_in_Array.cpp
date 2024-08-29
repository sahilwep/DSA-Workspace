/*

// Largest Element in Array


// Observations: 
    * We are given an array, & we need to find the largest element from the array.


// Intrusion: 
    // Approach 1: We can solve this by sorting: 
        * sort the array, & return the last element of an array
        * TC: O(nlogn)


    // Approach 2: we can use pointer that:
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
    // Approach 1: Sorting 
    int largest_Sorting(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int max = arr[n - 1];
        return max;
    }
    // Approach 2: we can use pointer
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