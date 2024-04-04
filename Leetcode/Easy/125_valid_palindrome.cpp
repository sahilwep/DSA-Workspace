/*
// Valid Palindrome: https://leetcode.com/problems/valid-palindrome/

    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

    Example 2:
    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.

    Example 3:
    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.


// ascii difference : A-a : 32
    a = 97      , z = 122
    A = 65      , Z = 90
    0 = 48      , 9 = 57
    


// Naive Solution: 
    s = "A man, a plan, a canal: Panama"
    * create a temp string.
    * Store the A-Z, a-z, & 0-9 value from original string to temp string
        * While Storing, convert (A -> a), in single case format..
    * Use two pointer, & compare the it till middle..
    * If any of the pointer has not same value, return false
    * else return true..
    * TC : O(n)
    * AS : O(n)

// Efficient Solution: Optimizing by taking AS as O(1)..
    s = "A man, a plan, a canal: Panama"
        * Idea : we are not maintaining the temp string.
        * We will use the iterator to iterate only if we get Alphanumeric values,
            * we will skip all the special characters... 
            * While iterating, if we get any A(Capital case) convert it to the small case & then compare..
    * Stings have several function that convert uppercase into lowercase & check for alphanumeric values...
    * isalnum() -> return true or false, depends on the condition...
    * tolower() -> convert the character into lower..
        
    * TC : O(n)
    * AS : O(1)

*/


#include<bits/stdc++.h>
using namespace std;

// Optimized AS from O(n) to O(1)
bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        // Skip non-alphanumeric characters from left
        while (i < j && !isalnum(s[i]))
            i++;
        // Skip non-alphanumeric characters from right, & moving the pointer
        while (i < j && !isalnum(s[j]))
            j--;
        // Compare characters, by converting them into lowercase
        if (tolower(s[i]) != tolower(s[j]))    // tolower() will convert the capital to small.
            return false;
        i++;
        j--;
    }
    return true;
}

// Naive Solution: 
bool isPalindrome_(string s) {
    string temp;
    // preprocessing : convert all small value into capital & store it into new temp string.
    for(int i=0;i<s.size();i++){
        // capital || small || numeric
        if(s[i] >=65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i] >= 48  && s[i] <= 57){
            // checking for small values, & convert it to capital letter..
            if(s[i] > 90 ){
                char c =   s[i] - 'a' + 'A';
                temp += c;
            }else {
                temp += s[i];  
            }
        }
    }
    // checking : 
    int i = 0;  // first value pinter
    int k = temp.size()-1;  // last value pointer
    while(i <= k){
        if(temp[i] != temp[k]){
            return false;   // case when two pointers are not equal
        }
        i++;
        k--;
    }
    return true;
}


int main(void){
    string s;
    
    getline(cin, s);

    int res = isPalindrome(s);
    (res == 1) ? cout << "True" : cout << "False";

    return 0;
}