/*

//  Roof Top

//  Observations: 
    * We are given the height of consecutive building, we can move from the height of building to the consecutive building..
    * We need to find the maximum number of consecutive steps we can put forward such that our gain in increased altitude with each steps.


// Example:


    Input: arr[] = [1, 2, 2, 3, 2]
    Output: 1
    Explanation: 
        1, 2, or 2, 3 are the only consecutive buildings with 
        increasing heights thus maximum number of consecutive steps
        with an increase in gain in altitude would be 1 in both cases.

    Input: arr[] = [1, 2, 3, 4]
    Output: 3
    Explanation: 
        1 to 2 to 3 to 4 is the jump of length 3 to have a maximum 
        number of buildings with increasing heights, 
        so maximum steps with increasing altitude becomes 3.


// Intrusion: 
    * we can iterate in an array, & compare the adjacent elements, if current element is grater than previous element, 
    * we can increment the counter, else if it's equal or smaller, we will assign counter = 0, 
    * at the end of every iterations, we will store the 

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007

class Solution {
public:
    int maxStep(vector<int> arr) {
        int res = 0;
        int cnt = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i] > arr[i-1]) cnt++;
            else cnt = 0;
            res = max(res, cnt);
        }

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}