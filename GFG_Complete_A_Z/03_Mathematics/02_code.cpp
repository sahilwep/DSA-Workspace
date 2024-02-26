/*
// Palindrome Number : 
    * If the reversal of the number is equal to the original number, then we can say it's palindrome number.


// Example : 
    I/p : 78987
    O/p : Yes

    I/p : 8668
    O/p : Yes

    I/p : 8 
    O/p : yes

    I/p : 21
    O/p : No

    I/p : 367
    O/p : No

// Number should be >= 0

// Observation : 
    * We can say the number that is divisible by 10 is not palindrome number.
    * -ve Numbers are not palindrome numbers.
    * Single numbers are palindrome numbers.
    * if reversal of a number is equal to the original number, then we can say number is palindrome number.
    

    // TC : O(d), d = no of digits.

// Operations of Modulo operator : 
    *   x % 10 = give the last digit of x
    *   x / 10 = remove the last digit of x
    *   example :  
        * x = 123
        * x % 10 = 3
        * x / 10 = 12.3 -> taking int of it, will round the value of 12.3 to 12   

*/

#include <bits/stdc++.h>
using namespace std;

bool palindromeNumber(int x){
    if(x < 0) return false;
    if(x % 10 == 0) return false;
    int temp = x;
    int rev = 0;
    while(temp > 0){
        int ld = temp % 10;
        rev = rev*10 + ld;
        temp = temp / 10;
    }
    if(rev == x) return true;
    else return false;
}

int main(void){
    int x;
    cin >> x;
    (palindromeNumber(x) == 1) ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;
}