/*
Problelm Link : https://leetcode.com/problems/count-square-submatrices-with-all-ones?envType=daily-question&envId=2024-10-27
*/

/*1277. Count Square Submatrices with All Ones

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/

//Approach-1 (Recursion + Memorization)
class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i >= m || j >= n){
            return 0;
        }

        if(matrix[i][j] == 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(i, j+1, matrix, dp);
        int diagonal = solve(i+1, j+1, matrix, dp);
        int below = solve(i+1, j, matrix, dp);

        return dp[i][j] = 1 + min(right, min(diagonal, below));
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int result = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    result += solve(i, j, matrix, dp);
                }
            }
        }    
        return result;
    }
};

//Approach-2 (Bottom Up)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j];
                }
                else if(matrix[i][j] == 1){
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                }
                result += dp[i][j];
            }
        }    
        return result;
    }
};