/*
// Tree Data Structure: 
    * Hierarchial data store in Tree structure: Non-liner data structure..
        * Example: 
            * Organization structure..
            * File storage structure...


                                  [10]
                                    |
                        [20]-----------------[30]
                         |                     |
                [40]----------[5]      [8]---[30]----[80]
                                               |
                                         [70]------[9]

    * Node: All the item that are in the tree, they are called node in the tree.
        * Example: {10, 20, 30, 40, 5, 8, 30, 80, 70, 9}

    * Root: Top of the hierarchy, we have root node.
        * Example: {10}

    * Leaf: Node that are bottom of the hierarchy, or node that has no node below them are known as leaf node.
        * Example: {40, 5}, {8}, {70, 9}, {80}

    * Child: Nodes that are just below the node are called children nodes.
        * Example: child of 10 : {20, 30}

    * Parent: Node that are just above a node is called parent node.
        * Example: parent of 20 is 10

    * Subtree: Tree DS, are recursive in nature, & tree itself contains many subtree, & these parts of tree are called subtrees.
        * Example:  subtree: {20, 40, 5}, {30, 70, 90}

    * Descendants: Descendants of node are all the nodes that lies in the subtree with this particular node as root   
        * Example: Descendants of 20 : subtree {40, 5}

    * Ancestors: An ancestor of a node is any other node on the path from the node to the root.
        * Example: ancestor of 40 is : {20, 10}

    * Degree: Degree of node is number of children it has: 
        * Example: degree of 20 is : 2, degree of 30 is : 3
        * Note : all the leaf node has degree '0'
    
    * Internal Node: All the node that are not a leaf node are called internal node
        * Example: {20, 30, 30, 10} 

// Application of tree data structure: 
    * To represent Hierarchial data: 
        * Organization Structure
        * Folder Structure
        * XML/HTML Content(JSON objects)
        * In OOP (Inheritance)
    
    * Binary Search Tree
    * Binary Heap: Used to represent priority queue: Priority queue are used to implement dijkstra algo, Huffman algo, Prims algo or any other place where we need a queue with priority...
    * B & B+ Tree are used in DBMS : Used to implement indexing..
    * Spanning & shortest path tree in computer networks
    * Parse Tree, Expression tree in compilers
    * More Variation of tree are used in practice: 
        * Trie: Used to represent dictionary, It's also support operations like prefix search...
        * Suffix Tree: Suffix tree is used to do fast searches in string, When we have pattern & when we have text
        * Binary Index Tree: Used for search in range index query
        * Segment Tree: Same as Binary index tree

*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(void){
    
    
    
    
    return 0;
}