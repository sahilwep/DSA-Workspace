/*

// Union of Two Sorted Arrays

// Observations: 
    * We are given two sorted, & we have to find the union of it..
    * Union: union can be defined as common & distinct element from both the array. 
    * We have to return the element in sorted array.



// Example
    Input: 
        n = 5, arr1[] = {1, 2, 3, 4, 5}  
        m = 5, arr2 [] = {1, 2, 3, 6, 7}
    Output: 1 2 3 4 5 6 7
    Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.


    Input: 
        n = 5, arr1[] = {2, 2, 3, 4, 5}  
        m = 5, arr2[] = {1, 1, 2, 3, 4}
    Output: 1 2 3 4 5
    Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.


    Input:
        n = 5, arr1[] = {1, 1, 1, 1, 1}
        m = 5, arr2[] = {2, 2, 2, 2, 2}
    Output: 1 2
    Explanation: Distinct elements including both the arrays are: 1 2.

// Intrusion: 
    // Approach 1: Using Set data structure
        * this will store common & distinct element from both the array.
        * TC: O(nlogn)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
        // using set to insert distinct & common values form both the array
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(arr1[i]);
        }
        
        for(int i=0;i<m;i++){
            s.insert(arr2[i]);
        }

        // Finally returning vector that store union of two arrays.
        vector<int> v;
        for(auto i : s){
            v.push_back(i);
        }

        return v;
    }
};

int main(){
	int T;
	cin >> T;
	while(T--){
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }

	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	}
	
	return 0;
}