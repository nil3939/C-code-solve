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
