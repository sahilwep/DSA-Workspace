/*

//  1652. Defuse the Bomb

//  Problem Statement:
    * You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

    * To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.
        * If k > 0, replace the ith number with the sum of the next k numbers.
        * If k < 0, replace the ith number with the sum of the previous k numbers.
        * If k == 0, replace the ith number with 0.

    * As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].
    * Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

// Example: 

    Example 1:
        Input: code = [5,7,1,4], k = 3
        Output: [12,10,16,13]
        Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.

    Example 2:
        Input: code = [1,2,3,4], k = 0
        Output: [0,0,0,0]
        Explanation: When k is zero, the numbers are replaced by 0. 

    Example 3:
        Input: code = [2,4,9,3], k = -2
        Output: [12,5,6,13]
        Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.

 



// Solution: 
    // Question Observations: 
        -> We are given an array, which we need to iterate on.
        -> We need to assume that array ends are connected.
        -> Then, from given condition of 'k', we can decide in which direction we need to iterate.

        -> Observations: 
            -> For Circular Array: 
                Either we can round the index with array size, if it's exceed the size
                Or we can create another temporary array of twice size of original array, & duplicate the element after the half of the size.

        -> We will understand both the solution with example:

    // Method 1: Rounding by it's size, so that we can get the accurate index in circular array:

        nums = [5,7,1,4], k = 3
        Output: [12,10,16,13]
            
            -> If index value is grater than size, we can take (index % size), which will give us valid range.

                if(k > 0):
                    -> We need to next select k element from the current index, & sore their sum in current index result.
                    [5,7,1,4]
                     0 1 2 3    -> index
                           i

                            -> We will iterate from i=0 to n,
                                -> we will iterate from current j=i+1 to (i + k);
                                -> We will get the sum of all the element from this size.
                            -> and, store sum in result.

                            -> Now, what if i = 3,
                                we need to iterate till next 3 elements, means till index (0->1->2)
                                But next i+1 = 4, which is invalid index, we need 0th index,
                                So, we will round it with array size, i.e 4 So,
                                            sum += code[j % n]

                            -> Rounding the index with array size will give us the index in range


                if(k < 0):
                    -> We need to previous select k element from the current index, & sore their sum in current index result.
                    -> k is negative, & we need to iterate back:
                    -> first make k positive so that we can access the correct index:

                    [5,7,1,4]
                     0 1 2 3    -> index
                           i

                            -> we will iterate from i=n-1 to 0
                                -> we will iterate from j=i-1 to (i - k):
                                -> We will get the sum of all the element from this size.
                            -> and, store sum in result.

                            -> Now what if i = 3,
                                we need to iterate backward to previous 3 element & get the sum of it.
                                then store it into result, 
                                Now, our k = 3, so, (i-k) => (3-3) = 0, means we will iterate till '0'
                                which is fine, because we are in range of array, but what if we exceed to negative range..
                            
                            -> What if i = 0,
                                [5,7,1,4]
                                 0 1 2 3    -> index
                                 i

                                we are at 0th index, & we need to traverse backward => (3->2->1) this is the index, from which we have to take values.
                                (j > (i-k)) = -ve => so, we will take abs(j), which will give the positive value.
                                but, if j = -1 => it will make '1', but we need to go on 4th, so we will subtract it from array size, which is n, so,
                                        sum += code(n - abs(j))

                if(k == 0):
                    -> Fill everything with '0'
                    -> Return array with default value '0'



    // Method 2: Creating Temporary array to solve this problem:

        nums = [5,7,1,4], k = 3, size = n
        Output: [12,10,16,13]

            -> Create twice size array & duplicate the second half:
            -> temp = [5,7,1,4,5,7,1,4] => Size = 2*n

                if(k > 0):
                    -> We need to next select k element from the current index, & sore their sum in current index result.
                            [5,7,1,4,5,7,1,4]
                             0 1 2 3 4 5 6 7
                                     n     2n

                        -> iterate from i=0 to i<n:
                        -> we can simply get the next k element & we will always in range.


                if(k < 0):
                    -> We need to previous select k element from the current index, & sore their sum in current index result.

                            [5,7,1,4,5,7,1,4]
                             0 1 2 3 4 5 6 7 8
                                     n      2*n
                        
                        -> Iterate form i=2*n-1 to i>n:
                        -> We can simply get the previous k values & we will always in range.


                if(k == 0):
                    -> Fill everything with '0'
                    -> Return array with default value '0'


// Complexity: 
    // Method 1:
        * TC: O(n*k)
        * AS: O(1), AS -> space required to solve particular problem, result array size is not include in this.

    // Method 2: 
        * TC: O(n*k)
        * AS: O(2n) approx O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    // Method 1:
    vector<int> decrypt_m1(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if(k > 0){
            for(int i=0;i<n;i++){
                int sum = 0;
                for(int j=i+1;j<k+i+1;j++){
                    sum += code[j % n];
                }
                res[i] = sum;
            }
        }else if(k < 0){
            k = abs(k); // making k to positive so that we can iterate in correct index.
            
            for(int i=n-1;i>=0;i--){
                int sum = 0;
                for(int j=i-1;j>=i-k;j--){
                    if(j >= 0){
                        sum += code[j % n];
                    }
                    else{
                        sum += code[n - abs(j)];
                    }
                }
                res[i] = sum;
            }
        }else{  // k == 0:
            return res;
        }

        return res;
    }

    // Method 2:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> temp = code;
        for(auto i: code) temp.push_back(i);
        vector<int> res;

        if(k > 0){
            for(int i=0;i<n;i++){
                int sum = 0;
                for(int j=i+1;j<i+k+1;j++){
                    sum += temp[j];
                }
                res.push_back(sum);
            }
        }
        else if(k < 0){
            k = abs(k); // making k to positive so that we can iterate in correct index.
            for(int i=temp.size()-1;i>=n;i--){
                int sum = 0;
                for(int j=i-1;j>i-k-1;j--){
                    sum += temp[j];
                }
                res.push_back(sum);
            }
            reverse(res.begin(), res.end());
        }
        else{   // else: k == 0:
            vector<int> temp(n, 0);
            return temp;
        }

        return res;
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> code(n);
    for(int i=0;i<n;i++) cin >> code[i];

    Solution obj;
    vector<int> res = obj.decrypt(code, k);

    for(auto i: res) cout << i << " ";
    cout << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
