/*
Problem Link: https://unstop.com/code/practice/299082
*/

/*Tree in Tree

Problem Statement
For a tree with N vertices numbered from 1 to N and edges connecting vertices ai and Bi, solve the problem for each X from 1 to N.

The problem requires finding the number of non-empty subsets V of the tree's vertices, such that the subgraph induced by V has exactly X connected components.

The final answer should be modulo 998244353.

Input Format
First Line contains one integer N
The second line contains N-1 space-seperated integers representing the edges of the tree.
Output Format
Print N lines.
The ith line should contain the answer for X=i.
Constraints
1 >= N <= 2* 10^3.
1 >= A[i], B[i] <= N.
Sample Testcase 0
Testcase Input
2
1 2
Testcase Output
3
0
Explanation
There is only one single edge in the tree.
Sample Testcase 1
Testcase Input
4
1 2
2 3
3 4
Testcase Output
10
5
0
0
Explanation
The induced subgraph will have two connected components in the following five cases and one in the others.

V={1,2,4}
V={1,3}
V={1,3,4}
V={1,4}
V={2,4}

*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MODULO = 998244353;
const int MAX_NODES = 5010;

vector<int> adjacencyList[MAX_NODES];
int dp[MAX_NODES][2][MAX_NODES];
int totalNodes;

void addEdge(int nodeA, int nodeB)
{
    adjacencyList[nodeA].push_back(nodeB);
    adjacencyList[nodeB].push_back(nodeA);
}

int computeSubsets(int currentNode, int parentNode)
{
    int subtreeSize = 1;

    dp[currentNode][0][0] = 1;
    dp[currentNode][1][1] = 1;

    for (int neighbor : adjacencyList[currentNode])
    {
        if (neighbor == parentNode)
            continue;

        int subtreeCount = computeSubsets(neighbor, currentNode);

        for (int selectedNodes = subtreeSize; selectedNodes >= 0; --selectedNodes)
        {
            for (int newNodes = subtreeCount; newNodes >= 1; --newNodes)
            {
                dp[currentNode][0][selectedNodes + newNodes] =
                    (dp[currentNode][0][selectedNodes + newNodes] +
                     (dp[currentNode][0][selectedNodes] *
                      (dp[neighbor][0][newNodes] + dp[neighbor][1][newNodes]) % MODULO) %
                         MODULO) %
                    MODULO;
            }
        }

        for (int selectedNodes = subtreeSize; selectedNodes >= 1; --selectedNodes)
        {
            for (int newNodes = subtreeCount; newNodes >= 1; --newNodes)
            {
                dp[currentNode][1][selectedNodes + newNodes] =
                    (dp[currentNode][1][selectedNodes + newNodes] +
                     (dp[currentNode][1][selectedNodes] * dp[neighbor][0][newNodes]) % MODULO) %
                    MODULO;

                dp[currentNode][1][selectedNodes + newNodes - 1] =
                    (dp[currentNode][1][selectedNodes + newNodes - 1] +
                     (dp[currentNode][1][selectedNodes] * dp[neighbor][1][newNodes]) % MODULO) %
                    MODULO;
            }
        }

        subtreeSize += subtreeCount;
    }

    return subtreeSize;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> totalNodes;

    for (int i = 1; i < totalNodes; ++i)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        addEdge(nodeA, nodeB);
    }

    computeSubsets(1, 0);

    for (int i = 1; i <= totalNodes; ++i)
    {
        cout << (dp[1][0][i] + dp[1][1][i]) % MODULO << endl;
    }

    return 0;
}


