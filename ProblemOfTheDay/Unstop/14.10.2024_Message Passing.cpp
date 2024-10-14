/*
Problem Link : https://unstop.com/code/practice/259647
*/

/*Message Passing

Problem Statement
There are N employees in a company, each with a certain power level represented in a sorted array pow of size N. Each employee has been assigned a message, and they need to pass this message to the next employee under the following conditions:

If Employee A passes a message to Employee B, then Employee B can only pass that message to Employee C if and only if the difference in power between A and B is equal to the difference in power between B and C.

Your task is to determine the maximum number of employees that can be part of a continuous message-passing sequence under these conditions.

 

Input Format
The first line of input contains a single integer N representing the number of employees.

The second line of input contains N space-separated integers representing the power levels of the employees in a sorted array pow.

Output Format
Print the maximum number of employees that can pass the same message in a sequence.

Constraints
1 <= N <= 10^3

1 <= pow[i] <= 10^4

Sample Testcase 0
Testcase Input
5
9 4 7 2 10
Testcase Output
3
Explanation
An employee with power 4 can pass the message to an employee with power 7, who can then pass it to an employee with power 10, because the difference between consecutive powers is the same (7-4 = 3 and 10-7 = 3). 

Therefore, the maximum number of employees in this message-passing sequence is 3.

Sample Testcase 1
Testcase Input
5
2 4 6 8 10
Testcase Output
5
Explanation
All employees can pass the message in the sequence (2 → 4 → 6 → 8 → 10) because the difference between consecutive powers is consistently 2. 

Therefore, the maximum number of employees in this message-passing sequence is 5.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(vector<ll>a) 
{
    ll n = a.size();
    if (n <= 2) 
        return n;

    ll max_len = 2;

    ll dp[n];

    for (ll i = 0; i < n; i++) 
    {
        dp[i] = 2;
    }

    for (ll j = n - 2; j >= 0; j--)
    {
        ll i = j - 1;
        ll k = j + 1; 
        while (i >= 0 && k < n)
        {
            if (a[i] + a[k] == 2 * a[j]) 
            {
                dp[j] = max(dp[k] + 1, dp[j]);
                max_len = max(max_len, dp[j]);
                i--;
                k++;
            }
            else if (a[i] + a[k] < 2 * a[j]) 
                k++;
            else 
                i--;
        }
    }
    return max_len;
}

int main()
{
    ll n;
    cin>>n;
    vector<ll>vec(n);
    for(ll i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout << solve(vec);

    return 0;
}