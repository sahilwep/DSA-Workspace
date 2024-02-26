/*
// Sieve of Eratosthenes 
    * find the all the prime number that are smaller or equal than n.

// Example : 
    I/p : n = 10
    O/p : 2 3 7

    I/p : n = 23
    O/p : 2 3 5 7 11 13 17 19 23

// Bruteforce Solution : 
    * we can iterate from 1 to n & check all the prime number with prime function & we can print those numbers.
    * Example : 
        n = 10
            i = 2 print(2)
            i = 3 print(3)
            i = 4
            i = 5 print(5)
            i = 6
            i = 7 print(7)
            i = 8
            i = 9
            i = 10

    * TC : O(sqrt(n)* n)

// Efficient Solution : 
    * Sieve Algorithm : idea is to create a boolean array of size n+1 & store all the value as true. Once we complete this algo all the values that are prime is true and rest of them are false.

            [ | |T|T|T|T|T|T|T|T|T |T |T |T |T |T |T |T |T |T |T |...|T]
             0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20.....n

    * This algorithm marks all the composite as false : 
        * It begins with 2 & every number that we are multiple of two it marks as false.   
            2 : 4, 6, 8, 10.... 
        * Then it begins with 3 & marks every numbers of multiple of 4 as false.
            3 : 6, 9, 12, 15....
        * Then it begin with 5 & marks every numbers of multiple of 5 as false.   
            5 : 10, 15, 20, 25...
    
            [ | |T|T|F|T|F|T|F|F|F |T |F |T |F |T |F |T |F |T |F |...|T/F]
             0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20.....n

    * Approach : 
        * we can iterate from 2 to sqrt(n) & from there
        * if the list value is true, means it will never mark false so far,
        * then we mark ther multiples as false.
        * then we print the whole list from 2 to n.
    
    * Example : 
        n = 9
            [ | |T|T|T|T|T|T|T|T]
             0 1 2 3 4 5 6 7 8 9 
        i = 2 print 2
            mark 4, 6, 8 as false,
            [ | |T|T|F|T|F|T|F|T]
             0 1 2 3 4 5 6 7 8 9 
        i = 3 print 3 
            mark 6 9 as false 
            [ | |T|T|F|T|F|T|F|F]
             0 1 2 3 4 5 6 7 8 9 
        Last we print : 
            2 3 5 7

    * TC : O(n*log(log(n)))


// Improved Efficient Solution : 
    * instead of starting nested loop from 2*i, we can start with i*i
    Implementation : 
        i^2, i^2+i, i^2+2i,...
    Earlier : 
        5 : 10, 15, 20, 25, 30,....
    After : 
        5 : 25, 30...

    Composite Numbers smaller than i
        i*(i-1)
        i*(i-2)
    this will ignore the number that has previously marked as false like : 10 i.e divisible by 2 & 5 so we will can save from this.
    * Implementation : 
        * we can use prime function to check the prime number then we will print these instead of storing in array.
        * same logic as above, simply start with i*i instead of 2*i

    * TC : O(n*log(log(n)))

*/



#include <bits/stdc++.h>
using namespace std;

// Prime function : TC : Sqrt(n)
bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i++){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}


// Bruteforce Solution : TC : O(n*sqrt(n))
void checkAllPrime(int n){
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            cout << i << " ";
        } 
    }
}

// Efficient Solution :  TC : O(n*log(log(n)))
void sieve(int n){
    vector<int> primeList(n+1, true); // create an array of size n+1 & make all the value as true.
    for(int i=2;i*i<=n;i++){    // iterate loop from 2 to sqrt(n)
        if(primeList[i]){   // if the value is true then goes in the loop.
            for(int j=2*i;j<=n;j=j+i){
                primeList[j] = false;   // making all the multiples as false.
            }
        }
    }
    // for printing the true values.
    for(int i=2;i<=n;i++){  // we start printing from 2, because 2 is the first prime number.
        if(primeList[i]){   // if the value is true.
            cout << i << " "; // print the index    
        }
    }
}

// Efficient Improved Solution : TC : O(n*log(log(n)))
void sieve_Improved(int n){
    vector<int> primeList(n+1, true); 
    for(int i=2;i*i<=n;i++){    
        if(primeList[i]){  
            for(int j=i*i;j<=n;j=j+i){
                primeList[j] = false; 
            }
        }
    }
    // for printing the true values.
    for(int i=2;i<=n;i++){  // we start printing from 2, because 2 is the first prime number.
        if(primeList[i]){   // if the value is true.
            cout << i << " "; // print the index    
        }
    }
   
}

// Reduce the codes : TC : O(n*log(log(n)))
void sieve_Improved_1(int n){
    vector<int> primeList(n+1, true);
    for(int i=2;i<=n;i++){
        if(primeList[i]){
            cout << i << " ";
            for(int j=i*i;j<=n;j=j+i){
                primeList[j] = false;
            }
        }
    }
}


int main(void){
    int n;
    cin >> n;
    sieve_Improved_1(n);

    return 0;
}