/*
Problem Link : https://unstop.com/code/practice/250745
*/

/*Ways to build

You are given three integers: N, length of the array ; M, maximum possible value of an element ; and K, target search cost. Your task is to construct an array that meets the following conditions:

The array, Arr, contains exactly N elements.
Each element in Arr satisfies 1 <= Arr[i] <= M for all valid indices i.
The search cost of the array must be exactly K.
The search cost is defined as the number of times a new maximum element is encountered when traversing the array from left to right. The first element always counts as a new maximum.
Your goal is to determine how many different ways the array Arr can be built, following the given conditions. Since the answer can be large, return the result modulo 10^9 + 7.

Input Format
The input line contains 3 space-separated integers, N, length of the array ; M, maximum possible value of an element ; and K, target search cost, respectively.

Output Format
Return the number of ways to build the array Arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

Constraints
1 <= N <= 50

1 <= M <= 100

0 <= K <= N

 

Sample Testcase 0
Testcase Input
5 2 3
Testcase Output
0
Explanation
It's impossible to create an array of length 5 using elements from 1 to 2 that has a search cost of 3. With only two possible values (1 and 2), we can't encounter a third new maximum, so there are no valid arrays. Hence, the output is 0.

Sample Testcase 1
Testcase Input
2 3 1
Testcase Output
6
Explanation
The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2], [3, 3]
Each of these arrays has a search cost of 1 because no new maximum element is found after the first element.


*/
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int numOfWays(int N, int M, int K) {
    // dp[n][k][m]: number of ways to build an array of length n,
    // with search cost k and current maximum m
    std::vector<std::vector<std::vector<int>>> dp(N+1, std::vector<std::vector<int>>(K+1, std::vector<int>(M+1, 0)));

    // Base case: an empty array has 1 way to be formed
    dp[0][0][0] = 1;

    // Iterate through each array length
    for (int n = 0; n < N; ++n) {
        // Iterate through each search cost
        for (int k = 0; k <= K; ++k) {
            // Iterate through each current maximum
            for (int m = 0; m <= M; ++m) {
                if (dp[n][k][m] == 0) continue; // Skip if no ways exist for this state

                // Case 1: Add a new element <= m, does not increase the search cost
                dp[n+1][k][m] = (dp[n+1][k][m] + 1LL * dp[n][k][m] * m % MOD) % MOD;

                // Case 2: Add a new element > m, increases the search cost by 1
                if (k + 1 <= K) {
                    for (int new_max = m + 1; new_max <= M; ++new_max) {
                        dp[n+1][k+1][new_max] = (dp[n+1][k+1][new_max] + dp[n][k][m]) % MOD;
                    }
                }
            }
        }
    }

    // Sum all ways to form an array of length N with search cost K
    int result = 0;
    for (int m = 0; m <= M; ++m) {
        result = (result + dp[N][K][m]) % MOD;
    }

    return result;
}

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    std::cout << numOfWays(N, M, K) << std::endl;
    return 0;
}
