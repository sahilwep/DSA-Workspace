/*

// Numbers containing 1, 2 and 3

// Observations: 
    * We are given an array, & We need to return return only those element which contains only {1, 2, 3} in their digits.


// Example: 
    1 2 13 4 23 43
        =>  {1, 2, 13, 23}
    
    4 6 7
        => {-1}


// Intrusion: 
    // Approach 1: Using normal iterative logic
        * We can iterate & check whether the digits of each element contains {1, 2, 3} or not, if they are following that rules, then we can store them in vector & return them.
        * TC: O(n)



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Using Iterative logic:
    // function used to find whether element following the rules or not?
    bool isFollow(int x){
        while(x > 0){
            int ld = x % 10;
            if(ld != 1 && ld != 2 && ld != 3){
                return 0;
            }
            x = x / 10;
        }
        return 1;
    }
    vector<int> filterByDigits_IterativeLogic(const vector<int>& arr) {
        int n = arr.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            bool check = isFollow(arr[i]);
            if(check){
                v.push_back(arr[i]);
            }
        }

        return v;
    }

};

int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> result = ob.filterByDigits(arr);
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}