/*
Problem Link :- https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1
*/


/*Wildcard Pattern Matching

Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.

The wildcard pattern can include the characters ? and *
‘?’ – matches any single character.
‘*’ – Matches any sequence of characters (including the empty sequence).

Note: The matching should cover the entire str (not partial str).

Examples:

Input: pattern = "ba*a?", str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'.
Input: pattern = "a*ab", str = "baaabab"
Output: 0
Explanation: Because in string pattern character 'a' at first position,
pattern and str can't be matched. 
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 <= length of(str, pattern) <= 200


*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


// } Driver Code Ends
class Solution {
    int help(string pattern , string str , int i , int j , vector<vector<int>>& dp){
        if(i == pattern.length() && j == str.length()){
            return 1;
        }
        if(i == pattern.length()){
            return false;
        }
        if(j == str.length() && pattern[i] == '*'){
            return help(pattern , str , i+1 , j , dp);
        }
        if(j == str.length()){
            return false;
        }
        if(pattern[i] != '?' && pattern[i] != '*' && pattern[i] != str[j]){
            return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int a = 0 , b = 0 , c = 0;
        if(pattern[i] == '*'){
            a = help(pattern , str , i+1 , j , dp);
            b = help(pattern , str , i , j+1 , dp);
        }
        c = help(pattern , str , i+1 , j+1 , dp);
        return dp[i][j] =  a|b|c;
    }
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        vector<vector<int>> dp(pattern.length() , vector<int>(str.length() , -1 ));
        return help(pattern , str , 0 ,0 , dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends