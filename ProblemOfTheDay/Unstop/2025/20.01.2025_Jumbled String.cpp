/*
Problem Link: https://unstop.com/code/practice/293639
*/

/*Jumbled String

Problem Statement
Given two strings, S and T, your task is to check whether T can be obtained by dividing S into two equal parts and interleaving the characters of the two parts with each other, without changing the order of characters within each part.

For example, the string "GHIJKL" can be split into two parts: "GHI" and "JKL". It can be interleaved into "GJHKIL" but not into "HGIKJL", as the order of characters within each part must remain intact.

Find whether T can be obtained from S under these conditions.

Input Format
The first line of input contain two space-separated strings S and T,representing the original string and the target string, respectively.

Output Format
Display boolean value 1 if T can be formed by interleaving the two parts of S; otherwise, print 0.

Constraints
1 ≤ | S, T | ≤ 10^2

Sample Testcase 0
Testcase Input
ABCD ADCB
Testcase Output
0
Explanation
ABCD can be jumbled into ABCD, ACBD, ACDB, CDAB, CADB, CABD. So, the string ADCB cannot be obtained from it. It is not a jumbled string.
Sample Testcase 1
Testcase Input
AB BA
Testcase Output
1
Explanation
The only two possible strings obtained from AB are AB and BA. These strings can be obtained by taking care of the order of characters. So, BA is a jumbled string.
*/

#include <iostream>
#include <string>
#include <vector>

bool can_form_by_interleaving(const std::string& S, const std::string& T) {
    int n = S.size();
    int m = T.size();
    if (n % 2 != 0 || m != n) {
        return false;
    }
    int half = n / 2;
    std::string part1 = S.substr(0, half);
    std::string part2 = S.substr(half);
    std::vector<std::vector<bool>> dp(half + 1, std::vector<bool>(half + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= half; i++) {
        for (int j = 0; j <= half; j++) {
            if (i + j > m) continue;

            if (i > 0 && dp[i - 1][j] && T[i + j - 1] == part1[i - 1]) {
                dp[i][j] = true;
            }

            if (j > 0 && dp[i][j - 1] && T[i + j - 1] == part2[j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    return dp[half][half];
}

int main() {
    std::string S, T;
    std::cin >> S >> T;
    bool result = can_form_by_interleaving(S, T);
    std::cout << (result ? 1 : 0) << std::endl;
    return 0;
}

