/*

// Implement strstr

// Observations: 
    * We are given string s, & we have to find the first occurrence of substring if it exists..


// Example:

Input:  s = GeeksForGeeks, x = Fr
Output: -1
Explanation: Fr is not present in the
string GeeksForGeeks as substring.


Input:  s = GeeksForGeeks, x = For
Output: 5
Explanation: For is present as substring
in GeeksForGeeks from index 5 (0 based
indexing).

// Intrusion:
    // Approach 1:
        * Using Normal iterative logic, & maintaining pointer to compare the string characters..
        * TC: O(n*m)

    // Approach 2: 
        * Using sting::npos
        * We can use string string.find(substring) functions..
        * which will return npos if not found, else return the starting index..
        * TC : O(n*m)

*/

#include<bits/stdc++.h>
using namespace std;

// Using normal iterations & comparision logic:
int strstr_(string s, string x){
    int pos = -1;   // initialize pos = -1, if substring is not found..
    // iteration start from original string in which we have to found
    for(int i=0;i<s.size();i++){
        int ptr = i;    // maintaining the ptr, so that we can compare the string portions with substring..
        // if substring first character is matched with string character
        if(s[ptr] == x[0]){
            bool flag = 0;  // making flag that will help us to know if the string portions is not matched with substring..
            // iterations in substring to match with original string
            for(int j=0;j<x.size();j++){
                // if string portions is matching with substring portions
                if(s[ptr] == x[j]){
                    ptr++;  // increment the string portions, so that we can continue matching with substring portions iterations..
                    continue;   // skipping the rest of logic, as the character of original string & substring is matched..
                }
                // else if character of string & substring is not matched, we can break out from this matching of selected ptr of outer loop, means original string..
                else{
                    flag = 1;
                    break;
                }
            }
            // If we have the matching of substring & original string portions, we can break out from the loop & return the position of starting matched character of the original string.
            if(flag == 0){
                pos = i;    // storing the position as substring is matched with string portions..
                break;
            }
        }
    }
    
    return pos;     // returning the string..
}

int strstr(string s, string x){
    int found = s.find(x);
    if(found != string::npos){
        return found;
    }
    else return -1;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
