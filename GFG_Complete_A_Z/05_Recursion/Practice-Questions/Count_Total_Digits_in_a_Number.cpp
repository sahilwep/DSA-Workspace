/*

// Count Total Digits in a Number


// Observations: 
    * we are given an integer n, we need to return how many digits that number contains.


// Intrusion: 
    * First we will write base case: if(n == 0) return 0
    * At every recursive calls we add 1 to counter, & we remove the last digit of the number, until our number becomes 0.


// Extra: Log Method
    * If we do: (log10(n) + 1), this will gives the count of digit.


*/

#include <iostream>
using namespace std;

class Solution {
public:
    int countDigits(int n) {
        if(n == 0) return 0;
        return 1 + countDigits(n / 10);
    }
};

int main(){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countDigits(n) << endl;
    }
    return 0;
}