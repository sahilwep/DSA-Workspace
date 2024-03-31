/*
// minimum consecutive flips
    * Minimum Group Flips to make same
    * Our task is to flip all 0's or all 1's to make array same
    * We have to flip the minimum numbers of flips for the elements in order to make this boolean array same..
    * We have to print those flips.

    I/p : arr[] = {1, 1, 0, 0, 0, 1}
    O/p : from 2 to 4
    Explanation: Here we can flip 1, which takes two flips, i.e 0->1 & 5
                 but for zeroes & we only have to perform one flips i.e 2->4, so we will take minimum flips..

    I/p : arr[] = {1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1}
    O/p : from 1 to 3
          from 5 to 6
    Explanations: For 1's we required 3 flips, but for zeroes we required only two flips, 
                so we choose to flip 0's, which will from 1->3 & 5->6

    I/p : arr[] = {1, 1, 1}
    O/p : 
    Explanation: as all the element is same,don't need to print anything..

    I/p : arr[] = {0, 1}
    O/p : From 0 to 0  OR From 1 to 1
    Explanation : numbers of flips are same, so we choose any of them..

// Naive solution
    * We start traversing from left to right
    * We count how many group's of 1 have, & we also count how many group's of 0 we have.
    * Now, we compare these groups of count...
    * We start another traversal to print the lesser number of group elements, as long as it is in array..
    * TC : O(n)

// Efficient Solution: 
    * We can solve this problem with one traversal approach
    * Fact : Only Two possibility => difference is 1 or 0 :-
        * If we count the number of groups of 0's or 1's, the difference b/w the group is at-most 1, either the counts will be the same or the difference will be one.
        * Example: 
            * These are the example, where the Group count difference is 1 : (beginning & end are same)
                        1 1 0 0 0 1 1 1 0 0 1
                            * Here 3 groups of 1's 
                            * 2 Groups of 0's
                            * Difference is 1

                        0 0 1 1 0 0 0 1 1 0 0
                            * Here 3 groups of 0's this time
                            * 2 groups of 1's
                            * Difference is 1
                            * 
                        * Also the case where all 1's or all 0's lies in this case:
                             1 1 1 1
                                 * Here group of 1's are 1
                                 * Group of 0's are 0
                                 * Difference is 1
                             0 0 0 0 
                                 * Here group of 0's are 1
                                 * Group of 1's are 0
                                 * Difference is 1
                    
                    * The reason is being simple: 
                        * Binary strings either begins with 0's or either begins with 1's.
                        * If we have the binary string begins with 1, the difference is 1, if we add 0's then difference will become 0, again if we insert some 1's difference will become 1, so this happens on a case of our insertion of 0's & 1's, but difference will only falls in range of 0 or 1.
                        * So conclusion: whatever the first set of value inside the string, & the end values of string, then the difference will become 1.
                        * If the beginning & end are not same , Down example:
            * These are the example, Group count difference is 0, that is same: (beginning & end are not same)
                        0 0 1 1 1 0 0 0 0 1 1
                        1 1 0 0 0 0 1 1 1 1 0
                            * Like in these example where beginning & ends are not same: the difference is 0.

            * From these possibility, if we make this strategy that we always flip the second group element
            * Then we will get the minimum flips.
            * Example: 
                        1 1 0 0 0 1 1 1 0 0 1
                            -----       --- 
                    * If we flip the second group's element, like in this case 0's, we will get the minimum flips..
                    * Because second group is the only group which will either have equal number of counts as the first group, or will have 1 less count.
                    * We want to minimize the flips.
                    * So, if we make a rule that whatever is the second group, we will flip those group of element always, it will either give me less count or it will give me equal count.

        * So, we traverse through the binary string, as soon as we get the different group, regardless of it's 0's or 1's, we will flip those range of groups.
        * As soon as we find the first differing element, we will flip these element everywhere, while keep on traversing & we will keep on flipping or keep on printing to this to this..
    * TC : O(n)
    

*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution: 
void maximumGroup(int arr[], int n){
    for(int i=1;i<n;i++){
        // condition to compare two distant groups element : when the element is different to the previous element.
        if(arr[i] != arr[i-1]){
            // comparing with arr[0], to move inside the second group whatever it is..
            if(arr[i] != arr[0]){
                cout << "From " << i << " to " ;
            } 
            // when arr[i] == arr[0] : this will end the range of the second element group,
            else {
                cout << (i-1) << endl; // we are printing one position before to end the range.
            }
        }
    }
    // edge case: when the first element & last element are not same: 
    if(arr[n-1] != arr[0]) {
        cout << (n-1) << endl;  // we have to print the last element.
    }
}

int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    maximumGroup(arr, n);

    return 0;
}
