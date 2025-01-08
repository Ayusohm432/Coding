/*
Problem Link: https://unstop.com/code/practice/292548
*/

/*Seat Allotment in Hackathon

Problem Statement
You are given a classroom layout consisting of N rows, with exactly 3 seats in each row. The school is organizing a hackathon where students are to form pairs. Each pair of students must sit next to each other to collaborate on their project.

Your task is to determine the number of possible seating arrangements where every seat in the classroom is filled by pairs of students sitting next to each other. As the answer can be very large, print the answer modulo 1e9+7.

Input Format
The first and only line will contain a single integer N.

Output Format
Print an integer, representing the number of possible ways in which the different pairs of students can sit in the classroom so that every seat in the classroom is filled. As the answer can be very large, print the answer modulo 1e9+7.

Constraints
1 ≤ N ≤ 2 * 10^2

Sample Testcase 0
Testcase Input
2
Testcase Output
3
Explanation
The three possible ways are:
Here, the cells with the same color represent the pair in the same team.


There are no other possible ways than the above 3 ways to fill all seats in a classroom with 2 rows and 3 columns such that people in the same team sit together.

Sample Testcase 1
Testcase Input
1
Testcase Output
0
Explanation
We can arrange the only pair of students in two ways: 
But still, one seat will remain vacant in both cases, which is unacceptable. So, there is no possible way to sit in a classroom having a single row and all seats filled.

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1000000007;
int32_t main(){
    int N;
    cin>>N;
    if (N % 2 != 0) {
        cout<<0<<endl;
        return 0;
    }
    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    dp[2] = 3;
    int sum=4;
    for (int i = 4; i <= N; i += 2) {
        dp[i] = (dp[i - 2] + 2*sum)%MOD;
        sum = (sum+dp[i]);
    }
    cout<<dp[N]<<endl;
    return 0;
}