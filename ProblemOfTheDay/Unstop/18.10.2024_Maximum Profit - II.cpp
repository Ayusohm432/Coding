/*
Problem Link : https://unstop.com/code/practice/297465
*/

/*Maximum Profit - II

Problem Statement
On Halloween night, Alice is on a mission to collect as many chocolates as possible from N different houses. She wants to maximize the total value of chocolates she can carry, given that her bag has a weight capacity of W.

Alice can take chocolates from any house multiple times, but she cannot take a fraction of a chocolate. Each house has a specific type of chocolate with a given value (price) and weight. Alice’s goal is to fill her bag with chocolates in such a way that the total value is maximized while the total weight does not exceed W.

Help Alice determine the maximum value she can collect.

Input Format
The first line contains two integers, N represent the number of houses and W represent the total weight capacity of Alice's bag.

The second line contains N integers representing the price of chocolates from each house.

The third line contains N integers representing the weight of chocolates from each house.

Output Format
Print the maximum value of chocolates Alice can collect without exceeding the weight limit W.

Constraints
1 ≤  N ≤ 10^5

1 ≤  W ≤ 10^5

1 ≤  arr[i] ≤ 10^5

Sample Testcase 0
Testcase Input
3 4
1 2 3
4 5 1
Testcase Output
12
Explanation
Alice can take 4 chocolates from the third house, each with a value of 3 and weight of 1, for a total value of 12. The total weight is 4.

Sample Testcase 1
Testcase Input
3 6
10 15 40
1 2 3
Testcase Output
80
Explanation
Alice can take 2 chocolates from the third house, each with a value of 40 and weight of 3, for a total value of 80. The total weight is exactly 6.

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    
    vector<int> prices(N);
    vector<int> weights(N);
    
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    
    // DP array to store maximum value for each weight capacity
    vector<int> dp(W + 1, 0);
    
    // Fill the dp array
    for (int i = 1; i <= W; i++) {
        for (int j = 0; j < N; j++) {
            if (weights[j] <= i) {
                dp[i] = max(dp[i], dp[i - weights[j]] + prices[j]);
            }
        }
    }
    
    // The maximum value of chocolates Alice can collect
    cout << dp[W] << endl;
    
    return 0;
}