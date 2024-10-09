/*

//  28. Find the Index of the First Occurrence in a String
 

//  Observations: 
    * Given two string needle and haystack, 
    * return the index of first occurrence of needle in haystack, or -1 If needle is not part of haystack.


// Example:

    Input: haystack = "sadbutsad", needle = "sad"
    Output: 0
    Explanation: "sad" occurs at index 0 and 6.
    The first occurrence is at index 0, so we return 0.

    Input: haystack = "leetcode", needle = "leeto"
    Output: -1
    Explanation: "leeto" did not occur in "leetcode", so we return -1.


// Intrusion: 
    // Matching & Comparing:
        * Whenever we find the first index of "needle" in "haystack" string, we will create a temp pointer & iterate throughout in haystack until we get the whole string..
        * If we get the string, we will return that index, else we return -1, if we don't get matched in haystack string. 
        * TC: O(n*m)

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
    int strStr(string h, string n) {
        int idx = -1;
        // Iterate in haystack
        for(int i=0;i<h.size();i++){

            // If first index of needle match with h[i]
            if(h[i] == n[0]){
                int ptr = i;    // create a temp pointer to match the needle string..
                string res = "";
                for(int j=0;j<n.size();j++){
                    if(h[ptr] == n[j]){
                        res += n[j];
                        ptr++;
                    }
                    else{
                        break;
                    }
                }
                // if we get the match, return the index 'i'
                if(res == n){
                    idx = i;
                    break;
                }
            }
        }

        return idx;
    }
};


void solve(){
    string haystack, needle;
    cin >> haystack >> needle;

    Solution obj;

    cout << obj.strStr(haystack, needle) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}