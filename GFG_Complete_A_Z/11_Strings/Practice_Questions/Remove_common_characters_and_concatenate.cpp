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


*/

#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
    // Bruteforce Solution:
    string concatenatedString(string s1, string s2){
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