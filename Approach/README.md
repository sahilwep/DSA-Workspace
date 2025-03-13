# Useful Approach used during problems solving:  


## Bruteforce Solution: 
* Try to solve every questions with bruteforce solution, The solution that comes first in your mind, doesn't matter how Efficient it is.., it may takes $O(2^n)$ or $O(n^3)$ or $O(n^2)$ or $O(n*m)$ and later on it may gives you **TLE**, at-least you the solutions Which will works on all the test-cases (NOT CONSIDERING THE TIME & SPACE CONSTRAINS), Later on we can improve our Bruteforce solution to Better to more Efficient one...


## Disjoint Set Union (DSU) || Union Find || Union By Size || Union By Rank:

- DSU helps us to determine whether two nodes belonging to a same components or not in **Dynamic Graph** with **Constant time**.
- **Use-case of DSU**:
    - When dynamic connectivity and merging of sets are needed.
    - Finding whether two nodes belong to the same connected component in an undirected graph.
    - Find the minimum cost to connect all nodes in a graph.
    - Checking if a graph contains a cycle in an undirected graph.
    - Maintaining components when elements are dynamically merged.
    - Maze Generation, Clustering, Image Processing, Percolation

    - **Union by Rank vs. Union by Size**

        - **Union by Rank:**
            - The rank represents the approximate depth of the tree.
            - When merging two sets, the tree with lower rank is attached to the tree with higher rank.
            - If both have the same rank, the rank of the new root is incremented.

        - **Union by Size:**
            - The size represents the number of elements in the set.
            - When merging two sets, the smaller set is always attached to the larger set.
            - The size of the new root is updated accordingly.
        
- **Why Should You NOT Use Both at the Same Time?**
    - **They Serve the Same Purpose:**
        - Both optimizations try to keep the tree as flat as possible to speed up findUPar().
        - Union by Rank minimizes depth using ranks.
        - Union by Size minimizes depth using sizes.
        - Using both is redundant and does not provide extra benefits.

    - **Conflicting Logic:**
        - Union by Rank updates the rank[] array, while Union by Size updates the size[] array.
        - If you mix them, the logic becomes inconsistent:
            - Should you compare rank or size when merging?
            - If rank says attach A to B, but size says attach B to A, which one should you follow?

    - **Increased Space Complexity:**
        -> Using both requires maintaining both rank[] and size[] arrays, which increases memory usage unnecessarily.


- Here, the implementation of DSU with UnionBySize & UnionByRank:
```cpp
// Union By Rank & Size:
class DisjointSet {
private:
    vector<int> rank, parent, size;
public:
    // Constructor:
    DisjointSet(int n) {
        // initial Configurations:
        rank.resize(n + 1, 0);  // declarations it with n + 1, will work with both 0-based and 1-based indexing.
        
        size.resize(n + 1, 1);  // size default value = 1, because of every node initially treated as single component.

        // for every node parent is themselves => parent[i] = i
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    // Find ultimate parent => with path compression
    int findUPar(int node) {
        if(parent[node] == node){
            return node;
        }

        // else go parent -> parent -> parent until we not reach to a node which is the ultimate parent.
        return parent[node] = findUPar(parent[node]);      // send parent[node] in recursive call to reach ultimate parent & save in parent[node] to use path compression => takes O(1)
        // return findUPar(parent[node]);      // Takes O(log(n)) logarithmic time, without path compression.
    }

    // Union By Rank => which we have to combine or attach (u & v)
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);    // find ultimate parent of u
        int ulp_v = findUPar(v);    // find ultimate parent of v
        

        // if both ultimate parents are same => they are already in same components.
        if(ulp_u == ulp_v) return;  // they are belonging to the same components => already attached.
        


        // If they were not in same components:
        if(rank[ulp_u] < rank[ulp_v]) { // check rank:
            parent[ulp_u] = ulp_v; // smaller goes & get's attached to the greater guy. => ultimate parent of smaller guy will be the ultimate parent of greater guy.
        }
        else if(rank[ulp_v] < rank[ulp_u]) {    // v ultimate parent is lesser rank than u ultimate parent: attach 
            parent[ulp_v] = ulp_u;  // smaller goes & get's attached to the greater guy.
        }
        else {  // if they have same rank:   we can assign anyone to anyone, but make sure the we should increase the rank of greater guy.
            parent[ulp_v] = ulp_u;      // we have attached ultimate parent of v to ultimate parent of u.
            rank[ulp_u]++;  // rank of ultimate parent of u will be increased, because that is where i am attaching it.
        }
    }


    // Union By Size: 
    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);    // find ultimate parent of u
        int ulp_v = findUPar(v);    // find ultimate parent of v
        

        // if both ultimate parents are same => they are already in same components.
        if(ulp_u == ulp_v) return;  // they are belonging to the same components => already attached.
        

        // If they were not in same components:
        if(size[ulp_u] < size[ulp_v]) { // check size:
            parent[ulp_u] = ulp_v; // smaller goes & get's attached to the greater guy. => ultimate parent of smaller guy will be the ultimate parent of greater guy.
            size[ulp_v] += size[ulp_u]; // size will be added, because the components gets connected.
        }
        else {  // else if ultimate parent of v is smaller than ultimate parent u |OR| size[ulp_u] == size[ulp_v] it's equal
            parent[ulp_v] = ulp_u;  // attach the larger 'u' to smaller 'v'.
            size[ulp_u] += size[ulp_v]; // add the size to ultimate parent of 'u'
        }
    }
};
```

- Which One Should We Use?
    - "Union by Size" is often preferred in practical scenarios because:
        - It directly considers the number of elements in a set.
        - It has slightly better cache efficiency.
    - Union by Rank is theoretically just as good, but rank values are not as intuitive to track as sizes.
    - Both methods ensure nearly constant time complexity O(α(n)) (inverse Ackermann function), so the choice is mostly based on implementation preference.


### DSU - UnionBySize Implementations:
```cpp
// DisjointSet: Union by size:
class DisjointSet {
private:
    vector<int> parent, size;
public: 
    DisjointSet(int n) {
        size.resize(n + 1, 1);      // initially every components treated as individual.
        
        // everyone parents are themselves.
        parent.resize(n + 1, 0);
        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }
    // Find ultimate parent:
    int findUltParent(int node) {
        // base case:
        if(parent[node] == node) {  // when any node pointing itself => return case, we have successfully find the ultimate parent.
            return node;    
        }
        
        // Recursive case: 
        return parent[node] = findUltParent(parent[node]);     // Using path compression which will give us O(1) constant time while we find any "node" in future.
    }
    // unionFind By Size:
    void unionBySize(int u, int v) {
        int ult_u = findUltParent(u);   // find ultimate parent of 'u'
        int ult_v = findUltParent(v);   // find ultimate parent of 'v'
        
        // Check whether they were in same component or not?
        if(ult_u == ult_v)  return;     // for same components don't do anything.
        
        // If they were in different components: connect them together => smaller to larger: By Size:
        if(size[ult_u] < size[ult_v]) { // size of ultimate parent of u is smaller than size of ultimate parent of v => connect ultimate parent 'u' to ultimate parent of 'v' & add overall size of ultimate parent of size 'v' by adding size of 'u' into it..
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u]; // increment size of larger node, as smaller added into it.
        } 
        else {  // ultimate parent of v size is lesser than the ultimate parent of size u: connect v to u & increment the size of 'u'
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];

        }   // NOTE: Equality case handled here because => In equality case we can connect anyone to anyone.
    }
};
```

#### Extra:

- [DSU Article](https://cp-algorithms.com/data_structures/disjoint_set_union.html)
- For More about **Time Complexity** How `O(4 alpha)` is near about `O(1)`, Do this GPT Prompt:
  - "Explain why the time complexity of the Disjoint Set Union (DSU) with path compression is O(α(n)), where α(n) is the inverse Ackermann function. Provide a step-by-step derivation, including the effects of path compression, recurrence relations, and why α(n) grows so slowly. Also, conclude why DSU operations are effectively O(1) in practice."



## Hashing: 
* Hashing is one of the important technique which is used variety of question regarding frequency.
* In hashing we are storing the frequency of every element.
* To use hashing we have many technique, it's all depends on our needs.
  
### Hashing elements using hash array or vector `int hash[n] = {0} or vector<int> vec(n, 0)` 
```cpp
void func(){
    int n;
    cin >> n;
    int arr[n];
    arrInp;   // macros defined to take array input.

    // Initialization of hashing: 
    // size should be depends on max, value in an array..
    int hash[n] = {0}   // hash[] array declare with default value '0'
    vector<int> hash1(n, 0);    // hash1 vector define with default value '0'

    // Storing frequency: 
    for(int i=0;i<n;i++){
        hash[arr[i]]++;     // store the frequency of that element on specific "arr[i]" as index.
        hash1[arr[i]]++;    // same with vector...
    }

    // accessing elements of hash:
    for(int i=0;i<n;i++){
        cout << i << hash[i] << " ";    // here i is element of an array, & hash[i] is frequency of that element.
        // cout << i << hash1[i] << " ";   // same way we can print hash stored in vector.
    }
    el; // macros defined to break line.
}
```

### Hashing Using `std::map`

* map stores hash value in sorted fashion, & when we are using map, we don't need to take care of size while storing elements into map.
* Searching takes: $O(logn)$
* Insertion takes: $O(logn)$ + `Rebalance`
* For more information about Time complexity of others operations visit: [GFG Map v/s Unordered Map](https://www.geeksforgeeks.org/map-vs-unordered_map-c/)

```cpp
void func(){
    int n;
    cin >> n;
    int arr[n];
    arrInp;   // macros defined to take array input.

    // Initialization of map:
    map<int, int> mp;

    // hashing: 
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    // traversing in map:
    for(auto i=mp.begin();i!=mp.end();i++){
        cout << i->first << " " << i->second;   // first value will be number, & second value will be index.
    }
}
```

### Hashing Using `std::unordered_map`

* 
* Searching takes: 
  * Avg: $O(1)$ 
  * worst: $O(n)$
* Insertion takes: `same as search`

```cpp
void func(){
    int n;
    cin >> n;
    int arr[n];
    arrInp;   // macros defined to take array input.

    // Initialization of unordered_map:
    unordered_map<int, int> ump;

    // hashing: 
    for(int i=0;i<n;i++){
        ump[arr[i]]++;
    }

    // traversing in map:
    for(auto i=ump.begin();i!=ump.end();i++){
        cout << i->first << " " << i->second;   // first value will be number, & second value will be index.
    }
}
```


## Two-Pointers: 

* Two-pointers is one of the important technique, which used to improve time complexity.
* We maintain two pointers in & depending our needs, we move them..
* Example: Reversal of an array
```cpp
void reverse(int arr[], int n){
    int ptr1 = 0;
    int ptr2 = n-1;
    while(ptr1 < ptr2){
        swap(arr[ptr1++], arr[ptr2--]);
    }
}
```
* At every iteration we swap `ptr1` & `ptr2` located elements and increase `ptr1` and decrease `ptr2`.
* There are many others examples that can solve by two pointer approach & improve time complexity from $O(n^2$ to $O(n)$



## upper_bound()

* `upper_bound()`: It return an iterator pointing to first element in the range [first, last] that is grater value, or last if no element is found.
* The element in that range shall already be sorted or at-least partitioned with respect to value.
* `upper_bound()` function uses `binary-search` internally.
* `upper_bound()` return iterator:
  * if we subtract `v.begin()` means first iterator, then we will get the index.
  * or if we directly store the result into an iterator, we will get the value itself.

> Example: 
```plain
Input : 10 20 30 30 40 50
Output : upper_bound for element 30 is at index 4

Input : 10 20 30 40 50
Output : upper_bound for element 45 is at index 4

Input : 10 20 30 40 50
Output : upper_bound for element 60 is at index 5
```
* Uses:

```cpp
int func(){
    vector<int> v = {10, 20, 30, 40, 50, 60}; // elements should be sorted
    
    int index = upper_bound(v.begin(), v.end(), 35) - v.begin();   // subtract v.begin() to iterator will give index

    vector<int>::iterator it = upper_bound(v.begin(), v.end(), 35);    // we can directly store iterator in an iterator type array
    
    cout << "Element " << *it << endl;   // use dereference to fetch the vlaue.
    cout << "Index " << index << endl;
    
}
```

* Useful in variety of question where we need searching..


## Sliding Window: 

* This technique is used to efficiently solve problems that involve `subrange` of window of elements within a large dataset.
* It is particularly useful for problems involving array or string where you need to examine contagious subarray or substring.
* The main idea is to maintain a window(a substring) & slide it over array or string to achieve the desired result with reduced time complexity compared to bruteforce approach.
* `Key Concept`: 
  * `Window size`: the length of subarray or substring that you are interested in.
  * `Sliding the window`: moving the window one element at a time from the start to the end of the array or string.
  * `Maintaining the window`: keep tracking of elements within the window and updating the result based on the elements currently in the window.
* `Types of sliding window`:
  * `Fixed size sliding window`: The window size is fixed and does not change.
  * `Dynamic size sliding window`: The window size can change dynamically based on condition specified in program.
* Example: find the sum of a subarray of size `k` in a given array:

```cpp
int maxSumSubarray(vector<int>& nums, int k) {
    if (nums.size() < k) return -1;     // when window size is grater than the array size.
    
    // Compute the sum of the first window of size k
    int max_sum = 0;
    for (int i = 0; i < k; i++) {   // iterate from 0 to k-1
        max_sum += nums[i];
    }
    
    int window_sum = max_sum;   // first window size will be the size of k element of array that we get.
    
    // Slide the window from start to the end of the array
    for (int i = k; i < nums.size(); i++) {
        // Slide the window right by subtracting the element left of the window
        // and adding the element that comes into the window
        window_sum += nums[i];  // adding the new element that comes into the window.
        window_sum -= nums[i - k];  // removing the element value from the window sum that goes out of the window.
        max_sum = max(max_sum, window_sum); // at last we will compare the maximum sum with each iterated sliding window, & last we store it on max_sum variable.
    }
    
    return max_sum;
}
```

*** 

## Array Difference Technique:

The **difference array technique** is a powerful method to efficiently perform range update operations on an array. It minimizes the time complexity compared to direct element-by-element updates.


### **Concept**
The difference array stores the difference between consecutive elements of the original array. This allows range updates to be applied in constant time.

Given an array `arr[]` of size `n`, the difference array `diff[]` is defined as:

```
diff[i] = arr[i] - arr[i-1]  (for 1 <= i < n)
```

### **How It Works**
If given a range `[low, high]` in the array, and you need to perform some changes (like adding a value `x`) to all elements in this range:

1. Update `diff[low]` by adding the value `x`.
2. Update `diff[high+1]` by subtracting the value `x` (only if `high+1` is within bounds).
3. Finally, compute the cumulative sum of the `diff` array to reconstruct the updated array.


### **Steps to Implement**

#### Step 1: Update the Difference Array
For a range `[l, r]` and a value `x` to be added:

- Increment `diff[l]` by `x`:
  ```
  diff[l] += x
  ```
- Decrement `diff[r+1]` by `x` (only if `r+1 < n`):
  ```
  diff[r+1] -= x
  ```

#### Step 2: Compute the Cumulative Sum
Take the prefix sum of the `diff` array to get the final values in the original array:

```
arr[0] = diff[0]
arr[i] = arr[i-1] + diff[i]  (for 1 <= i < n)
```

### **Example**

#### Problem:
Suppose you have an array `arr = [0, 0, 0, 0, 0]` (all zeros) of size 5, and you want to:
1. Add `10` to elements in range `[1, 3]`.
2. Add `20` to elements in range `[2, 4]`.

#### Solution:

##### Step 1: Initialize Difference Array
Start with `diff = [0, 0, 0, 0, 0, 0]` (extra element for ease of handling updates).

##### Step 2: Perform Range Updates
- For `[1, 3]` with `x = 10`:
  ```
  diff[1] += 10
  diff[4] -= 10
  diff = [0, 10, 0, 0, -10, 0]
  ```
- For `[2, 4]` with `x = 20`:
  ```
  diff[2] += 20
  diff[5] -= 20
  diff = [0, 10, 20, 0, -10, -20]
  ```

##### Step 3: Compute the Cumulative Sum
Take the prefix sum of `diff` to get `arr`:

```
arr[0] = diff[0] = 0
arr[1] = arr[0] + diff[1] = 0 + 10 = 10
arr[2] = arr[1] + diff[2] = 10 + 20 = 30
arr[3] = arr[2] + diff[3] = 30 + 0 = 30
arr[4] = arr[3] + diff[4] = 30 - 10 = 20
```

Final array: `arr = [0, 10, 30, 30, 20]`

### Code Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to perform range updates
void updateRange(vector<int>& diff, int l, int r, int x) {
    diff[l] += x;
    if (r + 1 < diff.size()) {
        diff[r + 1] -= x;
    }
}

// Function to construct the updated array from the difference array
vector<int> buildFinalArray(const vector<int>& diff) {
    vector<int> arr(diff.size() - 1, 0);
    arr[0] = diff[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        arr[i] = arr[i - 1] + diff[i];
    }
    return arr;
}

int main() {
    int n = 5;
    vector<int> diff(n + 1, 0); // Difference array initialized with 0

    // Apply range updates
    updateRange(diff, 1, 3, 10); // Add 10 to range [1, 3]
    updateRange(diff, 2, 4, 20); // Add 20 to range [2, 4]

    // Build and print the final array
    vector<int> finalArray = buildFinalArray(diff);
    for (int val : finalArray) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
```

*** 

