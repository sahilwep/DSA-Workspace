/*
// Convert Celsius to Fahrenheit : 

// Examples :

Input:
C = 32
Output: 89
Explanation: Using the conversion 
formula of celsius to fahrenheit , it
can be calculated that, for 32 degree
C, the temperature in Fahrenheit = 89.

Input:
50
Output: 122
Explanation: Using the conversion 
formula of celsius to fahrenheit, it
can be calculated that, for 50 degree
C, the temperature in Fahrenheit = 122.


// Observation : 
    * formula : F = ( 9/5 * C ) + 32
                    ( 1.8 * C ) + 32

*/

#include<bits/stdc++.h>
using namespace std;

double cToF(int C){
    return ((C * 1.8) + 32);
}

int main(void){

    int c;
    cin >> c;
    cout << floor(cToF(c)) << endl;


    return 0;
}