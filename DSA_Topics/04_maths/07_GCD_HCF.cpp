/*
    GCD/HCF : Greatest common divisor or Highest common factor.

    eg: (9,12)  : n1 = 9,   n2 = 12
    factors :   1,3,9         1,2,3,4,6,12
    So, from both of them the common factors are : 1,3
    So, the GCD/HCF is : 3

    eg (11,13)  : n1 = 11,  n2 = 13
    factors :      1,11         1,13
    so, from both of them the common factors are : 1
    so, the GCD/HCF is : 1

    eg (20,40)  : n1  = 20,     n2 = 40
    Factors :   1,2,4,5,10,20     1,2,4,5,10,20,40
    So, from both of them the common factors are : 1,2,3,5,10,20
    So, the GCD/HCF is : 20

    Now, how to find the GCD/HCF
    eg: (9,12)
        * we can iterate from (1 to 12), & check for ever number that it is divisible by both 9 & 12, 
        * if there are divisible by both, we can store our GCF, & again check further until we checked the last value i.e 12.
    

    * Now we can iterate the loop till 12, but after 9 there is no sense of iterating loop further, because after 9 there will be no such common factors for 9 & 12.
    * so we can say that we can iterate the loop till min(9,12)

    NOTE : any given number has always GCD 1, if they have further no highest common factors.

*/

#include <bits/stdc++.h>
using namespace std;

// function to check GCD/HCF
void check(int x, int y){
    int gcd = 1;    // 1 because any given two number has always GCD 1
    for(int i=1; i<=min(x,y); i++){
        if(x%i==0 && y%i==0){
            gcd = i;
        }
    }
    cout << endl <<  "GCD is : " << gcd;
}
// TC : O(min(n1,n2))


/*
// Optimized way : 
// Here we are finding HCF, so instead of going from 1 to min(n1,n2), 
// we can go from min(n1,n2) to 1, & during whenever we find the condition for HCF, we break out of the loop, 
// because we are finding the highest factor, & in reverse manner the first found common factors is Highest factor.
*/

void check_1(int x, int y){
    int gcd = 1;
    for(int i = min(x,y); i>=1; i--){
        if(x%i==0 && y%i==0){
            gcd = i;
            break;
        }
    }
    cout << endl <<  "GCD is : " << gcd;
}
// TC : O(min(n1,n2)), yeah because we have to look for worst case.

int main(void){

    int x,y;
    cin >> x >> y;
    check(x, y);
    check_1(x,y);

    return 0;
}