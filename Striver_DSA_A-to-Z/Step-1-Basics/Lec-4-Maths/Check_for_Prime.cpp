//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isPrime(int n) {
        if(n == 1) return 0;
        if(n == 2 || n == 3) return 1;
        if(n % 2 == 0 || n % 3 == 0) return 0;
        for(int i=5;i*i<=n;i+=6){
            if(n % i == 0 || n % (i+2) == 0){
                return 0;
            }
        }
        
        return 1;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << (ob.isPrime(N) ? "true" : "false") << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}