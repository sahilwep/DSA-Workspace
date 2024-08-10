/*

// Swap Kth nodes from ends

// Observations:
    * we are given linked list of integer k, we need to swap kth linked list node from the beginning & end of the linked list...
    * we need to swap nodes through the links, do not change the content of these nodes..
    * Node: if we think we can change the content of kth node from the first & last, that's not going to accept..
        * Instead we need to swap these nodes...

// Intrusion:
    * We need to get the nodes location from first & last, first..
    * Then we have to change the reference of these nodes...
    * IF we change the reference, our values will be changed...

    * First we need to find the size of linked list, because if the kth value is grater than the size, we don't have to change anything..
    * Second if the kth value is less than the size: 
        * we will iterate to the location of that node, & store the reference of that node..
        * we need to store the reference from start & end both..
            * For start: we can simply iterate till kth..
            * For last: we can subtract the location from the size...
        * once we get the reference location of these two nodes, all we have do is swap these nodes..
        * We have to take care of these nodes while swapping then allocate the values..

    // Example:

            * First we have to find the size of linked list:

                [1]-->[2]-->[3]-->[4]-->[5]-->[6], k = 2, size = 6


            * Second we need to find the kth locations of these nodes: 

                [1]-->[5]-->[3]-->[4]-->[2]-->[6]
                    |                 |
                    swapped          swapped

            * Once we have the location of these nodes, swap these nodes...
        
                [1]-->[5]-->[3]-->[4]-->[2]-->[6]
                    |                 |
                    swapped          swapped

    * Conclusion: 
        * We need to maintain two pointer while iterating the kth node from end & from start.
        * These pointer will help us to track before & current node locations...

*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x)
        : data(x)
        , next(NULL) {}
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void addressstore(vector<Node*>& arr, Node* head) {
    Node* temp = head;
    int i = 0;
    while (temp) {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(const vector<Node*>& before, const vector<Node*>& after, int num, int k) {
    if (k > num)
        return true;

    for (int i = 0; i < num; i++) {
        if ((i == k - 1) || (i == num - k)) {
            if (!((before[k - 1] == after[num - k]) &&
                  (before[num - k] == after[k - 1]))) {
                return false;
            }
        } else {
            if (before[i] != after[i]) {
                return false;
            }
        }
    }
    return true;
}

// Function to swap Kth node from beginning and end in a linked list.
class Solution {
  public:
    Node* swapKthNode(Node* head, int k) {
        // first we have to find the size of linked list, & work accordingly:
        Node *curr = head;
        int size = 0;
        while(curr){
            size++;
            curr = curr->next;
        }

        // case when given kth value is grater than the size..
        if(k > size){
            return head;
        }
        // when we are given k as middle position, means size/2 position of k, no need to swap..
        if(k * 2 - 1 == size){
            return head;
        }
        
        // Finding the kth node from beginning: 
        Node *x = head; // this reference will point the targeted kth node.
        Node *xPrev = NULL; // this reference will point before the targeted kth node from beg.. 
        for(int i=1;i<k;i++){
            xPrev = x;
            x = x->next;
        }

        // finding the kth node from end: 
        Node *y = head; 
        Node *yPrev = NULL;
        for(int i=1;i<size - k + 1;i++){
            yPrev = y;
            y = y->next;
        }

        // if xPrev exist, then new next will be y.
        // consider the case when y->next is x. In this case xPrev & yPrev are same.
        // So the statement "xPrev->next = y" create a self loop, this self loop will be broken when we change y->next
        if(xPrev != NULL){
            xPrev->next = y;

        }
        // same things applies to y
        if(yPrev != NULL){
            yPrev->next = x;
        }

        // swap the next pointer x & y. These statements also break self loop if x->next is y or y->next is x.
        Node *temp = x->next;
        x->next = y->next;
        y->next = temp;

        // change head pointer when k is 1 or n
        if(k == 1){
            return y;
        }
        if(k == size){
            return x;
        }

        return head;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        Node* head = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        int num = arr.size();
        vector<Node*> before(num);
        addressstore(before, head);

        Solution obj;
        obj.swapKthNode(head, k);

        vector<Node*> after(num);
        addressstore(after, head);

        if (check(before, after, num, k))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}