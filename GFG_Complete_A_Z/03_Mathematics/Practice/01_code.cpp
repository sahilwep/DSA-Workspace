/*
// Absolute Value : 

Input:
I = -32
Output: 32
Explanation: 
The absolute value of -32 is 32.

Input:
I = 45
Output: 45
Explanation: 
The absolute value of 45 is 45 itself.

// Observations : 
    * If we multiply any -ve number with (-1), it will make it positive.


*/

#include <bits/stdc++.h>
using namespace std;

int abs(int x){
    if(x >= 0){
        return x;
    }
    else{
        return x*(-1);
    }
}

int main(void){
    int x;
    cin >> x;
    cout << abs(x) << endl;

    return 0;
}