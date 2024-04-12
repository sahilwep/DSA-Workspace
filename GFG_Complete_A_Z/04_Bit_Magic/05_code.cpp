/*
// Count set bits:

    I/p: n = 5
    O/p: 2
            n = 5 : 101

    I/p: n = 7
    O/p: 3
            n = 7 : 111

    I/p: n = 13
    O/p: 3
            n = 13 : 1101

// Bruteforce solution: 
    * We can right shift the numbers by 1 & we can compare the last bit with 1, & count the number of bits.
    * TC : O(d)
        d = No of bits from last MSB

// Efficient solution: 
    * TC will runs only number of set bits times...
    * Algorithm: Brain Kerningam's algorithm:

// Brains Kerningam's Algorithm: 
    * IDEA : Traverse through only the set bits..
    * TC : O(set bits)
            
            int countBits(int n){
                int res = 0;
                while(n > 0){
                    n = [ ? ]  -> This expression should make the last set bit as 0.
                    res = res + 1;
                }
                return res;
            }
        * Example: 
            n = 40(101000)
            after I'st iteration: n = 32(100000)
            after II'nd iteration n = 0(000000)


    * We can use : n = n & (n-1)
            example: 
            First Iteration: 
                          n = 40: 101000
                        n-1 = 39: 100111 &
                                 ---------
                n & (n-1) = 32    100000  -> makes the last bit of original number is '0'

            Second Iteration: 
                          n = 32: 100000
                        n-1 = 31: 011111 &
                                 ---------
                n & (n-1) = 0     000000  -> makes the last bit of original number is '0'

    * TC : O(signed bits)

*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Efficient Solution: 
int countBits(int n){
    int cnt = 0;
    while(n > 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

// Bruteforce Solution:
int countBits_(int n){
    int cnt = 0;
    while(n != 0){
        if((n&1) != 0){
            cnt++;
        }
        n = (n >> 1);
    }
    return cnt;
}


int main(void){
    
    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        cout << countBits(n) << endl;
    }
    
    
    return 0;
}