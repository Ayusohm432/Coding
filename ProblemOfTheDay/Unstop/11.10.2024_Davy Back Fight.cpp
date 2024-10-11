/*
Problem Link : https://unstop.com/code/practice/259980
*/

/*Davy Back Fight

Problem Statement
N pirates gathered at the Long Ring Long Land for the Davy Back Fight. Each Pirate has a strength S[i] assigned to it. Now, several rounds will follow.

In each round, any two pirates will be called to fight against each other and the one having the higher strength will win this round. The loser of this round will be eliminated and have to join the pirate crew of the winner(initially, all the pirates belong to their crew). In case both the pirates have equal strengths, this round will be considered a tie, and nothing will happen.

You will have to answer Q queries, each of which can be of the following types:

1 X Y: This denotes that the crew containing pirate number X competes with the crew containing pirate number Y. If both the pirates are of the same crew, print -1. Otherwise, execute and store the result of this round as described by the rules above.
2 X: Output the crew of the pirate X at this point.
Input Format
The first line contains two integers N and Q denoting the number of pirates and the number of queries.

The next line contains N space-separated integers where the ith integer represents the strength S[i].

Q lines follow where each line can be of the format 1 X Y or 2 X as described in the problem statement.

 

It is guaranteed, that there is at least one query of second type.

Output Format
Print in each line the answer for the queries as described in the problem statement.

Constraints
1 <= N, Q <= 105

0 <= S[i] <= 106

1 <= X, Y <= N

Sample Testcase 0
Testcase Input
3 4
2 2 3
1 1 2
2 1
1 2 3
2 2 
Testcase Output
1
3
Explanation
Since pirate 1 and 2 has the same strength, nothing happened in the first query.


Hence, the answer for the second query, i.e. first pirate belongs to crew 1.


After the third query, pirate 3 acquires pirate 2 since S[3] > S[2].


Hence, the answer for the fourth query, i.e. second pirate now belongs to crew 3.

Sample Testcase 1
Testcase Input
5 5
3 2 5 7 1
1 1 2
2 2
1 3 4
1 1 4
2 1 
Testcase Output
1
4
Explanation
After the first query, pirate 1 acquires pirate 2 since S[1] > S[2] .


Hence, the answer for the second query, i.e. second pirate now belongs to crew 1.


After the third query, pirate 4 acquires pirate 3 since S[4] > S[3] .


After the fourth query, pirate 4 acquires pirate 1 along with pirate 2, since S[4] > S[1] .


Hence, the answer for the fifth query, i.e. first pirate now belongs to crew 4.

*/
#include <iostream>
#include <vector>

using namespace std;

// DSU (Disjoint Set Union) structure to manage pirate crews
class DSU {
public:
    vector<int> parent, strength, size;

    // Initialize DSU structure
    DSU(int n, vector<int>& S) {
        parent.resize(n+1);
        strength = S;
        size.resize(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    // Find the leader of the crew with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    // Union of two crews based on the strength of their leaders
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (strength[rootX] > strength[rootY]) {
                parent[rootY] = rootX;
            } else if (strength[rootX] < strength[rootY]) {
                parent[rootX] = rootY;
            }
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> S(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> S[i];
    }

    DSU dsu(N, S);

    for (int i = 0; i < Q; ++i) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int X, Y;
            cin >> X >> Y;

            if (dsu.find(X) == dsu.find(Y)) {
                cout << -1 << endl;
            } else {
                dsu.unionSets(X, Y);
            }
        } else if (queryType == 2) {
            int X;
            cin >> X;
            cout << dsu.find(X) << endl;
        }
    }

    return 0;
}
