/*
Problem Link: https://unstop.com/code/practice/301890
*/

/*Bruno's Rabbits

Problem Statement
Bruno has N grapes arranged in a row, each labeled with a type represented by a positive integer. He has two smart rabbits that can fetch grapes. When given a type number X, a rabbit will search through the row to pick the first grape of that type it finds, starting either from the left end or the right end. The rabbit takes one second to check each grape.

Bruno wants to eat two grapes of different types, where the sum of their types equals K. He can send both rabbits out at the same time, either from one end or from both ends of the row. Your task is to find out the minimum time it will take for the rabbits to bring back the two grapes. If it's not possible to find two grapes that meet this requirement, return -1.

Input Format
The first line of input contains two space-separated integers N and K, denoting the number of grapes and the required sum respectively.

The second line contains N space-separated integers representing the types of the grapes.

Output Format
Print a single integer indicating the minimum number of seconds required for Bruno to get the two grapes. If it's not possible to get the desired grapes, print -1.

Constraints
2 ≤ N ≤ 5 × 10^5
1 ≤ K ≤ 10^6
1 ≤ Ti ≤ 10^6

Sample Testcase 0
Testcase Input
5 5
2 4 3 2 1
Testcase Output
2
Explanation
Bruno wants two grapes with types that sum to 5.
Possible pairs are:
Type 4 and Type 1 (since 4 + 1 = 5).

Release one rabbit from the left with type 4 and one rabbit from the right with type 1:
The first rabbit finds grape of type 4 after checking 2 grapes (2 seconds).
The second rabbit finds grape of type 1 after checking 1 grape (1 second).
The total time taken is the maximum of these two, which is 2 seconds.

Thus, the answer is 2.

Sample Testcase 1
Testcase Input
5 5
2 4 9 2 5
Testcase Output
-1
Explanation
Bruno wants two grapes with types that sum to 5.
There are no pairs of grapes whose types add up to 5 in the given row.
Therefore, the output is -1.

*/

#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
int main()
{
    fast()
        ll n,
        k;
    cin >> n >> k;
    ll a[n + 1];
    map<ll, ll> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < k)
        {

            if (m[a[i]] == 0)
            {
                m[a[i]] = min(i, n - i + 1);
            }
            else
            {
                m[a[i]] = min(m[a[i]], min(i, n - i + 1));
            }
        }
    }
    int flag = 0;
    ll mini;
    for (ll i = 1; i < k; i++)
    {
        if (m[i] && m[k - i] && i != k - i)
        {
            if (flag == 0)
            {
                mini = max(m[i], m[k - i]);
                flag = 1;
            }
            else
            {
                mini = min(mini, max(m[i], m[k - i]));
            }
        }
    }
    if (flag == 0)
        cout << "-1";
    else
        cout << mini;
    return 0;
}