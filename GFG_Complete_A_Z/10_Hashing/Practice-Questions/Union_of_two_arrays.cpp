/*

// Union of two arrays


// Observations: 
    * we are given two array, we have to find the union of two arrays.
    * Union: union contains unique values & common values from both the array.
        * if there are repeated values in array, union will contains only once.

// Intrusion: 
    * We can use any set or map data structure to store them.
    * TC: O(n)


*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(vector<int> arr1, vector<int> arr2) {
        set<int> s;
        for(auto i : arr1) s.insert(i);
        for(auto i : arr2) s.insert(i);

        return s.size();
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.doUnion(a, b) << endl;
    }

    return 0;
}