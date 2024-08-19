/*

// Check if a string is Isogram or not

// Observations: 
    * We are given a string s, we have to check whether the string is isogram or not?
    * Isogram means character of string should appear once..


// Intrusion: 
    * We can use hashing...


*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isIsogram(string s){
        map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second > 1){
                return 0;
            }
        }
        return 1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}