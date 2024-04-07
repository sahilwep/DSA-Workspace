/*
// Equilibrium Point: 
        * A point is known as equilibrium point if the sum of element before it Sum of element after it is same.


    I/p : arr[] = {3, 4, 8, -9, 20, 6}
                   -----------  eq  --
                       left sum = right sum
                              6 = 6
    O/p : True


    I/p arr[] = {4, 2, -2}
                    -----
        left sum = right sum
               0  =  0
    O/p : True
    
    I/p arr[] = {4, 2, 2}
    O/p : False

// Naive Solution: 
    * We can use nested loop, outer loop from i = 0 to n
        * Inner loop will compute the left side sum of i
        * Inner loop will compute the right side sum of i
        * if it's equal we return true : return false
    
    * Example: 
            arr[] = {3, 4, 8, -9, 9, 7}
            i = 0, ls = 0, rs = 19;
            i = 1, ls = 3, rs = 15
            i = 2, ls = 7, rs = 7,          return true


    * TC : O(n^2)
    * AS : O(1)

// Better Solution: 
    * Basic Idea for efficient Solution: 
            arr[] = {3, 4, 8, -9, 9, 7}
        * Compute Prefix Sum:

               ps[] = {3, 7, 15, 6, 15, 22}

        * Compute Suffix Sum:                   (Suffix sum : is the sum of element from right side...)
         
               ss[] = {22, 19, 15, 7, 16, 7}

        * For every element (expect corner once), check if ps[i-1] is same as ss[i+1]
          
            * Corner Case: We have to take care of edge case to make equilibrium point: 
                    * For first element, we have to check if the "suffixSum[1] == 0" or not
                            * Because, When our iterator is at the first element of suffix sum array, 
                            * the left side part of it is "0" for case to become equilibrium point...
                            * So, the Right side part of it should also be "0" for case to become equilibrium point...
                            * This is why we are checking "SuffixSum[1] == 0" 
                        
                    * For last element, we have to check if the "prefixSum[n-2] == 0" or not
                            * Because, When our iterator is at the last element of prefix sum array, 
                            * the right side part of it is "0" for case to become equilibrium point...
                            * So, the left side part of it should also be "0" for case to become equilibrium point...
                            * This is why we are checking "prefixSum[n-2] == 0" 

    * Here, TC: O(n), AS: O(n)
    * We can further optimized this solution...

// Optimal Solution: 
    * Idea is to compute the total sum, traversing from left to right..
    * While traversing we can store the prefix sum in single variable by adding every element one by one...
    * Suffix sum we can get by Subtracting the prefix sum from the individual element that we crossed..
    
    * Example:  
                arr[] = {3, 4, 8, -9, 9, 7}
                rs = 22, ls = 0
                i = 0: ls = 0, rs = 19
                i = 1: ls = 3, rs = 15
                i = 2: ls = 7, rs = 7       : return true 


    * TC : O(n)
    * AS : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

// Optimal Solution: 
bool ePoint(int arr[], int n){
    int rs = arr[0];
    for(int i=1;i<n;i++){
        rs += arr[i];
    }
    int ls = 0;
    for(int i=0;i<n;i++){
        rs -= arr[i];
        if(ls == rs) return true;
        ls += arr[i];
    }
    return false;
}

// Better Solution: TC: O(n), SC: O(n)
bool ePoint_1(int arr[], int n){
    // Pre-computation of Prefix Sum:
    int ps[n];
    ps[0] = arr[0]; 
    for(int i=1;i<n;i++){
        ps[i] = arr[i] + ps[i-1];
    }
    // Pre-computation of Suffix Sum:
    int ss[n];
    ss[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        ss[i] = ss[i+1] + arr[i];
    }

    // // Printing Prefix sum & Suffix Sum for debugging
    // cout << endl << "ss : ";
    // for(int i=0;i<n;i++) cout << ps[i] << " ";
    // cout << endl << "ps : ";
    // for(int i=0;i<n;i++) cout << ss[i] << " ";
    // cout << endl ;

    for(int i=0;i<n;i++){
        // cout << ps[i] << " " << ss[i] << endl;   // print for debugging
        // edge case of suffix sum
        if (i == 0) {
            if (ss[i + 1] == 0) return true;
        } 
        // edge case prefix sum
        else if (i == n - 1) {
            if (ps[i - 1] == 0) return true;
        } 
        // case of equilibrium element
        else {
            if (ps[i - 1] == ss[i + 1]) return true;    
        }
    }
    return false;
}


// Naive Solution: 
bool ePoint_0(int arr[], int n){
    for(int i=0;i<n;i++){
        int ls = 0, rs = 0;
        // compute left side sum:
        for(int j=0;j<i;j++){
            ls = ls + arr[j];
        }
        // compute right side sum:
        for(int j=i+1;j<n;j++){
            rs = rs + arr[j];
        }
        if(ls == rs) return true;
    }
    return false;
}   

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        (1 == ePoint(arr, n)) ? cout << "True" << endl : cout << "False" << endl ;
    }
    return 0;
}