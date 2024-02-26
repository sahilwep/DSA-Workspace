/*
// GCD or HCF of Two Numbers : 

// Observation : 
    * Prime number : A number that can divided exactly only by itself & 1, we say it's prime
    * Composite number : A number that can have more than two factor.
    * GCD : Greatest Common factor : 
    * HCF : Highest Common Factor : 
    * We need to find the factors of both the number, whatever the highest factor that is able to divide both the number we can say it's the HCF.

// Examples : 
    I/p : a = 4, b = 6
    O/p : 2


    I/p : a = 100, b = 200
    O/p : 100

    I/p : a = 7, b = 13 
    O/p : 1


// Bruteforce Solution :
    * GCD of two numbers can be maximum as minimum of two numbers : 
    * Example : if a=100, & b=200, the GCD is 100, it can't go beyond hundred.
    * We initialize our result as min of two number : min(a,b)
    * We will check all the numbers smaller than min(a,b), if any of the number divide both of them, then we return the number as GCD.
    * TC : O(min(a, b))

// Efficient Solution : Euclidean Algorithm : 
    * if 'b' is smaller than 'a'
        GCD : gcd(a,b) = gcd(a-b, b)
    
    * Why ? 
        Let 'g' be GCD of 'a' and 'b'
            a = gx and b = gy & gcd(x,y) = 1
            (a-b) = g(x-y)
    
    * Algo : 
            while(a != b){
                if(a > b){
                    a = a -b;
                }
                else{
                    b = b -a;
                }
            }

    * Example : 
            a = 12, b = 15
            a = 12, b = 3
            a = 9, b = 3
            a = 6, b = 3
            a = 3, b = 3

    * TC : O(min(a,b))

    * Optimized version : 
        * Instead of doing repeated subtraction, we can do modulo division.
        * Algo : 
            gcd(a, b){
                if(b == 0) return a;
                return gcd(b, a%b);
            }
        * here we don't need to check for grater or smaller value, because we just flip the numbers.
        * Recursive Calls : 
                    a = 12, b = 15
                        
                        gcd(12, 15) ----> return 3
                            |
                            gcd(15, 12) ---> return 3
                                |
                                gcd(12, 3)---> return 3
                                    |
                                    gcd(3, 0)--> return 3   
                                    
        * TC : O(log(min(a,b)))

*/

#include <bits/stdc++.h>
using namespace std;

// Bruteforce Solution :
int gcd(int a, int b){
    int res = min(a,b); // initializing res = min(a, b), as we know it's not going beyond the smaller number
    // we are iterating till 1, as the last GCD of two number.
    while(res > 0){
        if(a % res == 0 && b % res == 0) break; // case when the number is able to divide both the number.
        res--;  // decrementing the number to check till 1.
    }
    return res; // returning res.
}

// Efficient Solution: 
int gcd_Eculid(int a, int b){
    while(a != b){
        if(a > b){
            a = a -b;
        }
        else{
            b = b -a;
        }
    }
    return a;
}

// Optimized version of euclidean : 
int gcd_Eculid_Optimized(int a, int b){
    if(b == 0) return a;
    else{
        return gcd_Eculid_Optimized(b, a%b);
    }
}

int main(void){
    int a,b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << gcd_Eculid(a, b) << endl;
    cout << gcd_Eculid_Optimized(a, b) << endl;

    return 0;
}
