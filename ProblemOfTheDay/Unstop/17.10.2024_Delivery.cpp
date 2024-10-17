/*
Problem Link : https://unstop.com/code/practice/297432
*/

/*Delivery

Problem Statement
The restaurant has decided to begin food delivery to residences. He anticipates receiving many orders for delivery, but there is a problem.

He lacks sufficient labour to complete all the deliveries. He has a solution for this; he will collect all the orders that must be delivered in the area. He has specifically named a few bidirectional routes that he refers to as fast roads.

These roads provide for quick travel because they are short and frequently empty of traffic. If and only if it is possible to reach point A to point B using only fast routes, that is how he intends to transmit instructions.

You must, given the configuration of fast roads, identify which orders are to be sent together.

Input Format
The first line of each test case contains two space-separated integers, N and M, denoting the number of locations and the number of fast roads.

Then M lines follow, each having two space-separated integers A and B, suggesting a fast road between locations A and B.

Assume that locations are indexed by numbers from 0 to N-1.

The next line contains an integer Q denoting the number of queries.

Each of the next Q lines contains two integers, X and Y.

For each query, you have to find out if orders meant for locations X and Y are to be sent together or not.

Output Format
One for each query. Output "YO" if the orders are to be delivered together and "NO" otherwise

Constraints
1 ≤ N ≤ 10^2

1 ≤ M ≤ 10^3

0 ≤ A, B, X, Y ≤ N-1

1 ≤ Q ≤ 3 * 10^3

Sample Testcase 0
Testcase Input
4 2
0 1
1 2
3
0 2
0 3
2 1
Testcase Output
YO
NO
YO
Explanation
The input represents an undirected graph with 4 vertices and 2 edges. The edges are (0,1) and (1,2). The graph has two connected components: {0,1,2} and {3}.


The first query is (0,2), and both vertices are in the same connected component, so the output is YO.


The second query is (0,3), vertices in different connected components, so the output is NO.


The third query is (2,1), vertices in the same corresponding component, so the output is YO.

Sample Testcase 1
Testcase Input
3 3
1 2
2 3
1 3
1
1 2
Testcase Output
YO
Explanation
Graph Construction:
Input is read and a graph (adjacency list) is created where each location is connected to others via bidirectional fast roads.


DFS for Connected Components:
A DFS is run starting from each unvisited location. The DFS assigns a unique label (component number) to all locations reachable from that location.
The vect array stores these component labels. Locations in the same component will have the same label.


Query Processing:
For each query, the program checks if the two locations have the same component label in the vect array.


If they share the same label, they are connected, and output is "YO". Otherwise, it's "NO".
For the query 1 2, both locations are part of the same component, so the output is "YO".

*/
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int MAX_N = 100;
const int MAX_M = 1000;
const int MAX_Q = 3000;

vector<ll> adj[MAX_N];
bool visited[MAX_N];

void bfs(ll start)
{
    queue<ll> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        for (ll v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

bool canReach(ll u, ll v)
{
    memset(visited, false, sizeof(visited));
    bfs(u);
    return visited[v];
}

int main()
{
    ll N, M, Q;
    cin >> N >> M;

    for (ll i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> Q;

    for (ll i = 0; i < Q; i++)
    {
        ll u, v;
        cin >> u >> v;

        if (canReach(u, v))
        {
            cout << "YO" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}