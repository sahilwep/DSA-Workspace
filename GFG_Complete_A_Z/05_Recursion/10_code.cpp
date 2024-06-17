/*
// Sum of digits using recursion

I/p: 253
O/p: 10

I/p: 9987
O/p: 33

I/p: 10
O/p: 1

// recursive tree: 
    getSum(258) -> return 15 to main control
        |--->return getSum(25) + 8 =>  7 + 8 = 15
                        |--->return getSum(2) + 5 => 2 + 5 = 7
                                        |--->return getSum(0) + 2 => 0 + 2 = 2
                                                    |---> base case hit: return 0

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int getSum(int n){
    if(n == 0){
        return 0;
    }else{
        return getSum(n/10) + (n%10);    // last digit remove & then last digit sums..
    }
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << getSum(n) << endl;
    }
    
    return 0;
}