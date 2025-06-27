/*
Problem Link: https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
*/

/*Mobile numeric keypad

There is a standard numeric keypad on a mobile phone. You can press the current button or any button that is directly above, below, to the left, or to the right of it. For example, if you press 5, then pressing 2, 4, 6, or 8 is allowed. However, diagonal movements and pressing the bottom row corner buttons (* and #) are not allowed.


Given an integer n, determine how many unique sequences of length n can be formed by pressing buttons on the keypad, starting from any digit.

Examples :

Input: n = 1
Output: 10
Explanation: Possible 1-digit numbers follow keypad moves - From 0 → 0, 1 → 1, 2 → 2 and so on, total 10 valid combinations are possible.
Input: n = 2
Output: 36
Explanation: Possible 2-digit numbers follow keypad moves -
From 0 → 00, 08 (2), 
From 1 → 11, 12, 14 (3),
From 3 → 33, 32, 36 (3), and so on,
total 36 valid combinations are possible.
Constraints:
1 ≤ n ≤ 15

*/

class Solution {
  public:
  
    long long help(int i , int j , int n , vector<vector<vector<long long>>> &dp){
        if(i>3 or j>2 or i<0 or j<0){
            return 0;
        }
        if(i==3 and (j==0 or j==2)){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[i][j][n] != -1){
            return dp[i][j][n];
        }
        n--;
        return dp[i][j][n+1] = help(i-1,j,n,dp)+help(i,j-1,n,dp)+help(i+1,j,n,dp)+help(i,j+1,n,dp)+help(i,j,n,dp);
    }
    long long getCount(int n) {
        // Your code goes here
        long long ans=0;
        
        vector<vector<vector<long long>>> dp(4,vector<vector<long long>>(3,vector<long long>(n+1,-1)));
        
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<3 ; j++){
                if(i==3 and (j==0 or j==2)){
                    continue;
                }
                ans += help(i,j,n,dp);
            }
        }
        return ans;
    }
};
