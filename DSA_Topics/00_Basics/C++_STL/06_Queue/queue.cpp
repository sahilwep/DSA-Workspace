/*
// Queue : 
    * Queue is a liner data structure in which elements can be inserted only from one side of the list called rear,
    * and the element can be deleted only from the other side called front.
    * Queue data structure follows the FIFO (first in first out) principle.
    * insertion of an element in a queue is called enqueue operation.
    * Deletion of an element is called dequeue operation.
    * We always maintain two pointer, one pointing to the element which was inserted at the first and still present in the list with front pointer and the second pointer pointing to the element inserted at the last with the rear pointer.
    
          front  | 7 | 2 | 6 | 1 |   |  rear    
        index      0   1   2   3   4
                    Queue

        TC : O(1), all the operation are happening in constant time.
*/

#include <bits/stdc++.h>
using namespace std;

void explainQueue(){

    queue<int> q;

    q.push(1);  // {1}
    q.push(2);  // {1, 2}
    q.push(4);  // {1, 2, 4}

    q.back() += 5;  //  {1, 2, 9}

    cout << endl <<  q.back();   // print 9

    // q is : {1, 2, 9}
    cout << endl <<  q.front();  // print 1

    q.pop();    // {2, 9}

    cout << endl <<  q.front();  // print 2

    // size swap empty same as stack.

}

int main(void){

    explainQueue();

    return 0;
}