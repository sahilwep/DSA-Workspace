/*
    count no of digit :
        e.g : 1234 => 4 digits
        e.g : 123456 => 6 digits
    solution : we can use counter : make counter = 0, and at every extraction of digit increment the counter value.
*/

#include <bits/stdc++.h>
using namespace std;

// optimal solution : 
    // (log10(n) + 1) => will give the no of digits.

int main(void){
    int n;
    cin >> n;
    cout << int(log10(n)+1);

    return 0;
}
// TC : O(log(N))

/*
// bruteforce solution : 
int main(void){
    int n;
    cin >> n;
    int count = 0;
    while (n>0){
        n = n/10;
        count++;
    }
    cout << count;
    return 0;
}
// TC : O(log(N))
*/