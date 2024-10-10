/*

//  3. Longest Substring Without Repeating Characters 

//  Observations: 
    * We are given a string, find the longest substring without repeating character.
    * A substring is a contiguous non-empty sequence of characters within a string.


// Example:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.


    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.


    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.




// Intrusion: 
    // Bruteforce Solution:
        * Use nested loop to find the subarray without repeating characters.
        * Iterate in outer loop string: Select element one by one
            * create a temp string that will store the subarray with unique elements only.
            * using custom function that will check whether the string contains that character or not?
            * If the function return, then only iterate further, else break..
            * In every iteration check the maximum size of string.
        * TC: O(n^2) -> Accepted
    
    // Optimization: 


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // function to check whether the character is present in the string or not?
    bool isThere(string s, char ch){
        for(auto i: s){
            if(i == ch) return 0;   // if chracter is in the string return false
        }

        return 1;   // if character is not in string return true
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int len = 0;
        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=i;j<n;j++){
                if(isThere(temp, s[j])){
                    temp += s[j];
                    int size = temp.size();
                    len = max(size, len);
                }else{
                    break;  // if character is not unique break the loop
                }
            }
        }

        return len;
    }
};

void solve(){
    string s;
    cin >> s;

    Solution obj;
    cout << obj.lengthOfLongestSubstring(s) << endl; 
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}