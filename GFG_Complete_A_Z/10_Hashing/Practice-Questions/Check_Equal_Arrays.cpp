/*

// Check Equal Arrays


// Observations: 
    * we are given two array, check whether these two array are same or not?
    * Two array are same if both the array is of same size & have same element, order of elements may differ.
    * NOTE: There may be repeated element found in an array, so we have to match them as well.


// Intrusion: 
    * If size is different, return false.
    * We will store the hash
    * We will compare the elements & their frequency


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp1;
        map<int, int> mp2;
        for(auto i : arr1) mp1[i]++;
        for(auto i : arr2) mp2[i]++;

        auto it1 = mp1.begin();
        auto it2 = mp2.begin();
        while(it1 != mp1.end() && it2 != mp2.end()){
            if(it1->first != it2->first) return 0;
            else{
                if(it1->second != it2->second) return 0;
            }
            it1++;
            it2++;
        }
        return 1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr1, arr2;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the first array elements
        stringstream ss1(input1);
        int number;
        while (ss1 >> number) {
            arr1.push_back(number);
        }

        getline(cin, input2); // Read the entire line for the second array elements
        stringstream ss2(input2);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        cout << (ob.check(arr1, arr2) ? "true" : "false") << "\n";
    }
    return 0;
}