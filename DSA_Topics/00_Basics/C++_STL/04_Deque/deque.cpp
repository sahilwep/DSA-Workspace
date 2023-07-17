/*

// Deque : deque is a sequencial container that provides the functionality of a double-ended ques data structure.
    * Double-ended queues are sequential container with feature of expansion and contraction on both ends.
    * They are similar to vector, but are more efficient in case of insertion and deletion of element.
    * we can insert and delete the element from the both ends.





*/


#include <bits/stdc++.h>
using namespace std;

void explainDeque(){
    
    deque<int> dq;      // { }
    dq.push_back(23);     // {23}
    dq.emplace_back(14);    // {23, 14}
    dq.push_front(10);      // {10, 23, 14}
    dq.emplace_front(84);    //{84, 10, 23, 14} 

    dq.pop_back();     // {84, 10, 23}
    dq.pop_front();     // {10, 23}

    for(auto it : dq) cout << it << " ";

    cout << endl << dq.back();  // this will give the last element.

    cout << endl << dq.front(); // this will give the first element.

    // rest function same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}


int main(void){

    explainDeque();

    return 0;
}