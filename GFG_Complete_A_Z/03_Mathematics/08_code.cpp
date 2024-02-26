/*

// Prime Factors : 
    * Prime factors are those divisors of the given number that are prime.
    * Prime Numbers : 2, 3, 5, 7, 11, 13,.....
    * Fact : when multiply the prime factors of a number it will give the original number.

// Examples : 

    I/p : n = 12
    O/p : 2 2 3
        * here 2 are two times, because 2 divides 12

    I/p : n = 13
    O/p : 13


    I/p : n = 315
    O/p : 3 3 5 7
        * If we multiply all the prime factor we will get original number.


// Bruteforce Solution :
    * first from 2 to num-1 get all the prime number & check it for that it's get divisible by the original number or not.
    * if that prime number is able to divide the original value, we can print that factor.


// Better Solution : 
    * Divisors always appears in pairs.
            30 : (1, 30), (2, 15), (3, 10), (5, 6)
    * Number can be written as multiplication of power of print factors.
            12 = 2^2 * 3^1
           315 = 2^1 * 3^2 * 5^2
    * let (x, y) be a pair
        x * y = n
        If, x <= y
            x * x <= n
              x <= sqrt(n)

    * example : 
            n = 450
            i = 2
                print(2)
                n = 225
            i = 3
                print(3)
                n = 75
                print(3)
                n = 25
            i = 4 
            i = 5
                print(5)
                n = 5
                print(5)
                n = 1

        Note : 450 = 2^1 * 3^2 * 5^2
    * example : 
            n = 84
            i = 2 : 
                print(2)
                n = 42
                print(2)
                n = 21
            i = 3 : 
                print(3)
                n = 7
            After loop
                print(7)

    
        * TC : O(sqrt(n))

// Efficient Solution : 
    * we will remove iteration case explicitly
    * TC : O(sqrt(n))


*/

#include <bits/stdc++.h>
using namespace std;


// Prime number of not :
bool isPrime(int n){
    if(n==1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i=5;i*i<=n;i=i+6){
        if(n%i==0 || n%(i+2) == 0) return false;
    }
    return true;
}


// Bruteforce Solution :    TC : O(nlogn)
void primeFactors(int n){
    for(int i=2;i<n;i++){   // TC : O(n)
        if(isPrime(i)){ // check for prime numbers
            int x = i;  // storing in x
            // now checking if that number is able to divide n
            while(n % x == 0){  // TC : O(logn)
                cout << i << " ";   // if it's able to divide print that number.
                x = x*i;    // multiplying number with i, to check next factor.
            }
        }
    }
}


// Better Solution : 
void primeFactors_m1(int n){    
    if(n <= 1) return;  // if number is 1 or less, then we return.
    for(int i=2;i*i<=n;i++){    // iterate only till sqrt(n)
        while(n%i == 0){    // if(n is divisible by i)
            cout << i << " ";  //  print i
            n = n/i;    // divide n = n/i
        }
    }
    if(n>1){    // case when n > 1
        cout << n << " ";
    }
}


// Efficient Solution : 
void primeFactors_m2(int n){
    if(n <= 1) return;
    while(n%2 == 0){
        cout << 2 << " ";
        n = n/2;
    }
    while(n%3 == 0){
        cout << 3 << " ";
        n = n/3;
    }
    for(int i=5;i*i<=n;i=i+6){
        while(n%i == 0){
            cout << i << " ";
            n = n/i;
        }
        while(n%(i+2) == 0){
            cout << (i+2) << " ";
            n = n/(i+2);
        }
    }
    if(n>3) cout << n << " ";   // as we already take care of 2 & 3, so we are not including these & directly print the remaining value.
}


int main(void){

    int n;
    cin >> n;
    primeFactors_m2(n);

    return 0;
}