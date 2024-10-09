/*
Problem link : https://unstop.com/code/practice/259977
*/

/*Buy Property 2

Problem Statement
You are a real estate agent, and you want to maximize your profit by buying and selling properties. The property prices are given in a list, where the value at the ith index represents the price on the ith day.

You are allowed to make multiple transactions (buying and selling), but you cannot engage in multiple transactions simultaneously (i.e., you must sell before you buy again). The goal is to determine the maximum profit you can achieve by making these transactions.

Input Format
The first line of input contains an integer N, representing the number of days.

The second line of input contains N space-separated integers, where each integer represents the price of the property on the corresponding day.

Output Format
Print a single integer representing the maximum profit you can make.

Constraints
1 <= N <= 104

Sample Testcase 0
Testcase Input
6
7 1 5 3 6 4
Testcase Output
7
Explanation
Buy on day 2 (price = 1) and sell on day 3 (price = 5), resulting in a profit of 5 - 1 = 4.
Then, buy on day 4 (price = 3) and sell on day 5 (price = 6), resulting in a profit of 6 - 3 = 3.
The total profit is 4 + 3 = 7.

Sample Testcase 1
Testcase Input
5
1 2 3 4 5
Testcase Output
4
Explanation
Buy on day 1 (price = 1) and sell on day 5 (price = 5).
The profit is calculated as 5 - 1 = 4.
The total profit is 4

*/
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int main() {
    int N;
    cin >> N;
    vector<int> prices(N);
    
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    
    cout << maxProfit(prices) << endl;
    return 0;
}
