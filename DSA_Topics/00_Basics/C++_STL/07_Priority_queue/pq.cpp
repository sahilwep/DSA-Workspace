/*
// Priority Queue
    * A priority queue is a type of queue that arrange element based on their priority values. Elements with higher priority values are typically retrieved before elements with lower priority value.


    TC :  push  :O(logn)
    TC :  top   :O(1)
    TC :  pop  :O(logn)


*/

#include <bits/stdc++.h>
using namespace std;

void explainPriorityQueue(){
    // Maximum Heap
    priority_queue<int> pq;

    pq.push(5);     //{5}
    pq.push(2);     //{5, 2}
    pq.push(8);     //{8, 5, 2}
    pq.emplace(10);     //{10, 8, 5, 2}

    cout << endl << pq.top();   // print 10

    pq.pop();    // {8, 5, 2}

    // size swap, empty function are same as other.

    // Minimum Heap or minimum priority queues
    // this will insert the value in minimum at top.
    priority_queue<int, vector<int>, greater<int>> pq_1;
    pq_1.push(5);   // {5}
    pq_1.push(2);   // {2, 5}
    pq_1.push(8);   // {2, 5, 8}
    pq_1.push(10);  // {2, 5, 8, 10}

    cout << endl << pq_1.top(); // print top element : 2
}

int main(void){

    explainPriorityQueue();

    return 0;
}