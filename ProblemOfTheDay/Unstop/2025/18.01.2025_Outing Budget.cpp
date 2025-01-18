/*
Problem link: https://unstop.com/code/practice/296080
*/

/*Outing Budget

Problem Statement
You are organizing a group outing and want to choose the best day for everyone to meet. Each friend provides a list of available dates from 1 to N. You need to calculate the total budget for the outing based on these dates.

To do this, you need to:

Consider all possible combinations of three dates (a, b, c) such that the sum of these dates equals n (i.e., A + B + C = N).
For each combination, compute the least common multiple (LCM) of c and the greatest common divisor (GCD) of A and B.
Sum all these LCM values to get the total budget.
Output the total sum modulo 10^9 + 7.
Input Format
The first line contains a single integer N, representing the total number of dates.

Output Format
Print a single integer representing the total sum of the LCM values modulo 10^9 + 7.

Constraints
3 <= N <= 10^5

Sample Testcase 0
Testcase Input
3
Testcase Output
1
Explanation
For n = 3, the only suitable triplet is (1, 1, 1) where LCM(1, GCD(1, 1)) = 1. The total sum is 1.

Sample Testcase 1
Testcase Input
5
Testcase Output
11
Explanation
For n = 5, the suitable triplets (a, b, c) are:


(1, 3, 1) where LCM(1, GCD(1, 3)) = 1
(1, 2, 2) where LCM(2, GCD(1, 2)) = 2
(1, 1, 3) where LCM(3, GCD(1, 1)) = 3
(2, 2, 1) where LCM(1, GCD(2, 2)) = 2
(2, 1, 2) where LCM(2, GCD(2, 1)) = 2
(3, 1, 1) where LCM(1, GCD(3, 1)) = 1

Summing these values gives 1 + 2 + 3 + 1 + 2 + 2 = 11.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;


long long calculate_lcm(int a, int b) {
    int temp = __gcd(a, b);
    return 1LL * a * b / temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    unordered_map<int, int> dp;
    unordered_map<int, vector<int>> divisors;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            divisors[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = i - 1;
        for (size_t j = 1; j < divisors[i].size(); j++) {
            dp[i] -= dp[i / divisors[i][j]];
        }
    }

    long long totalSum = 0;

    for (int c = 1; c < n; c++) {
        for (int divisor : divisors[n - c]) {
            totalSum = (totalSum + calculate_lcm(c, divisor) * dp[(n - c) / divisor] % mod) % mod;
        }
    }

    cout << totalSum << "\n";
    return 0;
}