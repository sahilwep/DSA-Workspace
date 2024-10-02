/*

//  345. Reverse Vowels of a String


//  Observations: 
    * We are given a string s, & we only need to reverse only the vowels of strings.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Function to check whether given character is string or not?
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    string reverseVowels(string s) {
        int n = s.size();

        // Using Two pointer to iterate over the string from start & end, & reverse the vowel:
        int start = 0;          // starting pointer
        int end = n - 1;        // ending pointer

        while(start < end){
            // If start pointer is not vowel, increment the counter vowel
            if(!isVowel(s[start])){
                start++;
            }
            // If end pointer is not vowel, decrment the counter in order to find the vowel
            else if(!isVowel(s[end])){
                end--;
            }

            // When both pointer is at vowel, we will swap these two characters.
            else if(isVowel(s[start]) && isVowel(s[end])){
                swap(s[start], s[end]); // swaping values
                // moving both pointers to reverse next pairs of vowels.
                start++;
                end--;
            }
        }
        
        return s;   // returning the vowel reversed string.
    }
};

void solve(){
    int n;
    string s;
    cin >> s;

    Solution obj;
    cout << obj.reverseVowels(s) << endl;
    
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}