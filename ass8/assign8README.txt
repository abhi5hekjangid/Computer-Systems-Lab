//2111CS01
// cpi is [0,10]
//Name is a combination of alphabets
//Roll No is combination of alphanumeric values

Testcase 1:
    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh createTable.sh CPI.tab RollNo Name CPI
    NEW TABLE 'CPI.tab' WITH FIELDS 'RollNo', 'Name', 'CPI' CREATED

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh insertRecord.sh CPI.tab -r "2111CS01" -n "Abhishek" -c 8.7
    RECORDS ADDED TO 'CPI.tab' relation  'RollNo' 2111CS01, 'Name' Abhishek and 'CPI' 8.7

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh insertRecord.sh CPI.tab 2
    Record 1
    ENTER VALUES FOR RollNo:
    2111CS17
    ENTER VALUES FOR Name:
    Sujay
    ENTER VALUES FOR CPI:
    8.5
    Record 2
    ENTER VALUES FOR RollNo:
    2111CS19
    ENTER VALUES FOR Name:
    Shaubhik
    ENTER VALUES FOR CPI:
    8.3
    2 RECORDS ADDED TO 'CPI.tab' relation

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ cat CPI.tab
    RollNo Name CPI
    2111CS01 Abhishek 8.7
    2111CS17 Sujay 8.5
    2111CS19 Shaubhik 8.3

Testcase 2
    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh updateRecord.sh CPI.tab -r "2111CS17" CPI 8.7
    RECORD WITH ROLLNO '2111CS17' IS UPDATED in 'CPI.tab' table

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh updateRecord.sh CPI.tab -r "2111CS17" CPI 8.7
    RECORD WITH ROLLNO '2111CS17' IS UPDATED in 'CPI.tab' table
    
Testcase 3:
    $ sh updateRecord.sh CPI.tab -r "2111CS01" RollNO "2111cs01"
    RECORD WITH ROLLNO '2111CS01' IS UPDATED in 'CPI.tab' table

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ cat CPI.tab
    RollNo Name CPI
    2111cs01 Abhishek Jangid
    2111CS17 Sujay Varma 8.7
    2111CS19 Shaubhik 8.3

Testcase 4:
    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh updateRecord.sh CPI.tab -r 2111cs01 rollno 2111CS01
    RECORD WITH ROLLNO '2111cs01' IS UPDATED in 'CPI.tab' table

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh updateRecord.sh CPI.tab -r 2111CS01 cpi 9.0
    RECORD WITH ROLLNO '2111CS01' IS UPDATED in 'CPI.tab' table

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ cat CPI.tab
    RollNo Name CPI
    2111CS01 Abhishek 9.0
    2111CS17 Sujay Varma 8.7
    2111CS19 Shaubhik 8.3

Testcase 5:
    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh updateRecord.sh NEW.tab -r "25" rollno 2111cs01
    No Record with given RollNo

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ cat NEW.tab
    ROLL NAMe date
    2111cs01 Abhishek 5
    2111cs02 Abhishek 4
    2111cs03 Abhishek 4
    2111cs04 Abhishek 4
    2111cs01 Abhishek 5
    2111cs01 Abhishek 5
    20 aa 2
    2111cs01 bb 3
    2111cs01 vv 4

Testcase 6:
    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh insertRecord.sh CPI.tab -r 2111CS01 -n Abhishek -c 5
    ROLLNO already exists.

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ cat CPI.tab
    RollNo Name CPI
    2111CS01 Abhishek 9.0
    2111CS17 Sujay Varma 8.7
    2111CS19 Shaubhik 8.3

Testcase 7:
    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ cat CPI.tab
    RollNo Name CPI
    2111CS01 Abhishek 9.0
    2111CS17 Sujay Varma 8.7
    2111CS19 Shaubhik 8.3

    abhis@MSI MINGW64 ~/Documents/c++/CS515/ass8
    $ sh insertRecord.sh CPI.tab -r 2111CS11 -n 5 -c 5
    Name should not be an integer.
