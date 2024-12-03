/*
Problem Link: https://unstop.com/code/practice/294136
*/

/*Maximizing Nutritional Value

Problem Statement
Alice goes to a grocery store to buy fruits for her smoothie shop. 

There are n varieties of fruits numbered from 1 to n. The price of the ith fruit is the price[i], and the nutritional value of it is a nutrition[i]. Alice also has k discount coupons, and each coupon can only be used on one item. By using a discount coupon, the price of any variety of fruit can be reduced to half of its original value (floor value). 

Alice only has m amount of money, and she wants to buy fruits to maximize their total nutritional value.

Find the maximum nutritional value Alice can get.

Note: Alice can only buy at most one unit of each fruit.

Input Format
The first line contains three space-separated integers, n, m, and k.

The next line contains n space-separated integers denoting the array price[i].

The next line contains n space-separated integers denoting the array nutrition[i].

Output Format
Print a single integer denoting the maximum nutritional value Alice can get, as described in the problem statement.

Constraints
1 ≤  n, m ≤  10^3

1 ≤  k ≤  10

1 ≤  price[i] ≤ 10^3

1 ≤  nutrition[i] ≤ 10^3

Sample Testcase 0
Testcase Input
4 4 1 
8 10 12 14
9 7 6 100
Testcase Output
9
Explanation
Alice has 4 varieties of fruits and 4 units of money. She also has 1 discount coupon. 

Alice can apply a discount on the first fruit, which she can get at (8/2) = 4 dollars. The nutritional value that she will get will be 9. 

This is the maximum nutritional value she can get by using 4 dollars using a discount coupon.

Sample Testcase 1
Testcase Input
4 4 1
2 4 5 7
20 17 15 10
Testcase Output
37
Explanation
Alice has 4 varieties of fruits and 4 units of money. She also has 1 discount coupon.

She could select fruit numbers 1 and 2 and apply a discount on the second fruit. This way, the total cost incurred would be 2 + (4/2): 4, and the nutritional value would be 20 + 17 = 37. 

This is the maximum possible nutritional value that Alice can get after using 4 dollars and using 1 discount coupon.

*/

#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002][12];

int solve(int idx, int sums, int cnt, int M, int K, vector<int> &price, vector<int> &nutrition) {
    if (idx == price.size()) return 0; 
    if (dp[idx][sums][cnt] != -1) return dp[idx][sums][cnt]; 
    int ans = solve(idx + 1, sums, cnt, M, K, price, nutrition);

    if (sums + price[idx] <= M) {
        ans = max(ans, nutrition[idx] + solve(idx + 1, sums + price[idx], cnt, M, K, price, nutrition));
    }


    if (sums + price[idx] / 2 <= M && cnt + 1 <= K) {
        ans = max(ans, nutrition[idx] + solve(idx + 1, sums + price[idx] / 2, cnt + 1, M, K, price, nutrition));
    }

    return dp[idx][sums][cnt] = ans; 
}

int maximizeNutritionalValue(int n, int m, int k, vector<int> &price, vector<int> &nutrition) {
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 0, m, k, price, nutrition); 
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> price(n), nutrition(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> nutrition[i];
    }

    int result = maximizeNutritionalValue(n, m, k, price, nutrition);
    cout << result << endl;

    return 0;
}

