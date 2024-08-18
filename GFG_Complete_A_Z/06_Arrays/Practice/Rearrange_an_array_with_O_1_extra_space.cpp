/*

// Rearrange an array with O(1) extra space

// Observations: 
    * we are given an array of size n, we have to rearrange an array in a way 
    * so that it should it become arrT[i] = arr[arr[i]]
    * Note: arr & arrT both are same variable, representing array before and after transformation respectively.
    * Note: array element range lie inside the array size..
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
        * the array element is given array lie in range 0 to n-1.
        * Now array element is needed that can store two different value at the same time.
        * To achieve this every element at ith index is incremented by (arr[arr[i]] % n)* n
        * After the increment operations of the first step, every value holds both new & old values.
        * old value can be obtained by (arr[i] % n) & new value can be obtained by arr[i] / n
    
        * We are storing two values old & new values in an array, that's how we are going to obtains it in O(1) complexity..
        * Example: 
        
                    arr[] = 4 0 2 1 3       n = 5
                    idx =   0 1 2 3 4

                    final = 3 4 2 0 1

            * After this operations: arr[i] = (arr[arr[i]] % n ) * n

                    arr[0] = arr[0] + (arr[arr[0]] % 5 ) * 5
                                4   +  (3 % 5) * 5
                                4   +        3 * 5 
                                4   +   15 = 19

                    arr[1] = arr[1] + (arr[arr[1]] % 5 ) * 5
                                0   +  (4 % 5) * 5
                                0   +        4 * 5 
                                0   +   20 = 20

                    arr[2] = arr[2] + (arr[arr[2]] % 5 ) * 5
                                2   +  (2 % 5) * 5
                                2   +        2 * 5 
                                2   +   10 = 12

                    arr[3] = arr[3] + (arr[arr[3]] % 5 ) * 5
                                1   +  (0 % 5) * 5
                                1   +        0 * 5 
                                1   +   0 = 1

                    arr[4] = arr[4] + (arr[arr[4]] % 5 ) * 5
                                3   +  (1 % 5) * 5
                                3   +        1 * 5 
                                3   +   5 = 8

                        * Operational array: [19 20 12 1 8]
                
            * Now, If we divide each element by n, i.e 5 we can get the new value that we want..

                    arr[0] = arr[0] / 5
                                19 / 5 => 3

                    arr[1] = arr[0] / 5
                                20 / 5 => 4

                    arr[2] = arr[0] / 5
                                12 / 5 => 2

                    arr[3] = arr[0] / 5
                                1 / 5 => 0

                    arr[4] = arr[0] / 5
                                8 / 5 => 1


                        * New array: [3 4 2 0 1]


            * In conclusion, we can say if we perform % modulo on Operational array, we can get the original value
            * If we perform / division on Operational array, we can get the new value...


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Naive Approach:
    void arrange_(long long arr[], int n) {
        long long temp[n];
        for(int i=0;i<n;i++){
            temp[i] = arr[arr[i]];
        }

        for(int i=0;i<n;i++){
            arr[i] = temp[i];
        }

    }
    // Efficient Approach:
    void arrange(long long arr[], int n) {
        // First step: Increase all values by (arr[arr[i]]%n)*n
        for (int i = 0; i < n; i++){
            long long x = arr[i];
            long long y = arr[x];
            // arr[i] += (arr[arr[i]] % n) * n;
            arr[i] = x + (y % n) * n;

        }
    
        // Second Step: Divide all values by n
        for (int i = 0; i < n; i++){
            arr[i] /= n;
        }
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