/*
Problem link: https://unstop.com/code/practice/293607
*/

/*Octal Pattern Count

Problem Statement
You are given an integer N, and your objective is to count the number of strings of length N that can be generated according to the following rules and convert this count to its octal representation.

The strings consist of lowercase vowels only ('a', 'e', 'i', 'o', 'u') and must follow the rules below for valid transitions between vowels:

'e' and 'u' can come after 'a'.
'i' and 'a' can come after 'e'.
'o' and 'e' can come after 'i'.
'u' and 'i' can come after 'o'.
'a' and 'o' can come after 'u'.
Note: If N is 0 or if no valid strings can be formed for the given N, Display 1.

Since the answer may be large, therefore output with mod 10^9+7.

Input Format
The first line of input contains a single integer N representing the length of the string.

Output Format
Display the octal representation of the number of valid strings of length N.

Constraints
1 <= N <= 2 * 10^6
Sample Testcase 0
Testcase Input
1
Testcase Output
5
Explanation
All possible strings are: "a," "e," "i," "o," and "u."
Sample Testcase 1
Testcase Input
2
Testcase Output
12
Explanation
10 possible strings are: "ae", "au", "ei", "ea", "ie", "io", "oi", "ou", "uo" and "ua". 10 to octal is 12.

*/

#include <iostream>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;

std::string user_logic(int n) {
    if (n == 0) {
        return "1";
    }

    std::vector<long long> dp(5, 1);

    for (int len = 2; len <= n; ++len) {
        std::vector<long long> next(5, 0);
        next[0] = (dp[1] + dp[4]) % MOD;
        next[1] = (dp[2] + dp[0]) % MOD;
        next[2] = (dp[3] + dp[1]) % MOD;
        next[3] = (dp[4] + dp[2]) % MOD;
        next[4] = (dp[0] + dp[3]) % MOD;
        dp = next;
    }

    long long result = 0;
    for (long long count : dp) {
        result = (result + count) % MOD;
    }

    std::string octal = "";
    while (result > 0) {
        octal = std::to_string(result % 8) + octal;
        result /= 8;
    }

    return octal.empty() ? "1" : octal;
}

int main() {
    int n;
    std::cin >> n;
    std::string result = user_logic(n);
    std::cout << result << std::endl;
    return 0;
}