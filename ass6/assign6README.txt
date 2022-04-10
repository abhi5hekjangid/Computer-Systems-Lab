This file contains sample outputs of the 'assign6.cpp' file which takes input from 'ip.txt' file.
Output Filename= op_m($m)n($n)k($k).txt
Time Complexity = O(k*m)(for finding hash values for values in S) + O(n*m*k)(for checking membership and finding collisions)
                = O(n*m*k)

Strategy:- 
        1. First we are finding the hash values for all the numbers belongs to S.
        2. Then we are storing these hash values in a array of size k*m, this array can be used in the future to find collisions.
        3. We are checking for all the numbers not present in set S with addition to some more numbers outside of set U.
        4  Then we are finding hash values for these numbers, after this finding collisions using the array generated in step 1.

Testcase 1: Filename = op_m2n10k4.txt
        2
        2 1 9
        7 3 9
        10
        4
        7 4 11 10

        Output:-
        m = 2
        n = 10
        k = 4
        Bloom filter is 
        1 1 0 1 1 1 1 1 1 0 

        0, false positive yes, collision cases, <10,2>, <10,1>
        1, false positive yes, collision cases, <10,1>, <10,2>
        2, false positive yes, collision cases, <11,1>, <11,2>
        3, false positive yes, collision cases, <7,2>, <7,1>
        5, false positive no.
        6, false positive yes, collision cases, <4,2>, <4,1>
        8, false positive yes, collision cases, <11,2>, <11,1>
        9, false positive yes, collision cases, <10,2>, <10,1>
        12, false positive yes, collision cases, <7,2>, <7,1>
        13, false positive yes, collision cases, <4,1>, <4,2>
        14, false positive no.
        15, false positive yes, collision cases, <4,2>, <4,1>
        Fraction of false positives , p = 0.833333

Testcase 2: Filename = op_m3n10k4.txt
        3
        3 1 5
        7 3 5
        3 4 9
        10
        4
        7 4 3 1

    Output:- 
        m = 3
        n = 10
        k = 4
        Bloom filter is 
        1 1 1 1 1 0 0 1 0 0 

        0, false positive yes, collision cases, <4,2>, <4,1>, <3,2>, <3,3>, <1,1>
        2, false positive yes, collision cases, <7,1>, <7,2>, <7,1>, <7,2>, <4,2>
        5, false positive yes, collision cases, <4,2>, <4,1>, <4,2>
        6, false positive yes, collision cases, <3,2>, <3,3>, <1,1>, <3,1>, <1,2>, <3,2>, <3,3>, <1,1>
        8, false positive yes, collision cases, <3,1>, <1,2>, <3,2>, <3,3>, <1,1>, <4,2>
        9, false positive yes, collision cases, <4,1>, <4,2>, <3,2>, <3,3>, <1,1>
        Fraction of false positives , p = 1

Testcase 3:
        3
        2 1 5
        7 3 7
        3 4 9
        10
        4
        7 4 3 1

        Output:- Filename = op_m3n10k4.txt
        m = 3
        n = 10
        k = 4
        Bloom filter is 
        1 0 1 1 1 0 0 1 0 0 

        0, false positive no.
        2, false positive no.
        5, false positive no.
        6, false positive yes, collision cases, <7,2>, <4,2>, <3,2>, <1,1>, <1,2>, <7,2>, <4,2>, <3,2>, <1,1>, <1,2>, <4,1>, <3,3>
        8, false positive no.
        9, false positive yes, collision cases, <4,1>, <3,3>, <7,2>, <4,2>, <3,2>, <1,1>, <1,2>, <4,1>, <3,3>
        10, false positive no.
        11, false positive no.
        12, false positive yes, collision cases, <7,1>, <7,2>, <4,2>, <3,2>, <1,1>, <1,2>, <4,1>, <3,3>
        13, false positive yes, collision cases, <3,1>, <7,2>, <4,2>, <3,2>, <1,1>, <1,2>, <7,3>, <4,3>, <1,3>
        14, false positive no.
        Fraction of false positives , p = 0.363636

Testcase 4:
        3
        3 1 5
        7 3 5
        3 4 9
        10
        4
        7 4 3 1
    Output:- Filename = op_m3n10k4.txt
        m = 3
        n = 10
        k = 4
        Bloom filter is 
        1 1 1 1 1 0 0 1 0 0 

        0, false positive yes, collision cases, <4,2>, <4,1>, <3,2>, <3,3>, <1,1>
        2, false positive yes, collision cases, <7,1>, <7,2>, <7,1>, <7,2>, <4,2>
        5, false positive yes, collision cases, <4,2>, <4,1>, <4,2>
        6, false positive yes, collision cases, <3,2>, <3,3>, <1,1>, <3,1>, <1,2>, <3,2>, <3,3>, <1,1>
        8, false positive yes, collision cases, <3,1>, <1,2>, <3,2>, <3,3>, <1,1>, <4,2>
        9, false positive yes, collision cases, <4,1>, <4,2>, <3,2>, <3,3>, <1,1>
        10, false positive yes, collision cases, <4,2>, <4,1>, <7,3>, <4,3>, <1,3>
        11, false positive yes, collision cases, <3,2>, <3,3>, <1,1>, <3,1>, <1,2>, <4,2>
        12, false positive yes, collision cases, <7,1>, <7,2>, <7,1>, <7,2>, <3,2>, <3,3>, <1,1>
        13, false positive yes, collision cases, <3,1>, <1,2>, <3,2>, <3,3>, <1,1>, <7,3>, <4,3>, <1,3>
        14, false positive yes, collision cases, <4,1>, <4,2>, <4,2>
        Fraction of false positives , p = 1

 
