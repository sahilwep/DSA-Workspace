// print from n to 1
#include <iostream>
using namespace std;

void print(int i, int n){
    // Base condition  : when i less than 1, then it recursion stop.
    if(i<1) return;
    cout << i << " ";
    // function calling : with i-1, means it decrement the value of i for each recursion call.
    print(i-1,n);
}

int main(void){
    int n;
    cin >> n;

    print(n,n); // e.g n=5, 5,5 pass.

    return 0;
}

// TC : O(n)
// SC : O(n)