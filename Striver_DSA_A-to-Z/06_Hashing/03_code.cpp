/*
// character hashing : hashing small alphabets.

// Note :
    * for lower case : character - a
    * for upper case : character - A

// Note : 
    * in hash[s[i] - 'a']
    * hash is an integer, but s is string i.e group of character..
    * So, it's auto caste itself into integer..

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void freq(string s){
        // precomputation : 
        int hash[26] = {0};
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        // fetching : 
        int time;
        cin >> time;
        while(time--){
            char ch;
            cin >> ch;
            cout << hash[ch - 'a'] << endl;
        }
    }

};

int main(void){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        Solution obj;
        obj.freq(s);
    }
    

    return 0;
}