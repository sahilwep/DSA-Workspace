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

    // Approach 2: 
        * Using sting::npos

*/

#include<bits/stdc++.h>
using namespace std;

// Using normal iterations & comparision logic:
int strstr(string s, string x){
    int pos = -1;
    for(int i=0;i<s.size();i++){
        int ptr = i;
        if(s[ptr] == x[0]){
            bool flag = 0;
            for(int j=0;j<x.size();j++){
                if(s[ptr++] == x[j]){
                    continue;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                pos = i;
                break;
            }
        }
    }
    
    return pos;
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
