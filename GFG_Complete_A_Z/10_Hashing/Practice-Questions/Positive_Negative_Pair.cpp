/*

// Positive Negative Pair

// Observations: 
    * We are given an array that contains positive & negative of same value, we need to find the pair & return it in vector.
    * We need to return the pair that appear first, means order of the vector depends on this.


// Intrusion: 
    * As are restrict to store the element in a pair that appear first,
    * We will hash the value in map, once the frequency of any value become 2 after inserting it, we will store it in the vector.
    * TC: O(n)
    * AS: O(n)


*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution{
public:
    vector<int> findPairs(int arr[], int n){
        vector<int> v;
        unordered_map<int, int> mp;     // using map to store the frequency.

        for(int i=0;i<n;i++){
            mp[abs(arr[i])]++;  // hashing element into the map.
            // if the frequency of the element just become 2, then this will be the first pair that should need to be insert in vector.
            if(mp[abs(arr[i])] == 2){
                int t = abs(arr[i]);
                v.push_back(t*-1);
                v.push_back(t);
            }
        }
        
        // If there is on positive negative pair, we will return 0.
        if(v.size() == 0){
            return {0};
        }
        
        return v;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    }

    return 0;
}