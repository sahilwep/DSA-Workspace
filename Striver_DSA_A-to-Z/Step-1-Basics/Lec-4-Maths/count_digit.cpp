#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        int cnt = 0;
        int temp = n;
        while(n > 0){
            int ld = n % 10;
            // check ld is not 0, & then check valid divisibility...
            if(ld != 0 && temp % ld == 0) cnt++;
            
            n = n / 10;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends