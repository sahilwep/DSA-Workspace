/*
// Bitwise Operator 2: 

* Note: Int size is of 4 bytes, so total bits are 32

// Left shift <<
        * Shift bits to left sides & 0 is added to end
        * Example: 
               x = 3: 00000....0011 (In binary)
               x<<1 : 00000....0110     => 6 in decimal
               x<<2 : 00000....1100     => 12 in decimal
        
        * NOTE: x << y is equivalent to (x * 2^y)
            x       y       x<<y        
            3       1        6      (3*2^1) 
            3       2        12      (3*2^2)
            3       4        48      (3*2^4)


// Right shift >> 
        * Shift bits to right sides & 0 is added to beginning  
        * Example: 
               x = 3: 00000....0011 (In binary)
               x>>1 : 00000....0001     => 1 in decimal
               x>>1 : 00000....0000     => 0 in decimal
        
        * NOTE: x >> y is equivalent to (x / 2^y)
            x       y       x>>y        
            33       1        16      (33/2^1) 
            33       2        8      (33/2^2)
            33       4        1      (33/2^4)


// Bitwise Not !
    * Flips the bits..
            x = 1 : 0000....001 (In Binary)
            ~x :    1111....110 (Flips the bits)

    * For Unsigned number:
        * Please note (2^32 - 1): 4294967296 - 1        (0 - 2^32)
                                : 4294967295
                            x = 1: (4294967295 - 1)  = 4294967294

    * For Signed number:        (-2^31 <---> 2^31-1)
        * Signed number are stored in 2's compliment form..
        *  2's compliment of x = 2^32 - x
        * Example: 
                x = 5   000....101
                ~x :    111....010
                        (2^32 - 1 - 5)
                        * here -1 is for 2's complement...



*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void leftShift(){
    int x = 3;
    cout << x << " Left shift by 1: " << (x << 1) << endl;
    cout << x << " Left shift by 2: " << (x << 2) << endl;
}

void rightShift(){
    int x = 3;
    cout << x <<  " Right shift by 1: " << (x >> 1) << endl;
    cout << x <<  " Right shift by 2: " << (x >> 2) << endl;
}

void bitwiseNot(){
    unsigned int x = 1;
    int y = 5;
    cout << "bitwise Not Unsigned: " << (~x) << endl;
    cout << "bitwise Not Signed: " << (~y) << endl;
}

int main(void){
    
    leftShift();
    rightShift();
    bitwiseNot();
    
    return 0;
}