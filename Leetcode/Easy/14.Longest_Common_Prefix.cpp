/*

//  14. Longest Common Prefix

//  Observations: 
    * Write a function to find largest common prefix string amongst all the the string.
    * If there is no common prefix string, return "" empty string.

// Example:

    Input: strs = ["flower","flow","flight"]
    Output: "fl"

    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings. 


// Intrusion: 
    // Using sorting: 
        * Sort the array of string..
        * then pick start & end element..
        * start matching both string character & build result string.
        * TC: O(nlogn)


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
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();

        // Sort the array
        sort(s.begin(), s.end());
        if(s[0][0] != s[n-1][0]) return ""; // return empty string if there is no common prefix string..

        // getting first & last element from array:
        string first = s[0];
        string last = s[n-1];

        // start building common prefix string
        string res = "";
        int i = 0;
        while(i < first.size()){
            if(first[i] == last[i]){
                res += first[i];
                i++;
            }
            else{
                break;
            }
        }

        return res;
    }
};

void solve(){

    int n;
    cin >> n;
    vector<string> s(n);

    for(int i=0;i<n;i++){
        cin >> s[i];
    }

    Solution obj;
    cout << obj.longestCommonPrefix(s) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}