/*

// Rearrange an array with O(1) extra space

// Observations: 
    * we are given an array of size n, we have to rearrange an array in a way 
    * so that it should it become arrT[i] = arr[arr[i]]
    * Note: arr & arrT both are same variable, representing array before and after transformation respectively.
    * Example Observations: 

    Input:  N = 5   arr[] = {4,0,2,1,3}
    Output: 3 4 2 0 1
    Explanation: 
        arr[arr[0]] = arr[4] = 3
        arr[arr[1]] = arr[0] = 4
        arr[arr[2]] = arr[2] = 2
        arr[arr[3]] = arr[1] = 0
        arr[arr[4]] = arr[3] = 1
        and so on
        So, arrT becomes {3, 4, 2, 0, 1}

// Intrusion: 
    * Naive Approach: 
        * We can use O(n) space auxilary array to store array elements & then we can perform all of these operations...
    
    * Efficient Approach:



*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Naive Approach:
    void arrange(long long arr[], int n) {
        long long temp[n];
        for(int i=0;i<n;i++){
            temp[i] = arr[arr[i]];
        }

        for(int i=0;i<n;i++){
            arr[i] = temp[i];
        }

    }
    // Efficient Approach:
    void arrange_(long long arr[], int n) {

    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        long long A[n];

        for(int i=0;i<n;i++)  cin>>A[i];

        Solution ob;
        ob.arrange(A, n);
        
        for(int i=0;i<n;i++)  cout << A[i]<<" ";
        cout<<endl;
    }
    return 0;
}