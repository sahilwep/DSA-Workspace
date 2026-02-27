/*

//  1404. Number of Steps to Reduce a Number in Binary Representation to One


//  Problem Statement: 
    - Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
        - If the current number is even, you have to divide it by 2.
        - If the current number is odd, you have to add 1 to it.
    - It is guaranteed that you can always reach one for all test cases.


// Example:
    Example 1: 
        Input: s = "1101"
        Output: 6
        Explanation: "1101" corresponds to number 13 in their decimal representation.
        Step 1) 13 is odd, add 1 and obtain 14. 
        Step 2) 14 is even, divide by 2 and obtain 7.
        Step 3) 7 is odd, add 1 and obtain 8.
        Step 4) 8 is even, divide by 2 and obtain 4.  
        Step 5) 4 is even, divide by 2 and obtain 2. 
        Step 6) 2 is even, divide by 2 and obtain 1.  

    Example 2:
        Input: s = "10"
        Output: 1
        Explanation: "10" corresponds to number 2 in their decimal representation.
        Step 1) 2 is even, divide by 2 and obtain 1.  

    Example 3:
        Input: s = "1"
        Output: 0


// Constraints:
    1 <= s.length <= 500
    s consists of characters '0' or '1'
    s[0] == '1'



// Observations:
    - We are given a binary string s & we need to make it '1'
    - If the decimal conversion of that number is odd then add 1, else if it's even then divide by 2
    - We need to return the number of step for which we can achieve s = "1"

    // Approach:
        - If we carefully observe:
        - Given constrains: 1 <= s.length() <= 500
        - It's useless to convert the number in decimal & then perform operations.
        - We have to do all the operations in binary:


    // Things we needed:
        - We know if we do right shift by '1' pos, then it's equivalent to divide by '2'
        - we need to know if the given binary string is even or odd.
            - if last bit is '1', means it's odd.
            - if last bit is '0', means it's even.
        - we need to find the way how we can add '1' in binary string..
            - We can write the custom function which will add the binary string with "1"
        - and we are all set..

    // Complexity:
        - TC: O(n^2)
        - SC: O(n)


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



void solve(){
    int n;
    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}