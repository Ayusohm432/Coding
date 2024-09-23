/*
Problem Link : https://unstop.com/code/practice/250619
*/

/*Elevator

Problem Statement
Eve is currently on the Nth floor of a building with a special elevator that has only two buttons:

One button to move down to the (N-1)th floor.
Another button to move down to the (N/2)th floor (if N is divisible by 2).
Her goal is to reach the ground floor (0th floor) using the minimum number of button presses.

Your task is to determine the minimum number of button presses required for Eve to reach the ground floor from the Nth floor.

Input Format
The first line of input contains a single integer N, representing the starting floor.

Output Format
A single integer representing the minimum number of button presses needed to reach the ground floor.

Constraints
0 <= N <= 104

Sample Testcase 0
Testcase Input
 10
Testcase Output
5
Explanation
Step 1) divide by 2 and obtain 5.


Step 2) subtract 1 and obtain 4.


Step 3) divide by 2 and obtain 2.


Step 4) divide by 2 and obtain 1.


Step 5) subtract 1 and obtain 0.

Sample Testcase 1
Testcase Input
2
Testcase Output
2
Explanation
Step 1) divide by 2 and obtain 1.


Step 2) subtract 1 and obtain 0.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n , vector<int>& dp){
    if(n == 0){
        return 0;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    int downOne = 1 + solve(n-1 , dp);
    int downHalf = INT_MAX;
    if(n%2 == 0){
        downHalf = 1 + solve(n/2 , dp);
    }
    return dp[n] = min(downOne , downHalf);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;

    vector<int> dp(N+1 , 0);
    dp[0] = 0;
    dp[1] = 1;

    solve(N , dp);
    cout<< dp[N];

    return 0;
}