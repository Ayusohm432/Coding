/*
Problem Link : https://unstop.com/code/practice/260010
*/

/*Speed Ticket

Problem Statement
During the night of the street race, there are N cars on the street, each with a given speed. The police will be alerted if the total number of speed variation pairs exceeds a certain threshold, X.

A pair of cars (i, j) has a speed variation if the absolute difference in their speeds is at least K. The total speed variation count is the number of such pairs where the speed difference is at least K.
You need to determine whether the total speed variation count is greater than the given threshold, X. If it is, the police will be alerted; otherwise, they will not.

Input Format
The first line contains three space separated integers, N, number of cars; K, minimum speed difference for variation; and X, alert threshold.

The second line contains N space-separated integers representing the speeds of the cars.

Output Format
Print YES if the total speed variation count exceeds X, otherwise, print NO.

Constraints
1 <= N <= 2 * 105

1 <= K, X <= 108

1 <= S[i] <= 108

Sample Testcase 0
Testcase Input
3 1 2
2 3 4
Testcase Output
YES
Explanation
The pairs with a speed variation of at least 1 are:
(2, 3) with a difference of 1
(2, 4) with a difference of 2
(3, 4) with a difference of 1
There are 3 pairs in total, and all of them have a speed variation that meets the required condition of at least 1.


Since there are 3 pairs and the threshold X is 2, which is less than the number of valid pairs, the police will be alerted.


Thus, the correct output is YES.

Sample Testcase 1
Testcase Input
4 2 4
2 3 1 4 
Testcase Output
NO
Explanation
The pairs with a speed variation of at least 2 are:
1) (2, 1) with a difference of 1 (This pair does not meet the condition because the difference is less than 2)
2) (2, 4) with a difference of 2
3) (3, 1) with a difference of 2
4) (3, 4) with a difference of 1 (This pair does not meet the condition because the difference is less than 2)
5) (1, 4) with a difference of 3

There are 3 such pairs (2, 1), (3, 1), and (1, 4) that meet the required speed variation condition. However, this is less than the threshold 4. Thus, the police will not be alerted, and the correct output is NO.

*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	long long k, x;
	cin >> n >> k >> x;

	vector<long long> a(n);
	for (auto &x : a) cin >> x;

	sort(a.begin(), a.end()); 
	long long cnt = 0; 

	int i = 0, j = 0;
	while (i < n) {
		if (j < i) j = i;
		else if (j >= n) break;
		if (a[j] - a[i] >= k) {
			i++;
			cnt += (n - j);
		}
		else j++;
	}

	if (cnt >= x) cout << "YES\n"; 
	else cout << "NO\n";
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("Error.txt", "w", stderr);
#endif

	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}