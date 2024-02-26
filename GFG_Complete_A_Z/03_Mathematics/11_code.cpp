/*
// Computing Power : 
    x = 2, n = 3
    => 2^3 => 2*2*2 => 8

// Example : 
    I/p : x = 2, n = 3
    O/p : 8

    I/p : x = 3, n = 4
    O/p : 81

    I/p : x = 5, n = 0
    O/p : 1

    I/p : x = 5, n = 1
    O/p : 5

// Bruteforce Solution : 
    * TC : O(n)

// Efficient Solution : 
    * This can be done by using recursion : 
        power(x, n) =   {
                            if (n%2==0){
                                power(x, n/2)*power(x, n/2)
                            }
                            else{
                                power(x, n-1)*x
                            }
                        }

    * Example :
                x  n
            pow(3, 5)
                |
                --------->temp = pow(3, 2) = 3*3
                |                  |
                |                  ------------->temp = pow(3, 1) = 3
                |                  |                        |
                |                  |                        ------------>temp = pow(3, 0) = 1
                |                  |                        |------------>return 3
                |                  |------------>return 3*3
                --------->return (3*3)*(3*3)*3

    * Time Complexity :
        T(n) = T(n/2)+theta(1)
        recursive tree for theta(1)
            n = 16
            n = 8
            n = 4
            ....

    * TC : theta(log(n))
    * AS : theta(log(n))
*/

#include<bits/stdc++.h>
using namespace std;

// Bruteforce Solution : TC : O(n)
int getPower(int x, int n){
    int res = 1;
    for(int i=1;i<=n;i++){
        res = res*x;
    }
    return res;
}

int getPower_1(int x, int n){
    if(n==0) return 1;
    int temp = getPower(x, n/2);
    temp = temp*temp;
    if(n%2 == 0){
        return temp;
    }
    else{
        return temp * x;
    }

}



int main(void){
    int x, n;
    cin >> x >> n;
    cout << getPower_1(x, n) << endl;

    return 0;
}