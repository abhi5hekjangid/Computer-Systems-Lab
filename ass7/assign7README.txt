//2111cs01
This file contains outputs of the file assign7.cpp which take input from user given file and outputs data to user give file.
Time Complexity : O(V+E)(for cycle detection) + O(V+E)(for printing graph)
                : O(V+E)

This file takes input from user file and then stores the edges in a adjacency list. After that we have three different functions for printing the whole,
red and blue graph. After this we have a 'cyc' array which stores the node which is currently under execution in dfs call. When our dfs finds the node which is
already visited then we print the cyc array from last till we get the same node from which we started printing.

Testcase 1:
    Input:
        10
        r b r r b r r b b b
        0 1, 0 2, 0 3, 1 3, 1 4, 1 7, 2 3, 2 5, 3 6, 4 7, 4 8, 5 6, 5 9, 6 7, 7 8, 8 9, -1

    Output:
        
        Original Graph
        0 -> 1, 2, 3
        1 -> 0, 3, 4, 7
        2 -> 0, 3, 5
        3 -> 0, 1, 2, 6
        4 -> 1, 7, 8
        5 -> 2, 6, 9
        6 -> 3, 5, 7
        7 -> 1, 4, 6, 8
        8 -> 4, 7, 9
        9 -> 5, 8

        Red SubGraph
        0 -> 2, 3, 
        2 -> 0, 3, 5, 
        3 -> 0, 2, 6, 
        5 -> 2, 6, 
        6 -> 3, 5, 

        Blue SubGraph
        1 -> 4, 7, 
        4 -> 1, 7, 8, 
        7 -> 1, 4, 8, 
        8 -> 4, 7, 9, 
        9 -> 8, 

        Red Cycles 

        0-2-3-0 color (r-r-r-r)
        2-3-6-5-2 color (r-r-r-r-r)

        Blue Cycles 

        1-4-7-1 color (b-b-b-b)
        4-7-8-4 color (b-b-b-b)

        Multi Color Cycles 

        0-1-3-0 color (r-b-r-r)
        3-2-5-6-3 color (r-r-r-r-r)
        2-3-6-5-2 color (r-r-r-r-r)
        6-5-9-8-4-7-6 color (r-r-b-b-b-b-r)
        4-7-6-5-9-8-4 color (b-b-r-r-b-b-b)
        5-6-7-8-9-5 color (r-r-b-b-b-r)

Testcase 2:
    Input:
        5
        r r r b b
        0 1, 0 2, 0 3, 1 2, 3 4, -1
    Output:
                
        Original Graph
        0 -> 1, 2, 3
        1 -> 0, 2
        2 -> 0, 1
        3 -> 0, 4
        4 -> 3

        Red SubGraph
        0 -> 1, 2, 
        1 -> 0, 2, 
        2 -> 0, 1, 

        Blue SubGraph
        3 -> 4, 
        4 -> 3, 

        Red Cycles 

        0-1-2-0 color (r-r-r-r)

        Blue Cycles 
        No cycle detected

        Multi Color Cycles 

        0-1-2-0 color (r-r-r-r)

Testcase 3:
    Input:
        5
        r r r b b
        0 2, 0 3, 1 2, 3 4, -1
        
    Output:        
        Original Graph
        0 -> 2, 3
        1 -> 2
        2 -> 0, 1
        3 -> 0, 4
        4 -> 3

        Red SubGraph
        0 -> 2, 
        1 -> 2, 
        2 -> 0, 1, 

        Blue SubGraph
        3 -> 4, 
        4 -> 3, 

        Red Cycles 
        No cycle detected

        Blue Cycles 
        No cycle detected

        Multi Color Cycles 
        No cycle detected

Testcase 4:
    Input:
        10
        r b g r b r r b b b
        0 1, 0 2, 0 3, 1 3, 1 4, 1 7, 2 3, 2 5, 3 6, 4 7, 4 8, 5 6, 5 9, 6 7, 7 8, 8 9, -1

    Output:
        Incompatible Input Values.

Testcase 5:
    Input:
        A
        r b g r b r r b b b
        0 1, 0 2, 0 3, 1 3, 1 4, 1 7, 2 3, 2 5, 3 6, 4 7, 4 8, 5 6, 5 9, 6 7, 7 8, 8 9, -1

    Output:
        Only numeric values are allowed.

