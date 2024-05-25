/*
//  3159. Find Occurrences of an Element in an Array

Input: 
arr[] = {1 3 1 7}
queries[] = {1 3 2 4}
x = 1
Output: 
0 -1 2 -1

// Observations: 
    * hash the value of x
        hash[] = {0, 2}
    * make a res vector to store the query...
    * assign the hash & query value to res..
        res[] = {0, -1, 2, -1}

*/

#include<bits/stdc++.h>
using namespace std;;

vector<int> findFreq(vector<int>& nums, vector<int> &queries, int x) {
    vector<int> hash;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == x){
            hash.push_back(i);  // stored index of values.
        }
    }
    vector<int> res;
    for(int i=0;i<queries.size();i++){
        int query = queries[i]; // getting the query number
        // if that query number is less than or equal to size, we can assign value..
        if(query <= hash.size()){
            int k = hash[query - 1];    // getting the hash value.
            res.push_back(k);   // storing into the result vector
        } else {
            res.push_back(-1);  // else storing -1
        }
    }
    return res; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        int m;
        cin >> m;
        vector<int> queries(m);
        for(int i=0;i<m;i++){
            cin >> queries[i];
        }
        int x;
        cin >> x;
        vector<int>  res = findFreq(nums, queries, x);
        for(auto i : res) cout << i << " ";
        cout << endl;
    }

    return 0;
}