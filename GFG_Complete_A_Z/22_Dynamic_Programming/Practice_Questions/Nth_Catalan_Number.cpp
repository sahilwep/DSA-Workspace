
/*

// Nth catalan number

// Observations:

    // Catalan Number: It's more like a fibonacci number...

        => 1 1 2 5 14...
        
        C0 = 1
        C1 = 1
        C2 = C0*C1 + C1*C0 = 1*1 + 1*1 = 2
        C3 = C2*C0 + C1*C1 + C0*C2 = 2*1 + 1*1 + 1*2 = 5
        C4 = C3*C0 + C2*C1 + C1*C2 + C0*C3 = 5*1 + 2*1 + 1*2 + 1*5 = 14
        
        Cn = Cn-1*C0 + Cn-2*C1 + Cn-3*C2 +.....+ C2*Cn-3 + C1*Cn-2 + C0*Cn-1


// IntrusioN:
    * Same subproblem evaluated again & again..
    * So, we will utilize this in order to get our nth catalan number..


*/

#include <bits/stdc++.h>
using namespace std;


class Solution{   
    const int mod = 1e9 + 7;
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n){
        vector<long long> t(n+1, 0);
        t[0] = 1;
        t[1] = 1;
        
        for(int i=2;i<n+1;i++){
            for(int j=0;j<i;j++){
                t[i] = (t[i] + (t[j] * t[i - j - 1]) % mod) % mod;
            }
        }
        
        return t[n];
    }
};
    

int main() {
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}