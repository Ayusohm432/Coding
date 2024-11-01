/*
Problem Link : https://unstop.com/code/practice/301920
*/

/*Will Lexi Survive

Problem Statement
Lexi is sick, and her doctor advises her to drink at least K liters of water every day for N days.

If Lexi drinks less than K liters of water on any day, her energy decreases by X. If her energy level reaches zero, she will not survive.

However, if Lexi drinks at least K liters, she gets a 5% energy boost that day. Given a list of how much water Lexi plans to drink each day, you need to determine how many days Lexi will survive.

Input Format
The first line contains four integers N, K, E, and X denoting the number of days, the minimum liters of water required per day, Lexi's initial energy level and the amount by which her energy decreases if she drinks less than K liters.

The second line contains N space-separated integers, each representing the amount of water Lexi plans to drink that day.

Output Format
Print a single integer indicating the number of days Lexi will survive based on her water consumption plan.

Constraints
0 <= N <= 10^4
0 <= K <= 20
0 <= E <= 10^2
0 <= X <= 10^2

Sample Testcase 0
Testcase Input
4 1 0 0
2 2 5 10
Testcase Output
0
Explanation
Lexi's initial energy is 0.
Since her energy is already zero, she cannot survive any day, regardless of how much water she drinks.
Thus, the answer is 0 days.

Sample Testcase 1
Testcase Input
4 2 10 1
1 2 3 4
Testcase Output
4
Explanation
Lexi's initial energy is 10, and she needs to drink at least 2 liters of water each day.
Day 1: Drinks 1 liter (less than 2), energy decreases by 1 (10 - 1 = 9).
Day 2: Drinks 2 liters (exactly 2), energy increases by 5% (9 + 0.45 = 9.45).
Day 3: Drinks 3 liters (more than 2), energy increases by 5% (9.45 + 0.4725 ≈ 9.9225).
Day 4: Drinks 4 liters (more than 2), energy increases by 5% (9.9225 + 0.4961 ≈ 10.4186).
Lexi survives all 4 days as her energy never reaches zero. Thus, the answer is 4 days.

*/

#include <bits/stdc++.h>
using namespace std;

int calculateSurvivalDays(int n, int k, double e, double x, vector<int>& arr);

int main() {
    int n, k;
    double e, x;
    cin >> n >> k >> e >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int days = calculateSurvivalDays(n, k, e, x, arr);

    cout << days << endl;
    return 0;
}

int calculateSurvivalDays(int n, int k, double e, double x, vector<int>& arr) {
    int survivalDays = 0;

    for (int i = 0; i < n; i++) {
        if (e <= 0) {
            break; // If energy is zero or less, Lexi cannot survive any longer
        }
        if (e > 0) {
            survivalDays++;
        }

        if (arr[i] < k) {
            // If Lexi drinks less than required, decrease her energy
            e -= x;
        } else {
            // If Lexi drinks at least the required amount, increase her energy by 5%
            e += (e * 0.05);
        }

        // If her energy is still above zero after the day, she survives this day
        
    }

    return survivalDays;
}