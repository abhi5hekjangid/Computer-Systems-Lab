This file contains sample outputs of the 'assign4.cpp' file which takes input from 'ip.txt' file.

Time complexity = O(n)(for buiding tree) + O(n*h)(for making tree left tilted here h= height of tree)
                     + O(n^2)(for finding duplicates) + O(n)(for printing tree)
                = O(n^2)

Testcase 1: 
    297 1 1          
    319 0 1      
    124 1 1
    282 0 0       
    530 1 1
    424 0 0
    287 1 1
    214 0 0
    471 0 0
    376 0 1
    173 0 0

    output:
        For the input binary tree

        Preorder : 297 319 282 124 530 287 471 376 173 214 424 
        Inorder : 319 282 297 471 287 376 173 530 214 124 424 

        For the left tilted binary tree

        Preorder : 297 124 530 287 376 173 471 214 424 319 282 
        Inorder : 173 376 287 471 530 214 124 424 297 282 319 

Testcase 2:
    8 1 1
    3 1 1
    10 0 1
    1 0 0
    6 1 1
    14 1 0
    4 0 0 
    7 0 0
    13 0 0

    output:
        For the input binary tree

        Preorder : 8 3 1 6 4 7 10 14 13 
        Inorder : 1 3 4 6 7 8 10 13 14 

        For the left tilted binary tree

        Preorder : 8 3 6 4 7 1 10 14 13 
        Inorder : 4 6 7 3 1 8 13 14 10 

Testcase 3:
    1 0 0
    2 1 0
    3 0 0

    output:
        Invalid Tree.

Testcase 4:
    A 0 0
    2 1 0
    3 0 0

    output:
        Only numeric values are allowed.

Testcase 5:
    1 012 0
    2 1 0
    3 0 0

    output:
        Invalid input for key(node) 1.


Testcase 6:
    1 1 1
    2 1 0
    3 0 0
    4 0 0

    output:
        For the input binary tree

        Preorder : 1 2 4 3 
        Inorder : 4 2 1 3 

        For the left tilted binary tree

        Preorder : 1 2 4 3 
        Inorder : 4 2 1 3

Testcase 7:
    1 1 1
    2 0 0
    1 1 0
    4 0 0

    output:
        Duplicates keys are present.

Testcase 8:
    1 0 
    2 0 0 
    3 0 0

    output:
        Less values than expected in input.

Testcase 9:
    1 0 1
    2 0 1
    3 0 1
    4 0 1
    5 0 0

    output:
        For the input binary tree

        Preorder : 1 2 3 4 5 
        Inorder : 1 2 3 4 5 

        For the left tilted binary tree

        Preorder : 1 2 3 4 5 
        Inorder : 5 4 3 2 1 

Testcase 10:
    1 1 0
    2 1 0
    3 1 0
    4 1 0
    5 0 0

    output:
        For the input binary tree

        Preorder : 1 2 3 4 5 
        Inorder : 5 4 3 2 1 

        For the left tilted binary tree

        Preorder : 1 2 3 4 5 
        Inorder : 5 4 3 2 1 