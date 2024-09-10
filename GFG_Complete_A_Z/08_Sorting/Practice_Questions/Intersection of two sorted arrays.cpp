/*

// Intersection of two sorted arrays

// Observations: 
    * We are given two array, we need to return the insertion of both the array.
    * If there is no common element, return -1


// Intrusion: 
    // Bruteforce Approach:
        * We can use nested loop to iterate in both the array & find the common & return the vector that contains the intersection of two array.
        * we will be having duplicate values, so we need to remove that values from both the array.
        * We can use set-data structure, that will store only unique elements.
        * TC: O(n*m)    -> TLE
    
    // Efficient Solution: 
        * We can use hashing approach in to find the intersection
        * We can use set data structure to store the elements, because this will ignore the duplicate values.
        * TC: O(nlogn + mlogm + nlogm)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Bruteforce Solution: O(n*m)
    vector<int> printIntersection_Brute(vector<int> &arr1, vector<int> &arr2){
        // Discarding duplicates values:
        // Storing Unique data from first array:
        set<int> s1;
        for(auto i: arr1) s1.insert(i);

        // Storing Unique data from first array:
        set<int> s2;
        for(auto i: arr2) s2.insert(i);

        // Now Finding the intersection values from both the array:
        vector<int> res;
        for(auto i=s1.begin();i!=s1.end();i++){
            bool isFound = 0;
            for(auto j=s2.begin();j!=s2.end();j++){
                if(*i == *j){
                    isFound = 1;
                    break;
                }
            }
            if(isFound){
                res.push_back(*i);
            }
        }
        if(res.size() == 0){
            res.push_back(-1);
        }

        return res;
    }
    // Efficient Solution: O(nlogn + mlogm + nlogm)
    vector<int> printIntersection(vector<int> &arr1, vector<int> &arr2){
        // Discarding duplicates values:
        // Storing Unique data from first array:
        set<int> s1;
        for(auto i: arr1) s1.insert(i);

        // Storing Unique data from first array:
        set<int> s2;
        for(auto i: arr2) s2.insert(i);

        // Now Finding the intersection values from both the array:
        vector<int> res;
        for(auto i=s1.begin();i!=s1.end();i++){
            if(s2.find(*i) != s2.end()){
                res.push_back(*i);
            }
        }
        if(res.size() == 0){
            res.push_back(-1);
        }

        return res;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        vector<int> v;
        v = ob.printIntersection(arr1, arr2);

        for (int i = 0; i < v.size(); i++)  cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}