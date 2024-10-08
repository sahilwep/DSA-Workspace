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
    // Bruteforce Approach: 
        * we will keep iterating in string until we not find innermost bracket, whenever we get closing bracket,
        * We will make our string that much times long..
        * But this approach will take so much time..
        * Example: 
                2[a3[c2[x]]y]
            * First work with the innermost bracket.
                2[a3[cxx]y]
            * then gradually go out of the zone.
                2[acxxcxxcxxy]
                acxxcxxcxxyacxxcxxcxxy  -> Answer
        

    // Efficient Approach: Using stack
        * Two stacks will be used:
            * numStack: To store the repeat count (integer k).
            * strStack: To store the partially constructed string.
        * Iterate through the input string:
            * If a digit is encountered, calculate the full number (since it could be multiple digits).
            * If an opening bracket [ is encountered, push the current repeat count and the current string onto their respective stacks, and reset the current string.
            * If a closing bracket ] is encountered, pop the string from strStack and the number from numStack. Repeat the current string k times and append it to the string popped from strStack.
            * If a letter is encountered, keep appending it to the current string.
        * Output the final constructed string.

        * Example: 2[a3[c2[x]]y]

                        |       |           |   x   |
                        |       |           |   [   |
                        |       |           |   c   |
                        |   2   |           |   [   |
                        |   3   |           |   a   |
                        |   2   |           |   [   |
                        ---------           ---------
                        numbers             string

                    * Encounter with ']'
                    * remove characters from string stack until we hit with '[' -> x
                    * remove 2 from stack
                    * repeat x 2 times => xx
                    * Push it on the stack:
                    
                        |       |           |       |
                        |       |           |   xx  |
                        |       |           |   c   |
                        |       |           |   [   |
                        |   3   |           |   a   |
                        |   2   |           |   [   |
                        ---------           ---------
                        numbers             string

                    * Same steps repeat until we are not at the end of string..

                    * At the end we will have our all the decoded strings into stack, just transfer it into string, then reverse it & return.

        * TC: O(n)
        * AS: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;          // Stack to store repeat counts
        stack<string> strStack;       // Stack to store intermediate strings
        string currentStr = "";       // Current string being processed
        int num = 0;                  // Current number being processed

        for(char c: s){
            // if it's digit, from the number(could be multiple digits)
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }
            // Push the current number and string to stack, then reset them
            else if(c == '['){
                numStack.push(num);
                strStack.push(currentStr);
                num = 0;    // reset the number
                currentStr = "";    // reset the current string
            }
            // If we encounter with closing bracket we need to process the element before them & number of times..
            else if(c == ']'){
                // Pop the number and the string from stacks:
                int repeatCnt = numStack.top();
                numStack.pop();
                string temp = strStack.top();
                strStack.pop();

                // Append the current string 'repeatCnt' times:
                for(int i=0;i<repeatCnt;i++){
                    temp += currentStr; // With current string, adding temp on it.
                }

                // set the current string to the newly formed string:
                currentStr = temp;
            }
            // Otherwise, it's a character, append to the current string:
            else{
                currentStr += c;
            }
        }

        return currentStr;        
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