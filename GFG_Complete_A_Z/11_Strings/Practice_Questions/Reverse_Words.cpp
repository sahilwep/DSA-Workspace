/*

// Reverse Words


// Observations: 
    * we are given string s,
    * We have to reverse the string without reversing the word, words are separated by '.'
    * at last we need to return the string.


// Intrusion: 
    * First we will split the words into individual string, & export into the vector, then we reverse the vector..
    * Once we have reverse the vector, we will export the whole vector into the string.
    * TC: O(N)
    * AS: O(N)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Method 1:
    string reverseWords_M1(string s){
        int n = s.size();
        string solu = "";
        string temp = "";
        
        for(int i=0;i<n;i++){
            if(s[i] == '.'){
                solu = '.' + solu;
                solu = temp + solu;
                temp = "";
            }else{
                temp += s[i];
            }
        }
        
        solu = temp + '.' + solu;
        
        for(int i=0;i<s.size();i++){
            s[i] = solu[i];
        }
        
        return s;
    } 

    // Method 2:
    string reverseWords(string s){
        vector<string> res;
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i] != '.'){
                temp += s[i];
            }
            else{
                res.push_back(temp);
                temp = "";
            }
        }
        res.push_back(temp);    // inserting last value.
        reverse(res.begin(), res.end());

        string solu = "";
        for(int i=0;i<res.size();i++){
            solu += res[i];
            if(i != res.size()-1){
                solu += '.';
            }
        }
        return solu;
    } 
};

int main() {
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}