/*

// Sorting Elements of an Array by Frequency

// Observations: 
    * We are given an array that contains duplicate values, sort them according to their frequency of element, 
    * i.e element have higher frequency will come first.
    * If the frequency of two elements are same, then the smallest element comes first.

// Example: 

    Input: arr[] = [5, 5, 4, 6, 4]
    Output: [4, 4, 5, 5, 6]
        Explanation: The highest frequency here is 2. 
        Both 5 and 4 have that frequency. 
        Now since the frequencies are the same the smaller element comes first. 
        So 4 4 comes first then comes 5 5. Finally comes 6. 
        The output is 4 4 5 5 6.


    Input: arr[] = [9, 9, 9, 2, 5]
    Output: [9, 9, 9, 2, 5]
        Explanation: The highest frequency here is 3. 
        Element 9 has the highest frequency So 9 9 9 comes first. 
        Now both 2 and 5 have the same frequency. So we print smaller elements first. 
        The output is 9 9 9 2 5.


// Intrusion:
    // Approach: Sorting Elements by Frequency Using Hashing
        1. Hashing the Elements:
            * We start by using a hashing approach to store the frequency of each element in the array.
            * The idea is to create a hashmap (or unordered_map) that stores each element along with its first occurrence index and frequency.
            * The hashmap structure will be: unordered_map<int, pair<int, int>>, where:
                * The key is the element itself.
                * The value is a pair containing:
                    * The index of the first occurrence of the element.
                    * The frequency of the element.

        2. Transferring to a Vector:
            * After hashing the elements, we need to transfer the hashmap contents into a vector for sorting.
            * We create a vector of pairs with the structure vector<pair<int, pair<int, int>>>, where each entry from the hashmap is inserted.

        3. Sorting the Vector:
            * The vector is then sorted based on two criteria:
                * Frequency: Elements with higher frequency appear first.
                * Value: If two elements have the same frequency, the smaller element comes first.
            * We achieve this by writing a custom comparator function (fcompare) that handles the sorting logic.

        4. Generating the Result:
            * After sorting, we iterate through the sorted vector and build the final 1D result vector.
            * Each element is added to the result vector as many times as its frequency.

        5. Time and Space Complexity:
            * Time Complexity: 
                * The overall time complexity is O(nlogn) due to the sorting step.
                * TC: O(nlogn)
            * Space Complexity: 
                * The space complexity is O(n) as we use additional space for the hashmap and the vector.
                * AS: O(n)

// Learning Outcomes:
    * When we have a question where we have to work with the frequency of the element, & from that frequency we are doing some operations, then in that case we can use the similar approach that we have used here. 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Using Hashing Approach: 
    // Custom comparator function to sort elements by frequency and value.
    // Parameter arrangement: (element, (index, freq))
    static bool fcompare(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2){
        // Compare based on frequency (p1.second.second and p2.second.second).
        if(p1.second.second != p2.second.second){
            // Higher frequency comes first.
            return (p1.second.second > p2.second.second);
        }
        // If frequencies are the same, smaller value comes first.
        else{
            return (p1.first < p2.first);
        }
    }
    vector<int> sortByFreq(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Create a hashmap to store elements with their first occurrence index and frequency.
        // hashmap arrangements: < element, <index, frequency> >
        unordered_map<int, pair<int, int> > hash;
        for(int i=0;i<n;i++){
            // If the element is already in the hashmap, increment its frequency.
            if(hash.find(arr[i]) != hash.end()){
                hash[arr[i]].second++;
            }
            // Otherwise, add the element with its index and set frequency to 1.
            else{
                // we will store that element into hashmap & assign their index & their frequency:
                // make_pair() function used to create pair
                hash[arr[i]] = make_pair(i, 1);
            }
        }

        // Step 2: Transfer hashmap elements into a vector for sorting.
        auto it = hash.begin();
        // Vector to store the final sorted order:
        vector<pair<int, pair<int, int> > > temp;
        for(it;it!=hash.end();it++){
            temp.push_back(make_pair(it->first, it->second));   // storing the values from the hashmap to vector.
        }


        // Step 3: Sort the vector according to frequency and value.
        sort(temp.begin(), temp.end(), fcompare);


        // Step 4: Construct the sorted array based on the sorted vector.
        vector<int> solu;
        for(int i=0;i<temp.size();i++){
            int cnt = temp[i].second.second;
            while(cnt--){
                solu.push_back(temp[i].first);
            }
        }

        return solu;    // returning the result
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}