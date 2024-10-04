/*

//  136. Single Number

//  Observations: 
    * We are given non-empty array that contains integer arr[i],
    * Every element appears twice 



// Example:

    Input: nums = [2,2,1]
    Output: 1

    Input: nums = [4,1,2,1,2]
    Output: 4

    Input: nums = [1]
    Output: 1

// IntrusioN: 
    // Hashing Approach:
        * We can use hashmap & store the frequency of every element, then iterate into map, & return those element whose frequency is 1.
        * TC: O(n)
        * AS: O(n)


    // Bit Manipulations:
        * We can use XOR Property:
            * XOR: -> Same bits false, and different bits true.

            * If we take xor of any number with 0 result will be 0
                A ^ 0 = A

            * If we take xor of any number with same number result will be 0.
                A ^ A = 0

        * From this property, the element whose apper twice will be 0, & the element which appear only once, will be there.
        * Example:
            1 1 2 2 3   ->  01 ^ 01 ^ 10 ^ 10 ^ 11 -> 11(3) left 
        
        * TC: O(n)
        * AS: O(1)
        
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
    // Using Hashing: 
    int singleNumer_hashing(vector<int>& nums){
        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;

        for(auto i: mp){
            if(i.second == 1) return i.first;
        }

        return -1;
    }
    // Bit-Manipulations
    int singleNumber(vector<int>& nums) {

        int res = 0;    // initializing result as 0
        
        for(auto i: nums){
            // taking XOR with every element, which leave element whose appears only once.
            res = res ^ i;
        }

        return res; // returning that element
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++) cin >> v[i];

    Solution obj;

    cout << obj.singleNumer_hashing(v) << endl;
    cout << obj.singleNumber(v) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}