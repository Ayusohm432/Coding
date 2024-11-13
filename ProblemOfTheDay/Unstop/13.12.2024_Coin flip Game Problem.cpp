/*
Problem Link : https://unstop.com/code/practice/307794
*/

/*Coin flip Game Problem

Problem Statement
You have M coins placed on the floor, all initially showing tails.

In the first round, you flip all the coins to heads.
In the second round, you flip every second coin that is currently showing heads, turning it to tails.
In the third round, you flip every third coin, toggling it between heads and tails.
In the ith round, you flip every ith coin.
After performing this for M rounds, where in the last round you only flip the Mth coin, determine how many coins are showing heads.

Input Format
The first line contains an integer M representing the number of coins.

Output Format
Print the number of coins that are showing heads after M rounds.

Constraints
 0 <= M <= 10^4

Sample Testcase 0
Testcase Input
3
Testcase Output
1
Explanation
At first, the three Coins are [tail, tail, tail].


After the first round, the three Coins are [head, head, head].


After the second round, the three Coins are [head, tail, head].


After the third round, the three Coins are [head, tail, tail]. 


So you should Print 1 because there is only one Coin left with the head.

Sample Testcase 1
Testcase Input
0
Testcase Output
0
Explanation
No Coin no head

*/

#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

int find(int n) {
    // User should implement the logic here
    int heads = 0;
    for (int i = 1; i <= n; i++) {
        int factors = 0;
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                factors++;
                if (j * j != i) {
                    factors++;
                }
            }
        }
        if (factors % 2 == 1) {
            heads++;
        }
    }
    return heads;
}


int main() {
    int m;
    cin >> m;
    int count = find(m);
    cout << count << endl; // print the result
    return 0;
}