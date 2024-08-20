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
        * TC: O(max(s1.size(),s2.size()) * (log(max(s1, s2))))
        
                aacdb
                gafd



*/

#include <bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    // Efficient Solution: 
    // function to find the character from string.
    bool searchString(string s, int start, int end, char x){
        int mid = (start + end) / 2;
        while(start <= end){
            if(x == s[mid]){
                return 1;
            }else if(x > s[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        return 0;
    }

    string concatenatedString(string s1, string s2){
        map<char, int> mp;
        for(char c : s1) mp[c]++;
        for(char c : s2) mp[c]++;

        string res = "";
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second == 1){
                res += i->first;
            }
        }
        string final = "";
        sort(res.begin(), res.end());
        for(int i=0;i<s1.size();i++){
            bool found = searchString(res, 0, res.size(), s1[i]);
            if(found){
                final += s1[i];
            }
        }
        for(int i=0;i<s2.size();i++){
            bool found = searchString(res, 0, res.size(), s2[i]);
            if(found){
                final += s2[i];
            }
        }

        return final;
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