
/*
    we will need to find that the given input is prime no or not ?
    NOTE : A number that has only 2 factors & it is divisible by 1 & itself, that no is prime no.

    Solution :  
        * We need to find the factors,
        * then we can count the factors, & if it is equal to 2, that means number is prime
    * Bruteforce approach :
        * we can iterate the loop till n & check for the factor condition.
        * if the condition is satisfied we will increase counter.
        * and at last we will check that if, counter is == 2, then the number is prime.
        * else not
        * TC : O(n)
    * Optimal Solution : 
        * by previous TC : O(n), we know that for finding factors, we can use "sqrt()" methods
        * we can use square root method to get all the factors.
        * we know that using square root method i.e iterating loop til "i<=sqrt(n)" we can find all the factors
            * by using the condition to for factors, & inside we can increase counter for i & (n/i)
        * last we can check the condition for (counter == 2), if it's satisfied, then print the prime.
        * TC : O(sqrt(n))
*/

#include <bits/stdc++.h>
using namespace std;

int main(void){

    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i*i<=n; i++){
        if(n % i == 0){
            cnt++;
            if(n/i != i){
                cnt++;
            }
        }
    }
    if(cnt == 2){
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;
}