/*
//  Palindrome check using recursion: 


I/p: aabcbba
O/p: YES

I/p: abba
O/p: YES

I/p: geeks
O/p: NO

// Base case: 
    if n == 0 || n == 1 return true     -> single character will always be true.
    we can say if(start >= end) return true;
    else{
        we have to recursively check all the character of string...

            (s[0] == s[n-1]) && (s[1] == s[n-2]) && (s[2] == s[n-3])... (s[n/2] == s[n/2])

                * If these return 1, then only return 1, else if any of these character not matched, we return false
            
            return (s[start] == s[end]) && (s[start+1] == s[end-1]);    // we can write like this..
    }


// Note: string is passed as reference for optimized purpose, to avoid string copy in cpp, (because formal & actual parameter concept work here...)

// TC: O(n)

// Recursive calls:
        isPalindrome("abba",0, 3)   => return 1 && 1 to main scope
                |--->return ('a' == 'a) && isPalindrome("bb",1 , 2)     => return 1 && 1
                                                |--->return ('b' == 'b) && isPalindrome("",2 , 1)   => return 1 && 1
                                                                            |---> base case hit: return 1


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPalindrome(string &s, int start, int end){
    if(start >= end) return true;   // condition when only one element is there, or there is no element left..
    return (s[start] == s[end] && isPalindrome(s, start+1, end-1));     // means current index element & recursively call next & prev element to match if all the element matched & return true, then only we return true, else we return false;
}

int main(void){
    
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int start = 0, end = s.size()-1;
        bool res = isPalindrome(s, start, end);
        (res == 0) ? cout << "NO" << endl : cout << "YES" << endl;
    }
    
    return 0;
}