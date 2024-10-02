/*

//  1456. Maximum Number of Vowels in a Substring of Given Length


//  Observations: 
    * We are given string s, & integer k, return the maximum number of vowel in any substring of s, with window size length k.


// Intrusion: 
    // Bruteforce Solution:
        * We will use two pointer i & j
            * first pointer at 0, & second at position k-1
            * now we will check whether that window size substring has any vowel or not, by simply iterating over that substring portions, & count the number of vowel.
            * At end we will store the maximum vowel found while iterating throughout the array by simply iterating one index forward both the pointers.
        * This approach will have time complexity O(n^2), because every time we are checking the window size subarray.
        * TC: O(n^2) -> TLE
    
    // Optimization: 
        * While iterating the pointer, instead of checking the whole subarray we will check the two index of substring,
        * starting & the end position of window, whether these element are vowel or not,
        * Depending on that we will increment & decrement the vowel count..
        * TC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Bruteforce Solution:
    // function to count vowel of given string:
    int vowCnt(string s, int start, int end){
        int cnt = 0;
        for(int i=start;i<=end;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                cnt++;
            } 
        }
        return cnt;

    }
    int maxVowels_Brute(string s, int k) {

        // We have to count the vowel in window size k:
        int i = 0;  // start range
        int j = k-1;  // end range

        int maxCnt = 0;
        while(j < s.size()){
            int count = vowCnt(s, i, j);
            maxCnt = max(count, maxCnt);
            i++;
            j++;
        }

        return maxCnt;
    }

    // Optimization: 
    // function to return whether the given character is vowel or not?
    bool isVow(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int maxVowels(string s, int k) {
        // First finding the vowels in k size window:
        int maxCnt = 0;
        for(int i=0;i<k;i++){
            if(isVow(s[i])) maxCnt++;
        }
        
        int vCnt = maxCnt;  // temporary variable to check maximum vowel among all the window.

        int i = 0;
        int j = k;
        while(j < s.size()){
            // vowel is adding in window
            if(isVow(s[j])){
                vCnt++;
            }
            // vowel is removing from the window
            if(isVow(s[i])){
                vCnt--;
            }

            // storing the maxVowels:
            maxCnt = max(vCnt, maxCnt);
            i++;
            j++;
        }

        return maxCnt;
    }
};


void solve(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    Solution obj;
    cout << obj.maxVowels(s, k) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}