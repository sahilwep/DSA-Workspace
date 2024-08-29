/*
    extract digit :  
        e.g : 1234  => print 1 2 3 4
        e.g : 5234  => print 5 2 3 4
    Concept :   
        * if we divide 1234 by 10 we will get remainder 4, & quotient 123.something which is round int(123)
        * So if we perform : 1234 % 10 => gives 4
        * & if we perform : 1234 / 10 => gives 123
        * after we perform :  123 % 10 => gives 3
        * & perform : 123 / 10  => gives 12
        * and till our number 1234 goes to 0.   
*/

#include<bits/stdc++.h>
using namespace std;

// bruteforce approach
int main(void){
    int n;
    cin >> n;
    while (n>0){
        // int last_digit = n % 10;
        // cout << last_digit << " ";
        // or
        cout << n%10 << " ";
        n /= 10;    // equivalent to n = n / 10
    }
    return 0;
}
// TC : O(log(n))