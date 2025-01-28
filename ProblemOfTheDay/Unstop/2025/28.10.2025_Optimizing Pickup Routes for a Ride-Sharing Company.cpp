/*
Problem Link: https://unstop.com/code/practice/306606
*/

/*Optimizing Pickup Routes for a Ride-Sharing Company

Problem Statement
A ride-sharing company needs to determine the shortest driving routes from its main office to various pickup points in a city.

The ride-sharing company's main office represents the starting point, and there are n pickup points in different parts of the city. The flight connections between cities represent the road connections or routes between the main office and the pickup points, with m connections indicating the number of available routes.

Determine the length of the shortest route between the main office and each pickup point.

Input Format
The first line of input contains two integers, n and m, where n is the number of pickup points and m is the number of flight connections. Pickup points are numbered from 1 to n, with point 1 representing the main office.

The subsequent m lines provide details of the flight connections. Each line consists of three integers a, b, and c, where a is the starting pickup point, b is the destination pickup point, and c is the length of the flight. Each flight is directed from a to b.

Output Format
Print n integers representing the shortest distance from the main office to each of the pickup points, numbered from 1 to n.

Constraints
1≤ n ≤ 10^5

1≤ m ≤ 2*10^5

1≤ a , b ≤n

1≤ c ≤ 10^9

Sample Testcase 0
Testcase Input
3 4
1 2 6
1 3 2
3 2 3
1 3 4
Testcase Output
0 5 2
Explanation




Nodes: 3 pickup points (1, 2, 3), with 1 as the main office.


Connections:
1 to 2 with distance 6
1 to 3 with distance 2
3 to 2 with distance 3
1 to 3 with distance 4


Output: 0 5 2
Distance from 1 to 1: 0 (distance to itself is always 0).
Distance from 1 to 2: Shortest route is 1 → 3 → 2 with a total distance of 2 + 3 = 5.
Distance from 1 to 3: Direct route from 1 to 3 has a distance of 2.





Sample Testcase 1
Testcase Input
1 1
1 1 1
Testcase Output
0
Explanation
Nodes: 1 pickup point (1), which is also the main office.
Connections: There is one flight from 1 to 1 with a distance of 1.
Since there is only one pickup point, and it is the same as the main office, the shortest distance from the main office to itself is always 0.


Output: 0
This indicates that there are no other nodes to calculate distances to, so the output is simply the distance from node 1 to itself, which is 0.

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
void find_shortest_distances(int n, int m, const std::vector<std::vector<int>> &connections)
{
    unordered_map<int, unordered_map<int, int>> mp;
    for (auto it : connections)
    {
        int a = it[0], b = it[1], c = it[2];
        if (mp[a].find(b) != mp[a].end())
        {
            mp[a][b] = min(mp[a][b], c);
        }
        else
        {
            mp[a][b] = c;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<int> dis(n + 1, LLONG_MAX), vis(n + 1, 0);
    dis[1] = 0;
    while (!pq.empty())
    {
        auto i = pq.top();
        pq.pop();
        int node = i.second;
        int d = i.first;
        if (d > dis[node])
            continue;
        vis[node] = 1;
        for (auto it : mp[node])
        {
            int adj = it.first, adjd = it.second;
            if (!vis[adj] && dis[adj] > adjd + d)
            {
                dis[adj] = adjd + d;
                pq.push({adjd + d, adj});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
}

signed main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> connections(m, std::vector<int>(3));
    for (int i = 0; i < m; ++i)
    {
        std::cin >> connections[i][0] >> connections[i][1] >> connections[i][2];
    }
    find_shortest_distances(n, m, connections);
    return 0;
}