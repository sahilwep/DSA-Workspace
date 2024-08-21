/*

// Anagram


// Observations: 
    * We are given two string, we have to check whether both the string have same frequency for each of their character..


// Intrusion: 
    // Sorting Method: 
        * We can sort the value & then compare the string..
        * TC: O(n*logn)
        * AS: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Bruteforce Solution:
    bool isAnagram(string a, string b) {
        if(a.size() != b.size()) return 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b) return 1;
        return 0;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}