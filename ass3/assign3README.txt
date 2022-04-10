This file contains sample outputs of the 'assign1.cpp' file which takes input from 'ip.txt' file.

Testcase 1:
    15
    10
    30
    101 0 MW
    102 20 MD
    103 22 MD
    104 24 DD
    105 28 MD

    output:- 
    101,0,15,15
    102,20,30,10
    103,22,32,10
    104,24,60,36
    105,28,42,14
    Average waiting time is 17

Testcase 2:
    15
    10
    30
    101 0 MW
    102 0 MD
    103 2 MD
    104 4 DD
    105 10 MD

    output:-
    101,0,15,15
    102,0,10,10
    103,2,20,18
    104,4,45,41
    105,10,30,20
    Average waiting time is 20.8

Testcase 3:- 
    1A
    10
    30
    101 0 MW
    102 0 MD
    103 2 MD
    104 4 DD
    105 10 MD

    output:-
    Invalid Time for service.

Testcase 4:
    15
    10
    30
    101 0 A
    102 0 MD
    103 2 MD
    104 4 DD
    105 10 MD

output:
    Invalid request type.

Testcase 5:
    
    15
    10
    30
    101 0 MW
    102 0 MD
    103 0 MD
    104 0 DD
    105 0 MD

    output-
    101,0,15,15
    102,0,10,10
    103,0,20,20
    104,0,45,45
    105,0,30,30
    Average waiting time is 24

Testcase 6:
    15
    10
    30
    101 10 MD
    102 0 MD
    103 15 MD
    104 0 MD
    105 20 MD

    output:-
    101,10,20,10
    102,0,10,10
    103,15,25,10
    104,0,10,10
    105,20,30,10
    Average waiting time is 10

Testcase 7:
    1.5
    10
    30
    101 10 MD
    102 0 MD
    103 15 MD
    104 0 MD
    105 20 MD

    output:-
    Invalid Time for service.

Testcase 7:
    15
    10
    30
    101 10 MD
    102 0 MD
   
    output:-
    101,10,20,10
    102,0,10,10
    Average waiting time is 10