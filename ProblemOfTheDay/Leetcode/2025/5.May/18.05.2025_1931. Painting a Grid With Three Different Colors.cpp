/*
Problem Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors?envType=daily-question&envId=2025-05-18
*/

/*1931. Painting a Grid With Three Different Colors

You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.
Example 2:


Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.
Example 3:

Input: m = 5, n = 5
Output: 580986
 

Constraints:

1 <= m <= 5
1 <= n <= 1000

*/

class Solution {
    int mod  = 1e9+7;
    int dp[1000+2][1023];

    int ways(int& m, int& n, int r, int c, int curr, int prev){
        if(c == n){
            return 1;
        }
        if(r == m){
            return ways(m, n, 0, c+1, 0, curr);
        }
        if(r == 0 && dp[c][prev] != -1){
            return dp[c][prev];
        }

        int topColor = 0;
        if(r > 0){
            topColor = curr & 3;
        }

        int leftColor = (prev >> ((m-r-1)*2)) & 3;

        int currWays = 0;
        for(int i=1; i<=3; i++){
            if(i != topColor && i != leftColor){
                currWays = (currWays + ways(m, n, r+1, c, (curr << 2)+i, prev)) % mod;
            }
        }

        if(r == 0){
            dp[c][prev] = currWays;
        }

        return currWays;
    }
public:
    int colorTheGrid(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return ways(m, n, 0, 0, 0, 0);
    }
};