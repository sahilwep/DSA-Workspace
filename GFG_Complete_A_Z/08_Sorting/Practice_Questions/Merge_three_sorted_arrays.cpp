/*
// Merge three sorted arrays


// Observations: 
    * we are given three sorted array, we need to merge them into one array, so that it should be in sorted.

// Example: 

    Input: 
        N = 4, A[] = [1 2 3 4] 
        M = 5, B[] = [1 2 3 4 5] 
        P = 6, C[] = [1 2 3 4 5 6]
    Output: 1 1 1 2 2 2 3 3 3 4 4 4 5 5 6
    Explanation: Merging these three sorted arrays, we have: 1 1 1 2 2 2 3 3 3 4 4 4 5 5 6.

    Input: 
        N = 2, A[] = [1 2]
        M = 3, B[] = [2 3 4] 
        P = 4, C[] = [4 5 6 7]
    Output: 1 2 2 3 4 4 5 6 7 
    Explanation: Merging three sorted arrays, we have: 1 2 2 3 4 4 5 6 7.

// Intrusion: 
    // Using MergeFunction() Logic:
        * we use merge function that will merge two given array, once we sorted two given array, we can pass third array with sort it.
        * TC: O(n), where n = a.size() + b.size() + c.size()

    // Using Hashing:
        * are we are given with the constrains that the values of element are less or equal to size of array.
        * We can use map data-structure that will store the values in sorted order.
        * Once we have hash all the values, we need to write all the values into the new array.
        * TC: O(nlogk), where n = total element, k = no of unique elements in the array.

*/

#include<bits/stdc++.h>
using namespace std; 

class Solution{
public:
    // Using merge function(): 
    // Custom merge function to merge two sorted array
    vector<int> mergeFunc(vector<int> arr1, vector<int> arr2 ){
        int size = arr1.size() + arr2.size();
        vector<int> res(size);
        int idx = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 < arr1.size() && ptr2 < arr2.size()){
            if(arr1[ptr1] < arr2[ptr2]){
                res[idx++] = arr1[ptr1++];
            }else{
                res[idx++] = arr2[ptr2++];
            }
        }
        // leftover in first array:
        while(ptr1 < arr1.size()){
            res[idx++] = arr1[ptr1];
            ptr1++;
        }
        // leftover in second array:
        while(ptr2 < arr2.size()){
            res[idx++] = arr2[ptr2];
            ptr2++;
        }
        return res;
    }
    vector<int> mergeThree_Using_Merge(vector<int>& a, vector<int>& b, vector<int>& c){
        // merge first two array
        int size = a.size() + b.size() + c.size();
        vector<int> res(size, 0);
        res = mergeFunc(a, b);

        // merge third array
        res = mergeFunc(res, c);

        return res;
    }

    // Using Hashing: 
    vector<int> mergeThree(vector<int>& a, vector<int>& b, vector<int>& c){
        map<int, int> mp;
        // hashing first array elements:
        for(auto i : a) mp[i]++;
        // hashing second array elements:
        for(auto i : b) mp[i]++;
        // hashing third array elements:
        for(auto i : c) mp[i]++;

        // After hashing we need to make new array that store all the element in sorted fashion.
        vector<int> res;
        for(auto i=mp.begin();i!=mp.end();i++){
            int times = i->second;
            int val = i->first;
            for(int j=0;j<times;j++){
                res.push_back(val);
            }
        }

        return res;
    }


};

int main(){ 
    int t;
    cin >> t;

    while(t--){
        int n,m,o;
        cin>>n>>m>>o;
        vector<int> A,B,C;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }
        
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            B.push_back(x);
        }
        
        for(int i=0;i<o;i++){
            int x;
            cin>>x;
            C.push_back(x);
        }

        Solution obj;
        vector<int> ans = obj.mergeThree(A, B, C);
        for(auto i: ans) cout << i << " ";
        cout << "\n";
    }
    return 0; 
} 