/*

// Anagram


// Observations: 
    * We are given two string, we have to check whether both the string have same frequency for each of their character..


// Intrusion: 
    // Sorting Method: 
        * We can sort the value & then compare the string..
        * TC: O(n*logn)
        * AS: O(n)

    // Hashing Method: 
        * We can use hashing, & Store the frequency of each character & then compare it..
        * TC: O(n)
        * AS: O(n)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Efficient Solution:
    bool isAnagram(string a, string b) {
        if(a.size() != b.size()){
            return 0;
        }
        // Using map data structure that will store the character in sorted fashion.
        map<char, int> mp1;
        map<char, int> mp2;

        for(int i=0;i<a.size();i++){
            char c = a[i];
            mp1[c]++;
        }

        for(int i=0;i<b.size();i++){
            char c = b[i];
            mp2[c]++;
        }

        // comparing both the map frequency:
        map<char, int>::iterator i = mp1.begin();
        map<char, int>::iterator iEnd = mp1.end();
        map<char, int>::iterator j = mp2.begin();
        map<char, int>::iterator jEnd = mp2.end();

        while(i != iEnd || j != jEnd){
            // compare:
            if(i->first != j->first) return 0;
            // if both the map first element is same, then we have to check for frequency:
            else{
                // checking the frequency: p
                if(i->second != j->second ) return 0;
            }
            // increment both the pointer:
            i++;
            j++;
        }
        return 1;   // means after the iteration on both the map, we have same frequency..
    }
    // Bruteforce Solution:
    bool isAnagram_(string a, string b) {
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