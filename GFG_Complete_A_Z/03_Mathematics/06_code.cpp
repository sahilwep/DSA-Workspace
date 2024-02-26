/*
// LCM of two numbers : 
    * LCM : Least Common Multiple : The smallest number that is divisible by both.

// Example : 

    I/p : a = 4, b = 6
        * 12 is the smallest number that is divisible by both the number.
    O/p : 12

    I/p : a = 12, b = 15
    O/p : 60

    I/p : a = 2, b = 8
    O/p : 8

    I/p : a = 3, b = 7
    O/p : 21

// Bruteforce Solution :
    * We know LCM would be grater than or equal to larger of two number.
    * using max function : max(a, b)
    * Example : 
            a = 4, b = 6
            res = max(4, 6)
            res = 6
            res = 7
            res = 8
            res = 9
            res = 10
            res = 11
            res = 12 -> return


    * Algo : 
            res = max(a, b);
            while(true){
                if(res % a == 0 && res % b == 0) return res;
                res++
            }
            return res;
    
     * TC : O(a*b - max(a, b))


// Efficient Solution : 
    * Formula :  (a*b) = gcd(a,b) * lcm(a,b)

    * Example : 
        a = 4, b = 6
        gcd = 2

        Then : lcm  = (4 * 6) / 2 

    * TC : O(log(min(a,b)))
          
*/


#include <bits/stdc++.h>
using namespace std;

// Bruteforce Solution: 
int LCM(int a, int b){
    int res = max(a, b);
    while(true){
        if(res % a == 0 && res % b == 0) return res;
        res++;
    }
    return res;
}

// Efficient Solution: TC : O(log(min(a,b)))
int LCM_Eff(int a, int b){
    return (a*b)/gcd(a,b);
}

// Euclidean for getting GCD : TC : O(log(min(a,b)))
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(void){
    int a, b;
    cin >> a >> b;

    cout << LCM(a, b) << endl;
    cout << LCM_Eff(a, b) << endl;

    return 0;
}