/*
// Trailing Zeros in factorial.
    * Count zeros in factorial of a number.

// Example : 
    I/p : 5
            1*2*3*4*5 = 120 -> 1 zeros at last.
    O/p : 1

    I/p : 10
            1*2*3*...*10 = 3628800 -> 2 zeros at last.
    O/p  : 2


// Observations : 
    // Bruteforce Solution : 
        * first find the factorial of the number, then we nedd to get the last digit of the number & count how many zeros it has.


    // Efficient Solution : 
        * The idea is to count how many two's and five's we have in the prime factorization of the given factorial.


                1x2x3x4x5x6x7x8x9x10x.......n
                        ^          ^

        * If we consider both 2 & 5 as pairs, then we can count how may trailing zeros we are going to have.
        * Because 2 & 5 together form the trailing zeros.
        * In factorial the number of five is going to less than the number of 2's, so we simply need to find how many 5 we have in prime factorization.
        * Example : 
                        1x2x3x4x5x6x7x8x9x10x.......n
                                ^          ^
        * As we know that ever 5th number is five, we can say if we have to count how many five we have in the prime factorization in the number.
        * we can say if we have number n then atleast, 
                    n/5  5 prime number in the prime factorization.
        * we are saying atleast not exact, because there are some number that has more than one 5, says prime factor for prime factor.
        * for example : 
            * 25, it has 2 five in prime factor.   
        * General formula : 
        
                Trailing Zeros count :     [n/5] + [n/25] + [n/125] + ...

    * We are Multiplying with 5 & adding it with (n/multiple of 5)
    * approach : 
                        for(i = 0 ;i<=n;i = i * 5){
                            res = res + n/i;
                        }

    // Time complexity :    
        k = number of iteration.
            5^k <= n
            k <= log(base 5)n
        // TC : O(log(n))
    
    * This solution solve the issue of overflow & time complexity,
    * we are not computing the factorial, we are dividing the number with multiple of 5.

*/

#include <bits/stdc++.h>
using namespace std;

int fact(int x){
    if(x == 1) return x;
    return x * fact(x-1);
}

// Bruteforce Solution : TC : O(n) + O(d) => O(n), 
int trailingZeros(int x){
    int num = fact(x);
    int cnt = 0;
    while(num > 0){
        int ld = num % 10;
        if(ld != 0) break;
        cnt++;
        num = num / 10;
    }
    return cnt;
}

// Efficient solution : TC : O(log(n))
int trailingZeros_1(int x){
    int res = 0;
    for(int i=5;i<=x;i=i*5){
        res = res + x/i;
    }
    return res;
}


int main(void){
    int x;
    cin >> x;
    cout << trailingZeros(x) << endl;
    cout << trailingZeros_1(x) << endl;

    return 0;
}
