/*
Problem link: https://unstop.com/code/practice/506970
*/

/*Fibonacci with a Twist

Problem Statement
You are given a number N and asked to calculate X based on the following recurrence rules:

Base cases:

If N = 0, then X = 5.
If N = 1, then X = 3.
For N > 1, the recurrence is as follows:

If N is odd, then X = (F(N-1) + F(N-2)) mod 998.
If N is even, then X = (F(N-1) * F(N-2)) mod 999.
Where F(N) represents the value of X for N calculated according to the above rules.

Task: Given a number N, help calculate X efficiently.

Input Format
The first and only line of input contain a single integer N.

Output Format
Print the value of X.

Constraints
0 <= N <= 10^5

Sample Testcase 0
Testcase Input
10
Testcase Output
675
Explanation
Given N = 10,
We need to calculate F[2], F[3], F[4], ... , F[9], such that
F[10] = (F[9] + F[8]) mod 999, which will give answer = 675.

Sample Testcase 1
Testcase Input
5
Testcase Output
288
Explanation
Given N = 5,
We need to calculate F[2], F[3] and F[4], such that
F[5] = (F[4] + F[3]) mod 998, which will give answer = 288.

*/

#include <iostream>
#include <vector>
using namespace std;
int solve(int n, vector<int>& dp){
    if(n == 0){
        return 5;
    }

    if(n == 1){
        return 3;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    if(n % 2 != 0){
        return dp[n] = ((solve(n-1, dp) + solve(n-2, dp)) % 998);
    }else{
        return dp[n] = ((solve(n-1, dp) * solve(n-2, dp)) % 999);
    }
}

int calculateX(int N) {
    /*
    Write your logic here.
    Parameters:
        N (int): Single integer input
    Returns:
        int: Computed result based on the problem statement
    */
    vector<int> dp(N+1, -1);
    return solve(N, dp); 
}

int main() {
    int N;
    std::cin >> N;  // Read the single integer input
    int result = calculateX(N);
    std::cout << result << std::endl;  // Print the result
    return 0;
}