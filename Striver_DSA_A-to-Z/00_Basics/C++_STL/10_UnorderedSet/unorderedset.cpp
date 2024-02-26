/*
// Unordered set : 
    * it is simillar to set, only thing is it didn't stored in order
    * Unique & randomly ordered.
    * TC : O(1)
    * NOTE : lower_bound & Upper_bound don not work.
    * in worst case : O(n), it does not happened, one in a million case.
*/


#include <bits/stdc++.h>
using namespace std;

void explainUnorderedSet(){

    unordered_set<int> ust;

    ust.insert(9);
    ust.insert(1);
    ust.insert(1);
    ust.insert(2);
    ust.insert(4);
    ust.insert(8);
    ust.insert(10);
    ust.insert(22);
    // it can have unordered, buy only unique values.
    for(auto it : ust) cout << it << " ";
    
    // lower_bound & upper_bound do not work.
    // Rest of the function are same, 
    // it does not store in any particular order it has a better complexity that set in most case, except some when collision happens.

}

int main(void){

    explainUnorderedSet();

    return 0;
}