/*

//  1352. Product of the Last K Numbers


//  Problem Statement: 
    -> Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.
    -> Implement the ProductOfNumbers class:
        -> ProductOfNumbers() Initializes the object with an empty stream.
        -> void add(int num) Appends the integer num to the stream.
        -> int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
    -> The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.


// Example:
    Input
        ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
        [[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

    Output
        [null,null,null,null,null,null,20,40,0,null,32]

    Explanation:
        ProductOfNumbers productOfNumbers = new ProductOfNumbers();
        productOfNumbers.add(3);        // [3]
        productOfNumbers.add(0);        // [3,0]
        productOfNumbers.add(2);        // [3,0,2]
        productOfNumbers.add(5);        // [3,0,2,5]
        productOfNumbers.add(4);        // [3,0,2,5,4]
        productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
        productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
        productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
        productOfNumbers.add(8);        // [3,0,2,5,4,8]
        productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient:
class ProductOfNumbers {
private:
    vector<int> nums;
    int n;
public:
    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) { // TC: O(1)
        if(num == 0) {  // if number is '0'
            nums = {};  // make array empty.
            n = 0;  // resize array to '0' size.
        }else { // else
            if(nums.empty()) {  // if our array is empty.
                nums.push_back(num);    // push this element for the first time.
            }else{  // else 
                nums.push_back(nums[n-1] * num);    // multiply it with last element & then push it.
            }
            n++;    // increasing size by 1 // increment size by 1
        }
    }
    
    int getProduct(int k) { // TC: O(1)
        if(k > n) return 0; // when k is grater than n, product will be 0, because smaller / larger => gives decimal value in '0'( 23 / 100 => answer in 0.something.)
        else if(k == n) return nums[n-1];   // when k is equal to n last element will be product
        else{
            return nums[n-1] / nums[n - k - 1]; // last element / product of till kth element.
        }
    }
};


// BruteForce:
class ProductOfNumbers {
private:
    vector<int> nums;
    int n;
public:
    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) { // get the product from n-k to n & return it.
        int prod = 1;
        int n = nums.size();
        for(int i = n - k; i < n; i++) {
            prod *= nums[i];
        }

        return prod;
    }
};
    
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */