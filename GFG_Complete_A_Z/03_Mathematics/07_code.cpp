/*
// Check for Prime : 2, 3, 5, 7, 11, 13, 17, 19....
    * Numbers that are divisible by 1 & only itself : we considered as prime
    * '2' is the only even prime number, rest of the even number are not prime.
    * 1 is not the prime number, as it has only one factor.
    * The number that is not prime, considered as composite numbers.

// Examples : n > 0

    I/p : n = 13
    O/p : Yes

    I/p : n = 14 
    O/p : No

    I/p : n = 101
    O/p : Yes

// Bruteforce Solution :        TC : O(n)
    * Method 1 : we are using counter, & counting only 2 value if only two factors of numbers exist, we say prime.
    * Method 2 : We are checking numbers b/w 2 to n-1, as we separate (1 & n), if any number able to divide we say not prime.

// Efficient Solution :         TC : O(sqrt(n))
    * Idea for Efficient Solution : Divisors always appears in pairs.   
    * Example : 

        30 : (1, 30), (2, 15), (3, 10), (5, 6)
        65 : (1, 65), (5, 13)  
        25 : (1, 25), (5, 5)

    * If (x, y) pair, we can say :  
                (x * y) = n
    * And if (x <= y), we can say : 
                (x * x) <= n
                      x <= Sqrt(x)
    * The ideas is to traverse the number from 2 to sqrt(n), we we find any divisor we say not prime, else prime.
    * Example : 
                n = 65
                        i = 2       
                        i = 3       
                        i = 4       
                        i = 5       
                n = 37
                        i = 2
                        i = 3
                        i = 4
                        i = 5
                        i = 6

    *        i*i <= n   <==>  i<= sqrt(n)


// more Efficient Solution : 
    * Values of i for large n.
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18....Sqrt(n)


    * we can eliminate the number that are divisible b/y 3 & 2 for large iteration of n.
    * By checking (n%2==0) & (n%3==0), we can save many iterations.
    * after removing from the list : we have to check : 
    
    5, 7, 11, 13, 17, 19,.....sqrt(n) 

    * we can start loop from 5 till sqrt(n) & increment with (i=i+6)
    * we only have to check this condition inside the loop.
                 if(n%i==0 || n%(i+2)==0) return false;

    * Example  :
               n = 121
                    i = 5
                    i = 11

               n = 1031
                    i = 5
                    i = 11
                    i = 17
                    i = 23
                    i = 29
                Note : 35 * 35 = 1225, which is more than 1031.

    * TC : O(sqrt(n))
    

*/


#include <bits/stdc++.h>
using namespace std;

// Bruteforce Solution : TC : O(n)
bool isPrime(int n){
    if(n == 1) return false;    // as 1 is not prime
    int cnt = 0;    
    for(int i=1;i<=n;i++){
        if(n % i == 0) cnt++;
        if(cnt == 3) return false;
    }
    return true;
}

// Bruteforce Method 2 : Checking b/w 2 & that n-1
bool isPrime_m2(int n){
    if(n == 1) return false;
    for(int i=2;i<n-1;i++){
        if(n%i == 0) return false;
    }
    return true;
}

// Efficient Method : 
bool isPrime_m3(int n){
    if(n == 1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

// More Efficient Method :
bool isPrime_m4(int n){
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i =5;i*i<=n;i=i+6){
        if(n%i==0 || n%(i+2)==0) return false;  // i & i + 2 combinations are the once that we have to check, after cancelling 2 & 3's multiples..
    }
    return true;
} 


int main(void){

    int n;
    cin >> n;
    if(isPrime_m4(n) == 1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

