/*
Problem Link: https://leetcode.com/problems/shortest-common-supersequence?envType=daily-question&envId=2025-02-28
*/

/*1092. Shortest Common Supersequence 

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.

*/

class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int n1 = str1.length();
            int n2 = str2.length();
    
            vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    
            for(int i=0; i<=n1; i++){
                dp[i][0] = i;
            }
    
            for(int j=0; j<=n2; j++){
                dp[0][j] = j;
            }
    
            for(int i=1; i<=n1; i++){
                for(int j=1; j<=n2; j++){
                    if(str1[i-1] == str2[j-1]){
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }else{
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                    }
                }
            }
    
            string superSequence = "";
            int i = n1;
            int j = n2;
    
            while(i > 0 && j > 0){
                if(str1[i-1]  == str2[j-1]){
                    superSequence += str1[i-1];
                    i--;
                    j--;
                }else if(dp[i-1][j] < dp[i][j-1]){
                    superSequence += str1[i-1];
                    i--;
                }else{
                    superSequence += str2[j-1];
                    j--;
                }
            }
    
            while(i > 0){
                superSequence += str1[i-1];
                i--;
            }
    
            while(j > 0){
                superSequence += str2[j-1];
                j--;
            }
    
            reverse(superSequence.begin(), superSequence.end());
            return superSequence;
        }
    };