/*
Problem Link : https://unstop.com/code/practice/295754
*/

/*Divide the Players

Problem Statement
You need to divide N players into two teams to play a match. The players have different proficiency levels, given in an array Arr. There is also a number K called the "fair factor" that helps decide if the division is fair.

Rules to divide the players:

The absolute difference between the sum of proficiency levels of both teams should be as small as possible.
This absolute difference must be less than or equal to the fair factor k.
Your task is to determine if it's possible to divide the players into two teams fairly. If it is possible, Print True, otherwise, Print False.

Input Format
The first line of input contains an integer N, representing the total number of players.

The second line of input contains N space-separated integers representing the proficiency levels of the players.

The third line of input contains an integer K, representing the fair factor.

Output Format
Display True if the players can be divided fairly into two teams,otherwise Display False.

Constraints
1 <= N <= 10^3

0 <= Arr[i] <= 10^2

1<= K <= 5

Sample Testcase 0
Testcase Input
2
12 5
5
Testcase Output
False
Explanation
There are only two players, and the absolute difference in their proficiency levels is 7, which is greater than the fair factor 5. So, it's not possible to divide them fairly.

Sample Testcase 1
Testcase Input
3
1 2 3
2
Testcase Output
True
Explanation
The players can be divided into two teams with proficiency sums 3 and 3, making the absolute difference 0, which is less than or equal to the fair factor 2. Thus, the division is fair.

*/


#include <bits/stdc++.h>
using namespace std;

int divide_players(vector<int>& arr, int n, int k);

int main() 
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    bool answer = divide_players(arr, n, k);
    cout << (answer ? "True" : "False");
    return 0;
}

int divide_players(vector<int>& arr, int n, int k) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    int target = total_sum / 2;
    
    // DP array to keep track of possible sums
    vector<bool> dp(target + 1, false);
    dp[0] = true; // We can always have a sum of 0

    // Fill the DP table
    for (int num : arr) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    // Find the closest sum to half of the total sum
    for (int i = target; i >= 0; i--) {
        if (dp[i]) {
            int sum1 = i;
            int sum2 = total_sum - sum1;
            int difference = abs(sum1 - sum2);
            return difference <= k; // Return true if the difference is within the fair factor
        }
    }
    
    return false; // If no valid division is found
}
