/*
Problem link :- https://www.geeksforgeeks.org/problems/edit-distance3702/1
*/


/*Edit Distance


Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.
Input : str1 = "gfg", str2 = "gfg"
Output: 0
Explanation: Both strings are same.
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ str1.length(), str2.length() ≤ 100
Both the strings are in lowercase.



*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include <vector>

using namespace std;


// } Driver Code Ends
class Solution {
    int fun(int i , int j , string s1 , string s2 ,vector<vector<int>>& dp){
        if(i == s1.size() && j == s2.size()){
            return 0;
        }
        if(i > s1.size() || j > s2.size()){
            return 1e9;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        
        int p = 1e9;
        if(s1[i] == s2[j]){
            p = fun(i+1 , j+1 , s1 , s2 , dp);
        }
        
        int opr1 = 1 + fun(i+1 , j , s1 , s2 , dp);
        int opr2 = 1 + fun(i , j+1 , s1 , s2 , dp);
        int opr3 = 1 + fun(i+1 , j+1 , s1 , s2 , dp);
        
        return dp[i][j] = min(p , min(opr1 , min(opr2 , opr3)));
    }
  public:
    int editDistance(string str1, string str2) {
        // Code here
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        return fun(0 , 0 , str1 , str2 , dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends