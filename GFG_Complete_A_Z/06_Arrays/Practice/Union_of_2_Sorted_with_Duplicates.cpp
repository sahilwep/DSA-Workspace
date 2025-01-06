/*

//  Union of 2 Sorted with Duplicates

//  Problem Statement: 
    -> Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
        -> Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

// Example: 
    Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
    Output: 1 2 3 4 5 6 7
    Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

    Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
    Output: 1 2 3 4 5
    Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.

    Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
    Output: 1 2
    Explanation: Distinct elements including both the arrays are: 1 2.


// Approach 1: 
    -> We can use set data structure to perform whole operations
    -> TC: O(n*log(n))

// Approach 2: 
    -> We can use Two pointers technique.
    -> After that we will remove duplicates.
    -> TC: O(n)



*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) -> Efficient One
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> res;
        
        int i = 0;
        int j = 0;
        
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                res.push_back(a[i]);
                i++;
                j++;
            }
            while(a[i] < b[j] && i < a.size()){
                res.push_back(a[i]);
                i++;
            }
            while(a[i] > b[j] && j < b.size()){
                res.push_back(b[j]);
                j++;
            }
        }
        
        while(i < a.size()){
            res.push_back(a[i]);
            i++;
        }
        while(j < b.size()){
            res.push_back(b[j]);
            j++;
        }

        // After insertion remove duplicate values:
        i = 0;
        j = 0;
        while(j < res.size()){
            if(res[i] != res[j]){
                i++;
                res[i] = res[j];
            }
            j++;
        }
        
        vector<int> sol;
        for(int j = 0 ; j <= i ; j++){
            sol.push_back(res[j]);
        }
        
        
        return sol;
    }
};


// Normal With Set: TC: O(n*log(n))
class Solution_Set_Method {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {

        set<int> s;
        for(auto i: a){
            s.insert(i);
        }
        
        for(auto i: b){
            s.insert(i);
        }
        
        vector<int> res;
        for(auto i: s){
            res.push_back(i);
        }
        
        return res;
    }
};
