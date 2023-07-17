/*
    * C++ STL has sort(), that sort the most container, not map.

    a = starting element, a+n-> ending element + starting element

    sort(a, a+n);
{
*/


#include <bits/stdc++.h>
using namespace std;

// comparator says they are in the correct order or not ?
bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;  //if  p1{_,second} < p2{_,second} true
    if(p1.second > p2.second) return false; 
    // if two are same then sort in descending order.
    // p1.second == p2.second then sort the first element in descending order.
    if(p1.first > p2.first) return true;
    return false;
}


void explainExtra(){

    vector<int> v = {1, 3, 2, 9, 5, 4, 8};
    sort(v.begin(), v.end());   // {1, 2, 3, 4, 5, 8, 9}
    for(auto it : v) cout << it << " ";
    cout << endl;

    // sort in descending order.
    vector<int> v_1 = {1, 3, 2, 9, 5, 4, 8};
    sort(v_1.begin(), v_1.end(), greater<int>()); // grater is comparator.   
    for(auto it : v_1) cout << it << " ";
    cout << endl;
    
    // sort in range : [start(included), end(not included)]    
    vector<int> v_2 = {1, 3, 6, 9, 5, 4, 8};
    sort(v_2.begin()+ 2, v_2.begin()+ 5); 
    for(auto it : v_2) cout << it << " ";

    // sort in own desired way by writing our own comparator  (comparison functor) :
    pair<int,int> a[] = {{1, 2}, {2, 1}, {4, 1}};

/*
    // sort it according to second element  : i.e : 1, 1, 2
    // if second element is same, then sort : i.e for {2, 1} & {4, 1}
    // it according to first element but in descending order : i.e {4, 1}, {2, 1}

        // * so our sorted order is : {{4, 1}, {2, 1}, {1, 2}}

        // sort(a, a+n, comp)
    // we have to write comp functor, that return in boolean, true or false.
*/


}

int main(void){

    explainExtra();

    return 0;   
}