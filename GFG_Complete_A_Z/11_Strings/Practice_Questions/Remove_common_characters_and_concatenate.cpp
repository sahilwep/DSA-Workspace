/*

// Remove common characters and concatenate


// Observations: 
    * we are given two string s1, & s2, we have to remove all the common character from both the string, & we have to print only uncommon character from both the string..

// Intrusion:
    // Bruteforce Solution: 
        * as we have to get the uncommon character from both the string, first we can concinnate both the string, & then perform both the operations..
        * First we can find the uncommon string from first string, & then we can find uncommon string from second string.
        * TC: O(s1.size() * s2.size())

    // Efficient Approach: 
        * we can use hashing approach.
        * We can extract data which are unique, & then sort them & perform the searching operations..
        * TC: O(nlogn), n = maximum size string.


*/

#include <bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    // Efficient Solution:
    string concatenatedString(string s1, string s2){
        map<char, int> mp1;
        map<char, int> mp2;
        for(char c : s1) mp1[c]++;
        for(char c : s2) mp2[c]++;
        
        string res = "";
        // Checking the character from first string, by comparing from the frequency of second string...
        for(char c : s1){
            // if character from first string does not exist in the map of second string
            if(mp2.find(c) == mp2.end()){
                res += c;
            }
        }
        // Checking the character from the second string by comparing from the frequency fo first string...
        for(char c : s2){
            // if character from second string does not exist in the map of first string
            if(mp1.find(c) == mp1.end()){
                res += c;
            }
        }
        if(res.empty()){
            return "-1";
        }
        return res;
    }

    // Bruteforce Solution:
    string concatenatedString_(string s1, string s2){
        string res = "";
        // first getting the unique character from first string
        for(int i=0;i<s1.size();i++){
            bool flag = 0;
            for(int j=0;j<s2.size();j++){
                if(s1[i] == s2[j]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                res += s1[i];
            }
        }
        // second getting the unique character form second string
        for(int i=0;i<s2.size();i++){
            bool flag = 0;
            for(int j=0;j<s1.size();j++){
                if(s2[i] == s1[j]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                res += s2[i];
            }
        }
        if(res.empty()){
            return "-1";
        }

        return res;
    }

};

int main(){
    int t;
    cin >> t;

    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        Solution obj;
        string res = obj.concatenatedString(s1, s2);
        cout<<res<<endl;
    }
    return 0; 
}