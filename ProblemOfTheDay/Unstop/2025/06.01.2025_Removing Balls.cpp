/*
Problem Link: https://unstop.com/code/practice/250896
*/

/*Removing Balls

Problem Statement
Aryan and Ankit play a game with N boxes . There are an even number of boxes arranged in a row, and each box has a positive integer number of stones balls, denoted by balls(i).
The objective of the game is to end with the most balls. 

Rules:

Aryan and Ankit take turns picking all the balls from either the beginning or the end of the row of boxes.
Aryan always plays first.
Both players play optimally, meaning they make decisions to maximize their number of balls.
The game ends when there are no more boxes left.
Assume Aryan and Ankit play optimally. Print Aryan if Aryan wins or ties  and print Ankit if Ankit wins.

Input Format
The first line of input contains an integer N,representing the size of the array.
The second line of input contains N space separated integers representing the number of balls in the boxes.

Output Format
Display "Aryan" if Aryan wins or Display"Ankit" if Ankit wins.

Constraints
1<=N<=10^2
Assuming Arr denotes the array and Arr(i) denotes array element at ith index of the array.
1<=Arr(i)<=10^4

Sample Testcase 0
Testcase Input
4
1 1 1 2
Testcase Output
Aryan
Explanation
Let Aryan pick 2.


Now Ankit has 2 chances in both his chances he can only pick 1, so Ankit’s score will be 2, and Aryan’s score will be 3.

Sample Testcase 1
Testcase Input
2
3 2
Testcase Output
Aryan
Explanation
Aryan can take the first element (3), and Ankit is left with 2. Aryan's score will be 3, and Ankit's score will be 2, so Aryan wins.

*/

#include <iostream>
#include <vector>
#include <algorithm>

std::string determine_winner(int n, const std::vector<int>& balls) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = balls[i];
    }

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            dp[i][j] = std::max(balls[i] - dp[i + 1][j], balls[j] - dp[i][j - 1]);
        }
    }

    if (dp[0][n - 1] >= 0) {
        return "Aryan";
    } else {
        return "Ankit";
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> balls(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> balls[i];
    }

    std::string result = determine_winner(n, balls);
    std::cout << result << std::endl;
    return 0;
}