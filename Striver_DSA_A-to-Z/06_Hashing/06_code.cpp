/*
// Hashing string using unordered-map.

    map<char, int>

        a-> 2
        b-> 4
        c-> 1
        d-> 0....
*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        unordered_map <char, int> mpp;
        for(int i=0;i<s.size();i++){
            // precomputation :
            mpp[s[i]]++;
        }

        // fetching : 
        int time;
        cin >> time;
        while(time--){
            char ch;
            cin >> ch;
            cout << mpp[ch] << endl;
        }
    }
    return 0;
}





