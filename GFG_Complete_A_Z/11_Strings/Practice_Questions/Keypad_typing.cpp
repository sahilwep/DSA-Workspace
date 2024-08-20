/*

// Keypad typing

// Observations: 
    * we are given string s of length n, containing lower case letter..
    * Every string is mapped with the number, we need to find that & store in string, & return that string..


// Example:
    Input:  S = geeksforgeeks
    Output: 4335736743357
        Explanation:geeksforgeeks is 4335736743357
        in decimal when we type it using the given
        keypad.

    Input:  S = geeksquiz
    Output: 433577849
        Explanation: geeksquiz is 433577849 in
        decimal when we type it using the given
        keypad.

*/

#include<bits/stdc++.h>
using namespace std;

string printNumber(string s, int n){
    string res = "";
    for(int i=0;i<n;i++){
        if(s[i] == 'a' || s[i] == 'b' || s[i] == 'c'){
            res += '2';
        }
        else if(s[i] == 'd' || s[i] == 'e' || s[i] == 'f' ){
            res += '3';
        }
        else if(s[i] == 'g' || s[i] == 'h' || s[i] == 'i'){
            res += '4';
        }
        else if(s[i] == 'j' || s[i] == 'k' || s[i] == 'l'){
            res += '5';
        }
        else if(s[i] == 'm' || s[i] == 'n' || s[i] == 'o'){
            res += '6';
        }
        else if(s[i] == 'p' || s[i] == 'q' || s[i] == 'r' || s[i] == 's'){
            res += '7';
        }
        else if(s[i] == 't' || s[i] == 'u' || s[i] == 'v'){
            res += '8';
        }
        else if(s[i] == 'w' || s[i] == 'x' || s[i] == 'y' || s[i] == 'z'){
            res += '9';
        }
    }

    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,temp;
        cin>>s;
        int i,len=s.length();

        cout << printNumber(s,len) << "\n";
    }
    return 0;
}
