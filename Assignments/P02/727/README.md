## 727 - Equation
### Isha Perry
### Description:

The infix expression to be converted is in the input file in the format of one character per line. 
The input starts with an integer on a line by itself indicating the number of test cases. Several 
infix expressions follows, preceded by a blank line. The program will only be designed to handle 
the binary operators +, -, x, /. The operands will be one digit numerals. The operators * and / have 
the highest priority. The operators + and - have the lowest priority. Operators at the same precedence 
level associate from left to right. Parentheses act as grouping symbols that over-ride the operator 
priorities. Each testcase will be an expression with valid syntax. The output file will have each 
postfix expression all on one line. Print a blank line between different expressions.


### Files

|   #   | File                       | Description                              |
| :---: | -------------------------- | ---------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | Main file containing solution            |
|   2   | [input1](./input1)         | Input given                              |
|   3   | [input2](./input2)         | Input from debug                         |


### Instructions

- Compiled using c++11 on repl.it

### Sources
- Checks if char is number
  - https://www.interviewsansar.com/isdigit-c-check-if-char-is-digit/
