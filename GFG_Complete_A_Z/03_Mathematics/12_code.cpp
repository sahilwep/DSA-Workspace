/*
// Iterative Power : 

// IDEA : 

        3^10 = 3^8 * 3^2        |   10 : 1010

        3^19 = 3^16 * 3^2 * 3^1 |   19 : 10011

                         1   0   1   0
                        3^8 3^4 3^2 3^1
                    res = 1
                    x = x*x

    * Every Number can be written as sum of power of 2(Sets bits in binary representation).
    * We can traverse all bits of a number(from LSB to MSB) in log(n) time.
    * Algo :  
     
        res = 1
        while(n>0){
            if(n%2!=0){
                // Bits are 1
            }
            else{
                // bits are 0
            }
            n = n/2;
            x=x*x;
        }   

    // TC : O(log(n))
    // AS : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

int power(int x, int n){
    int res = 1;
    while(n>0){
        if(n%2 != 0){ // or (n & 1)
            res = res*x;
        }
        x = x*x;
        n = n/2; // or n >> 1
    }
    return res;
}


int main(void){
    int x, n;
    cin >> x >> n;
    cout << power(x, n) << endl;

    return 0;
}


