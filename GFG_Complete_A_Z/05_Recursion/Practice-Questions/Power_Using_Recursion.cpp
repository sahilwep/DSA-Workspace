/*

// Power Using Recursion

// Observations: 
    * we are given two integer n & p, we have to find n^p


// Intrusion: 
    * Writing Base cases: 
        * if p == 0, we have to return 1, (because, n^0 = 1)
        * if n == 0, we have to return 0, (because, 0^anything = 0)
        * if p == 0 || p == 1 -> return n, because at every recursive call we are subtracting p by 1


// Recursive Call:

    RecursivePower(2, 5)
            |---->2 * RecursivePower(2, 4)
            |               |---->2 * RecursivePower(2, 3)
            |               |               |---->2 * RecursivePower(2, 2)
            |               |               |               |---->2 * RecursivePower(2, 1)
            |               |               |               |           | (p == 1) return n-> 2
            |               |               |               |           
            |               |               |               |----> (2 * 2) = 4
            |               |               |
            |               |               |---->(2 * 4) = 8
            |               |
            |               |---->(2 * 8) = 16
            |
            |---->(2 * 16) = 32

        * 32 return to parent call





*/

#include <iostream>
using namespace std;

class Solution{
public:
    int RecursivePower(int n,int p){
        if(p == 0) return 1;
        if(n == 0) return 0;
        if(p == 0 || p == 1) return n;
        return n * RecursivePower(n, p-1) % (1000000007);
    }
};

int main() {
	int T;
	cin>>T;     // testcase
	while(T--){

	    int n,p;
	    
	    //taking n and p as inputs
	    cin>>n>>p;
	    
	    Solution obj;
	    cout<<obj.RecursivePower(n,p)<<endl;
	}
	return 0;
}