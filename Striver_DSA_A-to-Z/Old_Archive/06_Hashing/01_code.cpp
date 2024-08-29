/*
// Hashing :  

// problem :
    * problem with array : 
        * if we have a array :  1 2 1 3 2
        * if we want to find the frequency of an element 1 : 
            * for finding the frequency of element 1, we have to iterate the loop from 0 to n,
            * with using the condition : (arr[i]==1) we can find the element in array :
            * also, after that we have to use the counter, that how many times the element is occurring in the list.
            * TC : O(n)
        * if we want to find the frequency of an element 2 : 
            * for finding the frequency of element 2, we have to iterate the loop from 0 to n,
            * same steps we will be doing here, as we do in previous case.    
            * TC : O(n)
        .........
        .........
        * if we want to find the frequency of an element 10092:
            * for this also, we have to iterate the loop till n, & check for each element.
            * TC : O(n)
        
        * If we want to compute for "Q" number of element to find the frequency in array of element "N" 
        * Then in this case the TC : O(QxN), and this will be taking the more time than we expect : 
        * suppose : Q is 10e5 & N is 10e5,
            * we have to compute for the O(10e5 x 10e5) = (10e10), which is huge number :
            * NOTE : (for operation 10e8 =~ 1 sec) it takes : 
            * So, for 1 operation : 1/10e8
                * for 10e10 operation => 10e10/10e8 => 10e2 => 100 sec.
                    * So, 100 sec is approx : 2 min, 
                    * we can't wait for 2 min to execute the code.
                    * this is why we use the concept of hashing.s
        * Hashing solve this issue :
// Hashing : 
    * first we create the hash array of size : the maximum element present in array :
        * in our case : 1 2 1 3 2 :     (maxElement is 3)
        * we will create the hash array of size 3
    * then we will assign all the hashArray element to be "0", in beginning.
    * then we perform the pre-storing/fetching
    * In precalculation : 
        * we will update our hash array, by looking the element in array : 
        *   eg :    array[] : 1 2 1 3 2
                    Hash[]  : 0 0 0 0       (initially) 
                    index   : 0 1 2 3    
                * we will iterate array[]
                    * at index 0 of array[] we found 1(element)
                        * Update : hash[] : 0 1 0 0 
                    * at index 1 of array[] we found 2(element)
                        * Update : hash[] : 0 1 1 0
                    * at index 2 of array[] we found 1(element)
                        * Update : hash[] : 0 2 1 0
                    * at index 3 of array[] we found 3(element)
                        * Update : hash[] : 0 2 1 1 
                    * at index 4 of array[] we found 2(element)
                        * Update : hash[] : 0 2 2 1
                         
                * AT FINAL : our hash[] :   0  2   2   1  
                                 index  :   0  1   2   3
                * so at a single pre-computation : we compute the frequency of an array,
                * and we mapped it with the indexing.
        * For Fetching, we can directly fetch it with the index.
            * eg : how many times element (x=2) appear in array : hash[x] : 2(fetch) 
            * eg : how many times element (x=3) appear in array : hash[x] : 1(fetch) 
            * eg : how many times element (x=1) appear in array : hash[x] : 2(fetch) 
            * eg : how many times element (x=5) appear in array : hash[x] : not appear in array : error. 
            * eg : how many times element (x=0) appear in array : hash[x] : 0(fetch)
// Observation :
    * for array, we to perform the pre-computation, then we can fetch the frequency.

// logic : 
    * eg : array[5] :   1   2   3   2   1       : size {n}
            index   :   0   1   2   3   5
            hash[3] :   0   0   0   0   0 (initially) (size = 3, because the max element is 3) 

    * for(i=0;i<n;i++){
        hash[arr[i]] = hash[arr[i]] + 1;    
    }
        * for i = 0 -> arr[i] = 1 => So, hash[1] = hash[1] + 1;
                                         hash[1] =   0     + 1; 

        * for i = 1 -> arr[i] = 2 => So, hash[2] = hash[2] + 1;
                                         hash[2] =   0     + 1; 

        * for i = 2 -> arr[i] = 3 => So, hash[3] = hash[3] + 1;
                                         hash[3] =   0     + 1; 

        * for i = 4 -> arr[i] = 2 => So, hash[2] = hash[2] + 1;
                                         hash[2] =   1     + 1;     (previously the value is 1, so we are adding it with 1 to make it 2) 

        * for i = 5 -> arr[i] = 1 => So, hash[1] = hash[1] + 1;
                                         hash[1] =   1     + 1;     (previously the value is 1, so we are adding it with 1 to make it 2) 

                * Updated Hash[] : { 0   2    2   1}
// NOTE : 
    * we know that the maximum element is : 3, so there is no need to find the maxElement, but you need to find the maxElement before performing the pre-computation.
    * we can assign all the element as "0" in hash, by doing (int hash[size] = {0})

* TC : O(n)   


// input : 
1   // test case 
5   // size
1 2 3 2 1   // array
4   // query times
1   // q1
2   // q2
3   // q3
6   // q4

// output : 
2
2
1
0

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
    void findFrequency(int arr[], int n){
        int q;
        cin >> q;   // taking the number of query. 
        int hash[4] = {0};    // creating the hash array of size 3(since, the maxElement is 3).
        // pre-computation :
        for(int i=0;i<n;i++){
            hash[arr[i]] = hash[arr[i]] + 1;
        }
        // fetching  :
        while(q--){
            int num;
            cin >> num;
            cout << hash[num] << endl;
        }
    }
};

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        Solution obj;
        obj.findFrequency(arr, n);
    }

    return 0;
}