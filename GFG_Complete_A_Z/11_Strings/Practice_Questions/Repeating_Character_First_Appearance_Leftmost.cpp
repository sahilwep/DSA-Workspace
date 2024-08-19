/*

// Repeating Character - First Appearance Leftmost

// Observations: 
    * we are given a string s, we need to find the index of repeated character whose first appearance is leftmost.

// Intrusion: 
    * We can use map & hashing technique..


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to find repeated character whose first appearance is leftmost.
    int repeatedCharacter (string s){
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }

        for(int i=0;i<s.size();i++){
            if(mp[s[i]] > 1){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        Solution obj;
        int index = obj.repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
    }
    return 0;
}