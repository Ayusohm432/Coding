/*
Problem Link : https://unstop.com/code/practice/259944
*/

/*Frog Jump
Problem Statement
There is a frog who wants to cross a river that has N magical stones floating on its surface. Each stone has a magical power that helps the frog take a maximum size of jump equal to the magical power of the stone. E.g., if a stone has a magical power of 3 then the frog can either go 3, 2, or 1 step forward at once. 

Given an array representing the magical power of the stones. Find out if the frog can get enough power to finally cross the river. 

Return true if the frog can cross the river, or false otherwise.

Input Format
The first line of input contains an integer N denoting the magical stones floating on its surface.

The next line of input contains N space-separated integers denoting the magical power as an integer.

Output Format
The testcases are case sensitive so you have to print true if the frog can cross the river, or false otherwise.

 

Constraints
1 <= N <= 104

Sample Testcase 0
Testcase Input
5
1 3 1 1 4
Testcase Output
true
Explanation
Jump 1 step from index 0 to 1, then 3 steps to the last index.

Sample Testcase 1
Testcase Input
5
3 2 1 0 4
Testcase Output
false
Explanation
You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


*/


#include <iostream>
#include <vector>

using namespace std;

bool canCrossRiver(vector<int>& stones) {
    int n = stones.size();
    vector<bool> dp(n, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        if (!dp[i]) continue;
        for (int j = 1; j <= stones[i]; j++) {
            if (i + j < n) dp[i + j] = true;
        }
    }

    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    cout << (canCrossRiver(stones) ? "true" : "false") << endl;

    return 0;
}