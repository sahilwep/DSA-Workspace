/*
// Count Digits 

// Example 

    I/p : x = 9235
    O/p : 4

    I/p : x = 132
    O/p : 3

    I/p : x = 3
    O/p : 1

// Observation : 
    * The idea is to remove each digit one by one, by dividing it with 10.
    * TC : O(d), d = no of digit.


*/

#include<bits/stdc++.h>
using namespace std;

// Using division method : // TC : O(d)
int countDigit(int x){
    int ans = 0;
    while(x > 0){
        ans++;
        x = x / 10;
    }
    return ans;
}

// Using log method.    // TC : O(1)
int countDigit_1(int x){
    // using log method : 
    return int(log10(x) + 1);
}

int main(void){

    int x;
    cin >> x;
    cout << countDigit(x) <<endl;
    cout << countDigit_1(x) <<endl;

    return 0;
}