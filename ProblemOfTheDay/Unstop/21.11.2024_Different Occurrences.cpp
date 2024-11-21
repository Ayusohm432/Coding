/*
Problem Link : https://unstop.com/code/practice/261231
*/

/*Different Occurrences

Problem Statement
Jack is given a string S of length N. Bob provides Jack with a query string "query" of length M. Jack wants to determine how many times Bob's query appears as a subsequence in his string S.

Help Jack count the number of times Bob's query can be found as a subsequence in the string S.

Note: The characters in the subsequence must appear in the same order as they are in the query string when choosing them from string S.

Input Format
The first line of input consists of two space-separated strings, S and query, with lengths N and M, respectively.

Output Format
Display a single integer representing the number of times Bob's query appears as a subsequence in Jack's string S.

Constraints
1 ≤ | N | ≤ 10^2
1 ≤ | M | ≤ 10^2

Sample Testcase 0
Testcase Input
competitive ti
Testcase Output
3
Explanation
There are 3 sub-sequences:
t at index 5 and i at index 6 = "ti"
t at index 5 and i at index 8 = "ti"
t at index 7 and i at index 8 = "ti"

Sample Testcase 1
Testcase Input
banana ban

Testcase Output
3
Explanation
There are 3 sub-sequences: 
b from 0th index, a from 1st index and n from 2nd index = "ban"
b from 0th index, a from 1st index and n from 4th index = "ban"
b from 0th index, a from 3rd index and n from 4th index = "ban"

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countSubsequences(string S, string query) {
    int n = S.length();
    int m = query.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(S[i-1] == query[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    string S, query;
    cin >> S >> query;
    
    cout << countSubsequences(S, query) << endl;
    
    return 0;
}