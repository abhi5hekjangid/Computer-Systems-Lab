This file contains sample outputs of the 'assign2.cpp' file which takes input from 'ip.txt' file.

Testcase 1:
    2000000000
    8888888888

    Comparison result: first number is lesser than the second number
    Addition result: 1,08888,88888
    Subtraction result: -68888,88888

Testcase 2:
    -2000000000
    8888888888

    -2->00000->20000
    2->88888->88888

    Comparison result: first number is lesser than the second number
    Addition result: 68888,88888
    Subtraction result: -1,08888,88888


Testcase 3:
    2000000000
    -8888888888

    2->00000->20000
    -2->88888->88888

    Comparison result: first number is greater than the second number
    Addition result: -68888,88888
    Subtraction result: 1,08888,88888


Testcase 4:
    -2000000000
    -8888888888

    -2->00000->20000
    -2->88888->88888

    Comparison result: first number is greater than the second number
    Addition result: -1,08888,88888
    Subtraction result: 68888,88888


Testcase 5:
        0
    8888888888

    1->0
    2->88888->88888

    Comparison result: first number is lesser than the second number
    Addition result: 88888,88888
    Subtraction result: -88888,88888

Testcase 6:
    0
    -8888888888
    
    
    1->0
    -2->88888->88888

    Comparison result: first number is greater than the second number
    Addition result: -88888,88888
    Subtraction result: 88888,88888

Testcase 7:
    8888888888
    0

    2->88888->88888
    1->0

    Comparison result: first number is greater than the second number
    Addition result: 88888,88888
    Subtraction result: 88888,88888

Testcase 8:
    -8888888888
    0

    -2->88888->88888
    1->0

    Comparison result: first number is lesser than the second number
    Addition result: -88888,88888
    Subtraction result: -88888,88888

Testcase 9:
    -8888
    -8888

    -1->8888
    -1->8888

    Comparison result: first number is equal to the second number
    Addition result: -17776
    Subtraction result: 0

Testcase 10:
    0
    0

    1->0
    1->0

    Comparison result: first number is equal to the second number
    Addition result: 0
    Subtraction result: 0


Testcase 11:
    2000000000.12334
    8888888888.1222

    Only numbers allowed inside input.

Testcase 12:
    ABCD
    8888888888


    Only numbers allowed inside input.

Testcase 13:
    1234
    12111111111
    8888888888

    More than 2 Numbers.

Testcase 14:
    -0
    8888888888

    -0 invalid.

Testcase 15:
    -8888888888
    2000000000

    -2->88888->88888
    2->00000->20000

    Comparison result: first number is lesser than the second number
    Addition result: -68888,88888
    Subtraction result: -1,08888,88888

