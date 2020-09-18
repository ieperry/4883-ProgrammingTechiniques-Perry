## 540 - Team Queue
### Isha Perry
### Description:

The input file will contain one or more test cases. Each test case begins with the number of teams
t (1 ≤ t ≤ 1000). Then t team descriptions follow, each one consisting of the number of elements
belonging to the team and the elements themselves. Elements are integers in the range 0..999999. A
team may consist of up to 1000 elements. Finally, a list of commands follows. There are three 
different kinds of commands:
- ENQUEUE x — enter element x into the team queue
- DEQUEUE — process the first element and remove it from the queue
- STOP — end of test case
The input will be terminated by a value of 0 for t. For each test case, first print a line saying
‘Scenario #k’, where k is the number of the test case. Then, for each ‘DEQUEUE’ command, print the 
element which is dequeued on a single line. Print a blank line after each test case, even after the last one.


### Files

|   #   | File                       | Description                              |
| :---: | -------------------------- | ---------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | Main file containing solution            |
|   2   | [input1](./input1)         | Input given                              |
|   3   | [input2](./input2)         | Input from debug                         |


### Instructions

- Compiled using c++11 on repl.it
