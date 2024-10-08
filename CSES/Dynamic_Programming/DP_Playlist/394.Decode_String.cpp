/*

//  394. Decode String

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is
 being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square 
brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain 
any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.



//  Observations: 
    * We are given an encoding string, return decoded string.
    * The encoding rules are:
        * k[encoding_string], where the encoded_string inside the square brackets is begin repeated exactly k times.
        * Note that k is guarantee to be a positive integer.
    * You may assume that input string is always valid; there are no extra white spaces, square bracket are well-formed. etc.
        * Furthermore you may assume that the original data does not contains any digits and that digits are only for those repeat number i.
        * For example, ther will not be input like 3a or 2[4]
    * The test cases are generated so that the length of the output will never exceed 10^5.


// Example:

    Input: s = "3[a]2[bc]"
    Output: "aaabcbc"

    Input: s = "3[a2[c]]"
    Output: "accaccacc"

    Input: s = "2[abc]3[cd]ef"
    Output: "abcabccdcdcdef"


//  Intrusion:
    * 


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    string decodeString(string s) {
        

    }
};


void solve(){
    string s;
    cin >> s;

    Solution obj;

    cout << obj.decodeString(s) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}