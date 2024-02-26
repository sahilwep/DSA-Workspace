/*
// character hashing : 256 elements :

// input : 
1
anandsahilwep
6
s
a
w
p

// output : 
1
3
1
1
1
1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void freq(string s){
        // precomputation : 
            int hash[256] = {0};    // to store 0 at every index.
            for(int i=0;i<s.size();i++){
                hash[s[i]]++;
            }
        // fetching : 
            int times;
            cin >> times;
            while(times--){
                char ch;
                cin >> ch;
                cout << hash[ch] << endl;
            }
    }
};

int main(void){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        obj.freq(s);
    }
    return 0;
}