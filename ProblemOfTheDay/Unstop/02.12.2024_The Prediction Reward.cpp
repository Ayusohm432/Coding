/*
Problem link: https://unstop.com/code/practice/294135
*/

/*The Prediction Reward

Problem Statement
Alice will choose a number between 1 to N inclusive. Your task is to predict the number that Alice chose. If you predict the number correctly, you will be rewarded. However, if your prediction is wrong, Alice will tell you whether the number she chose is greater or smaller than your prediction, and you will keep predicting until you find the number. For each wrong prediction number K, you will give K coins to Alice.

You are given the number N.

Your task is to return the minimum coins you should have to be rewarded by Alice, no matter what number she chooses.

Input Format
The first and only line will contain a single integer N.

Output Format
Print an integer denoting the minimum coins you should have.

Constraints
1 ≤ N ≤ 200

Sample Testcase 0
Testcase Input
2
Testcase Output
1
Explanation
Alice can choose either 1 or 2. If we predict 1, which matches Alice’s number, then no coins need to be paid. Otherwise, we have to pay 1 coin. Even if Alice's number is greater, then it must be 2. We can predict 2 by paying only 1 coin. So, we have to pay only 1 coin in the worst-case scenario.
Sample Testcase 1
Testcase Input
10
Testcase Output
16
Explanation
Alice has chosen a number between 1 and 10. Your goal is to predict this number, minimizing the total number of coins you will give Alice in the worst-case scenario.


The winning strategy is as follows:

The range is [1,10]. You predict 7.
If this is Alice’s number, you don't give any coins. Otherwise, you give Alice 7 coins.
If Alice’s number is higher, the range becomes [8,10]. You predict 9.
If this is Alice’s number, your total is 7 coins. Otherwise, you give Alice 9 more coins.
If Alice’s number is higher, it must be 10. You predict 10. Your total is 7 + 9 = 16 coins.
If Alice’s number is lower, it must be 8. You predict 8. Your total is 7 + 9 = 16 coins.

If Alice’s number is lower than 7, the range is [1,6]. You predict 3.
If this is Alice’s number, your total is 7 coins. Otherwise, you give Alice 3 more coins.
If Alice’s number is higher, the range becomes [4,6]. You predict 5.
If this is Alice’s number, your total is 7 + 3 = 10 coins. Otherwise, you give Alice 5 more coins.
If Alice’s number is higher, it must be 6. You predict 6. Your total is 7 + 3 + 5 = 15 coins.
If Alice’s number is lower, it must be 4. You predict 4. Your total is 7 + 3 + 5 = 15 coins.
If Alice’s number is lower than 3, the range becomes [1,2]. You predict 1.
If this is Alice’s number, your total is 7 + 3 = 10 coins. Otherwise, you give Alice 1 more coin.
If Alice’s number is higher, it must be 2. You predict 2. Your total is 7 + 3 + 1 = 11 coins.

In all possible cases, the worst outcome requires you to give Alice 16 coins. Hence, the minimum number of coins you should have to guarantee a win is 16.

*/

//Approach-1
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int minCoinsRecursive(int start, int end, vector<vector<int>>& dp) {
    if (start >= end) return 0;

    if (dp[start][end] != -1) return dp[start][end];

    int minCoins = INT_MAX;


    for (int guess = start; guess <= end; ++guess) {

        int coinsSpent = guess;


        int worstCase = coinsSpent + max(minCoinsRecursive(start, guess - 1, dp), minCoinsRecursive(guess + 1, end, dp));
        minCoins = min(minCoins, worstCase);
    }


    dp[start][end] = minCoins;
    return minCoins;
}

int minCoins(int N) {
    vector<vector<int>> dp;
    dp.assign(N + 1, vector<int>(N + 1, -1));
    return minCoinsRecursive(1, N, dp);
}

int main() {
    int N;
    cin >> N;
    cout << minCoins(N) << endl;
    return 0;
}



