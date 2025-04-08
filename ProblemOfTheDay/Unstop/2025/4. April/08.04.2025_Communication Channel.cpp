/*
Problem Link: https://unstop.com/code/practice/293609
*/

/*Communication Channel

Problem Statement
You are a network engineer responsible for designing the communication network for a large company with N departments. You want to create a complete undirected graph to represent the network, where each vertex represents a department, and each edge represents a communication channel between departments.

Each edge has a weight representing the cost of maintaining the communication channel. You want to ensure that the sum of the cost of maintaining the communication channels incident to the first department (the department you are in charge of) is equal to the cost of the minimum spanning tree of the entire network.

Additionally, you want to minimize the cost of the network by limiting the cost of each channel to be in the range of 1 to K.

Your task is to find the number of different network designs that satisfy these conditions.

Input Format
The first line of input contains two space-separated integers N and K ,Where N represents number of departments in the company (vertices in the graph) and K represents maximum cost of a communication channel.
Output Format
Display the number of distinct network designs that meet the specified conditions.
As the result may be very large, return it modulo 10^9 + 7 .
Constraints
2 <= N <= 250
1 <= K <= 250
Sample Testcase 0
Testcase Input
2 1
Testcase Output
1
Explanation
There is only one network design possible:

Sample Testcase 1
Testcase Input
3 2
Testcase Output
5
Explanation
The five network designs that are possible are:

In the above designs, the cost of the MST is equal to the cost of the communication channels inclined to your department.


*/

#include <iostream>
#include <vector>

const long long M = 1000000007;

long long power(long long b, long long e) {
    long long r = 1;
    b %= M;
    while (e) {
        if (e & 1)
            r = (r * b) % M;
        b = (b * b) % M;
        e >>= 1;
    }
    return r;
}

int count_distinct_network_designs(int N, int K) {
    int m = N - 1;
    std::vector<long long> f(m + 1, 0), i(m + 1, 0);
    f[0] = 1;

    for (int j = 1; j <= m; j++)
        f[j] = (f[j - 1] * j) % M;

    i[m] = power(f[m], M - 2);
    for (int j = m; j >= 1; j--)
        i[j - 1] = (i[j] * j) % M;

    std::vector<long long> dp(m + 1, 0), new_dp(m + 1, 0);
    dp[0] = 1;

    for (int x = 1; x <= K; x++) {
        std::fill(new_dp.begin(), new_dp.end(), 0);
        long long b = K - x + 1;

        for (int s = 0; s <= m; s++) {
            if (dp[s] == 0)
                continue;

            long long t = 1;
            for (int f = 0; f <= m - s; f++) {
                new_dp[s + f] = (new_dp[s + f] + dp[s] * t) % M;
                if (f == m - s)
                    break;

                long long q = power(b, s + f);
                t = (t * q) % M;
                t = (t * power(f + 1, M - 2)) % M;
            }
        }
        dp = new_dp;
    }

    long long r = (f[m] * dp[m]) % M;
    return r;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    int result = count_distinct_network_designs(N, K);
    std::cout << result << std::endl;
    return 0;
}
