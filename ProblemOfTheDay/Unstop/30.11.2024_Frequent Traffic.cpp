/*
Problem Link: https://unstop.com/code/practice/298225
*/

/*Frequent Traffic

Problem Statement
A city has N landmarks and N-1 paths. From any landmark there is path to every other landmark. There is a carhop owner with N cars numbered from 1 to N.

He wants to visit all the paths and for every path he knows whether the path is visited or not. If the with car is selected it will visit all the path from ith landmark to 1st landmark which is the rooted landmark of the city.

Select minimum number of cars to visit all the paths.

Input Format
The first line consist of N the number of landmarks.
The next N-1 lines contain u,v and c where u and v are connected path and if c is 1 then {u,v} is visited and if c is 0 then it is not visited.
NOTE:The paths represent a tree.

Output Format
Print the minimum number of cars to visit all the paths.

Constraints
2<=N<=2*10^5

1<=u,v<=N

0<=c<=1

Sample Testcase 0
Testcase Input
4
1 2 0
2 3 1
2 4 0
Testcase Output
1
Explanation
If we select the at path 4 it will visit {4,2},{2,1} so all the paths will be visited as {2,3} is already visited.


So minimum number of car will be 1.

Sample Testcase 1
Testcase Input
6
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
Testcase Output
0
Explanation
All Paths are already visited.

*/

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll inf = 1e18, mod = 1e9 + 7;
vector<pair<ll, ll>> adj[100005];
ll visited[100005], ans = 0;
ll dfs(ll curr)
{
    visited[curr] = 1;
    ll flg = 0;
    for (auto it : adj[curr])
    {
        if (visited[it.first])
            continue;
        if (it.second == 0)
        {
            if (dfs(it.first))
                flg = 1;
            else
                flg = 1, ans++;
        }
        else
        {
            if (dfs(it.first))
                flg = 1;
        }
    }
    return flg;
}
int main()
{
    ll n, a, b, c;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        visited[i] = 0;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dfs(0);

    cout << ans << endl;
}

