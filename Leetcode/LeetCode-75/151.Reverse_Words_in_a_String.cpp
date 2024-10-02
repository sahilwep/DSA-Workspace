/*

//  151. Reverse Words in a String

//  Observations: 
    * We are given a string s, that contains several words.
    * We need to reverse the string in a way that the word itself is not reversed..
    * Also string itself contains some whitespaces in starting or ending or in between.


// Example:

    Input: s = "the sky is blue"
    Output: "blue is sky the"

    Input: s = "  hello world  "
    Output: "world hello"
    Explanation: Your reversed string should not contain leading or trailing spaces.

    Input: s = "a good   example"
    Output: "example good a"
    Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


// IntrusioN:
    * First we will remove whitespace from starting & ending.
    * Then remove extra spaces in between the two words.
    * Now extract word from string & store into vector,
    * Reverse the vector
    * Move vector element into result string.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Function used to remove whitespace from start, end & in-between the string.
    string makeGood(string s){
        // Removing white spaces from front & back:
        string t = "";
        int start = 0;
        int end = s.size() - 1;
        for(start;start<=end;start++){
            if(s[start] != ' ') break;
        }
        for(end;end>=start;end--){
            if(s[end] != ' ') break;
        }
        for(int i=start;i<=end;i++){
            t += s[i];
        }

        // Removing White Space in between the string:
        string u = "";
        int cnt = 0;
        for(int i=0;i<t.size();i++){
            if(t[i] == ' '){
                cnt++;
            }
            else{
                cnt = 0;
            }
            // if we have more than 1 spaces, we don't store that space.
            if(cnt > 1){
                continue;
            }
            // else we will store all the t[i] iterations into string u.
            else{
                u += t[i];
            }
        }

        return u;
    }

    // function to reverse the string word:
    string reverseWords(string s) {
        // if string has only one element:
        if(s.size() == 1) return s;

        // making string good -> removing whitespace from starting, ending, & in-between if we have more than 1 space
        s = makeGood(s);


        // Reverse string: by extracting word one by one, & moving it into the vector, which makes easy to reverse
        vector<string> res;
        string temp = "";   // variable use to fetch word from the string s
        for(int i=0;i<s.size();i++){
            // when we don't have spaces, we will add s[i] character into temp
            if(s[i] != ' '){
                temp += s[i];
            }
            // once we encounter with (' '), white spaces, we will insert temp string into the vector
            else{
                res.push_back(temp);    // inserting temp string into vector
                res.push_back(" "); // inserting white spaces also, so that when we reversed the vector & store the result into the string, we don't need to insert whitespace explicitly into the string.
                temp = "";  // making temp empty again, so that it can go for next word
            }
        }
        res.push_back(temp);    // This is the last word left in temp string, that we have to push into the vector.
        

        // Now, Reverse the result vector, this will reverse word order, not the word itself.
        reverse(res.begin(), res.end());


        // At last we will inset all the elements from vector to the string.
        string sol = "";
        for(int i=0;i<res.size();i++){
            sol += res[i];
        }

        return sol;
    }
};

void solve(){
    string s;
    getline(cin, s);
    Solution obj;
    cout << obj.reverseWords(s) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    cin.ignore();  // Ignore the newline after the number input
    while(t--){
        solve();
    }
    
    return 0;
}