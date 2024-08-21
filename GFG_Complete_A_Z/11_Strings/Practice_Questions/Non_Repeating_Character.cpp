/*

// Non Repeating Character

// Observations: 
    * We are given string of size n, we have to return the first non-repeating character from stirng..
    * If there is no repeating character, return "$"

// Intrusion: 
    // BruteForce Solution: 
        * we can use nested loop..
        * TC: O(n*n)
        * AS: O(1)

    // Efficient Solution:
        * We can use hashing, approach:
        * Once we hash all the value into map, we can iterate throughout the string, & check for the first character that has frequency 1, if we are not able to find such character, we will return '$'
        * TC: O(n)
        * AS: O(n)
 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Bruteforce Solution:
    char nonrepeatingCharacter(string s){
        for(int i=0;i<s.size();i++){
            bool isFound = 0;
            for(int j=0;j<s.size();j++){
                // we have to skip the comparing position, which we using to comparing the whole string.
                if(i != j){
                    if(s[i] == s[j]){
                        isFound = 1;
                        break;
                    }
                }
            }
            if(!isFound){
                return s[i];
            }
        }
        return '$';
    }

    // Efficient Solution: 
    char nonrepeatingCharacter_(string s){
        unordered_map<char, int> mp;
        for(char i : s) mp[i]++;

        // checking the first Non repeating string
        for(int i=0;i<s.size();i++){
            if(mp[s[i]] == 1){
                return s[i];
            }
        }
        return '$';
    }

};

int main() {
    int T;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonrepeatingCharacter(S);

        if(ans != '$')
        cout << ans;
        else cout << "-1";

        cout << endl;
    }
    return 0;
}