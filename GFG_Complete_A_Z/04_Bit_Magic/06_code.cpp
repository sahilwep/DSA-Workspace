/*
// Power of Two: 
        n >= 0

    I/p : n = 4
    O/p : True

    I/p : n = 6
    O/p : False

    I/p : n = 1
    O/p : True

    I/p : n = 0
    O/p : False

// Explanation: Power of two
        2^0 = 1
        2^1 = 2
        2^2 = 4
        2^3 = 8
        2^4 = 16

// Naive Solution: 
    * Explicitly handle 0
    * Repeatedly divide by 2 & check the remainder...
        example: n = 4,     condition for false: [if(n % 2 != 0) return false;]
            4   // (condition for false not satisfies),  divide by 2
            2   // (condition for false not satisfies),  divide by 2
            1  -> when we get 1 loop break..   (Return true)
        example: n = 6
            6   // (condition for false not satisfies),  divide by 2  
            3   // (condition for false satisfied ) -> break;
    
    * TC : O(log(n))

// Efficient Solution: 
    * We will use Brains Kerningam's Algorithm: n = n & (n-1) -> makes the last bit of original number "0"
        * Binary representation of power of 2 is only one set bits.
                    2 : 000...0010
                    4 : 000...0100
                    8 : 000...1000...
        * If the set bit is 1, return true, else return false.
    * Brains kerningam's algo makes last bit as 0, and we know binary representation of 2 has only one set bits..
    * If we apply brains algo, & if our result number is "0", we can say our number is divisible by 2, else return false.
        * Example: of number which can not be divisible by 2: 
            n = 6 : binary : 000...0110
            Apply brains kerningam's algo: (n & (n-1))
            
                        n = 6   000...0110
                        n = 5   000...0100  &
                            ------------------
                                000...0100 -> this is not equal to "0", so we return false...
    * TC : O(1)

*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Efficient Solution:
bool powerOfTwo(int n){
    // if(n == 0) return false;
    // n = n & (n-1);
    // if(n == 0) return true;
    // return false;
    // or:
    // if(n == 0) return false;
    // return ((n & (n-1)) == 0);
    // or: 
    return (n && ((n & (n-1)) == 0));
}

// Naive Solution: 
bool powerOfTwo_(int n){
    if(n == 0) return false;    // check n, explicitly..
    // loop break either the n == 1, means it's able to divide by 2, or if it's not able to divide by 2, it's return false..
    while(n != 1){
        if(n % 2 != 0) return false;    // loop break when the n is not able to divide b/y 2
        n = n / 2;      // divide by 2, at every iterations...
    }
    return true;
}

int main(void){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        (1 == powerOfTwo(n)) ? cout << "True" << endl : cout << "False" << endl;
    }
    
    return 0;
}