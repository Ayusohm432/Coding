/*
Problem Link ;- https://unstop.com/code/practice/250281
*/

/*Pack the Socks

Problem Statement
You are a shopkeeper and bought N pairs of socks of several colours in bulk. The colour of each pair of socks is represented as a non-negative integer. The socks are sold as sets of 3 each. A set of socks consists of 3 socks of the same colour.

You want to find the number of different sets that can be made from the N pairs of socks you bought today.

Note: order of indices of sock pairs in the set does not matter.

Input Format
The first line of the input contains a single integer N - the number of pairs of socks that you have.

The second line of the input contains n space-separated integers a1, a2, …, an, where ai represents the colour of the ith pair.

Output Format
Print a single integer representing the total number of different sets of 3 socks that can be formed from the N pairs of socks.

Constraints
1 <= N <= 105

0 <= ai <= 10^3

Sample Testcase 0
Testcase Input
7
1 3 3 1 1 3 3
Testcase Output
5
Explanation
We can form two sets of 3 pairs of:


1) 1 Set containing color 1.


2) 4 possible set containing socks having color 3:
    2nd, 3rd and 6th sock
    2nd, 3rd and 7th sock
    2nd, 6th and 7th sock
    3rd, 6th and 7th sock

Sample Testcase 1
Testcase Input
6
1 3 3 1 1 3
Testcase Output
2
Explanation
We can form two sets of 3 pairs of:
1) 1 Set containing 1.
2) 1 set containing 3.


*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> sockCounts;
    for (int i = 0; i < N; i++) {
        int color;
        cin >> color;
        sockCounts[color]++;
    }

    int totalSets = 0;
    for (auto& pair : sockCounts) {
        int count = pair.second;
        totalSets += count / 3;
    }

    cout << totalSets << endl;

    return 0;
}