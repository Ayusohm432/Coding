/*
Problem Link : https://unstop.com/code/practice/294134
*/

/*Maximum Power

Problem Statement
You are given an integer array 'arr' of length N representing the power of individual army troops in a defense camp. Your task is to divide these troops into two army groups such that:

The total power of both groups is equal.
Each group must contain at least one troop.
Each troop can only belong to one group (no overlap between groups).
Your goal is to determine if it is possible to divide the troops into two such groups. If it is possible, print the total power of a single group. Otherwise, print 0.

Input Format
The first line contains a single integer N.

The second line contains N space-separated integers representing the elements of the array arr.

Output Format
If it is possible to divide the troops into two groups with the given condition, print the total power of a single group, Otherwise print 0.

Constraints
0 <= N <= 10^2

1 <= arr[i] <= 10^3

Sample Testcase 0
Testcase Input
4 
1 2 4 9
Testcase Output
0
Explanation
There is no way to form the two armies from the given powers. Hence the answer is 0.
Sample Testcase 1
Testcase Input
3
1 3 2
Testcase Output
3
Explanation
We can form the two teams with power 3, i.e {1, 2} and {3}.


*/
#include <iostream>
#include <vector>
using namespace std;

bool can_partition(vector<int>& arr) {
    int total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }

    if (total_sum % 2 != 0) {
        return false;
    }

    int target = total_sum / 2;
    int n = arr.size();
    
    vector<bool> dp(target + 1, false);
    dp[0] = true; 
    for (int i = 0; i < n; ++i) {
        for (int j = target; j >= arr[i]; --j) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    return dp[target];
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    if (can_partition(arr)) {
        int total_sum = 0;
        for (int i = 0; i < N; ++i) {
            total_sum += arr[i];
        }
        cout << total_sum / 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
