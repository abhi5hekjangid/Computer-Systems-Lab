This file contains the ouput of the 'midsem.cpp' program which takes input from 'ip.txt' file.

Time Complexity = O(n)(for creating tree) + O(n)(for finding farthest node) 
                    + O(n)(in worst case for right rotating tree at particular value)
                    + O(n)(for checking if tree is valid or not)
                = O(n)
            
I am using Queue data structure for creating binary search tree in level order traversal.
Also to finding farthest nodes, first I am finding the height of BST and then I am finding all the leaf nodes
with height equal to height of the tree.
For making right rotation, I am finding the node which has data as entered key and after that 
I am checking if we can make right rotation or not, If we can make, I am making the right rotating calls.

Sample outputs:

    Testcase 1:
        Input:
            48 38 60
            38 31 -1
            60 56 -1
            31 15 34
            56 -1 -1
            15 -1 25
            34 -1 -1
            25 -1 -1
        
        Output:
            the preorder traversal of the tree is 48 38 31 15 25 34 60 56 
            the inorder traversal of the tree is 15 25 31 34 38 48 56 60 

            For the aforementioned example, the farthest leaf node(s): 25 
            The distance of the leaf from the root is: 4

            For the aforementioned example,
            Enter key value for right rotation: 15

            Right rotation w.r.t 15 is not possible.
    
    Testcase 2:
        Input:
            48 38 60
            38 31 -1
            60 56 -1
            31 15 34
            56 -1 -1
            15 -1 25
            34 -1 -1
            25 -1 -1
        
        Output:
            the preorder traversal of the tree is 48 38 31 15 25 34 60 56 
            the inorder traversal of the tree is 15 25 31 34 38 48 56 60

            For the aforementioned example, the farthest leaf node(s): 25
            The distance of the leaf from the root is: 4

            For the aforementioned example,
            Enter key value for right rotation: 31

            Right rotation w.r.t 31 is possible.
            The tree after right rotation.

            the preorder traversal of the tree is 48 38 15 31 25 34 60 56
            the inorder traversal of the tree is 15 25 31 34 38 48 56 60

    Testcase 3:
        Input:
            13 10 15
            10 5 11 
            15 -1 16
            5 4 8
            11 -1 -1
            16 -1 -1
            4 3 -1
            8 -1 -1
            3 -1 -1
        
        Output:
            the preorder traversal of the tree is 13 10 5 4 3 8 11 15 16 
            the inorder traversal of the tree is 3 4 5 8 10 11 13 15 16

            For the aforementioned example, the farthest leaf node(s): 3
            The distance of the leaf from the root is: 4

            For the aforementioned example,
            Enter key value for right rotation: 10

            Right rotation w.r.t 10 is possible.
            The tree after right rotation.

            the preorder traversal of the tree is 13 5 4 3 10 8 11 15 16
            the inorder traversal of the tree is 3 4 5 8 10 11 13 15 16
    
    Testcase 4:
        Input:
            48 38 60
            38 31 50
            60 56 -1
            31 15 34
            56 -1 -1
            15 -1 25
            34 -1 -1
            25 -1 -1
        
        Output:
            Invalid Tree.
        
    Testcase 5:
        Input:
            A 38 60
            38 31 -1
            60 56 -1
            31 15 34
            56 -1 -1
            15 -1 25
            34 -1 -1
            25 -1 -1
        
        Output:
            Only numeric values are allowed.

    Testcase 6:
        48 38 60
        38 31 -1
        60 56 0
        31 15 34
        56 -1 -1
        15 -1 25
        34 -1 -1
        25 -1 -1

        Output:
            Invalid Tree.