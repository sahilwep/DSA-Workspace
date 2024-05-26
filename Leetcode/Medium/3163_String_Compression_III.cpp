/*
//  3163. String Compression III            https://leetcode.com/problems/string-compression-iii/description/



*/

#include<bits/stdc++.h>
using namespace std;

string compressedString(string word) {
    int n = word.length();
    int count = 0;
    int i=0, j=0;   // two pointer
    string res = "";
    while(j<n){
        count = 0;
        while(j < n && word[i] == word[j] && count < 9){
            j++;
            count++;
        }
        res += to_string(count) + word[i];
        i = j;
    }
    return res;
}

void solve(){
    string s;
    cin >> s; 
    cout << compressedString(s) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}