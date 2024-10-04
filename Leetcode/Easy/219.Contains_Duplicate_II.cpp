/*

//  219. Contains Duplicate II

//  Observations: 


// Intrusion: 
    // Bruteforce Solution:
        * In this approach, we use a nested loop to compare each element in the array with every other element that comes after it. 
        * The outer loop selects an element, and the inner loop checks all elements within the specified range (k) for a duplicate. 
        * If a duplicate is found within the range, we return true. If no duplicate is found, we return false.
        * TC: O(n^2)
        * AS: O(1)

    // Using Hashing: 
        * This approach leverages a hashmap (unordered_map) to optimize the search for duplicates. 
        * Instead of comparing every element with others in a nested loop, we can use the hashmap to track the indices of elements. 
        * The key insight is that for each element, if it already exists in the hashmap, we check the difference between its current index and the index stored in the map. 
        * If this difference is less than or equal to k, we return true. Otherwise, we update the index of the element in the map.
        * TC: O(n)
        * AS: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007


class Solution {
public:
    // Brute-force Solution:
    bool containsNearbyDuplicate_Brute(vector<int>& nums, int k) {
        // Finding potential duplicates:
        int n = nums.size();
        if (k == 0) return false; // i and j being the same violates the condition.

        // Pick elements one by one:
        for (int i = 0; i < n; i++) {
            // Compare with elements after index i:
            for (int j = i + 1; j < n; j++) {
                // If the distance between indices exceeds k, break the loop:
                if (j - i > k) break;
                // If a duplicate is found, return true:
                if (nums[i] == nums[j]) return true;
            }
        }

        return false; // No duplicates found within the specified range.
    }

    // Optimized Hashing Solution:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return false; // i and j being the same violates the condition.

        // Using an unordered map to store elements and their indices:
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            // If the current element is already in the map:
            if (mp.find(nums[i]) != mp.end()) {
                // Check if the absolute difference between indices is <= k:
                if (abs(mp[nums[i]] - i) <= k) {
                    return true; // Condition satisfied, return true.
                }
                // If the previous index is too far, update it with the current index for future checks:
                else {
                    mp[nums[i]] = i;
                }
            } 
            // If the element is not in the map, store it with its index:
            else {
                mp[nums[i]] = i;
            }
        }

        return false; // No duplicates found within the specified range.
    }
};


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for(int i=0;i<n;i++) cin >> nums[i];

    Solution Obj;
    (Obj.containsNearbyDuplicate(nums, k)) ? cout << "True" : cout << "False";
    cout << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}