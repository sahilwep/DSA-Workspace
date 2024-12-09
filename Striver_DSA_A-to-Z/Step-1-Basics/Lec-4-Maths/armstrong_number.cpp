#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool armstrongNumber(int n) {
        // count number of digit:
        int tDigit = log10(n) + 1;
        int res = 0;
        int temp = n;
        while(temp > 0){
            int ld = temp % 10;
            res += pow(ld, tDigit);
            temp /= 10;
        }
        
        return (res == n);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        bool flag = ob.armstrongNumber(n);
        if (flag) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}