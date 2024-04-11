/*
// Binary representation of Negative number: 

    * Negative numbers are represented in 2's compliment form

    * Range of numbers:[-2^(n-1) to 2^(n-1) - 1]
    * Here n is number of bits.
    
    * Steps to get 2's compliment:
        * Inverse all bits: we can do NOT operator(~)
        * Add 1
        * Direct Formula: 2^n - x
    
    * Example: n = 4, no of bits..
        Range: [-2^3 to 2^3 -1]
        Binary representation of x = -3
        3: 0011
        2's complement: (1100 + 1)
                     : 1101 -> 13 in decimal
        * This is the binary representation of x, where x = -3
        * We can get the value with direct formula: 
                    * 2^n - x
                    * 2^4 - 3
                    * 16 -  3 = 13 


* NOTE: Only negative numbers are represent with 2's complement form, positive numbers are represent using simple decimal to binary conversion.

// Why 2's compliment form: 
    * We have only one representation of zero
    * The arithmetic operation are easier to perform, actually 2's complement idea is derived from the idea of 0-x.
    * The leading bit is always 1.

    * Example: 
        * Let say we have to represent 3, so it will represent like 32 bit:
                                          0000..0011        (Binary rep. of 3)
        * Let say we have to represent -3, so it will represent with 2's compliment.
                                          1111..1101        (Binary rep. of -3)

    * We can also use signed bit to represent, or 1's complement..
        * In signed bit, the left most, or the first bit is used to signed..
            * Example: 
                        -3 : 1000...0011
                        3 : 0000..-0011    
            * The problem with this approach is, '0', 0 can be represent with both ways, -0 & +0
                            1000...0000 : -0
                            0000...0000 : +0
            * So, this will create confusion in arithmetic operations, so this is why signed bit representation is not used...

        * Same problem lies with 1'complement(in 1's comp. we simply invert all the bits..): 
                            0000..0011 : 3
                            1111..1100 : -3
                    * But, again the same problem arieses of representing '0' with both ways...
                            0000..0000:  +0
                            1111..1111 : -0
                    * Again same problem, so this reduces the range, & create confusion

        * This is why we prefer 2's complement representation..

// Range of signed & unsigned : 
        * Signed: -2^(n-1) to 2(n^-1) -1        : Range round off
        * Unsigned: 0 to 2^n -1                 : Bigger range..

    * Example for 32 bits: 
        * signed: -2^31 to 2^31 - 1
        * Unsigned: 0 to 2^32 - 1

// Intrusion behind 2's complement: 
    * We simply subtract the number from 0
    * Example: 
            say number 3, & 4 bits to represent: 
                    0011
            * If we subtract it from 0: 
                  1 0000
                    0011  -
                -----------
                      01 
            * If we add or remove 1 in front, it's doesn't matter, it's basically subtraction from 0.
            * Leading bits doesn't matter...
    * In binary representation of negative number using 2's complement, the leading bit is always 1..
    * because, the rage : 2^(n-1) - 1 is for negative number as it's signed(-ve), so we are using the binary representation of negative number leading bits as 1..


*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(void){
    
    int x, n;
    cin >> x >> n;
    int res = (pow(2, n) - x);
    cout << "Binary rep: " <<  res << endl;
    
    return 0;
}