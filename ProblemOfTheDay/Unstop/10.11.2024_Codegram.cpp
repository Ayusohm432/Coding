/*
Problem Link : https://unstop.com/code/practice/295982
*/

/*Codegram

Problem Statement
Alice created a social media app called "Codegram." In this app, there's a feature called "Probab-list." If you follow a person, say P, then not only does P's account get added to your Probab-list, but all the accounts in P's Probab-list also get added to yours.

Now, imagine a social network represented by a directed graph where each person is a node, and there's an edge from person u to person v if u follows v.

Your task is to figure out the smallest number of people needed to create a social network where there are exactly N pairs of people who are mutual Probab-list friends.

Among all such social networks with the minimum number of people, find the maximum number of pairs of people such that one person is in the other’s Probab-list but not vice versa.

Input Format
The first a line of input contains a single integer N, representing the number of pairs of people who need to be mutual Probab-list friends.

Output Format
Display two integers separated by a space. The first integer is the minimum number of people required. The second integer is the maximum number of one-way follower pairs in such a network.

Constraints
0 <= N <= 10^6

Sample Testcase 0
Testcase Input
3
Testcase Output
3 0
Explanation



Here, there are exactly 3 pairs who are in each other’s Probab-list. So, the minimum number of nodes required is 3, and there is no pair where Person A is in the probab-list of B but not the opposite.

Sample Testcase 1
Testcase Input
0
Testcase Output
0 0
Explanation
Here, we need exactly 0 pairs who are in each other’s Probab-list. So, the minimum nodes required are 0. So, there will be no social networks on Codegram.

*/

#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int s = 1; (s * (s - 1)) / 2 <= i; ++s) {
            int p = (s * (s - 1)) / 2;
            if (i - p >= 0) {
                dp[i] = std::min(dp[i], dp[i - p] + s);
            }
        }
    }

    std::cout << dp[n] << ' ' << ((long long) dp[n] * (dp[n] - 1)) / 2 - n << '\n';
}

int main() {
    solve();
    return 0;
}
