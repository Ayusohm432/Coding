/*
Problem link ; https://unstop.com/code/practice/303834
*/

/*Jack and their enemies


Problem Statement
Jack enjoys playing his favorite game, Enemy Exodus, which features N groups of enemies, with the i-th group containing group[i]  enemies.
There's a critical point in the game: after M minutes, the enemies activate a super shield headquarters that makes them invulnerable. Jack knows this and wants to eliminate all enemies before the shield is activated.
Each minute, he can decide on a kill rate K, which represents the number of enemies he will attempt to kill from a chosen group. If a group has fewer than K enemies, he will kill all remaining enemies in that group for that minute. Jack prefers to kill enemies slowly but must still finish off all of them before the shield activates.
The task is to determine the minimum integer value of K that allows him to kill all enemies within the M minutes and convert this value into octal format.
Input Format
Each test case consists of three lines of input.
The first line contains the integer N, representing the number of groups of enemies.
The second line includes Nspace-separated integers, representing the number of enemies in each group.
The third line provides the integer M, indicating the number of minutes Jack has before the enemies activate their shield.
Output Format
Print the minimum integer K followed by K in an octal number. If no such min value exists, print 1.

Constraints
1<=N<=10^4

N<=M<=10^9

1<=group[i]<=10^9

Sample Testcase 0
Testcase Input
4 
3 6 7 11
8
Testcase Output
4 4
Explanation
The lower index value here is 4, which, when converted to octal, gives 4

Sample Testcase 1
Testcase Input
5 
30 11 23 4 20
5
Testcase Output
30 36
Explanation
The minimum value here is 30, which, when converted to octal, gives 36

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isFeasible(const vector<int>& group, int K, int M) {
    long long totalTime = 0;
    for (int enemies : group) {
        totalTime += (enemies + K - 1) / K; 
        if (totalTime > M) return false;  
    }
    return totalTime <= M;
}

int findMinimumK(const vector<int>& group, int M) {
    int low = 1, high = *max_element(group.begin(), group.end());
    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isFeasible(group, mid, M)) {
            result = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int N, M;
    cin >> N;
    vector<int> group(N);
    for (int i = 0; i < N; ++i) cin >> group[i];
    cin >> M;

    int minK = findMinimumK(group, M);
    cout << minK << " " << oct << minK << endl; 
    return 0;
}

