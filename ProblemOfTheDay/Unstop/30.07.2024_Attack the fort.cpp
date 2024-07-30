/*
Problem Link :- 
*/

/*Attack the fort


Problem Statement
    There are n forts in an enemy kingdom with different power levels in the array arr. The army must:
    Not attack forts with power of 0 or less.
    Attack forts in increasing order of power where the power difference between the last attacked fort and the next to be attacked is exactly 1.
    The army can attack any fort at any time but can only attack each fort once.
    Your task is to maximize the number of attacked forts and determine the absolute difference between (last attacked fort power + 1) and the fort with the maximum power. If no fort is attacked, print -1.

Note: If there are multiple orders with the maximum number of attacked forts, then the last attacked fort will be the minimum from all such orders.

Input Format
    The first line contains a single integer n denoting number of elements in array arr.

    The second line contains n space-separated integers denoting elements of array arr.

Output Format
    Print the integer denoting absolute difference between (last attacked fort power + 1) and the fort with the maximum power. If no fort is attacked, print -1.

Constraints
    1 <= n <= 10^5

    -10^5 <= arr[i] <= 10^5

Sample Testcase 0
    Testcase Input
        5
        4 2 3 1 10
    Testcase Output
        5
    Explanation
        The army can attack in order
        Order: 1 -> 2 -> 3->4, max fort conquered is 4 
        Since there are no more forts left to be attacked with given conditions. Hence, |10-(4+1)| = 5 is printed.

Sample Testcase 1
    Testcase Input
        10
        1 2 3 5 6 7 8 8 9 19
    Testcase Output
        9
    Explanation
        The army can attack in two order

        order: 1 -> 2 -> 3, max fort conquered is 3 
        order: 5->6->7->8->9, max fort conquered is 5 

        Consider 2nd order to be optimal the output will be |19 - (9+1)| = 9


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    unordered_map<int, int> dp;
    int maxPower = 0;
    int lastAttacked = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) continue;

        if (dp.find(arr[i] - 1) != dp.end()) {
            dp[arr[i]] = dp[arr[i] - 1] + 1;
        } else {
            dp[arr[i]] = 1;
        }

        if (dp[arr[i]] > maxPower) {
            maxPower = dp[arr[i]];
            lastAttacked = arr[i];
        }

        maxPower = max(maxPower, dp[arr[i]]);
    }

    if (lastAttacked == -1) {
        cout << -1 << endl;
    } else {
        int maxFort = *max_element(arr.begin(), arr.end());
        cout << abs(maxFort - (lastAttacked + 1)) << endl;
    }

    return 0;
}