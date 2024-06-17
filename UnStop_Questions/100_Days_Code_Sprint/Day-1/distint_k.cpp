/*

Kth unique element:         https://unstop.com/code/challange-asesment/250739?moduleId=372

// Observations: 
    * We have to find the kth unique element in an array of string...
    * If kth element does't exist, return empty string "", 
    * else return the element..

// Bruteforce Solution: 
    * TC : O(n^2)
    * Intrusion:    
        * We will  start selection each element & iterate throughout the array, 
            * if we able to found the element, we will break out from inner loop, & increase outer pointer..
            * Else if we are not able to found the element till nth index of inner pointer, we will increment the temp_counter by 1
                * & we will match with kth number, we return the pointed number of that index.
            * After the traversal of outer array, if we are not able to found that element, we will return empty string..


// Efficient Solution: 
    * TC : O(n)
    * Intrusion:
        * We will use hashmap to store the frequency of every element(let say freqMap ).
        * we will use another array(let say uniqueString) to store the order of element, it will only store all the element only times, means repeating value will not be store..
        * once we have these two data, we can start checking...
            * we will start iterating in uniqueString from 0 to their size..
            * We will initialize uniqueCounter
            * We will select every element & start checking in freqMap , whether it contains only one element or not,(avg TC of finding in element in unordered map is O(1))
                * if it contains only one element, we will increment the uniqueCounter...
                    * at any unique movement unique counter is equal to kth value, we will return that selected element of uniqueString..
            * else if we are not able to found that element, we return empty string...




// Extra: ----------------------------------------------

The average time complexity of finding an element in an unordered map is O(1) because it is implemented using a hash table. 
Here’s a detailed explanation:

How Hash Tables Work

    * Hash Function: When you insert a key into the unordered map, a hash function computes an index based on the key. This index is where the key-value pair is stored in an underlying array.
    * Index Calculation: The hash function distributes keys uniformly across the array to minimize collisions (when two keys hash to the same index).
    * Collision Handling: If a collision occurs, the unordered map typically handles it using techniques such as chaining (storing multiple elements in a linked list at the same index) or open addressing (finding another index within the array).

Why O(1) Average Time Complexity?

    * Direct Access: The hash function allows for direct access to the bucket where the key-value pair is stored. This direct access is why lookups, insertions, and deletions can be done in constant time on average.
    * Uniform Distribution: A good hash function ensures that keys are uniformly distributed across the array, reducing the number of collisions.
    * Load Factor: The load factor (ratio of the number of elements to the number of buckets) is kept below a certain threshold by resizing the hash table (increasing the number of buckets) when it becomes too full. This resizing ensures that the average number of elements per bucket remains constant, maintaining O(1) average time complexity.

Factors Affecting Performance

    * Quality of the Hash Function: A poor hash function that results in many collisions can degrade performance to O(n) in the worst case, where nn is the number of elements.
    * Table Size and Resizing: Proper resizing of the hash table when the load factor exceeds a certain limit helps maintain O(1) average time complexity.
    * The average time complexity of finding an element in an unordered map is (O(1)) because it is implemented using a hash table. Here’s a detailed explanation:

Summary

    The O(1) average time complexity for finding an element in an unordered map is due to the efficiency of the hash function
    in distributing keys and the direct access provided by indexing into the underlying array. Proper handling of collisions and
    maintaining a good load factor are crucial to achieving this performance.

----------------------------------------------

*/
#include <bits/stdc++.h>
using namespace std;


// Bruteforce Solution:
string printKDistinct(vector<string>& arr, int n, int k){
    int dist_count = 0; // counter that count unique element.
    for(int i = 0;i<n;i++){
        // Check if the current element is present somewhere else.
        int j;
        for(j = 0;j<n;j++){ // iteration of inner loop..
            if (i != j && arr[j] == arr[i]) // if we got same element, we will break out..
                break;
        }

        // If element is unique, means throughout the inner loop we have iterated till (n-1)
        if (j == n) dist_count++;   // increment the unique element counter


        if (dist_count == k)  return arr[i];  // at any movement distinct counter is equal to kth, we will return that outer loop element of array..
    }

    return "";  // else, returning empty string...
}



// Efficient Solution: 
string printKDistinct_Eff(const vector<string>& arr, int k) {
    unordered_map<string, int> freqMap;     // creating freqMap to store the frequency of each element..
    vector<string> uniqueStrings;       // creating array that store only unique element..

    // Populate the frequency map and track the order of first appearance
    for (const string& str : arr) {
        // storing the unique element to uniqueString array, it will store all the element for the first time, but once it's repeating, it will not store that element, idea is to store the order..
        if (freqMap[str] == 0) {
            uniqueStrings.push_back(str);
        }
        freqMap[str]++;
    }

    // // debug item
    // for(auto i : uniqueStrings) cout << i << " ";
    // cout << endl;

    // Find the kth distinct string
    int dist_count = 0;
    for (const string& str : uniqueStrings){   // iterate in uniqueString...
        // if the frequency counter is equal to 1 of freqMap[str], means freq of str element(as unordered map will take O(1) for find operations) , we goes inside the loop..
        // cout << str << " " << freqMap[str] << endl;  // debug item
        if (freqMap[str] == 1) {
            dist_count++;   // increment the distinct counter..
            // at any time dist_counter is equal to k, we will return that specific string...
            if (dist_count == k) {
                return str;
            }
        }
    }

    return ""; // else return empty string..
}


int main (){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    int k;
    cin >> k;

    // cout << printKDistinct(arr, rn, k) << endl;
    cout << printKDistinct_Eff(arr, k) << endl;

    return 0;
}
