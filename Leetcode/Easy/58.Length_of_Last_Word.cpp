/*

//  58. Length of Last Word


// Observations:
    * we are given a string containing words & spaces, return the size of last word.


// Example:

    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.

    Input: s = "   fly me   to   the moon  "
    Output: 4
    Explanation: The last word is "moon" with length 4.

    Input: s = "luffy is still joyboy"
    Output: 6
    Explanation: The last word is "joyboy" with length 6.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        int cnt = 0;
        bool flag = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] != ' '){
                cnt++;
                flag = 1;
            }
            if(s[i] == ' ' && flag == 1){
                break;
            }
        }

        return cnt;
    }
};


void solve(){
    string s;
    getline(cin, s);

    Solution obj;

    cout << obj.lengthOfLastWord(s) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    cin.ignore();
    while(t--){
        solve();
    }
    
    return 0;
}