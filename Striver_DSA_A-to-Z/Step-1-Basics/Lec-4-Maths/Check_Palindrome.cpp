// https://leetcode.com/problems/palindrome-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution_String_Rev_Method{
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0; // negative number cannot be palindrome:

        string s = to_string(x);
        string temp = s;
        reverse(begin(temp), end(temp));;

        return (temp == s);
    }
};


class Solution_normal_Int_Rev_Logic {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0; // negative number cannot be palindrome:

        // reverse number:
        int temp = x;
        long rev = 0;
        while(x > 0){
            rev = (rev * 10) + x % 10;
            x /= 10;
        }

        return (temp == rev);
    }
};