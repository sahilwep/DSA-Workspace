/*

//  Fibonacci Numbers - Bottom Up DP

//  Observations: 
    * We are given number n, & we need to find the nth fibonacci number.

// Intrusion: 
    * The solutions for bottom up DP, will maintain an auxilary array, which given the solution for current problem by fetching the solution from previous sub-problem:

// Example: 
    * n = 5

            [ 0 | 1 |   |   |   |   ]   -> create a table of size n+1
              0   1   2   3   4   5

        * Assign value for a[0] = 0, a[1] = 1
        * Now, generate current solution with taking previous two solution..
        * f[n] = f[n-1] + f[n-2]
            * Our Current solution depends upon the previous two solution, that is f[n-1] & f[n-2], So, we need these value to generate the current solution.


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

class Solution{
public:
    //Function to find the nth fibonacci number using bottom-up approach.
    long long findNthFibonacci(int n){
       long long arr[n + 1];
       arr[0] = 0, arr[1] = 1;
       for(int i=2;i<=n;i++){
           arr[i] = arr[i-1] + arr[i-2];
       }
       
       return arr[n];
    }
};

int main(){
    int testcases;
    cin>>testcases;
    
    while(testcases--){
        int number;
        cin>>number;

        Solution obj;
        cout<<obj.findNthFibonacci(number)<<endl;
    }
    
	return 0;
}