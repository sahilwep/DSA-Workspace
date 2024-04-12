/*
// Check if k'th bits is set or not?

    I/p : n = 5, k = 1
            0000..0101
    O/p : Yes

    I/p : n = 8, k = 2
            0000..1000
    O/p : No
    
    I/p : n = 0, k = 3
            0000..0000
    O/p : No

* k <= No of bits in the binary representation of n.

// Idea for the solution: 
    * How do you check the last bit?
        if((n&1) != 0){
            print("Yes");
        } else {
            print("No");
        }

    * How do you check kth bit?
        * We mainly need to do bitwise and with a number with only kth is set : (2^k -1)
                     000..010..00   
                           - 
                        kth bit   

// Naive solution : 
    * We are computing (2^k -1)
    * after getting the value, we will simply check the condition for last bit...
    * Example: 
        n = 5 : (000..0101)
        k = 3   
        After loop: 
            x = 4 : (000..0100)

            n = 5:      00...0101
            x = 4:    & 00...0100
                    ----------------
                        00...0100 (Representation of 4), which is non-zero value

    * Time complexity is O(k)

// Alternate Naive solution: 
    * We reduce n to [n/(2^(k-1))]
    * Example: 
            n = 5 : (000...0101)
            k = 3
            After loop: 
                n = 1: (000...0001)
            * This will move the bits to the left, if the kth bit's is set it's the last bit, else if not set we return false..

    * TC : O(k)

// Efficient solution: 
    * Left shift is used to check the signed bits..
    * Left shift operator is equivalent to power, so we didn't use the loop to compute the power, this is equivalent to 2^(k-1)
    * & Then we simply check the signed bits of condition with x bits that we shifted..
            n = 5 : (000...0101)
            k = 3
            After loop: 
                x = 4 : (000...0100)

                      n = 5:      00...0101
                      x = 4:    & 00...0100
                               ----------------
                                  00...0100 (Representation of 4), which is non-zero value

// TC : O(1)

// Efficient solution: 
    * Right shift can also be used to check the signed bits...
    * equivalent to n/2^(k-1)
            n = 5 : (000...0101)
                            - 
            k = 3

            After loop: 
                x = 1 : (000...0001)

                      1:          00...0001
                      x = 1:    & 00...0001
                               ----------------
                                  00...0001 
    * Here, we are doing  (n >> (k-1)), because we are comparing the last bits with 1, 
    * if we do (n >> k), the kth bits pop out...

// TC : O(1)
*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Efficient Solution:
void isSet(int n, int k){
    int x = (n >> (k -1));      //  equivalent to n/2^(k-1)
    if((x&1) != 0){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}

// Efficient Solution:
void isSet_3(int n, int k){
    int x = (1<<(k-1));     // equivalent to 2^(k-1)
    if((n&x) != 0){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}

// Another Naive solution: 
void isSet_2(int n, int k){
    for(int i = 0;i<k-1;i++){
        n = n/2;    // this will move the bits to the left...
    }
    if((n&1) != 0){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}

// Naive solution: 
void isSet_1(int n, int k){
    int x = 1;
    for(int i = 0;i<k-1;i++){
        x  = x*2;
    }
    if((n&x) != 0){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}

int main(void){
    
    int n, k;
    cin >> n >> k;
    isSet(n, k);
    isSet_3(n, k);
    isSet_1(n, k);
    isSet_2(n, k);

    
    return 0;
}