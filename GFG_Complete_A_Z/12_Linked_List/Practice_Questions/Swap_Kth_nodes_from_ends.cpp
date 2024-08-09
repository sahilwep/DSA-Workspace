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

                * The swapping logic that we are doing in array, we have to perform similary, but we need to take care about previous & next nodes that we are swapping:

                * Edge case: 
                    * when we are swapping 1'st nodes from starting & end, 
                    * then we have to take care about last previous, & first next nodes, because nodes contains links..


                            [1]-->[5]-->[3]-->[4]-->[2]-->[6]
                             |                             |
                        swapped                         swapped

                            [Head node ref]           [end Node Ref]
                                t1                          t2
                            
                        * These are the two operations that we have to preform:
                            t2->next = head->next   // changing the last node ref to the first node ref..
                            t1->next = NULL

                        * First ref contains the location of r1 = head->next
                        * second ref contains the location of r2 = secondLast (we can find this location by iterating)


                * 






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
    Node* swapkthnode(Node* head, int k) {
        // first we have to find the size of linked list, & work accordingly:
        Node * c1 = head;
        int size = 1;
        while(c1->next != NULL){
            c1 = c1->next;
            size++;
        }
        // case when given kth value is grater than the size..
        if(k > size){
            return head;
        }

        // Edge case when k = 1 & size = 1
        if(size == 1 && k == 1){
            return head;
        }

        // handling k = 1: 
        if(k == 1){
            // storing the reference: 
            Node *c2 = head;
            while(c2->next->next != NULL){
                c2 = c2->next;
            }
            Node *t1 = head->next;   // storing the reference of first node.
            Node *t2 = c2;    // storing second last node reference.
            c2 = c2->next;  // changing the reference of current iterator.

            // changing the reference: 
            t2->next = t1;
            t1->next = c2;


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
        obj.swapkthnode(head, k);

        vector<Node*> after(num);
        addressstore(after, head);

        if (check(before, after, num, k))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}