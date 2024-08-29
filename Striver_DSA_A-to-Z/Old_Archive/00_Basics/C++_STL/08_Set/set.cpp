/*
// Set : Set are type of associative container in which each element has to be unique the value of the element identifier it.
    * The values are stored in order i.e : either ascending or descending.
    * Stores in a sorted order
    * Stores only unique values.
    

    * NOTE : In set everything is happens in logarithmic time complexity i.e O(log(n))
        * if we are inserting, erasing, everything happens in logarithmic.

*/

#include <bits/stdc++.h>
using namespace std;

void explainSet(){

    set<int> st;

    st.insert(1);   // {1}
    st.emplace(2);  // {1, 2}
    st.insert(2);  // {1, 2}
    st.insert(4);  // {1, 2, 4}
    st.insert(4);  // {1, 2, 4}
    st.insert(3);  // {1, 2, 3, 4}

    // functionality of insert in vector can be used also, that only increases efficiency.

    // begin(), end(), rbegin(), rend(), size(), 
    // empty(), and swap() are same as the above.s

    // {1, 2, 3, 4}
    auto it = st.find(3); // it return to the iterator which points to 3
    cout << *it;    // this will print 3

    // this item is not in the set.
    auto itt = st.find(6);  // NOTE : if the element is not in the set, it will always return st.end();
    cout << endl << *itt;   // return 4

    // {1, 2, 3, 4}
    st.erase(4);    // erases 4 & maintain the sorted order  // takes logarithmic time.

    int cnt = st.count(1);  // set is unique & sorted, so if it exist it will return 1, else 0
    cout << endl << cnt << endl;

    auto it_1 = st.find(3); // find 3 in set.s
    st.erase(it);   // it will erase 3, & takes constant time.


    // erase(start, end)
    set<int> st_1 = {1, 2, 3, 4, 5};
    for(auto it : st_1) cout << it << " ";  // this will give {1, 2, 3, 4, 5}
    cout << endl;

    auto it1 = st_1.find(2);    // find the 2
    auto it2 = st_1.find(4);    // find the 4
    st_1.erase(it1, it2);   // after erase : {1, 4, 5}
    for(auto itr : st_1) cout << itr << " ";



    // lower_bound & upper_bound function work in same way as in vector it does.
    set<int> st_2 = {1, 2, 3, 4, 5};
    auto it3 = st_2.lower_bound(2); // lower bound of 2 point at 2
    cout << endl << *it3;
    auto it4 = st_2.upper_bound(3); // upper bound of 3 point at 4
    cout << endl << *it4;   // this will give 4
    cout << endl << *it4 - 1;   // this will give 3
    
}

int main(void){

    explainSet();

    return 0;
}