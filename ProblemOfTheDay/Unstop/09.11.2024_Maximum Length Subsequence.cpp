/*
Problem Link : https://unstop.com/code/practice/295753
*/

/*Maximum Length Subsequence

Problem Statement
You are given a string str of size N made up of lowercase English letters.

Your task is to find if the maximum length of a subsequence (where the difference between the ASCII values of consecutive characters is exactly 2) is a prime number. If it is, print 1. Otherwise, print 0.

Note: If the maximum length of the subsequence is 1 , print 0.

Input Format
The first line of input contains a single string str consisting of lowercase English letters. 

Output Format
Display 1 if the maximum length of a valid subsequence is a prime number, otherwise Display 0.

Constraints
1 <= |N| <= 10^6

Sample Testcase 0
Testcase Input
aad
Testcase Output
0
Explanation
Only a single length subsequence and the difference of their ASCII value is not exactly 2. Hence the answer is 0.

Sample Testcase 1
Testcase Input
ac
Testcase Output
1
Explanation
The subsequence “ac” follows the condition, i.e., the difference between the two characters is 2.


And the length of the subsequence = 2 is a prime number. Hence 1 is printed.

*/

#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long int

bool isPrime(ll n) {
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll solve(string str) {
    unordered_map<char, ll> dp; 

    for (char c : str) {
        if (dp.count(c - 2)) {
            dp[c] = max(dp[c], dp[c - 2] + 1);
        } else {
            dp[c] = max(dp[c], 1LL); 
        }
        if (dp.count(c + 2)) {
            dp[c] = max(dp[c], dp[c + 2] + 1);
        } else {
            dp[c] = max(dp[c], 1LL); 
        }
    }

    ll maxLength = 0;
    for (auto &entry : dp) {
        maxLength = max(maxLength, entry.second);
    }

    return maxLength;
}

int main() {
    string s;
    cin >> s;
    ll maxLength = solve(s);
    cout << (maxLength > 1 && isPrime(maxLength) ? 1 : 0);
    return 0;
}