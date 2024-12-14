/*
Problem Link: https://unstop.com/code/practice/298158
*/

/*Excellent collection

Problem Statement
Emma loves to collect the old Pepsi bottle caps, she has a collection of n caps each of which has price ai, but she called a collection Excellent if and only if a1+a2+⋯+am=2⋅(a1⊕a2⊕⋯⊕am) where ⊕ denotes the bitwise XOR operation.

You are given an array of length n: a1,a2,a3…an.

Append at most 3 caps such that the collection becomes Excellent, you have to tell whether is possible to make a collection excellent or not.

Input Format
The first line contains T the number of test cases. Then each test case follows the given rules.

The First Line of each test case contains an integer N, representing the size of an array.

The next line contains N space-separated integers a1, a2, a3….an.

Output Format
For each test case print "YES" if it is possible to make a collection Excellent otherwise print "NO"

Constraints
1 <= T <= 10^3

1 <= N <= 10^3

1 <= A[i] <= 10^9

Sample Testcase 0
Testcase Input
3
4
1 2 3 6
1
1
2
1 1
Testcase Output
YES
YES
YES
Explanation
In the first case all the element is already satisfying the property hence the answer is “Yes”.


In the second test case, we can add 18 and 6 then (1+18+6)=2*(1⊕18⊕6), so the answer will be YES.


In the Third test case, we can add 2 and the array becomes Excellent since (1+1+2+2)=2(1⊕1⊕2⊕2);

Sample Testcase 1
Testcase Input
2
4
3 5 6 7
3
6 7 8
Testcase Output
YES
YES
Explanation
In the first test case, we can add 7 and 28 to make an array Excellent since (3+5+6+7+7+28) = 2*(3⊕5⊕6⊕7⊕7⊕28).


In the second test case, we can add 9 and 30 to make an array Excellent since (6+7+8+9+30)=2*(6⊕7⊕8⊕9⊕30).

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

string solve(ll n, vector<ll> arr)
{
    ll totalSum = 0;
    ll totalXor = 0;

    for (ll cap : arr) {
        totalSum += cap;
        totalXor ^= cap;
    }

    if (totalSum == 2 * totalXor) {
        return "YES";
    }

    return "YES";
    
}

int main()
{
    _io;
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        cout << solve(n, arr) << endl;
    }
    return 0;
}
