/*
// Recursive traversal : 


        rPrint(ref(10)) 
            ->print(10)
            ->rPrint(ref(20))   return-^
                ->print(20)
                ->rPrint(ref(30))   return-^
                    ->print(30)
                    ->rPrint(ref(40))   return-^
                        ->print(40)
                        ->rPrint(ref(50))   return-^
                            ->print(50)
                            ->rPrint(ref(NULL)) return-^
                                -> Base_Case HIT* return-^

// Approach : 
    * when head == NULL, return
    * print head->data
    * call function with parameter head->next

// complexity : 
    * TC : O(n)
    * AS : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int x){
            data = x;
            next = NULL;
        }
};

void display(Node *head){
    if(head == NULL) return;
    cout << head->data << " ";
    display(head->next);
}

int main(void){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    display(head);

    return 0;
}