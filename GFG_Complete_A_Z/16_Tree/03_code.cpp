/*
// Tree Traversal: 
    * In simple word we can say, printing every key of the tree exactly once..

    * We have two method: 
        * BFS: Breadth First Search(or Level order): Traverse nodes level by level, Cover later on.. 
        * DFS: Depth First Search: In DFS we go to one side, we finish it completely or traverse it completely, then we go to other side.. 
            * In DFS, we can consider DFS traversal using three task:
                * We need to process the root node.
                * We need to process the left subtree in the same way as we process the whole tree.
                * We need to process the right subtree in the same way as we process the whole tree.   
                * We need to do three things & these three things are recursive in nature: 
                    * Traverse Root
                    * Traverse left Subtree
                    * Traverse right Subtree
                * So we have to factorial 3 permutation, & factorial 3 permutation is 6, & out of the six three are popular: 
                    * Inorder: (left, root, right)
                    * Preorder: (root, left, right)
                    * Postorder: (left, right, root)
                        * left -> leftSubtree
                        * right -> rightSubtree
                * NOTE : In all these traversal left subtree is visited before right subtree.
            * Example: 
                                            [10]
                                             |
                                     [20]---------[30]

                    * Inorder: 20, 10, 30
                    * Preorder: 10, 20, 30
                    * Postorder: 20, 30, 10


            * Example: 
                                            [10]
                                             |
                                    [20]------------[30]
                                     |                |
                              [40]------[50]          -------[60]
                                         |
                                 [70]---------[80]

                    * Inorder: 40, 20, 70, 50, 80, 10, 30, 60
                    * Preorder: 10, 20, 40, 50, 70, 80, 30, 60
                    * Postorder: 40, 70, 80, 50, 20, 60, 30, 10

*/ 
