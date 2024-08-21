/*

// Non Repeating Character

// Observations: 
    * We are given string of size n, we have to return the first non-repeating character from stirng..

// Intrusion: 
    * We can use hashing, approach: 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    char nonrepeatingCharacter(string S){
      
       
    }

};

int main() {
    int T;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonrepeatingCharacter(S);

        if(ans != '$')
        cout << ans;
        else cout << "-1";

        cout << endl;
    }
    return 0;
}