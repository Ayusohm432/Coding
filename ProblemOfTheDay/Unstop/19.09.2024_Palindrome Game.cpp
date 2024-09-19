/*
Problem Link : https://unstop.com/code/practice/250597
*/

/*Palindrome Game

Problem Statement
Alice loves palindromes. So She has been given a string a length n and she wants to figure out the minimum cost in which she can convert the given string to a palindrome. Remember in one step she can insert any character at any position but the cost of that operation will be one.  

Input Format
The input consists of a single line containing the string str.

Output Format
Output a single integer representing the minimum cost to make the string a palindrome.

 
Constraints
 1 <= str.length <= 500

Sample Testcase 0
Testcase Input
zzazz 
Testcase Output
0
Explanation
We don't need to append anything since the string "zzazz" is already a palindrome.
Sample Testcase 1
Testcase Input
mbadm
Testcase Output
2
Explanation
"mbdadbm" or "mdbabdm" are two possible strings. So 2 cost will be required.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LCS(string s1, string s2) {
    int n = s1.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int minInsertionsToMakePalindrome(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    int lcsLength = LCS(str, revStr);

    return str.length() - lcsLength;
}

int main() {
    string str;
    cin >> str;
    cout << minInsertionsToMakePalindrome(str) << endl;
    return 0;
}
