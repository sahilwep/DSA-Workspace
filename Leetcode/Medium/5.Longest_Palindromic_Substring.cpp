/*

//  5. Longest Palindromic Substring


//  Observations:
    * Given a string return the longest palindromic substring.

// Example:

    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

    Input: s = "cbbd"
    Output: "bb"

// Intrusion:
    // Bruteforce Approach:
        * Using nested loop build a subarray that will be following the condition for palindrome
        * TC: O(n^2) -> TLE
    
    // Efficient Approach:
        * 



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Efficient Approach:
    bool longestPalindrome(string s){

    }
    // Bruteforce Solutions: 
    // function to check the string whether palindrome or not?
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;
        while(l < r){
            if(s[l] != s[r]) return 0;
            l++;
            r--;
        }

        return 1;
    }
    string longestPalindrome_brute(string s) {
        int n = s.size();
        if(n == 1) return s;

        string res = "";
        int resSize = 0;

        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=i;j<n;j++){
                temp += s[j];
                if(isPalindrome(temp)){
                    if(temp.size() > resSize){
                        res = temp;
                        resSize = temp.size();
                    }
                }
            }
        }

        return res;
    }
};

void solve(){
    string s;
    cin >> s;

    Solution obj;
    cout << obj.longestPalindrome(s) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}