// remove the specific element from the an array
// Bruteforce solution 

#include <bits/stdc++.h>
using namespace std;

// print function to print vector.
void print(vector<int> &nums){
    for(int i = 0; i< nums.size(); i++){
        cout << nums[i] << " ";
    }
}

// function to remove the specific element.
vector<int> removeElement(vector<int> &nums, int val){
    vector<int> res;
    for(int i = 0 ; i<nums.size(); i++){
        if(nums[i] != val){
            int temp = nums[i];
            res.push_back(temp);
        }
    }
    cout << "\nAfter removal of element : ";
    return res;
}


int main(void){

    vector<int> vec = {1,2,3,4,3,5,3};
    int val = 3;    // target value
    cout << "\nOriginal value : ";  
    print(vec);     // printing the original value.
    

    // removal element
    vector<int> result = removeElement(vec, val);
    for(auto it : result) cout << it << " ";    // after removal printing the current value.


    return 0;
}
