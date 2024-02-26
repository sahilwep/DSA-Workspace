/*
// linked list implementation of stack : 

    

// Stack Operations : Insertion and deletion perform from the head node.
    * push()
    * pop()

*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

struct MyStack{
    Node *head;
    int size;
    MyStack(){
        head = NULL;
        size = 0;
    }
    void push(int x){
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }
    void pop(){
        if(head == NULL) return;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    int getSize(){
        return size;
    }
    void display(){
        if(head == NULL) return;
        Node *curr = head;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main(void){

    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.getSize() << endl;

    s.display();

    s.pop();
    s.pop();
    cout << endl;
    s.display();
    
    return 0;
}