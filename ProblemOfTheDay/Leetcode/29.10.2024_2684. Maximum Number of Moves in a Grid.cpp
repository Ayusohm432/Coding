/*
Problem Link : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid?envType=daily-question&envId=2024-10-29
*/

/*2684. Maximum Number of Moves in a Grid

You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.

 

Example 1:


Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.
Example 2:


Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
Output: 0
Explanation: Starting from any cell in the first column we cannot perform any moves.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
1 <= grid[i][j] <= 106


*/

class Solution {
public:
    int m;
    int n;

    vector<int> directions = {-1, 0, 1};

    int DFS(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int moves = 0;
        for(int& dir : directions){
            int newRow = row + dir;
            int newCol = col + 1;

            if(newRow >= 0 && newRow < m && newCol >=0 && newCol < n && grid[newRow][newCol] > grid[row][col]){
                moves = max(moves, 1+DFS(newRow, newCol, grid, dp));
            }
        }
        return dp[row][col] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int result = 0;

        vector<vector<int>> dp(m, vector<int>(n,-1));

        for(int row = 0; row < m; row++){
            result = max(result, DFS(row, 0, grid, dp));
        }

        return result;
    }
};