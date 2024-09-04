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
        * AS: O(1)

    // Approach 2: Using Hashing
        * we can create a hashset that contains the value {1, 2, 3}
        * Now by iterating we can check the values are present in hashset or not..
        * Using hashing is efficient when we have many values to check, & using condition for each of them is not the good approach..
        * In these case we can use hashset & by using this we can check in O(1) time complexity.
        * We can use unordered_set -> this will take O(1) for find in average case.
        * TC: O(n)
        * AS: O(k), k = size of hashset

// NOTE: 
    * when we have to compare some large range we can use hashset in this case.

*/

#include <bits/stdc++.h>
#include <unordered_set>
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

    // Approach 2: Using Hashing: 
    // function to check whether the element of an array follows the rules or not?
    bool isFollowing(int x){
        // using set to insert the the range of values in set, Unordered set will take O(1) in avg case.
        unordered_set<int> s;
        for(int i=1;i<=3;i++){
            s.insert(i);
        }

        // checking: 
        while(x > 0){
            // if the digits are not in hashset we will return 0, means that element fail to follow the rules.
            if(s.find(x % 10) == s.end()){
                return 0;
            }
            x /= 10;
        }

        return 1;
    }
    vector<int> filterByDigits(const vector<int>& arr) {
        int n = arr.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            bool check = isFollowing(arr[i]);
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