/*
// Print N to 1 Using Recursion


// TC : O(n)
// AS : O(n)


*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void func(int n){
    if( n == 0) return;
    cout << n << endl;
    func(n-1);
}


int main(void){
    
    func(10);
    
    return 0;
}