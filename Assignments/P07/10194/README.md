## 10194 - Football
### Isha Perry
### Description:



The first line of input will be an integer N in a line alone (0 < N < 1000). Then, will follow N
tournament descriptions. Each one begins with the tournament name, on a single line. Tournament
names can have any letter, digits, spaces etc. Tournament names will have length of at most 100.
Then, in the next line, there will be a number T (1 < T ≤ 30), which stands for the number of teams
participating on this tournament. Then will follow T lines, each one containing one team name. Team
names may have any character that have ASCII code greater than or equal to 32 (space), except for
‘#’ and ‘@’ characters, which will never appear in team names. No team name will have more than 30
characters.

Following to team names, there will be a non-negative integer G on a single line which stands for
the number of games already played on this tournament. G will be no greater than 1000. Then, G
lines will follow with the results of games played. They will follow this format:
team name 1#goals1@goals2#team name 2
For instance, the following line:
Team A#3@1#Team B

Means that in a game between Team A and Team B, Team A scored 3 goals and Team B scored 1.
All goals will be non-negative integers less than 20. You may assume that there will not be inexistent
team names (i.e. all team names that appear on game results will have apperead on the team names
section) and that no team will play against itself.

For each tournament, you must output the tournament name in a single line. In the next T lines you
must output the standings, according to the rules above. Notice that should the tie-breaker be the
lexographic order, it must be done case insenstive. The output format for each line is shown bellow:
[a]) Team name [b]p, [c]g ([d]-[e]-[f]), [g]gd ([h]-[i])
Where:
- [a] = team rank
- [b] = total points earned
- [c] = games played
- [d] = wins
- [e] = ties
- [f] = losses
- [g] = goal difference
- [h] = goals scored
- [i] = goals against
There must be a single blank space between fields and a single blank line between output sets. 



### Files

|   #   | File                       | Description                              |
| :---: | -------------------------- | ---------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | Main file containing solution            |
|   2   | [input1](./input1)         | Input given                              |
|   3   | [input2](./input2)         | Input from debug                         |


### Instructions

- Compiled using c++11 on repl.it

### Sources
- Used sort function
  - //https://github.com/ksaveljev/UVa-online-judge/blob/master/10194.cpp
- Helped make my compare string function
  - //https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
