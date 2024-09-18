/*

//  A. Colorful Stones (Simplified Edition)

// Observations: 
    * There are given sequence of colorful stones. The color of each stones is one of red, green, blue. we are given string s.
    * The i-th(1-based) character of string s represents the color of the i-th stones. If the character is 'R', 'G', 'B'
    * Initially squirrel liss is standing on the first stones, you perform instruction on more time.
    * You are given string t. the number of instruction is equal to the length of of t, and i-th charater of t represents the i-th instruction.
    * Calculate the final position of liss, after performing all the instruction, and print 1-based position. It is grantee that liss don't move the sequence.
    * In conclusion: 
        * we are given string s, and
        * we are given sequence t.
        * If s character is matching with the t character we will move forward, else s character will not move, but we will keep moving the t character..
        * At the end we need to find the final position of s[i]


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;

    int k = 0;
    for(int i=0;i<t.size();i++){
        if(s[k] == t[i]){
            k++;
        }
    }
    
    cout << k+1 << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}


