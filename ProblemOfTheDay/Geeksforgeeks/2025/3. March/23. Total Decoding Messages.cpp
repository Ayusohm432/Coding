/*
Problem Link: https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1
*/

/*Total Decoding Messages

A message containing letters A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are given a string digits. You have to determine the total number of ways that message can be decoded.

Examples:

Input: digits = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(1, 2, 3), "LC"(12, 3) and "AW"(1, 23).
Input: digits = "90"
Output: 0
Explanation: "90" cannot be decoded, as it's an invalid string and we cannot decode '0'.
Input: digits = "05"
Output: 0
Explanation: "05" cannot be mapped to "E" because of the leading zero ("5" is different from "05"), the string is not a valid encoding message.
Constraints:
1 ≤ digits.size() ≤ 103

*/

class Solution {
    int mod = 1e9+7;
    int solve(string &str, int n, vector<int>& dp){
        if(n == 0 || n == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int count = 0;
        if(str[n-1] >= '1'){
            count = count + solve(str, n-1, dp) % mod;
        }
        if(str[n-2] == '1' || str[n-2] == '2' && str[n-1] <= '6'){
            count = (count + solve(str, n-2, dp) % mod) % mod;
        }
        
        return dp[n] = count % mod;
    }
  public:
    int countWays(string &digits) {
        // Code here
        int n = digits.length();
        if(digits[0] == '0'){
            return 0;
        }
        vector<int> dp(n+1, -1);
        
        return solve(digits, n, dp);
    }
};