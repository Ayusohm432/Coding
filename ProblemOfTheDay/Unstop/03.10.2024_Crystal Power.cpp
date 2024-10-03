/*
Problem Link : https://unstop.com/code/practice/259680
*/

/*Crystal Power

Problem Statement
In a magical kingdom, there are enchanted N crystals with various powers, represented as an array nums, where nums[i] represents the power of the ith crystal.

The inhabitants of the kingdom wish to create mystical orbs with a specific total power, denoted by the integer target. They can use an infinite supply of each type of crystal to form these orbs.

Your task is to help the kingdom's inhabitants find all the unique ways to achieve the target power by merging crystals. Each combination of crystals should sum up to exactly the target power.

Input Format
The first line of input contains two space-separated integer N, which represents the number of crystals, and an integer target, which represents the target power, respectively. 

The second line of input contains N space-separated integers representing the power of each crystal in the array nums.

Output Format
Print the number of unique ways to achieve the target power by merging the crystals.

Constraints
1 <= N <= 10^3

1 <= nums[i] <= 10^5

1 <= target <= 10^5

Sample Testcase 0
Testcase Input
2 6
5 7
Testcase Output
0
Explanation
There are no ways to reach the target power of 6 by merging the given crystals with powers 5 and 7.

Sample Testcase 1
Testcase Input
3 4
2 3 4
Testcase Output
2
Explanation
There are 2 ways to achieve the target power of 4 by merging crystals:


Using two crystals of power 2 each (2 + 2).
Using one crystal of power 4.

These are the two possible ways to achieve the target power of 4.
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll combinationSum4(vector<int>& nums, int target) {
    vector<ll> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i - nums[j] >= 0) {
                dp[i] += dp[i - nums[j]];
                //dp[i] %= 1000000007; // to avoid overflow
            }
        }
    }
    return dp[target];
}

int main() {
    int N, target;
    cin >> N >> target;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    cout << combinationSum4(nums, target) << endl;
    return 0;
}