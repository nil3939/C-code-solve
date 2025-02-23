//https://codeforces.com/problemset/problem/1906/A

#include <bits/stdc++.h>
using namespace std;
char grid[3][3];
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1}; 
int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }
    string smallest = "ZZZ";
    for (int r1 = 0; r1 < 3; r1++) {
        for (int c1 = 0; c1 < 3; c1++) {
            for (int d1 = 0; d1 < 8; d1++) {
                int r2 = r1 + dr[d1];
                int c2 = c1 + dc[d1];
                if (r2 < 0 || r2 >= 3 || c2 < 0 || c2 >= 3) continue;
                for (int d2 = 0; d2 < 8; d2++) {
                    int r3 = r2 + dr[d2];
                    int c3 = c2 + dc[d2];
                    if (r3 < 0 || r3 >= 3 || c3 < 0 || c3 >= 3) continue;
                    if ((r1 != r2 || c1 != c2) && (r1 != r3 || c1 != c3) && (r2 != r3 || c2 != c3)) {
                        string word = "";
                        word += grid[r1][c1];
                        word += grid[r2][c2];
                        word += grid[r3][c3];
                        if (word < smallest) {
                            smallest = word;
                        }
                    }
                }
            }
        }
    }

    cout << smallest << "\n";
    return 0;
}


/* dr[] and dc[]: These arrays define the 8 possible directions (left, right, up, down, and diagonals).
For example:
(-1, 0) means "up."
(0, 1) means "right."
Direction Index	Movement (dr, dc)
0	(-1, -1) (Up-Left)
1	(-1, 0) (Up)
2	(-1, 1) (Up-Right)
3	(0, -1) (Left)
4	(0, 1) (Right)
5	(1, -1) (Down-Left)
6	(1, 0) (Down)
7	(1, 1) (Down-Right)
1. Input the 3x3 Grid
Use a 2D character array grid[3][3] to store the input.
Read 9 characters representing the grid.
Initialize Variables
Direction Arrays (dr, dc):
These represent the 8 possible movements in the grid:
mathematica
Copy
Edit
Up-Left, Up, Up-Right, Left, Right, Down-Left, Down, Down-Right
Copy
Edit
dr[] = {-1, -1, -1, 0, 0, 1, 1, 1}
dc[] = {-1, 0, 1, -1, 1, -1, 0, 1}
smallest:
Set the initial smallest word as "ZZZ". This is the largest possible 3-letter word.
3. Explore All Possible 3-Letter Words
Iterate through every cell (r1, c1) in the grid as the first letter.
Step 1: First Letter Selection
Use two nested loops for rows and columns:
cpp
Copy
Edit
for (int r1 = 0; r1 < 3; r1++) {
    for (int c1 = 0; c1 < 3; c1++) {
Step 2: Second Letter Selection
Explore all 8 directions from the first letter:
cpp
Copy
Edit
for (int d1 = 0; d1 < 8; d1++) {
    int r2 = r1 + dr[d1];
    int c2 = c1 + dc[d1];
Boundary Check: Ensure the second position (r2, c2) is within the grid:
cpp
Copy
Edit
if (r2 < 0 || r2 >= 3 || c2 < 0 || c2 >= 3) continue;
Step 3: Third Letter Selection
From the second letter, again explore all 8 directions:
cpp
Copy
Edit
for (int d2 = 0; d2 < 8; d2++) {
    int r3 = r2 + dr[d2];
    int c3 = c2 + dc[d2];
Boundary Check: Ensure the third position (r3, c3) is within the grid:
cpp
Copy
Edit
if (r3 < 0 || r3 >= 3 || c3 < 0 || c3 >= 3) continue;
Step 4: Ensure All Three Positions Are Unique
Verify that all three selected cells are distinct:
cpp
Copy
Edit
if ((r1 != r2 || c1 != c2) && (r1 != r3 || c1 != c3) && (r2 != r3 || c2 != c3)) {
4. Form the 3-Letter Word
Construct a string using the characters at the three valid positions:
cpp
Copy
Edit
string word = "";
word += grid[r1][c1];
word += grid[r2][c2];
word += grid[r3][c3];
5. Update the Smallest Word
Compare the new word with the current smallest and update if it is smaller:
cpp
Copy
Edit
if (word < smallest) {
    smallest = word;
}
6. Output the Result
Print the lexicographically smallest 3-letter word:
cpp
Copy
Edit
cout << smallest << "\n";
Example Execution Walkthrough:
For the grid:

objectivec
Copy
Edit
BCB
CAC
BCB
Possible 3-letter words:
"BCB", "BCC", "CAC", "ABC", "ACB", "CAB", etc.
Lexicographically smallest:
"ABC".*/
