/*

// Panagram Checking

// Observations: 
    * Given a string s, we have to check whether it's panagram or not?
    * Panagram: A string that contains every letters of alphabet.
    * We are given string in uppercase & lowercase.
    * we have to convert it into lower or uppercase:


// Intrusion: 
    * We can use hashing approach:
        * We can hash all the letters of string into hash array, that contains every letter of alphabet, & then we can check..
    * TC: O(n)
    * AS: O(n)


ASCII Values: 
    A = 65, a = 97
    0 = 48


*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool checkPangram (string s) {
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i] >= 65 && s[i] <= 90){
                temp += s[i] - 'A' + 'a';
            }else if(s[i] >= 97  && s[i] <= 122){
                temp += s[i];
            }
        }

        // using hashing approach:
        map<char, int> mp;
        // hash alphabets:
        for(char ch = 'a'; ch <= 'z';ch++){
            mp[ch] = 0;
        }
        // hash string:
        for(auto i : temp) mp[i]++;
        
        // checking frequency:
        for(auto i =mp.begin();i!=mp.end();i++){
            if(i->second == 0){
                return 0;
            }
        }
        return 1;
    }

};

int main(){
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}