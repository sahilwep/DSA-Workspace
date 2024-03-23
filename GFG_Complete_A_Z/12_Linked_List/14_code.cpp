/*
// Singly Linked list v/s Doubly linked list:

    // Singly LL:
        * maintain only next pointer.

    // Doubly LL: 
        * maintain both next, & prev pointer

    Complexity:         Singly linked list      |       Doubly linked list
    insertion beg:              O(1)            |           O(1)
    insertion end:              O(n)            |           O(n), (O(1), if the tail pointer is maintained)
    deletion  beg:              O(1)            |           O(1)
    deletion  end:              O(n)            |           O(n), (O(1), if the tail pointer is maintained)
    traversal:                  O(n)            |           O(n)

*/