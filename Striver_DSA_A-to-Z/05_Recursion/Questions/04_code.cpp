// print 1 to n, without using (i+1,n)

/*
    Backtracking : The statement that executed, when the recursion hit return case, & it returning, so order of printing the values in backward manner.
*/

#include <iostream>
using namespace std;

void print(int i, int n){
    // Base condition
    if(i<1) return;
    // function call
    print(i-1,n);
    // statement after the function call will execute when the base condition hit, and it return,
    // this we can say Backtracking.
    cout << i << " ";
}

int main(void){
    int n;
    cin >>n;
    print(n,n);

    return 0;
}