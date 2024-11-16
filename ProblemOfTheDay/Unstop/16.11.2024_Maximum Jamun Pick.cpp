/*
Problem link: https://unstop.com/code/practice/306970
*/

/*Maximum Jamun Pick

Problem Statement
During a sports day event at school, a game involves picking N buckets of jamuns placed in a row. Each bucket has a different number of jamuns bucket[i]. The goal is to choose a subset of buckets such that the total number of jamuns is maximized. However, there is a rule: you cannot pick two adjacent buckets.

Given an array of integers representing the number of jamuns in each bucket, your task is to select the buckets in such a way that the sum of jamuns is as large as possible without picking adjacent buckets.

Input Format
The first line contains an integer N, representing the number of buckets.

The second line contains N integers, where each integer represents the number of jamuns in a bucket.

Output Format
Print a single integer, the maximum sum of jamuns that can be obtained by picking non-adjacent buckets.

Constraints
1 <= N <= 10^6

0 <= bucket[i] <= 10^3

 
Sample Testcase 0
Testcase Input
5
2 7 9 3 1
Testcase Output
12
Explanation
The best strategy is to pick the 1st bucket (2 jamuns) and the 3th bucket (9 jamuns) and 5th bucket (1 jamuns), giving a total of 2 + 9 + 1 = 12 jamuns.

Sample Testcase 1
Testcase Input
4
1 2 3 1
Testcase Output
4
Explanation
The best strategy is to pick the 1st bucket (1 jamun) and the 3rd bucket (3 jamuns), giving a total of 1 + 3 = 4 jamuns.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> buckets(n);
    for (int i = 0; i < n; i++) {
        cin >> buckets[i];
    }
    if (n <= 2) {
        cout << *max_element(buckets.begin(), buckets.end()) << endl;
        return 0;
    }
    vector<int> dp(n);
    dp[0] = buckets[0];
    dp[1] = max(buckets[0], buckets[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + buckets[i]);
    }
    cout << dp[n-1] << endl;
    return 0;
}