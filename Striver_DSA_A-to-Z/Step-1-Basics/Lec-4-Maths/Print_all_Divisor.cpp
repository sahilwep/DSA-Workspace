/*

//  All divisors of a Number

//  Problem Statement: 
    - Given an integer n, print all the divisors of N in the ascending order.
 
// Examples:

    Input : n = 20
    Output: 1 2 4 5 10 20
    Explanation: 20 is completely divisible by 1, 2, 4, 5, 10 and 20.

    Input: n = 21191
    Output: 1 21191
    Explanation: As 21191 is a prime number, it has only 2 factors(1 and the number itself).


//  Observations:
    
     let say n = 36
            factors will be : 1, 2, 3, 4, 6, 9, 12, 18, 36
            so, 
                for 1 to be a factors, it's need to multiply by something & then it divide to n, & if condition is satisfied then it become the factor.
                same for 2, it need to multiply by something..

                n = 36

                    1      X      36        n/1
                    2      X      18        n/2
                    3      X      12        n/3     or we can say       n/i
                    4      X      9
            --------6------X------6---------- mid value ie nothing but square root, because sqrt(36) = 6
                    9      X      4
                    12     X      3
                    18     X      2
                    36     X      1
                factors         need to multiply with

        Conclusion : 
            * we can say we need to iterate the loop till sqrt(n),
            * & inside the loop we need to check for condition : for n to become factor 
                    * i.e  (n % i == 0), it this satisfied, then we can print (i) & (n/i)
        


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
  public:
    void print_divisors(int n) {
        
        set<int> st;
        for(int i = 1; i <= sqrt(n); i++) {
            if(n % i == 0) {
                st.insert(i);
                st.insert(n / i);
            }
        }
        
        for(auto i: st) cout << i << " ";
    }
};
