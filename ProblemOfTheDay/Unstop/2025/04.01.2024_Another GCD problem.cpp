/*
Problem Link: https://unstop.com/code/practice/303966
*/
/*Another GCD problem

Problem Statement
Given an array 'a' consisting of 'n' elements. Find the number of pairs (i, j) where:

0 <= i, j <= n-1
The greatest common divisor (gcd) of ai, and aj is equal to 'x'.
Here x belongs from 1 to n.

Input Format
The first line contains an integer t  (1 ≤ t ≤ 10^3 )   — the number of testcase.

The first line of each testcase contains a single integer n (1 ≤ n ≤ 2 * 10^5  )   — the number of elements in the array.

The second line contains n integers a1,a2,…,an  (1 ≤ ai ≤10^9) — the value of element ai

Output Format
Print the number of pair 0  <= i, j<= n-1, such that gcd(ai, aj) equals x.

Constraints
1≤ t ≤10^3   

1≤ n ≤2*10^5   

1 ≤ ai ≤10^5

Sample Testcase 0
Testcase Input
1
5
2 3 4 5 10
Testcase Output
6 3 0 0 1
Explanation
The problem statement is self-explanatory for the output. The number of pairs (ai, aj ) that have gcd(ai, aj ) = 1 is 6, which are(2, 3), (2, 5), (3, 5), (3, 4), (3, 10) ;


The number of pairs (ai, aj ) that have gcd(ai, aj ) = 2 is 3, which are(2, 4), (2, 10), (4, 10) ; and so on for other values of X.

Sample Testcase 1
Testcase Input
1
6
1 2 4 5 6 10
Testcase Output
8 6 0 0 1 0
Explanation
The problem statement is self-explanatory for the output. The number of pairs (ai, aj ) that have gcd(ai, aj ) = 1 is 8


The number of pairs (ai, aj ) that have gcd(ai, aj ) = 2 is 6; and so on for other values of X.

*/

#include <bits/stdc++.h>
using namespace std;

int arr[2000001];

void user_logic(int n, vector<int>& vec) {
    // Reset the frequency array
    for (auto i = 0; i < 2000001; i++) arr[i] = 0;

    // Count the frequency of each element in the array
    for (auto i = 0; i < n; i++) {
        arr[vec[i]]++;
    }

    // Calculate the number of pairs for each possible GCD value
    for (int i = 1; i <= 1e5; i++) {
        for (auto j = 2 * i; j < 1e5; j += i) {
            arr[i] += arr[j];
        }
    }

    // Calculate the number of pairs for each GCD value
    for (auto i = 1; i < 1e5; i++) {
        arr[i] = (arr[i] * (arr[i] - 1)) / 2;
    }

    // Adjust the counts using the inclusion-exclusion principle
    for (auto i = 1; i < 1e5; i++) {
        for (auto j = 2 * i; j < 1e5; j += i) {
            arr[i] -= arr[j];
        }
    }

    // Output the results for x from 1 to n
    for (auto i = 0; i < n; i++) {
        cout << arr[i + 1] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (auto i = 0; i < n; i++) {
            cin >> vec[i];
        }
        // Call the user_logic function
        user_logic(n, vec);
    }
    return 0;
}