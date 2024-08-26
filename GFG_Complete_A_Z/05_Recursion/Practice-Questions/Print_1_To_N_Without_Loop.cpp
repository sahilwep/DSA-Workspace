/*

// Print 1 To N Without Loop

// Observations: 
    *  we are given integer n, & we have to print number from 1 to n.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void printNos(int n){
        if(n == 0) return;
        printNos(n-1);
        cout << n << " ";
    }
};

int main(){
    int T;
    cin>>T;
    
    while(T--){
        int N;
        cin>>N;
        Solution ob;
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}