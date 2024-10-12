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
        * TC: O(n^3) -> TLE
    
    // Efficient Approach:
        * A string is palindrome if it's same from left to right & right to left.
        * We need to find longest palindromic substring.
        * for any given string palindromic substring can be odd or even..
        * Example:
            * odd length substring
                 s = b a b a d
                       --|--
                
                                b a b a d
                                  --|--
                        * Here for odd we can pick any i, & grow towards left & right -> this is how we can find the longest substring..
                        * For any 'i' if (i+1) & (i-1) are same, then we will grow the size, else return the substring..
            
            * even length substring

                 s = b a b b a d
                       -------
        
                                b a b b a d
                                  --|----
                                    i
                        * Problem here in even case that the (i & i + 1) are same, & (i-1 & i+2) is same..
                        * So, we need to take care of that also..


            * Concluding the point, we need to check for even & odd case both.
        
        * TC: O(n^2)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Efficient Approach:
    // function that will check the string by every i & return the substring.
    string expandFromCenter(string s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;     // grow towards left
            right++;    // grow towards right
        }

        // (left + 1), because it's increment in last value, & same with right also..
        return s.substr(left + 1, right - left - 1);    // returning the substring part.
    }
    string longestPalindrome(string s){
        int n = s.size();
        if(n <= 1) return s;

        string res = s.substr(0, 1);    // default we have single element itself a palindrome.

        for(int i=0;i<n-1;i++){
            string odd = expandFromCenter(s, i, i);     // In odd case we will pass same pointer as left & right.
            string even = expandFromCenter(s, i, i+1);  // In even case we will pass one pointer ahead to i

            // comparing the size of returned odd & even substring with previous substring & storing the result.
            if(odd.size() >  res.size()){
                res = odd;
            }
            if(even.size() > res.size()){
                res = even;
            }
        }

        return res;
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