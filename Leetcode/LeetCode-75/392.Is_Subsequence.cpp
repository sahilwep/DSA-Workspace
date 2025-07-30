/*

//  392. Is Subsequence

//  Observations: 
    * We are given two string "s" & "t", return true if, "s" is Subsequence of "t"


// Example:

Input: s = "abc", t = "ahbgdc"
Output: true

Input: s = "axc", t = "ahbgdc"
Output: false




// Intrusion: 
    // Using Iterative Window Search: 
        * It's work more like we use to find subarray from string, we just need to iterate the second string whenever we got matched:
        * We will iterate in string "t":
            * Whenever (t[i] == s[0]) first element of "s" is matched any "t[index]"
            * we will start another iterations in "s", & keep matching with "t", if it's matched with all the element of "s", return true, else, start with next match with (s[0] == t[index])
        * NOTE: We are matching with substring not subarray, so we whenever we encounter with different, we just need to iterate in first array "t" till we not get matched with current index of string "S"
        * TC: O(n) -> if subsequence is found



// Efficient Two pointers approach:
    -> Use two pointer
        -> if character matched, increment both the pointer
        -> Else increment the second one 't' pointer only
    -> last check if first pointer reaches to end or not?

    // Complexity: 
        -> TC: O(n)
        -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Two pointers Approach: 
class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i = 0;
        int j = 0;

        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return (i == s.size()) ? 1 : 0;
    }
};


// Classical Nested solutions: 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0 && t.size() == 0) return 1;    // If both the string is empty return true
        if(t.size() == 0) return 0; // if second string is empty & fist is not, return false
        if(s.size() == 0) return 1; // if first string is empty & second is not, return true.


        // Start iterating on "t":
        for(int i=0;i<t.size();i++){
            // Whenever t[index] is matched with s[0] first character of "s"
            if(s[0] == t[i]){
                string match = "";  // temp string used for matched at the end.

                // Start iterating on "s"
                for(int j=0;j<s.size();j++){
                    // Whenever there is matched:
                    if(s[j] == t[i] && i < t.size()){
                        match += t[i];    // Storing it into temp string
                        i++;    // increment 'i' for next matched
                    }
                    // Whenever element of s[j] is not matched with t[i], we will move i till we not get matched with s[index].
                    else{
                        // iterating moving ptr till we not get matched with s[index]
                        while(t[i] != s[j] && i < t.size()){
                            i++;
                        }

                        // When we got matched, Store t[i] into temp string, & Increment the i, so that we can go for next matched.
                        match += t[i];
                        i++;
                    }

                    if(i >= t.size()) break;  // when i is exceed with t.size(), we will break out immediately
                }

                // if temp string is matched with given string, return true
                if(match == s) return 1;
            }
        }

        return 0;   // else we will return 0, if substring is not found.
    }
};

void solve(){
    string s, t;
    cin >> s >> t;

    Solution obj;
    cout << obj.isSubsequence(s, t) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}