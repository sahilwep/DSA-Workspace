/*

// Kth Smallest

// Observations: 
    * We have to find the kth smallest number from an array


// Intrusion: 
    * We can use set or map data structure to store the values..
    * Then we can iterate till k, & return the element if there exist, else return -1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        map<int, int> mp;   // using map data structure..
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for(auto i=mp.begin();i!=mp.end();i++){
            if(k == 1){
                return i->first;
            }
            k--;
        }
        
        return -1;
    }
};


int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}