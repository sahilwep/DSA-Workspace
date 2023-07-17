/*
// Multi-Set
    * Multi-Set only obey sorted, it will not obey unique.
    
*/

#include <bits/stdc++.h>
using namespace std;

void explainMultiSet(){

    multiset<int> ms;

    ms.insert(1);   // {1}
    ms.insert(1);   // {1, 1}
    ms.insert(1);   // {1, 1, 1}
    ms.insert(1);   // {1, 1, 1, 1}

    for(auto it : ms) cout << it << " ";    // print{1, 1, 1, 1}
    cout << endl;
    ms.erase(1);    // all 1's are erased.  NOTE : here we are passing element into a function parameter.
    for(auto it : ms) cout << it << " ";    // print nothing

    multiset<int> ms_1 = {1, 2, 2, 2, 3, 3, 4, 5};

    int cnt = ms_1.count(2);
    cout << cnt << endl;    // this will print 3

    // only a single one erased
    multiset<int> ms_2 = {1, 1, 1, 1, 2, 3, 4};
    ms_2.erase(ms_2.find(1));           // {1, 1, 1, 2, 3, 4}
    for(auto it : ms_2) cout << it << " ";  // print {1, 1, 1, 2, 3, 4}
    cout << endl;

    // erase in range.  {1, 1, 1, 2, 3, 4}
    auto it_rr = ms_2.find(1);  // create new iterator to store the last address.
    advance(it_rr, 2); // Now the iterator is one position ahead of where you want it to be.
    // This is because in the erase() function it takes from the start till one element less than the end that we specified.
    ms_2.erase(ms_2.find(1), it_rr); // {start(included), last(excluded)}
    
    for(auto it : ms_2) cout << it << " ";  // print {1, 2, 3, 4}
    
}

int main(void){

    explainMultiSet();
    return 0;
}