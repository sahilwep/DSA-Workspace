/*

//  735. Asteroid Collision


//  Observations: 
    * We are given an array asteroid of integer representing asteroids in row.
    * For each asteroid, the absolute value represent it's size.
    * and the sign represent the directions.
    * Positive means right, negative means left.
    * Each Astroid moves at same speed.
    * Find out the state of astroid after all the collision, if two astroid meet, the smaller one will explode.
    * If both at same size, both will explode.
    * Two asteroid moving at same direction will never explode.


// Intrusion: 
    // Using stack:
        * We will start iterating from start to end;
            * when we got positive value, insert it into stack.
            * When we got negative value, check whether that element is compatable to inserted into stack or not.
                * first check whether the top element is less than 0, means there is already negative element, so break out from the iterations.
                * if top element is less than the absolute current value, remove top element.
                * if top element is equal to current absolute value, remove top element, & make sure current element is not inserted into stack.
                * else, when top element is grater than the current absolute element, break & make sure current element is not inserted into stack.
            * At the end check whether we should insert, the current element or not.
        * after all the operations shift element from stack to vector, & reverse it, & return it.
        * TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> s;

        for(int i=0;i<n;i++){
            // when we have positive value, we will insert that into our stack.
            if(a[i] > 0){
                s.push(a[i]);
            }
            // When we have negative value, we will ckeck whether it's is compatable to get inserted into stack or not?
            else{
                bool isDestroyed = 0;   // this flag will 
                while(!s.empty()){
                    int top = s.top();
                    // if stack to element is negative, menas do nothing exit out, because both the value will go on left.
                    if(top < 0){
                        break;
                    }

                    // when current value strength is grater than the top, then remove top value
                    if(top < abs(a[i])){
                        s.pop();
                    }
                    // when current is equal to top, remove top element & make sure that current value is not get inserted into stack.
                    else if(top == abs(a[i])){
                        s.pop();
                        isDestroyed = 1;
                        break;  // break out, as don't have to anything further.
                    }
                    // when top is grater than the current value:
                    else{
                        isDestroyed = 1;    // this will make sure current value will not get inserted into stack.
                        break;  // break out from the loop, as we found the grater element.
                    }
                }

                // At the end we will check whether the current element is destroyed or not, if not push it into stack.
                if(!isDestroyed){
                    s.push(a[i]);
                }
            }
        }

        // Now pushing element from stack to vector:
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }


        // at the end we will reverse the result vector:
        reverse(res.begin(), res.end());


        return res; // returning the result.
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    Solution obj;
    

    vector<int> res = obj.asteroidCollision(v);

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