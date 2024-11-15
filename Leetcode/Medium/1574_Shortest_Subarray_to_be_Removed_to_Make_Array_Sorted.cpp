/*

// 1574. Shortest Subarray to be Removed to Make Array Sorted


//  Problem Statement: 
    * Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
    * Return the length of the shortest subarray to remove.
    * A subarray is a contiguous subsequence of the array.

// Example:

    Example 1:

        Input: arr = [1,2,3,10,4,2,3,5]
        Output: 3
        Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
        Another correct solution is to remove the subarray [3,10,4].

    Example 2:

        Input: arr = [5,4,3,2,1]
        Output: 4
        Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].

    Example 3:

        Input: arr = [1,2,3]
        Output: 0
        Explanation: The array is already non-decreasing. We do not need to remove any elements.


//  Visualization: 

        Example:
            arr = [1,2,3,10,4,2,3,5]    Output: 3
                    
                    1 2 3 |10 4 2| 3 5
                          -------       -> remove this subarray -> 3 size
                    
                    1 2 3 3 5 -> Sorted
                
                OR  
                    1 2 |3 10 4| 2 3 5
                        -------         -> remove this subarray -> 3 size

                    1 2 2 3 5 -> Sorted

                Observations:

                        1 2 3 10 | 4 | 2 3 5
                        --------      ------
                    
                    -> In this array these two parts are sorted, if we remove '4', is the entire array sorted ?

                        1 2 3 | 10 | 2 3 5
                    
                    -> Now this time '10' is what which is restricting our array to be sorted, let's remove this one also

                        1 2 3 | 2 | 3 5        OR      1 2 | 3 | 2 3 5

                    -> Again we have '2' OR '3' which is restricting our array to be sorted, let's remove any one of them.

                        1 2 3 3 5   -> We have removed '2', & after that our array is sorted
                    
                    -> In total we have removed 3 elements, means 3 size subarray which needs to be removed.
                

                    -> IF we carefully observe , the last portions after the subarray is sorted..

                        1 2 3 10 4 | 2 3 5
                                   -------
                        
                        -> If we have find this portions first & then compare it with starting sorted portions we may calculate the elements which need to be removed.
                        -> and during computations of the element which needs to be removed, we can find the subarray size which needs to be removed.



                    // Let's Analyze this by using two pointers:
                        -> We have think to use two pointer because we need to find contigious window in our array, & this window can be found from starting & ending of an array.
                        -> Come to intrusion:

                        1 2 3 10 4 | 2 3 5
                        i            j

                            j = This pointer identifies, element after that pointer are sorted.
                            i = Starting pointer, which we have to move, by comparing with 'j' pointer
                        


                    // How do we find 'j' pointer:
                        -> we can iterate from backward with condition => (arr[j] >= arr[j-1])
                        -> we need to keep our j pointer in bound, so we will use =>  (j > 0)

                            while(j > 0 && (arr[j] >= arr[i-1])) j--;



                    // Now we have to look on 'i' pointer & compare it with 'j' pointer & move 'i' & 'j' accordingly so that we can find minimum size subarray which we need to remove.
                        -> we will check (arr[i] <= arr[j]) & move our 'i', 
                        -> because we are sure that elements from 'j' are sorted, & if 'arr[i]' is smaller than 'arr[j]', 
                        -> This means our array is sorted, & then we move our 'i' pointer forward to find next possibility.

                            0 1 2 3  4   5 6 7  -> index
                            1 2 3 10 4 | 2 3 5  -> array
                            i            j
                                    (arr[i] <= arr[j]) yes -> move i to find next possibility       => subarray_size = j-i-1 = 5-0-1 = '4'
                                    (arr[i] >= arr[i-1]) we have move i forward only because this conditions satisfied


                            0 1 2 3  4   5 6 7  -> index
                            1 2 3 10 4 | 2 3 5  -> array
                              i          j
                                    (arr[i] <= arr[j]) yes -> move i to find next possibility       => subarray_size = j-i-1 = 5-1-1 = '3'
                                    (arr[i] >= arr[i-1]) we have move i forward only because this conditions satisfied


                            0 1 2 3  4   5 6 7  -> index
                            1 2 3 10 4 | 2 3 5  -> array
                                i        j
                                    (arr[i] <= arr[j])  NO,
                                     NO case: -> this time we will try to move 'j' & find element that satisfy: (arr[i] <= arr[j])



                            0 1 2 3  4   5 6 7  -> index
                            1 2 3 10 4 | 2 3 5  -> array
                                i          j
                                    (arr[i] <= arr[j]) yes, -> move i to find next possibility      => subarray_size = j-i-1 = 6-2-1 = 3
                                    (arr[i] >= arr[i-1]) we have move i forward only because this conditions satisfied



                            0 1 2 3  4   5 6 7  -> index
                            1 2 3 10 4 | 2 3 5  -> array
                                  i        j
                                    (arr[i] <= arr[j]) NO,
                                     NO case: -> this time we will try to move 'j' & find element that satisfy: (arr[i] <= arr[j])
                            


                            0 1 2 3  4   5 6 7  -> index
                            1 2 3 10 4 | 2 3 5  -> array
                                  i          j
                                    (arr[i] <= arr[j]) NO,
                                     NO case: -> this time we will try to move 'j' & find element that satisfy: (arr[i] <= arr[j])




                            0 1 2 3  4   5 6 7 8   -> index
                            1 2 3 10 4 | 2 3 5    -> array
                                  i            j
                                    'j' is out of bound, so loop will break.
                                    also we if we saw, we can delete all the elements after 'i', & if we calculate size -> subarray_size: j-i-1 = 8-3-1 = 4

                            
                            Also, we can't move forward 'i', because till now, (arr[i] >= arr[i-1]) this condition satisfied.
                            So, we will breakout from the loop


                            We will take subarray_size minimum from all of the possibilities.
                        

                        -> In Conclusion:

                                First we have find 'j'

                                    1 2 3 10 4 | 2 3 5  
                                                 j
                                
                                Then we have moved i from 0th index till the index if(arr[i] >= arr[i-1]) this condition satisfied.
                            
                                    1 2 3 10 4 | 2 3 5  
                                    |------|     j
                                        i
                                      range

                                'i' can move in this range, from '1' to '10', because this condition (arr[i] >= arr[i-1]) satisfied.

                                lastly 'j' is moved forward, if this condition is not satisfied: (arr[i] <= arr[j])

                                and for every valid condition of (arr[i] <= arr[j]), we will calculate subarray size by: (j-i-1)

                                TC: O(n), because we haven't visit any element twice.

                        -> These types of question can be solved easily if we draw the hill diagram of inputs:

                                    1 2 3 10 4 | 2 3 5  




                                    10            |
                                    9             |
                                    8             |             
                                    7             |             
                                    6             |
                                    5             |           |    
                                    4             |  |        |    
                                    3          |  |  |     |  |     
                                    2       |  |  |  |  |  |  |  
                                    1    |  |  |  |  |  |  |  |  
                                         1  2  3  10 4  2  3  5


// Edge case:
    -> It may be possible that given array is in increasing or decreasing order.


    -> Given elements are in increasing order:
    
                1 2 3
                    j

            while(j > 0 && arr[j] >= arr[j-1) j--;

                1 2 3
                j
                Now this time j is at 0th index.
            
            And while loop for 'i', we were starting from (i = 0) & first condition of while loop is: (i < j) -> So this while loop never executes.

            and we have return res = 'n' in our answer which is wrong, because whole array is sorted


            So, if we have apply this check before going for 'i'
                if(j == 0) return 0 // means no element need to remove.
            our job will be done.
            

    -> Given elements are in decreasing order:

                while(i < j && i == 0 || arr[i] >= arr[i-1]) -> we will go in this loop, because (i < j && (i == 0)) executes
            
            3 2 1
            i   j

                j is at n-1 index
                while(j > 0 && arr[i] > arr[j) j++;  -> move j pointer forward
                now j is at nth index

            3 2 1
            i     j
            0 1 2 3

                Now calculate subarray_Size (j-i-1) = 3-0-1 = '2'
                two elements should be removed to make array sorted
                3 2 1 -> if we remove two elements from array then, it's sorted 
        
        So, this condition handles carefully, with the given condition.

    -> Conclusion: 
        we need to apply if(j == 0) return 0; before going to check for 'i' pointer.
    

    -> Another Case: When we reach to 'j', it may be possible before that all the elements needs to be removed.

                5 2 1 3 4
                    -----
                    sorted

                [5 2] 1 3 4
                 i    j

                      before j all the elements needs to be removed.

                Checks:

                    [5 2] 1 3 4
                     i    j
                            (arr[i] > arr[j]) -> move j


                    [5 2] 1 3 4
                     i      j
                            (arr[i] > arr[j]) -> move j


                    [5 2] 1 3 4
                     i        j
                            (arr[i] > arr[j]) -> move j
                    

                    [5 2] 1 3 4
                     i          j
                     0 1  2 3 4 5
                            Now, iteration is over for 'j', now we will find subarraySize: j-i-1 = 5-0-1 = '4' -> store this into result

                    
                    Now check i can be move forward or not?
                        while(i < j && (i == 0 || arr[i] >= arr[i-1])) -> yes, because (i == 0)
                    
                        [5 2] 1 3 4
                           i        j

                        while(i < j && (i == 0 || arr[i] >= arr[i-1])) -> NO, because second "AND" not satisfied
                    
                    
                    And our result is '4', which is not the correct answer.

                
                // Observations:
                    First we were finding 'j' index,
                            5 2 (1 3 4)
                                 j
                    and elements from j are already sorted.

                    So, if we have removed element before jth array will be in sorted order...

                    So, instead of assigning "res = n", we will assign (res = j), because in worse case, j will be returned, if ith not found.
                                
                                5 2 (1 3 4)
                                     j
                                0 1  2 3 4
                            
                            -> j is returned, '2', means two elements needs to be removed to make our array sorted.
                    
                    So, "res = j"
                    



// Complexity:
    * TC: O(n)  -> no element visit twice.
    * AS: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr){ 
        int n = arr.size();

        // Step 1: First find the jth pointer from right hand side
        int j = n-1;
        while(j > 0 && arr[j] >= arr[j-1]){     // j should be in bound && current element is grater equal to previous one -> move 'j' towards left.
            j--;
        }

        int i = 0;  // initializing ith pointer
        int res = j;    // assumption we are making in worse case removing all element left to index j because index j to n-1 are sorted.


        // Step 2: start finding correct i and j and find deleted elements (j-i-1)
        while(i < j && (i == 0 || arr[i] >= arr[i-1])){     // (i < j) will make sure i should be remains in bound, and (i == 0) means when we are at 'i = 0' first index we want to enter in loop & check the conditions, (arr[i] >= arr[i-1]) this condition specify that we need increasing order of 'i'

            
            // When this condition (arr[i] > arr[j]) hit, we will have to move j pointer forward, so that we can check for further possibility.
            while(j < n && arr[i] > arr[j]){    // (j < n) will make sure j should be in bound of array while moving forward.
                j++;    // incrementing jth pointer forward
            }

            // When we reach here that means:
            // We have found the correct jth element such that (arr[i] <= arr[j])
            res = min(res, (j - i - 1));    // storing the size of subarray that should be removed, & taking minimum from all the possibilities.
            i++;    // last incrementing ith pointer, because we are inside loop, means (arr[i] > arr[i-1]), and we can check for further possibilities.
        }

        return res;
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    Solution obj;
    cout << obj.findLengthOfShortestSubarray(arr) << endl;
    
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}