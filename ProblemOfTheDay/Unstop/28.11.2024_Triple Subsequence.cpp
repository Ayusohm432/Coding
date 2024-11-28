/*
Problem link: https://unstop.com/code/practice/293637
*/

/*Triple Subsequence

Problem Statement
You are given an array Arr of size N.
Your task is to find the length of the longest subsequence such that each element in the subsequence is exactly three times the previous element.

Input Format
The first line of input contains a single integer N ,representing the size of the array Arr.

The second line of input contains N integers,representing  the elements of the array Arr.

Output Format
Print a single number representing the maximum length of the subsequence satisfying the condition.

Constraints
1 <= N<= 10^2

0 <= Arr[i] <= 2*10^3

Sample Testcase 0
Testcase Input
3
1 2 3
Testcase Output
2
Explanation
Consider subsequence {1, 3} here 3 is triple of 1. Hence the answer is 2.
Sample Testcase 1
Testcase Input
4
2 3 6 18
Testcase Output
3
Explanation
Consider the subsequence {2, 6, 18}. Here 6 is a triple of 2, and 18 is a triple of 6. Hence the answer is 3.

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(vector<ll>& arr) {
    // User will write the logic here
    int n = arr.size();
    unordered_map<ll, int> dp;
    int maxLen = 0;

    for(int i=0; i<n; i++){
        dp[arr[i]] = 1;
        if(arr[i] % 3 == 0 && dp.find(arr[i]/3) != dp.end()){
            dp[arr[i]] = dp[arr[i] / 3] + 1;
        }
        maxLen = max(maxLen, dp[arr[i]]);
    }
    return maxLen;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(arr);
    return 0;
}

