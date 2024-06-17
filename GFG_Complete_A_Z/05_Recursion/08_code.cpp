/*
// Natural Number sum using recursion:

I/p : n = 2
O/p : 3

I/p : n = 4
O/p : 10

I/p : n = 5
O/p : 15

// TC : O(n)
// AS : O(n)

// Recursive tree:
        sumOfNatural(5) -> return 15 to main
            |--->return 5 + sumOfNatural(5) => 5 + 10 => 15
                                |--->return 4 + sumOfNatural(3) => 4 + 6 = 10
                                                    |--->return 3 + sumOfNatural(2) => 3 + 3 = 6
                                                                        |--->return 2 + sumOfNatural(1) => 2 + 1 = 3
                                                                                            |--->return 1 + sumOfNatural(0) => 1 + 0 = 1
                                                                                                                |--->base case hit: return 0


*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sumOfNatural(int n){
    if(n == 0) return 0;    // base case
    return n + sumOfNatural(n-1);
}

int main(void){
    
    int n;
    cin >> n;
    
    cout << sumOfNatural(n) << endl;
    
    return 0;
}