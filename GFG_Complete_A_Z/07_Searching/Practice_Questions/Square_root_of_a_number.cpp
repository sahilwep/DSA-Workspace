/*

//  Square root of a number

//  Observations: 
    * We are given an integer n, & we need to find the square root of that number, Then return the floor value of that
    * Floor value of given number is greatest integer which is less than or equal to that number

// Key Observations: 
    * Sqrt of 1 is 1 & 0 is 0
    * from 1 to n, we can iterate, & find (i*i <= n) , for which i it's satisfied..

// Intrusion: 
    // Method 1: 
        * Using iterative approach: O(sqrt(n))
    // Method 2:
        * Using sqrt() function: O(logn)
    // Method 3:
        * Using Binary Search: O(logn)
        * Lowe bound = 0, upper bound = n/2
        * The floor of sqrt cannot be more than n/2 when n > 1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long long int lli;
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
    // Using Binary Search:
    long long int floorSqrt(long long int n) {
        // Base case: 
        if(n == 1 || n == 0) return n;

        lli  start = 0, end = n/2;
        lli ans;
        while(start <= end){
            lli mid = (start + end) / 2;

            // If x is perfect square:
            lli sqr = mid*mid;
            if(sqr == n) return mid;

            // mid*mid is less or equal to n
            if(sqr <= n){
                start = mid + 1;
                ans = mid;
            }
            // mid*mid is greater than n
            else{
                end = mid - 1;
            }
        }

        return ans;
    }
    // Bruteforce Solutions: Iterative method O(sqrt(n))
    long long int floorSqrt_iter(long long int n) {
        // base case: 
        if(n == 1 || n == 0){
            return n;
        }

        // // Using For loop:
        // int i = 1;
        // for(i;i*i<=n;i++);
        // return i-1;


        // Using While loop:
        // Trying all the combinations of number, until it's less or equal to n
        int i = 1;
        int result = 1;
        while(result <= n){
            i++;
            result = i*i;
        }

        return i-1;

    }
    // Using sqrt() method: O(logn)
    long long int floorSqrt_Sqrt(long long int n) {
        return sqrt(n);
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}