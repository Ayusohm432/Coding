/*
Problem link: https://unstop.com/code/practice/303273
*/

/*Distribute Car Toys

Problem Statement
Count the number of ways to distribute toy cars among 3 children such that each child should not have more than K toy cars, and the total number of distributed toy cars equals S.

Input Format
The input consists of 2 lines.

The first input line contains an integer, i.e., K.

The second input line contains an integer, i.e ,S.

Output Format
Print the number of ways to distribute toy cars among 3 children.

Constraints
2 ≤ K ≤ 5*10^3

0 ≤ S ≤3*K

Sample Testcase 0
Testcase Input
5
15
Testcase Output
1
Explanation
K = 5 and S = 15
Only possible way is {5,5,5}.
Sample Testcase 1
Testcase Input
2
2
Testcase Output
6
Explanation
K = 2 and S = 2
Let C1 = first child, C2 = second child, C3 = third child.

C1, C2, C3 = { (0, 0, 2), (0, 2, 0), (2, 0, 0), (0, 1, 1), (1, 0, 1), (1, 1, 0) }

So, there are 6 ways to distribute toy cars.

*/

//Appraoch-1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int k, s;
    cin >> k;
    cin >> s;

    int count = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int l = s - i - j;
            if (l >= 0 && l <= k) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

//Approach-2

#include <iostream>
#include <vector>
using namespace std;

int countWays(int k, int s, int child, vector<vector<int>>& memo) {
    if (s == 0) {
        return 1;
    }
    if (child >= 3 || s < 0) {
        return 0;
    }
    
    if (memo[child][s] != -1) {
        return memo[child][s];
    }

    int ways = 0;
    for (int i = 0; i <= k; i++) {
        ways += countWays(k, s - i, child + 1, memo);
    }

    memo[child][s] = ways;
    return ways;
}

int main() {
    int k, s;
    cin >> k;
    cin >> s;

    vector<vector<int>> memo(3, vector<int>(s + 1, -1));
    int result = countWays(k, s, 0, memo);
    cout << result << endl;

    return 0;
}