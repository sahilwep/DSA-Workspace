// Check string is Palindrome or not using recursion
/*
    condition for strings is palindrome is : The reversal is exact equal to the original.
        ABCBA   : reverse => ABCBA
        MADAM   : reverse => MADAM 
    * We know that string is nothing but combination of character or we can say a array that contain multiple character.

        M   A   D   A   M
        0   1   2   3   4
    
        Now we can say if : f(i)    
                                if(i>=n/2) return true  // this condition will executed only when all the left & right are checked.
                                if(fist_index) != n-i-1(last_index) return false    // this will execute in any recursion, if this condition will satisfied, or we can say character values are not matches.
                                return f(i+1)   // if first two condition are false, then this will executed.

            TC : O(n/2)
            SC : O(n/2)
*/
#include <bits/stdc++.h>
using namespace std;


bool f(int i, string &s){
    if(i>= s.size()/2) return true;
    if(s[i] != s[s.size()-i-1]) return false;
    f(i+1, s);
}



int main(void){
    string s = "MADAM";
    (1 == f(0, s)) ? cout << "True" : cout << "False";

    return 0;
}