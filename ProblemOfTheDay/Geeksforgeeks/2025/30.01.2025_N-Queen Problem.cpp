/*
Problem Link: https://www.geeksforgeeks.org/problems/n-queen-problem0315/1
*/

/*N-Queen Problem

The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
For eg. below figure represents a chessboard [3 1 4 2].



Examples:

Input: n = 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.
Input: n = 4
Output: [[2 4 1 3 ] [3 1 4 2 ]]
Explaination: There are 2 possible solutions for n = 4.
Input: n = 2
Output: []
Explaination: There are no possible solutions for n = 2.
Constraints:
1 ≤ n ≤ 10

*/

class Solution {
private:
    void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
        vector<int> temp;
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                if (board[row][col] == 1) {
                    temp.push_back(row + 1); 
                    break;
                }
            }
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        int x = row, y = col;

        while (y >= 0) {
            if (board[x][y] == 1) return false;
            y--;
        }

        x = row, y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 1) return false;
            x--;
            y--;
        }
        x = row, y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 1) return false;
            x++;
            y--;
        }

        return true; 
    }

    void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans) {
        if (col == n) {
            addSolution(ans, board, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;  
                solve(col + 1, n, board, ans);  
                board[row][col] = 0;  
            }
        }
    }

public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans; 
        solve(0, n, board, ans); 
        return ans; 
    }
};