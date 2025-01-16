/*
Problem link: https://unstop.com/code/practice/303835
*/

/*The Segment Queries

Problem Statement
The problem consists of an array a containing N elements and involves handling two types of queries.

The first type, designated as Type-1, is represented by the command ! L R M , which adds the integer M to all elements in the array within the specified range from index L to index R.

The second type of query, labeled as Type-2, is indicated by the command ?, which requests the total sum of all the elements present in the array.

Input Format
The input begins with a single integer t, which represents the number of test cases (where 1 ≤ t ≤ 10).

For each test case,

the first line contains two integers, N and Q, representing the number of elements in the array and the number of queries, respectively.Here, 1 ≤ N ≤ 2*10^5 and 1 ≤ Q ≤ 2*10^5.
The second line of each test case provides n integers, denoted as a1,a2,…,an​, which represent the initial values of the array elements, constrained by 1 ≤ ai ≤ 10^9.
Additionally, the total sum of N  across all test cases is limited to 2*10^5.

Output Format
For each type-2 query print the sum of array at that point

Constraints
1≤ t ≤10

1≤ N ≤2*10^5

1 ≤ Q ≤ 2*10^5

1 ≤ ai ≤10^9

Sample Testcase 0
Testcase Input
1
 3 1
 -2 2 1
  ?
Testcase Output
1
Explanation
At query 1, it asks us to output the sum of the array: sum of ([-2, 2,1]) = 1
Sample Testcase 1
Testcase Input
1
 5 3
 1 2 3 4 5
 ! 1 2 4
 ! 1 4 -5
 ?
Testcase Output
3
Explanation
Changes in array after subsequent queries:
At query 1, the array becomes: [5, 6, 3, 4, 5]
At query 2, the array becomes: [0, 1, -2, -1, 5]
At query 3, it asks us to output the sum of the array: sum of ([0, 1, -2, -1, 5]) = 3

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> user_logic(int n, int q, vector<int> &arr, vector<vector<string>> &queries)
{
    vector<int> ans;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    for (auto &query : queries)
    {
        if (query[0] == "!")
        {
            int l = stoi(query[1]);
            int r = stoi(query[2]);
            int m = stoi(query[3]);

            sum += (r - l + 1) * m;
        }
        else if (query[0] == "?")
        {
            ans.push_back(sum);
        }
    }

    return ans;
}

signed main()
{
    int t;
    cin >> t;

    vector<int> results;

    for (int i = 0; i < t; ++i)
    {
        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[j];
        }

        vector<vector<string>> queries(q);
        for (int k = 0; k < q; ++k)
        {
            string query_type;
            cin >> query_type;

            if (query_type == "!")
            {
                string l, r, m;
                cin >> l >> r >> m;
                queries[k] = {query_type, l, r, m};
            }
            else
            {
                queries[k] = {query_type};
            }
        }

        vector<int> result = user_logic(n, q, arr, queries);
        results.insert(results.end(), result.begin(), result.end());
    }

    for (const int &res : results)
    {
        cout << res << endl;
    }

    return 0;
}