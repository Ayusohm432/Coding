/*
Problem Link : https://unstop.com/code/practice/307629
*/

/*Helping Mike

Problem Statement
You and Mike are good friends. One day Mike got stuck solving a  tricky problem, and he needed your help. Even though you are busy, you are committed to helping Mike. The problem states as follows……

You are given an array of values of size N consisting of positive integers. You are also given integer array queries of size M. For the ith query, you want to make all of the elements of values equal to queries[i]. You can subtract or add any integer value X to the present value(x will be your choice).print  the score for each query after making the values of the array values equal to queries[i].

Score: sum of all the X values chosen to make every value of the array values equal to the given query.

Note that after each query, the array is reset to its original state.

Input Format
The first line will contain two space-separated integers, N and M.

N-the size of the array values.

M-the size of the array queries arrays.

The next line contains N space-separated integers representing values[i].

The next line contains M space-separated integers representing queries[i].

Output Format
Print the score for each query. The scores should be printed in a space-separated way.

Constraints
1≤N,M≤10^5

0<=values[i],queries[i]<=10^9

Sample Testcase 0
Testcase Input
3 2
1 2 3
1 5
Testcase Output
3 9
Explanation
Query1: |1-1| + |1-2| + |1-3|=3


Query 2:|5-1|+|5-3|+|5-3|=9

Sample Testcase 1
Testcase Input
3 2
1 1 1
4 5
Testcase Output
9 12
Explanation
Query1: |4-1| + |4-1| + |4-1|=9


Query 2:|5-1|+|5-1|+|5-1|=12

*/

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

vector<ll> compute_scores(ll n, ll m, vector<ll>& values, vector<ll>& queries);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> values(n);
    vector<ll> queries(m);

    for (ll i = 0; i < n; i++) {
        cin >> values[i];
    }

    for (ll i = 0; i < m; i++) {
        cin >> queries[i];
    }

    vector<ll> results = compute_scores(n, m, values, queries);

    for (ll res : results) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}

vector<ll> compute_scores(ll n, ll m, vector<ll>& values, vector<ll>& queries) {
    // User needsa to implement this function
    vector<ll> results;

    for (ll i = 0; i < m; i++) {
        ll query_value = queries[i];
        ll score = 0;
        
        // Calculate the score for the current query
        for (ll j = 0; j < n; j++) {
            score += abs(values[j] - query_value);
        }
        
        results.push_back(score);
    }
    
    return results;
}
