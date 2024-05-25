/*
//  3159. Find Occurrences of an Element in an Array


*/

#include<bits/stdc++.h>
using namespace std;;

vector<int> findFreq(vector<int>& nums, vector<int> &queries, int x) {
    vector<int> res;
    vector<int> hash;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == x){
            hash.push_back(i);  // stored index of values.
        }
    }
    for(int i=0;i<queries.size();i++){
        if(i <= hash.size()){
            cout << hash[i] << " ";
            int k = hash[queries[i-1]];
            res.push_back(k);
        }else {
            res.push_back(-1);
        }
    }
    cout << endl;
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
        for(int i=0;i<n;i++){
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