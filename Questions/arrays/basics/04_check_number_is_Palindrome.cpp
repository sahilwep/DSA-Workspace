/*
// check the number is Palindrome or not ?

    * given number is x 
    * return true if it's palindrome, or return false if it's not.

Example : 1
    input : x = 121
    output : true
    Explanation : 121 reads as 121 from left to right and from right to left.

Example : 2
    input : -121
    output : false
    Explanation : It reads -121 from left to right & 121- from right to left, therefor it is not palindrome. 

Example : 3 
    input : 10
    output : false
    Explanation : reads 01 from right to left & 10 from left to right.

*/

#include <bits/stdc++.h>
using namespace std;

// bruteforce : 
bool isPalindrome(long long x){
    if(x < 0) return false; // note, for -ve number, we know that it's not a palindrome.
    long long temp = x;
    long long rev = 0;
    while(temp != 0){
        int ld = temp % 10;     // getting the last digit : 123 % 10 = 3
        rev = rev*10 + ld;  // to add two numbers, like 3 & 4 -> 34, by (3*10 + 4 = 34)
        temp = temp / 10;   // dividing the number to get short for next iteration. (123 / 10) = 12
    }
    if (rev == x) return true;
    else return false; 
}
// TC = O(log n)

// better solution : we can store one half of the integer into another variable in reversed order, 
// then we can compare it to the other unaltered half of the number and see if they are equal or not
// which should in this case of Palindrome.
bool isPalindrome_m1(long long x){
    /*
        * number is not 0 & it is completely divisible by 10, then we can say number is not palindrome,
        * because, like 10, 20, 100, 140.. any divisible by 10 & that has rem = 0 are hence, it Palindrome.
        * if number is -ve then, it's not palindrome.
    */
    // condition that makes number to be not a palindrome.
    if(x<0 || (x!=0 && x%10==0)) return false;
    int check = 0;
    // here we when (x > check), then only it executes, mean when (check==x) || (check>x) this loop break, which is half value. 
    while(x>check){
        check = check*10 + x%10;
        x = x/10;
    } 
    //          even       odd         case
    return (x==check || x==check/10);
}
// TC : O(n/2)


// better solution : converting it into string.
bool isPalindrome_m2(long long x){
    if(x == 0) return true;
    // converting int into string.
    string str = to_string(x);
    // getting length
    int n = str.length();
    // iterating only half.
    for(int i = 0; i<n/2; i++){
        // if first element & last element are not same then return false.
        if(str[i] != str[n-i-1]){
            return false;
        }
    }
    // when loop finish, and all our condition is failed, else returning true.  
    return true;
}
// TC : O(n/2)

int main(void){

    long long x = 121;

    cout << endl << isPalindrome(x);
    cout << endl << isPalindrome_m1(x);
    cout << endl << isPalindrome_m2(x);

    return 0;
}