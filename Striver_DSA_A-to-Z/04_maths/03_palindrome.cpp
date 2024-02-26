/*
    Palindrome : 121, 1221, 123321, 12321.. these numbers are palindrome.
    Not Palindrome : 1234, 12422..

    Solution : 
        * we can reverse the number if our reverse number is same to the original value, states True, else false.
*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int temp = n;
    int result = 0;
    while (n>0){
        int ld = n % 10;
        result = (result * 10) + ld; 
        n = n / 10;
    }
    (result == temp) ? cout << "Palindrome" : cout << "Not Palindrome"; 

    return 0;
}
// TC : O(log(N))