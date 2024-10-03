/*

//  1207. Unique Number of Occurrences


//  Observations: 
    * Given an array return true, if number of occurrence of each value in array is unique, or return false otherwise.


// Example:

    Input: arr = [1,2,2,1,1,3]
    Output: true
    Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

    Input: arr = [1,2]
    Output: false

    Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
    Output: true


// IntrusioN:
    * We will use hashing approach & hash all the values from into hashmap: 
    * then compare the frequency if any of them are having same frequency we will return 0, otherwise 1.


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

class Solution{
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // First hash all the frequency of every element into map:
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        // Second insert all the frequency from into set:
        set<int> s;
        for(auto i: mp){
            // If any value is already present we return false.
            if(s.find(i.second) != s.end()){
                return 0;
            }
            s.insert(i.second);
        }

        return 1;   // else return true.
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    Solution obj;
    cout << obj.uniqueOccurrences(arr) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}