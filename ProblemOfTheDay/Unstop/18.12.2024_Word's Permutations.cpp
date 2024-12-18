/*
Problem link: https://unstop.com/code/practice/301096
*/

/*Word's Permutations

Problem Statement
Given a word S, calculate the number of distinct permutations of its letters such that the letter with the highest frequency does not occur consecutively. The input string consists solely of lowercase letters. Your task is to output the total number of distinct permutations where the most frequent letter is not adjacent to itself.

Input Format
The first line contains an integer T, the number of test cases.
Each of the next T lines contains a single word S.

Output Format
For each test case, print the number of distinct permutations of the letters in the given word where the letter with the highest frequency does not appear together.

Constraints
1 <= T <= 10^3
1 <= S.lenght <= 50



Sample Testcase 0
Testcase Input
1
mississippi
Testcase Output
33810
Explanation
For the word "mississippi," the letters 's' and 'i' both have the highest frequency of 4. We calculate the total permutations and subtract the permutations where all 'i's (or all 's's) are together:


Total permutations: 11! / (4!4!2!) = 34650
Permutations with 4 'i's together: 8! / (4!2!) = 840
Permutations with 4 'i's not together: 34650 - 840 = 33810

Sample Testcase 1
Testcase Input
1
honolulu
Testcase Output
3780
Explanation
For the word "honolulu," the letter 'o' has the highest frequency of 2. We calculate the total permutations and subtract the permutations where all 'o's are together:


Total permutations: 7! / (3!2!2!) = 2520
Permutations with 3 'o's together: 5! / (3!2!) = 30
Permutations with 3 'o's not together: 2520 - 30 = 3780

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fact(ll n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.size(), ans = 1;
        ll hash[26] = {0};
        vector<ll> v1;
        vector<ll> v2;
        for (ll i = 0; i < n; i++)
        {

            hash[s[i] - 'a']++;
        }

        for (ll i = 0; i < 26; i++)
        {
            if (hash[i] != 0)
                v1.push_back(hash[i]);
        }
        sort(v1.begin(), v1.end());
        ll sz = v1.size();
        ll mx = v1[sz - 1];
        // cout<<mx<<endl;
        for (ll i = n; i > mx; i--)
        {
            ans = ans * i;
        }
        for (ll i = 0; i < sz - 1; i++)
        {
            ll temp = fact(v1[i]);
            ans = ans / temp;
        }
        ll rem_mx = n - mx + 1;
        ll res = 1;
        ll mx2 = v1[sz - 2];

        for (ll i = rem_mx; i > mx2; i--)
        {
            res = res * i;
        }
        for (ll i = 0; i < sz - 2; i++)
        {
            ll temp = fact(v1[i]);
            res = res / temp;
        }
        cout << ans - res << endl;
    }
    return 0;
}