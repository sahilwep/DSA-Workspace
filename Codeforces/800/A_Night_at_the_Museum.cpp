/*
//  A. Night at the Museum

// Observations: 
    * There is a wheel that contains all the lower letter alphabets.
        * Initially pointer is at 'a', we are allowed to move the wheel clockwise or counterclockwise.
    * we are given a string & we need to print each character one by one.
    * we need to count the number of character that we skip during printing that string s.
    * all the time initial number changes, once we get the string.
    * we need to find the minimum no of rotations wheel required to print it.
    * Example: 
        s = zeus
        * Initially pointer at a
            * wheel look like:
                        ...z <- a b c d e f g h i j k l (m) n o p q r s t u v w x y z -> a...
            * we can go a to z(counterclockwise) by 1 count.
                * Now initial pointer has moved to z
            * Now from z to e, we can go(clockwise) by 5
            * Now from e to u, we can go(counterclockwise) by 10
            * Now from u to s, we can go(counterclockwise) by 2
                * Total: 1 + 5 + 10 + 2 = 18 rotations.


// Intrusion: 
    * We can solve this problem by multiple methods:
        * we can use circular doubly linked list
            * We can create Doubly Circular linked list & store all the alphabets..
            * Then we can iterate over from initial to final position, & Calculate the cost...
        * We can also use circular array
            * Last value Connected to first value..
                      a = 1
                      b = 2
                      c = 3
                      d = 4
                      e = 5
                      f = 6
                      g = 7
                      h = 8
                      i = 9
                      j = 10
                      k = 11
                      l = 12
                      m = 13
                      n = 14
                      o = 15
                      p = 16
                      q = 17
                      r = 18
                      s = 19
                      t = 20
                      u = 21
                      v = 22
                      w = 23
                      x = 24
                      y = 25
                      z = 26


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);


// #----------Solving by Circular Linked list------------#
struct Node{
    char data;
    Node *next, *prev;
    Node(char d){
        data = d;
        next = prev = NULL;
    }
};

Node *insertEnd(Node *head, char d){
    Node *temp = new Node(d);
    if(head == NULL){
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    // else when element is present
    Node *tempPrev = head->prev;
    temp->next = head;  // connecting temp -> next with head
    head->prev = temp;  // connecting head -> prev with temp
    temp->prev = tempPrev;  // connect temp -> prev with last element that was connected with head initially
    tempPrev->next = temp;  // finally connecting the last element with newly inserted element
    return head;
}

// printing the circular doubly linked list
void display(Node *head){
    cout << head->data << " ";
    Node *temp = head->next;
    while(temp != head){
        cout << temp->data << " ";
        temp = temp->next;
    }
    el;
}

int countWheel(Node *head, char initial, char final){
    // cout << initial << " " << final << endl;     // values that are coming..

    // finding the initial pointer: 
    Node *temp = head;
    while(temp->data != initial){
        temp = temp->next;
    }

    // Finding the cost for clockwise traversal from initial pointer to final pointer
    int cost1 = 0;
    Node *path1 = temp;
    while(path1->data != final){
        path1 = path1->next;    // clockwise
        cost1++;
    }


    // Finding the cost for counterclockwise traversal from initial pointer to final pointer
    int cost2 = 0;
    Node *path2 = temp;
    while(path2->data != final){
        path2 = path2->prev;    // counterclockwise
        cost2++;
    }

    // return the minimum cost: 
    return min(cost1, cost2);
}


void solveByLL(){
    string s;
    cin >> s;
    Node *head = NULL;  // Creating an empty node..
    char c = 'a';
    for(int i=0;i<26;i++){
        head = insertEnd(head, c++);    // store all the alphabets..
    }   
    // display(head);  // checking all the things are working correctly...

    int cnt = 0;
    cnt += countWheel(head, 'a', s[0]);
    for(int i=1;i<s.size();i++){
        cnt += countWheel(head,s[i-1], s[i]);
    }

    cout << cnt << endl;
}





// #----------Solving Using Array------------#
int cntCost(char arr[], char initial, char final){

    // finding initial point: 
    int iPtr = 0;
    for(int i=0;i<26;i++){
        iPtr++;
        if(arr[i] == initial) break;
    }

    // calculating cost:
    // Circular array traversing clockwise
    int cost1 = 0;
    for(int i=iPtr;i<26+iPtr-1;i++){
        cost1++;
        if(arr[i%26] == final) break;
    }
    // Circular array traversing counterclockwise:
    int cost2 = 0;
    for(int i=26+iPtr-1;i>=iPtr;i--){
        if(arr[i%26] == final) break;
        cost2++;
    }

    return min(cost1, cost2);
}

void solveByArray(){
    string s;
    cin >> s;
    char arr[26];
    char ch = 'a';
    for(int i=0;i<26;i++){
        arr[i] = ch++;  // hashed array with alphabets..
    }
    // finding the cost:

    int cnt = 0;
    cnt += cntCost(arr, 'a', s[0]);
    for(int i=1;i<s.size();i++){
        cnt += cntCost(arr, s[i-1], s[i]);
    }

    cout << cnt << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        // solveByLL();    // solve question by using linked list...
        solveByArray();    // solve question by using Array Logic...
    }
    
    return 0;
}